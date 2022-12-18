#include <game/entities/Enemy.hpp>

void Enemy::onInit() {
    setupTexture("assets/sprites/red_01.png");
    
    getSprite().alignCenter();
    getSprite().rotate(180);
    //getSprite().setPosition(450, 200);
    getSprite().setScale(1.5f, 1.5f);

    hp = 100;
    healthBar.setMax(100);
    healthBar.setValue(hp);

    float yOffset = -getSprite().getLocalBounds().height;

    healthBar.setSize({getSprite().getLocalBounds().width * 2, 7});
    healthBar.getForeground().setFillColor(Color::Red);
    healthBar.setPosition({
        getSprite().getPosition().x - getSprite().getLocalBounds().width, 
        getSprite().getPosition().y + yOffset * 1.5f
    });
}

void Enemy::onDraw(RenderTarget &target) {
    healthBar._draw(target);
}

void Enemy::onUpdate(float dt) {
    if (shaking) {
        if (!beginShaking) {
            posBuffer = getSprite().getPosition();
            beginShaking = true;
        }
        float shakeAmplitude = 2.f;
        shakeElapsedTime += dt;
        float x = shakeAmplitude * sinf(shakeElapsedTime);
        float y = shakeAmplitude * sinf(shakeElapsedTime);
        getSprite().move((shakeAmplitude - rand() % 5) * 100.f * shakeAmplitude * dt, (shakeAmplitude - rand() % 5) * shakeAmplitude * 100.f * dt);

        if (shakeElapsedTime >= seconds(0.5f).asSeconds()) {
            shaking = false;
            beginShaking = false;
            shakeElapsedTime = 0;
            getSprite().setPosition(posBuffer);
        }
    }
}

void Enemy::onCollisionStay(GameObject *object) {
    if (dynamic_cast<Bullet*>(object)) {
        shaking = true;
        healthBar.add(-10);
        if (healthBar.getValue() <= 0) {
            spawn(new Explosion).getSprite().setPosition(getSprite().getPosition());
            destroy(this);
        }
    }
}