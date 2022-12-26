#ifndef UICOMPONENT_HPP
#define UICOMPONENT_HPP

#include <vector>
#include <functional>
#include <SFML/Graphics.hpp>
#include "engine/GameSprite.hpp"

using namespace std;
using namespace sf;

class UIComponent {
private:
    bool selected;
    bool selectable;
    Vector2f origin;
    Vector2f position;
    Vector2f size;
    RectangleShape background;
    vector<UIComponent*> children;
public:
    void _init();
    void _draw(RenderTarget& target);
    void _update(float dt);
    void _whileSelected(float dt);

    virtual void onInit() {}
    virtual void onDraw(RenderTarget& target) {}
    virtual void onUpdate(float dt) {}
    virtual void onSelected() {}
    virtual void onUnselected() {}
    virtual void onWhileSelected(float dt) {}
    virtual void onUpdateTransform() {}

    void setPosition(Vector2f pos);
    void setSize(Vector2f size);
    void setSelectable(bool flag);
    void addChild(UIComponent& comp);
    void unselect();

    Vector2f getPosition();
    Vector2f getSize();
    bool isSelected();
    bool isSelectable();
    RectangleShape& getBackground();
};


#endif