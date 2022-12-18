#ifndef GAMESPRITE_HPP
#define GAMESPRITE_HPP

#include <SFML/Graphics.hpp>
#include "SpriteAnimator.hpp"
#include "Transition.hpp"

using namespace std;
using namespace sf;

class GameSprite : public Sprite {
private:
    SpriteAnimator animator;
    Transition transition;
public:
    GameSprite();
    void _update(float dt);
    
    void alignTop();
    void alignBottom();
    void alignLeft();
    void alignRight();
    void alignCenter();
    void alignX();
    void alignY();

    SpriteAnimator& getAnimator();
    Transition& getTransition();
};

#endif