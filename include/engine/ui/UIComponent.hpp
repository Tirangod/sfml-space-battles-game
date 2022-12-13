#ifndef UICOMPONENT_HPP
#define UICOMPONENT_HPP

#include <SFML/Graphics.hpp>


using namespace sf;

class UIComponent {
private:
    bool focused;
    bool inFocus;
public:
    void _draw(RenderTarget& target);
    void _update(float dt);
};


#endif