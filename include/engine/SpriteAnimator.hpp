#ifndef SPRITEANIMATOR_HPP
#define SPRITEANIMATOR_HPP

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class SpriteAnimator {
private:
    int frameIndex;
    float timer;
    float dt;
    bool repeated;
    bool finished;
    Sprite& sprite;
    Vector2i grid;
    Time speed;
    vector<IntRect> frames;
public:
    SpriteAnimator(Sprite& sprite);
    void _update(float dt);

    void setAnimGrid(Vector2i grid);
    void play();

    void setRepeated(bool flag);
    void setSpeed(Time speed);

    bool isRepeated();
    bool isFinished();
    float getSpeed();
    Time getDuration();
};

#endif