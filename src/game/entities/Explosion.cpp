#include <game/entities/Explosion.hpp>

void Explosion::onInit() {
    setupTexture("assets/sprites/anim.png");
    //getSprite().setPosition(pos);
    auto &animator = getSprite().getAnimator();
    animator.setAnimGrid({6, 6});
    animator.setRepeated(false);
    animator.setSpeed(milliseconds(10));
    
    getSprite().alignCenter();
}

void Explosion::onUpdate(float dt) {
    getSprite().getAnimator().play();

    if (timer.getElapsedTime() >= getSprite().getAnimator().getDuration()) {
        destroy(this);
    }
}
