#ifndef UITEXT_HPP
#define UITEXT_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "UIComponent.hpp"

using namespace std;
using namespace sf;

class UIText : public UIComponent {
private:
    Font font;
    Text text;
    static const int DEFAULT_SIZE = 16;
public:
    void onInit();
    void onDraw(RenderTarget& target);
    void onUpdate(float dt);
    void onSelected();
    void onWhileSelected(float dt);

    void loadFont(string path);
    void setFontSize(int size);
    void setString(string text);
    void setColor(Color color);
    void setPosition(Vector2f pos);
    void alignCenter();

    Text& getText();
};

#endif