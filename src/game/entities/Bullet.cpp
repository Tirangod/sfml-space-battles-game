#include <game/entities/Bullet.hpp>

void Bullet::onInit() {
    getSprite().loadFrom("assets/sprites/bullets/bullet_0.png");
    getSprite().alignCenter();
    getSprite().rotate(-90);
    getSprite().setScale(0.8f, 0.8f);

    moveDir = {0, -1};
    speed = 400.f;
}

void Bullet::onUpdate(float dt) {
    if (GameWindow::IsOutofScreen(getSprite().getPosition())) {
        destroy(this);
    }

    move(moveDir * speed * dt);
}

void Bullet::onCollision(GameObject *object) {
    if (dynamic_cast<Enemy*>(object)) {
        //if (timer.getElapsedTime().asSeconds() > 0.4f) {
        //new Blast(getSprite().getPosition())
        spawn(new Blast).getSprite().setPosition(getSprite().getPosition());
        destroy(this);
        //}
    }
}