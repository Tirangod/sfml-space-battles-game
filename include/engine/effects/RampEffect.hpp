#ifndef RAMP_HPP
#define RAMP_HPP

#include <cmath>
#include <SFML/Graphics.hpp>
#include "Effect.hpp"

using namespace std;
using namespace sf;

class RampEffect : public Effect {
private:
    Color startColor;
    Color endColor;
    int distR, distG, distB, distA;
public:
    RampEffect(Color startColor, Color endColor);
    void play(float dt);
    void started();
    void setStartColor(Color c);
    void setEndColor(Color c);
};

#endif
