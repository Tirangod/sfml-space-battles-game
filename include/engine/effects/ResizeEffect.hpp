#ifndef RESIZE_HPP
#define RESIZE_HPP

#include <SFML/Graphics.hpp>
#include "Effect.hpp"

using namespace std;
using namespace sf;

class ResizeEffect : public Effect {
private:
    Vector2f targetSize;
public:
    ResizeEffect(Vector2f size);
    void play(float dt);
    //void started();
};

#endif