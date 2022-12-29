#ifndef KEYBOARDUI_HPP
#define KEYBOARDUI_HPP

#include <vector>
#include <SFML/Graphics.hpp>

#include "engine/ui/CompsGroup.hpp"
#include "engine/Scene.hpp"
#include "UIComponent.hpp"

using namespace std;
using namespace sf;

class KeyboardUI {
private:
    int compIndex;
    vector<UIComponent*> comps;
public:
    void init();
    void draw(RenderTarget& target);
    void update(float dt);

    virtual void onInit() {}
    virtual void onDraw(RenderTarget& target) {}
    virtual void onUpdate(float dt) {}

    void addCompsGroup(CompsGroup& group);
    void addComp(UIComponent& comp);
    void select(int index);
    void selectNext();
    int getIndex();
};

#endif