#ifndef TRANSLATE_HPP
#define TRANSLATE_HPP

#include <SFML/Graphics.hpp>
#include "Effect.hpp"

using namespace std;
using namespace sf;

class TranslateEffect : public Effect {
private:
    Vector2f targetPos;
    Vector2f startPos;
    Vector2f dist;
public:
    TranslateEffect(Vector2f pos);
    void play(float dt);
    void started();
    void setTargetPosition(Vector2f pos);
};

#endif