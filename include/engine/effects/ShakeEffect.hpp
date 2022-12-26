#ifndef SHAKE_HPP
#define SHAKE_HPP

#include <SFML/Graphics.hpp>
#include "Effect.hpp"

using namespace std;
using namespace sf;

class ShakeEffect : public Effect {
private:
    Vector2f initPos;
    float amplitude;
public:
    ShakeEffect(float amplitude);
    void play(float dt);
    void started();
    void finished();
};

#endif