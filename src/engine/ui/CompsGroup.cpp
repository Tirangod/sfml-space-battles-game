#include <engine/ui/CompsGroup.hpp>


CompsGroup::CompsGroup() {
    size = {0.f, 0.f};
    margin = {0.f, 0.f};
    aligned = false;
}

void CompsGroup::applyTransforms() {
    size -= margin - comps[comps.size() - 1]->getSize();

    if (aligned)
        transform.setOrigin(size / 2.f);

    for (int i = 0; i < comps.size(); i++) {
        auto& comp = *comps[i];
        auto pos = (transform.getPosition() - transform.getOrigin() + margin * ((float)i));
        comp.setPosition({pos.x * transform.getScale().x, pos.y * transform.getScale().y});
    }
}

void CompsGroup::setPosition(Vector2f pos) {
    transform.setPosition(pos);
    //applyTransforms();
}

void CompsGroup::alignCenter() {
    aligned = true;
}

void CompsGroup::setMargin(Vector2f _margin) {
    margin = _margin;
    //applyTransforms();
}

void CompsGroup::add(UIComponent& comp) {
    comps.push_back(&comp);
    size += margin;
}

vector<UIComponent*>& CompsGroup::getComponents() {
    return comps;
}