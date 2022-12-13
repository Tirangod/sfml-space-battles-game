#ifndef SPRITEANIMATOR_HPP
#define SPRITEANIMATOR_HPP

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class SpriteAnimator {
private:
    Sprite& sprite;
    Vector2i grid;
    int frameIndex;
    float timer;
    Time speed;
    Time time;
    bool repeated;
    bool finished;
    vector<IntRect> frames;
public:
    SpriteAnimator(Sprite& sprite);
    void setAnimGrid(Vector2i grid);
    void play(float dt);

    void setRepeated(bool flag);
    void setSpeed(Time speed);

    bool isRepeated();
    bool isFinished();
    float getSpeed();
    Time getTime();
};

#endif