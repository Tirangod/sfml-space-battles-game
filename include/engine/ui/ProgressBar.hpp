#ifndef PROGRESSBAR_HPP
#define PROGRESSBAR_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

// TODO: implement UIComponent
class ProgressBar /*: public UIComponent */ {
    float value;
    float max;
    RectangleShape foreground;
    RectangleShape background;

    void updateSize();
public:
    ProgressBar(float startValue, float max);

    void draw(RenderTarget& target);

    void add(float amount);
    void setValue(float value);
    float getProgress();

    
    void setPosition(Vector2f pos);
    void setSize(Vector2f size);

    FloatRect getBounds() { return background.getLocalBounds(); }
    Vector2f getSize() { return background.getSize(); }
    RectangleShape getForeground() { return foreground; }
    RectangleShape getBackground() { return background; }
};

#endif