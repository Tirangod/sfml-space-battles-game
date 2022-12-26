#include <game/entities/Blast.hpp>

void Blast::onInit() {
    getSprite().loadFrom("assets/sprites/blast/blast_3.png");
    auto &animator = getSprite().getAnimator();
    animator.setAnimGrid({8, 8});
    animator.setRepeated(false);
    animator.setSpeed(milliseconds(10));
    
    getSprite().alignCenter();
}

void Blast::onUpdate(float dt) {
    getSprite().getAnimator().play();

    if (timer.getElapsedTime() >= getSprite().getAnimator().getDuration()) {
        destroy(this);
    }
}
