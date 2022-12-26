#include <engine/ui/UIComponent.hpp>

void UIComponent::_init() {
    selected = false;
    selectable = true;
    onInit();
}

void UIComponent::_draw(RenderTarget& target) {
    target.draw(background);

    for (int i = 0; i < children.size(); i++)
        children[i]->_draw(target);

    onDraw(target);
}

void UIComponent::_update(float dt) {
    for (int i = 0; i < children.size(); i++)
        children[i]->_update(dt);
    onUpdate(dt);
}

void UIComponent::_whileSelected(float dt) {
    if (!selected) {
        onSelected();
        selected = true;
    }
    onWhileSelected(dt);
}

void UIComponent::setPosition(Vector2f _position) {
    position = _position;
    background.setPosition(position);
    onUpdateTransform();
}
void UIComponent::setSize(Vector2f _size) {
    size = _size;
    background.setSize(size);
    onUpdateTransform();
}

void UIComponent::setSelectable(bool flag) {
    selectable = flag;
}

Vector2f UIComponent::getPosition() { return position; }
Vector2f UIComponent::getSize() { return size; }

void UIComponent::addChild(UIComponent& comp) {
    comp._init();
    children.push_back(&comp);
}

void UIComponent::unselect() { 
    selected = false;
    onUnselected();
}

bool UIComponent::isSelected() { return selected; }

bool UIComponent::isSelectable() { return selectable; }

RectangleShape& UIComponent::getBackground() { return background; }