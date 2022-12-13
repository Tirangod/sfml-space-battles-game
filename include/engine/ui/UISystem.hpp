#ifndef UISYSTEM_HPP
#define UISYSTEM_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "UIComponent.hpp"

using namespace std;
using namespace sf;

class UISystem {
private:
    vector<UIComponent> comps;
public:
    void draw(RenderTarget& target);
    void update(float dt);

    void addComp(UIComponent comp);
};

#endif