#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "GameSprite.hpp"

using namespace std;
using namespace sf;

class Background {
private:
    Color bgColor;
    vector<GameSprite> sprites; // Change to list to have sorting ability
public:
    Background();
    void draw(RenderTarget& target);
    void setColor(Color color);
    GameSprite& addSprite(GameSprite& sprite);
};

#endif