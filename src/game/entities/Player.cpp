#include "game/entities/Player.hpp"

PlayerInfo Player::Preset = Player0;

void Player::onInit() {
    getSprite().loadFrom(Preset.skinPath);
    getSprite().alignCenter();
    getSprite().setPosition(GameWindow::GetSizef() / 2.f);
    getSprite().setScale(1.5f, 1.5f);

    fireSound.loadFrom(Preset.fireSoundPath);
    fireSound.setVolume(50.f);
    GameSettings::AddEffectSound(fireSound);

    hp = Preset.maxHP;
    healthBar.onInit();
    healthBar.setMax(hp);
    healthBar.setValue(hp);

    healthBar.setSize({getSprite().getLocalBounds().width * 2, 7});

    speed = Preset.speed;

    shootingDelay = Preset.shootingDelay;
    canShooting = true;
    isShooting = false;
    shootingCooldown = 0;
}

void Player::move(float dt) {
    bool topBound       = getSprite().getPosition().y - getSprite().getLocalBounds().height/2 >= 0;
    bool bottomBound    = getSprite().getPosition().y + getSprite().getLocalBounds().height/2 <= GameWindow::Get().getSize().y;
    bool rightBound     = getSprite().getPosition().x + getSprite().getLocalBounds().width/2  <= GameWindow::Get().getSize().x;
    bool leftBound      = getSprite().getPosition().x - getSprite().getLocalBounds().width/2  >= 0;
    
    if (Keyboard::isKeyPressed(Keyboard::W) && topBound) {
        moveDir.y = -1;
    } else if (Keyboard::isKeyPressed(Keyboard::S) && bottomBound) {
        moveDir.y = 1;
    } else {
        moveDir.y = 0;
    }

    if (Keyboard::isKeyPressed(Keyboard::A) && leftBound) {
        moveDir.x = -1;
    } else if (Keyboard::isKeyPressed(Keyboard::D) && rightBound) {
        moveDir.x = 1;
    } else {
        moveDir.x = 0;
    }

    getSprite().move(moveDir * speed * dt);

    float yOffset = bottomBound ? getSprite().getLocalBounds().height : -getSprite().getLocalBounds().height;

    healthBar.setPosition({
        getSprite().getPosition().x - getSprite().getLocalBounds().width, 
        getSprite().getPosition().y + yOffset * 1.5f
        });
}


void Player::onShot() {
    fireSound.play();
    auto& bullet = spawn(new Bullet(Preset.bullet));
    bullet.getSprite().setPosition({getSprite().getPosition().x, getSprite().getPosition().y - 60.f});
}

void Player::shooting(float dt) {
    isShooting = Keyboard::isKeyPressed(Keyboard::Space);

    if (canShooting) {
        if (isShooting) {
            canShooting = false;
            shootingCooldown = 0;
            onShot();
        }
    } else {
        if (shootingCooldown <= shootingDelay) {
            shootingCooldown += 250.f * dt;
        } else {
            canShooting = true;
        }
    }
}

void Player::onUpdate(float dt) {
    move(dt);
    shooting(dt);
}

void Player::onDraw(RenderTarget &target) {
    healthBar._draw(target);
}