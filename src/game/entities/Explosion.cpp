#include <game/entities/Explosion.hpp>

Explosion::Explosion() {
    setupTexture("assets/sprites/anim.png");
    //getSprite().setPosition(pos);
    auto &animator = getSprite().getAnimator();
    animator.setAnimGrid({6, 6});
    animator.setRepeated(false);
    animator.setSpeed(milliseconds(10));
    
    getSprite().alignCenter();
}

void Explosion::onUpdate(float dt) {
    getSprite().getAnimator().play(dt);

    if (timer.getElapsedTime() >= getSprite().getAnimator().getTime()) {
        destroy(this);
    }
}
