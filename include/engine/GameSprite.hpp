#ifndef GAMESPRITE_HPP
#define GAMESPRITE_HPP

#include <SFML/Graphics.hpp>
#include "SpriteAnimator.hpp"

using namespace std;
using namespace sf;

class GameSprite : public Sprite {
private:
    bool set;
    Texture texture;
    SpriteAnimator animator;
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

    void loadFrom(string path);
    void create(Vector2u sizd);

    FloatRect getBounds();
    bool isSet();

    SpriteAnimator& getAnimator();
};

#endif