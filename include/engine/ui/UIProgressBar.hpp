#ifndef PROGRESSBAR_HPP
#define PROGRESSBAR_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "UIComponent.hpp"

using namespace std;
using namespace sf;

class UIProgressBar : public UIComponent {
    float value;
    float max;
    RectangleShape foreground;
    RectangleShape background;

    void updateSize();
public:
    UIProgressBar() {}
    UIProgressBar(float startValue, float max);

    void onInit();
    void onDraw(RenderTarget& target);

    void add(float amount);
    void setValue(float value);
    void setMax(float max);
    
    void setPosition(Vector2f pos);
    void setSize(Vector2f size);
    
    float getProgress();
    float getValue();
    float getMax();

    FloatRect getBounds();
    Vector2f getSize();
    RectangleShape& getForeground();
    RectangleShape& getBackground();
};

#endif