#include <game/entities/Enemy.hpp>

Enemy::Enemy()
: hp(100), healthBar({hp, 100})
{
    loadTexture("assets/red_01.png");
    centerSprite();
    getSprite().rotate(180);
    getSprite().setPosition(150, 150);
    getSprite().setScale(1.5f, 1.5f);

    float yOffset = -getSprite().getLocalBounds().height;

    healthBar.setSize({getSprite().getLocalBounds().width * 2, 7});
    healthBar.getForeground().setFillColor(Color::Red);
    healthBar.setPosition({
        getSprite().getPosition().x - getSprite().getLocalBounds().width, 
        getSprite().getPosition().y + yOffset * 1.5f
        });
}

void Enemy::onDraw(RenderTarget &target) {
    healthBar.draw(target);
}

void Enemy::onCollisionStay(GameObject *object) {
    healthBar.add(-10);
}