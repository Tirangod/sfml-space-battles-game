#include <engine/GameObject.hpp>

void GameObject::_init() {
    active = true;
    visible = true;

    boundsRect.setFillColor({0, 0, 0, 0});
    boundsRect.setOutlineColor({0, 255, 0});
    boundsRect.setOutlineThickness(3.f);

    onInit();
}

void GameObject::_update(float dt) {
    onUpdate(dt);
    
    boundsRect.setOrigin({
        sprite.getGlobalBounds().width / 2,
        sprite.getGlobalBounds().height / 2
    });
    boundsRect.setPosition(sprite.getPosition());
    boundsRect.setSize({
        sprite.getGlobalBounds().width,
        sprite.getGlobalBounds().height
    });
}

void GameObject::_draw(RenderTarget &target) {
    target.draw(sprite);
    onDraw(target);
    target.draw(boundsRect);
}
    
void GameObject::loadTexture(string path) {
    texture.loadFromFile(path);
    sprite.setTexture(texture);
}

void GameObject::centerSprite() {
    sprite.setOrigin(
        sprite.getLocalBounds().width / 2,
        sprite.getLocalBounds().height / 2
    );
}

void GameObject::setActive(bool flag) { active = flag; }
void GameObject::setVisibile(bool flag) { visible = flag; }
void GameObject::setTypeHash(long hash) { typeHash = hash; }

bool GameObject::isActive() { return active; }
bool GameObject::isVisible() { return visible; }
Texture& GameObject::getTexture() { return texture; }
Sprite& GameObject::getSprite() { return sprite; }
//long GameObject::getTypeHash() { return typeHash; }
