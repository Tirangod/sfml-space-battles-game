#ifndef GAMESPRITE_HPP
#define GAMESPRITE_HPP

#include <SFML/Graphics.hpp>
#include "SpriteAnimator.hpp"

using namespace std;
using namespace sf;

class GameSprite : public Sprite {
private:
    SpriteAnimator animator;

public:
    GameSprite();
    
    void alignTop();
    void alignBottom();
    void alignLeft();
    void alignRight();
    void alignCenter();
    void alignX();
    void alignY();

    SpriteAnimator& getAnimator();
};

#endif