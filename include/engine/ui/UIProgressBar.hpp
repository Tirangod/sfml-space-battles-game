#ifndef PROGRESSBAR_HPP
#define PROGRESSBAR_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "UIComponent.hpp"

using namespace std;
using namespace sf;

// TODO: implement UIComponent
class UIProgressBar : public UIComponent {
    float value;
    float max;
    RectangleShape foreground;
    RectangleShape background;

    void updateSize();
public:
    UIProgressBar() = default;
    UIProgressBar(float startValue, float max);

    void _draw(RenderTarget& target);
    void _update(float dt);

    void add(float amount);
    void setValue(float value);
    
    void setPosition(Vector2f pos);
    void setSize(Vector2f size);
    
    float getProgress();
    float getValue();

    FloatRect getBounds();
    Vector2f getSize();
    RectangleShape getForeground();
    RectangleShape getBackground();
};

#endif