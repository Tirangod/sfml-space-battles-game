#include <engine/effects/ResizeEffect.hpp>

ResizeEffect::ResizeEffect(Vector2f size) 
: targetSize(size)
{

}

// TODO
void ResizeEffect::play(float dt) {
    auto currBounds = getSprites()[0]->getBounds();
    auto currSize = Vector2f{currBounds.width, currBounds.height};
    float _t = 1.f - getTime() / getDuration();
    float t = (_t <= 1.f) ? _t : 1.f;
    float f = getEasingFunc()(t);
    float kx = f * (targetSize.x / currSize.x);
    float ky = f * (targetSize.y / currSize.y);
    getSprites()[0]->setScale(kx, ky);
    //cout << currSize.x << "; " << currSize.y << endl;
}