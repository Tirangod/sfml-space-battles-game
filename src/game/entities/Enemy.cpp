#include <game/entities/Enemy.hpp>

void Enemy::onInit() {
    getSprite().loadFrom(preset.skinPath);
    getSprite().alignCenter();
    getSprite().setRotation(90);
    getSprite().setScale(preset.scale);

    shakeEffect = new ShakeEffect(175.f);
    shakeEffect->addSprite(getSprite());
    shakeEffect->setDuration(seconds(0.35f));

    hp = preset.maxHP;
    healthBar.onInit();
    healthBar.setMax(hp);
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
        getSprite().getPosition().y + yOffset * preset.hpBarKY
    });
}  

void Enemy::onCollision(GameObject *object) {
    if (dynamic_cast<Bullet*>(object)) {
        shakeEffect->start();
        healthBar.add(-10);
        if (healthBar.getValue() <= 0) {
            auto& blast = spawn(new Blast(preset.blast));
            blast.getSprite().setPosition(getSprite().getPosition());
            destroy(this);
        }
    }
}

void Enemy::onKilled() {
    delete shakeEffect;
}