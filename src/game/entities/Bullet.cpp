#include <game/entities/Bullet.hpp>

void Bullet::onInit() {
    setupTexture("assets/sprites/bullet_15.png");
    //setupShader("assets/pixelate.frag");

    getSprite().alignCenter();
    getSprite().rotate(-90);
    getSprite().setScale(0.2, 0.2);

    moveDir = {0, -1};
    speed = 400.f;
}

void Bullet::onUpdate(float dt) {
    if (WindowInfo::IsOutofScreen(getSprite().getPosition())) {
        //destroy(this);
        destroy(this);
    }

    move(moveDir * speed * dt);
}

void Bullet::onCollisionStay(GameObject *object) {
    if (dynamic_cast<Enemy*>(object)) {
        //if (timer.getElapsedTime().asSeconds() > 0.4f) {
        //new Explosion(getSprite().getPosition())
        spawn(new Explosion).getSprite().setPosition(getSprite().getPosition());
        destroy(this);
        //}
    }
}