#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <vector>
#include <SFML/Graphics.hpp>

#include "GameWindow.hpp"
#include "GameSprite.hpp"

using namespace std;
using namespace sf;

class Background {
private:
    bool defaultBehaviour;
    Color bgColor;
    vector<GameSprite*> sprites; // Change to list to have sorting ability
public:
    Background();
    void _draw(RenderTarget& target);
    void _update(float dt);
    void setDefaultBehaviour(bool flag);
    void setColor(Color color);
    GameSprite& addSprite(GameSprite& sprite, bool fullscreen=false);
};

#endif