#include <game/entities/Bullet.hpp>

Bullet::Bullet(Vector2f startPos) {
    loadTexture("assets/bullet.png");
    centerSprite();

    getSprite().setPosition(startPos);

    moveDir = {0, -1};
    speed = 400.f;
}

void Bullet::onUpdate(float dt) {
    if (Global::WindowInfo::isOutofScreen(getSprite().getPosition())) {
        ObjectsPool::killObject(this);
    }

    getSprite().move(moveDir * (speed * dt));
}

void Bullet::onCollisionStay(GameObject *object) {
    ObjectsPool::killObject(this);
}