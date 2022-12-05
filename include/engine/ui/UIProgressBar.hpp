#ifndef PROGRESSBAR_HPP
#define PROGRESSBAR_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

// TODO: implement UIComponent
class UIProgressBar /*: public UIComponent */ {
    float value;
    float max;
    RectangleShape foreground;
    RectangleShape background;

    void updateSize();
public:
    UIProgressBar(float startValue, float max);

    void draw(RenderTarget& target);

    void add(float amount);
    void setValue(float value);
    float getProgress();
    
    void setPosition(Vector2f pos);
    void setSize(Vector2f size);

    FloatRect getBounds();
    Vector2f getSize();
    RectangleShape getForeground();
    RectangleShape getBackground();
};

#endif