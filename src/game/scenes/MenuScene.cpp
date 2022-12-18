#include <game/scenes/MenuScene.hpp>

void MenuScene::onInit() {
    getBackground().setColor({99, 199, 111});
}

void MenuScene::onUpdate(float dt) {
    if (Keyboard::isKeyPressed(Keyboard::Space)) {
        Scenes::SetNext();
    }
}