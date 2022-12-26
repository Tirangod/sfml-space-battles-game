#include <engine/effects/TranslateEffect.hpp>

TranslateEffect::TranslateEffect(Vector2f pos) 
: targetPos(pos)
{
}

void TranslateEffect::started() {
    startPos = getSprites()[0]->getPosition();
    dist = startPos - targetPos;
}

void TranslateEffect::play(float dt) {
    auto newPos = startPos - dist * f();
    getSprites()[0]->setPosition(newPos);
    
    /* old version without easings
    auto entityPos = getSprite().getPosition();
    float __dx = ((targetPos.x - entityPos.x) / getTime().asSeconds()) * dt;
    float __dy = ((targetPos.y - entityPos.y) / getTime().asSeconds()) * dt;
    getSprite().move(__dx, __dy);
    */
}

void TranslateEffect::setTargetPosition(Vector2f pos) {
    targetPos = pos;
}