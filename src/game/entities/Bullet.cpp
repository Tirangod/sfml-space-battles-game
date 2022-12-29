#include <game/entities/Bullet.hpp>

void Bullet::onInit() {
    getSprite().loadFrom(preset.skinPath);
    getSprite().alignCenter();
    getSprite().rotate(-90);
    getSprite().setScale(preset.scale);
    //getSprite().setScale(0.01f, 0.01f);
    
    scale = new ScaleEffect({1, 1});
    scale->addSprite(getSprite());
    scale->start();
    

    moveDir = {0, -1};
    speed = preset.speed;
}

void Bullet::onUpdate(float dt) {
    //scale->update(dt);
    if (GameWindow::IsOutofScreen(getSprite().getPosition())) {
        destroy(this);
    }

    move(moveDir * speed * dt);
}

void Bullet::onCollision(GameObject *object) {
    if (dynamic_cast<Enemy*>(object)) {
        spawn(new Blast(preset.blast)).getSprite().setPosition(getSprite().getPosition());
        destroy(this);
    }
}

float Bullet::getDamage() {
    return preset.damage;
}