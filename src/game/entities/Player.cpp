#include "game/entities/Player.hpp"


Player::Player()
: hp(60), healthBar({hp, 100})
{
    loadTexture("assets/metalic_02.png");
    centerSprite();
    getSprite().setPosition(250, 250);
    getSprite().setScale(1.5f, 1.5f);

    healthBar.setSize({getSprite().getLocalBounds().width * 2, 7});

    speed = 400.f;

    isShooting = false;
    shootingDelay = 40.f;
    shootingCooldown = 0.f;
}

void Player::move(float dt) {
    bool topBound       = getSprite().getPosition().y - getSprite().getLocalBounds().height/2 >= 0;
    bool bottomBound    = getSprite().getPosition().y + getSprite().getLocalBounds().height/2 <= Global::WindowInfo::getWindowSize().y;
    bool rightBound     = getSprite().getPosition().x + getSprite().getLocalBounds().width/2  <= Global::WindowInfo::getWindowSize().x;
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
    ObjectsPool::addObject(new Bullet({getSprite().getPosition().x, getSprite().getPosition().y - 50.f}));
}

void Player::shooting(float dt) {
    isShooting = Keyboard::isKeyPressed(Keyboard::Space); // Alternative: Mouse::isButtonPressed(Mouse::Left);

    if (isShooting) {
        if (shootingCooldown >= shootingDelay) {
            shootingCooldown = 0;
            onShot();
        }
        shootingCooldown += 250.f * dt; // Remove magic constant
    } else {
        shootingCooldown = 0;
    }
}

void Player::onUpdate(float dt) {
    move(dt);
    shooting(dt);
}

void Player::onDraw(RenderTarget &target) {
    healthBar.draw(target);
}