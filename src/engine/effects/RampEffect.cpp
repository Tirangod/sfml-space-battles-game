#include <engine/effects/RampEffect.hpp>

RampEffect::RampEffect(Color startColor, Color endColor) 
: startColor(startColor), endColor(endColor)
{
}

void RampEffect::started() {
    distR = static_cast<int>(endColor.r) - static_cast<int>(startColor.r);
    distG = static_cast<int>(endColor.g) - static_cast<int>(startColor.g);
    distB = static_cast<int>(endColor.b) - static_cast<int>(startColor.b);
    distA = static_cast<int>(endColor.a) - static_cast<int>(startColor.a);
    
    for (auto it = getSprites().begin(); it != getSprites().end(); ++it) {
        (*it)->setColor(startColor);
    }
    for (auto it = getShapes().begin(); it != getShapes().end(); ++it) {
        (*it)->setFillColor(startColor);
    }
}

void RampEffect::play(float dt) {
    Color newColor = {
        static_cast<Uint8>(startColor.r + distR * f()),
        static_cast<Uint8>(startColor.g + distG * f()),
        static_cast<Uint8>(startColor.b + distB * f()),
        static_cast<Uint8>(startColor.a + distA * f())
    };
    
    for (auto it = getSprites().begin(); it != getSprites().end(); ++it) {
        (*it)->setColor(newColor);
    }
    
    for (auto it = getShapes().begin(); it != getShapes().end(); ++it) {
        (*it)->setFillColor(newColor);
    }
}

void RampEffect::setStartColor(Color color) {
    startColor = color;
}

void RampEffect::setEndColor(Color color) {
    endColor = color;
}