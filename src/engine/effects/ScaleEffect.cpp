#include <engine/effects/ScaleEffect.hpp>

ScaleEffect::ScaleEffect(Vector2f scale) 
: targetScale(scale)
{

}

// TODO
void ScaleEffect::play(float dt) {
    auto& sprite = *getSprites()[0];
    float kx = f() * (targetScale.x / sprite.getScale().x);
    float ky = f() * (targetScale.y / sprite.getScale().y);

    cout << "f: " << f() << endl;
    cout << "scale: " << sprite.getScale().x << ", " << sprite.getScale().y << endl;
    //cout << "size: " << currBounds.width << ", " << currBounds.height << endl;
    cout << "k: " << kx << ", " << ky << endl;
    cout << "-------------------" << endl;

    //sprite.setScale(kx, ky);
}