#ifndef COMPSGROUP_HPP
#define COMPSGROUP_HPP

#include <vector>
#include <SFML/System.hpp>
#include "UIComponent.hpp"

using namespace std;

class CompsGroup {
private:
    bool aligned;
    Vector2f size;
    Vector2f margin;
    Transformable transform;
    vector<UIComponent*> comps;

public:
    CompsGroup();
    void applyTransforms();
    void alignCenter();
    void setPosition(Vector2f pos);
    void setMargin(Vector2f margin);
    void add(UIComponent& comp);
    vector<UIComponent*>& getComponents();
};

#endif