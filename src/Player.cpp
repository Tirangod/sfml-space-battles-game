#include "game/Player.hpp"


Player::Player()
{
    tex.loadFromFile("assets\\metalic_02.png");
    sprite.setTexture(tex);
    sprite.setOrigin(
        sprite.getLocalBounds().width / 2,
        sprite.getLocalBounds().height / 2
    );
    sprite.setPosition(150, 150);
    sprite.setScale(3, 3);

    healthBar.setSize({sprite.getLocalBounds().width * 2, 7});
    healthBar.setFillColor(Color::Green);

    speed = 400.f;
}

void Player::draw(RenderTarget &target) {
    target.draw(sprite);
    target.draw(healthBar);
}

void Player::move(float dt) {
    bool topBound = sprite.getPosition().y >= 0;
    bool bottomBound = sprite.getPosition().y <= Global::get().windowSize.y;
    bool rightBound = sprite.getPosition().x <= Global::get().windowSize.x;
    bool leftBound = sprite.getPosition().x >= 0;
    
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

    sprite.move(moveDir * speed * dt);

    healthBar.setPosition(
        sprite.getPosition().x - sprite.getLocalBounds().width, 
        sprite.getPosition().y + sprite.getLocalBounds().height * 1.5f);
}

void Player::update(float dt) {
    move(dt);
}

void Player::onCollision(GameObject *other) {

}

Sprite Player::getSprite() { return sprite; }
