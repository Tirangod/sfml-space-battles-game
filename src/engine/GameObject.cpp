#include <engine/GameObject.hpp>

GameObject *GameObject::EMPTY = new GameObject;

void GameObject::_init() {
    active = true;
    visible = true;

    renderStates = RenderStates::Default;

    /* For debuging */
    boundsRect.setFillColor({0, 0, 0, 0});
    boundsRect.setOutlineColor({0, 255, 0});
    boundsRect.setOutlineThickness(2.5f);
    boundsRect.setOrigin({
        sprite.getGlobalBounds().width / 2,
        sprite.getGlobalBounds().height / 2
    });

    onInit();
}

void GameObject::_update(float dt) {
    sprite._update(dt);
    onUpdate(dt);
    
    /* For debuging */
    if (Keyboard::isKeyPressed(Keyboard::Q)) {
        boundsRect.setPosition(sprite.getPosition());
        boundsRect.setSize({
            sprite.getGlobalBounds().width,
            sprite.getGlobalBounds().height
        });
    }
}

void GameObject::_draw(RenderTarget &target) {
    target.draw(sprite, renderStates);
    onDraw(target);
    
    /* For debuging */
    if (Keyboard::isKeyPressed(Keyboard::Q))
        target.draw(boundsRect);
}

void GameObject::onInit() {}
void GameObject::onUpdate(float dt) {}
void GameObject::onDraw(RenderTarget &target) {}
void GameObject::onKilled() {}

bool GameObject::intersects(GameObject *other) {
    return getBounds().intersects(other->getBounds());
}

/*
template<class T>
GameObject& GameObject::spawn(Vector2f pos, Vector2f scale, float rot) {
    auto type = new T;
    auto object = dynamic_cast<GameObject*>(type);
    object->getSprite().setPosition(pos);
    object->getSprite().setScale(scale);
    object->getSprite().setRotation(rot);

    ObjectsPool::AddObject(object);
    return *object;
}
*/

GameObject& GameObject::spawn(GameObject *object) {
    ObjectsPool::AddObject(object);
    return *object;
}

void GameObject::destroy(GameObject *object) {
    ObjectsPool::RemoveObject(object);
}

void GameObject::move(Vector2f velocity) {
    getSprite().move(velocity);
}

void GameObject::setupTexture(string path) {
    if (!texture.loadFromFile(path)) {
        throw ("Failed to load texture" + path);
    }
    sprite.setTexture(texture);
}

/*void GameObject::setupShader(string path) {
    shader.loadFromFile(path, Shader::Fragment);
    renderStates.shader = &shader;
}*/

void GameObject::setActive(bool flag) { active = flag; }
void GameObject::setVisibile(bool flag) { visible = flag; }

void GameObject::enable() {
    setActive(true);
    setVisibile(true);
}
void GameObject::disable() {
    setActive(false);
    setVisibile(false);
}

bool GameObject::isActive() { return active; }
bool GameObject::isVisible() { return visible; }
FloatRect GameObject::getBounds() { return sprite.getGlobalBounds(); }
Texture& GameObject::getTexture() { return texture; }
GameSprite& GameObject::getSprite() { return sprite; }


