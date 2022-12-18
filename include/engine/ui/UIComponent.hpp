#ifndef UICOMPONENT_HPP
#define UICOMPONENT_HPP

#include <SFML/Graphics.hpp>
#include "engine/GameSprite.hpp"

using namespace sf;

class UIComponent {
private:
    bool selected;

    GameSprite sprite;
public:
    void _draw(RenderTarget& target);
    void _update(float dt);

};


#endif