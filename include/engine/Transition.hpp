#ifndef TRANSITION_HPP
#define TRANSITION_HPP

#include <functional>
#include <cmath>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


using EasingFunc = function<float(float)>;

class Transition {
private:
    float dt;
    Sprite& sprite;
    Clock clock;
    Time duration;
    EasingFunc easingFunc;
public:
    Transition(Sprite& sprite);
    void _update(float dt);

    void setDuration(Time time);
    void setFunc(EasingFunc f);

    void scale(Vector2f k);
    void size(Vector2f size);
    void translate(Vector2f offset);
    void translateTo(Vector2f pos);
    void rotate(float da);
    void rotation(float angle);
    void shake(float amplitude);

    static float Linear(float x);
    static float EaseOutCirc(float x);
};

#endif
