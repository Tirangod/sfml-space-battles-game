#include <game/entities/Blast.hpp>

void Blast::onInit() {
    getSprite().loadFrom(preset.animImagePath);
    getSprite().setScale(preset.scale);
    auto& animator = getSprite().getAnimator();
    animator.setAnimGrid(preset.animGrid);
    animator.setRepeated(false);
    animator.setDuration(preset.animDuration);
    
    getSprite().alignCenter();
}

void Blast::onUpdate(float dt) {
    getSprite().getAnimator().play();

    if (timer.getElapsedTime() >= getSprite().getAnimator().getDuration()) {
        destroy(this);
    }
}
