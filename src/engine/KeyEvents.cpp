#include <engine/KeyEvents.hpp>

KeyEvents* KeyEvents::instance = nullptr;

KeyEvents& KeyEvents::Get() {
    if (instance == nullptr)
        instance = new KeyEvents;
    return *instance;
}
    
void KeyEvents::setPressedKey(Keyboard::Key key) {
    pressedKeys[key] = true;
    releasedKeys[key] = false;
}
void KeyEvents::setReleasedKey(Keyboard::Key key) {
    pressedKeys[key] = false;
    releasedKeys[key] = true;
}
void KeyEvents::clearKeys() {
    for (int i = 0; i < Keyboard::KeyCount; i++) {
        pressedKeys[i] = false;
        releasedKeys[i] = false;
    }
}

bool KeyEvents::isKeyPressed(Keyboard::Key key) {
    return Get().pressedKeys[key];
}
bool KeyEvents::isKeyReleased(Keyboard::Key key) {
    return Get().releasedKeys[key];
}