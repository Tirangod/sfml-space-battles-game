#include "game/Player.hpp"


Player::Player()
{
    Image img;
    img.loadFromFile("assets\\metalic_02.png");
    Texture tex;
    tex.loadFromImage(img);
    sprite.setTexture(tex);
    sprite.setOrigin(
        sprite.getLocalBounds().width / 2,
        sprite.getLocalBounds().height / 2
    );
    sprite.setPosition({150, 150});
}

void Player::draw(RenderTarget &target) {
    target.draw(sprite);
}

void Player::update(float dt) {

}

void Player::onCollision(GameObject *other) {

}

Sprite Player::getSprite() { return sprite; }
