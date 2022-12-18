#include <engine/Transition.hpp>

Transition::Transition(Sprite& sprite) 
: sprite(sprite)
{
    duration = seconds(0.5f);
    easingFunc = Linear;
}

void Transition::setDuration(Time time) {
    duration = time;
}
void Transition::setFunc(EasingFunc f) {
    easingFunc = f;
}

void Transition::scale(Vector2f k) {

}
void Transition::size(Vector2f size) {

}
void Transition::translate(Vector2f offset) {

}
void Transition::translateTo(Vector2f pos) {

}
void Transition::rotate(float da) {

}
void Transition::rotation(float angle) {

}

void Transition::shake(float amplitude) {
    float elapsed = clock.getElapsedTime().asSeconds();
    float x = amplitude * sinf(elapsed);
    float y = amplitude * cosf(elapsed);
    sprite.setPosition(
        sprite.getPosition().x + x, 
        sprite.getPosition().y + y
    );
}

void Transition::_update(float _dt) {
    dt = _dt;
}

float Transition::Linear(float x) {
    return x;
}
float Transition::EaseOutCirc(float x) {
    return sqrtf(1.f - powf(x - 1.f, 2.f));
}