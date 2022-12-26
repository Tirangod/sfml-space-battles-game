#include <game/entities/Enemy.hpp>

void Enemy::onInit() {
    getSprite().loadFrom("assets/sprites/enemies/ship1.png");
    getSprite().alignCenter();
    getSprite().setRotation(90);
    getSprite().setScale(2.f, 2.f);

    shakeEffect = new ShakeEffect(200.f);
    shakeEffect->addSprite(getSprite());

    hp = 100;
    healthBar.setMax(100);
    healthBar.setValue(hp);

    healthBar.setSize({getSprite().getLocalBounds().width * 2, 7});
    healthBar.getForeground().setFillColor(Color::Red);
}

void Enemy::onDraw(RenderTarget &target) {
    healthBar._draw(target);
}

void Enemy::onUpdate(float dt) {
    shakeEffect->update(dt);

    float yOffset = -getSprite().getLocalBounds().height;
    healthBar.setPosition({
        getSprite().getPosition().x - getSprite().getLocalBounds().width, 
        getSprite().getPosition().y + yOffset * 1.5f
    });
}  

void Enemy::onCollision(GameObject *object) {
    if (dynamic_cast<Bullet*>(object)) {
        shakeEffect->start();
        healthBar.add(-10);
        if (healthBar.getValue() <= 0) {
            Blast& blast = static_cast<Blast&>(spawn(new Blast));
            blast.getSprite().setPosition(getSprite().getPosition());
            blast.getSprite().setScale(3, 3);
            destroy(this);
        }
    }
}

void Enemy::onKilled() {
    delete shakeEffect;
}