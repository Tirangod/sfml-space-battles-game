#ifndef RESIZE_HPP
#define RESIZE_HPP

#include <SFML/Graphics.hpp>
#include "Effect.hpp"

using namespace std;
using namespace sf;

class ScaleEffect : public Effect {
private:
    Vector2f targetScale;
public:
    ScaleEffect(Vector2f scale);
    void play(float dt);
    //void started();
};

#endif