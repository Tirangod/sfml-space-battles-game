#include <engine/effects/ShakeEffect.hpp>

ShakeEffect::ShakeEffect(float amplitude) 
: amplitude(amplitude)
{
}

void ShakeEffect::started() {
    initPos = getSprites()[0]->getPosition();
    
}

void ShakeEffect::finished() {
    getSprites()[0]->setPosition(initPos);
}

void ShakeEffect::play(float dt) {
    float dx = (2.f - rand() % 5) * amplitude * dt;
    float dy = (2.f - rand() % 5) * amplitude * dt;
    getSprites()[0]->move(dx, dy);
}