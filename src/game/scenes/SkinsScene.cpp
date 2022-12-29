#include <game/scenes/SkinsScene.hpp>

void SkinsScene::onInit() {
    bg.loadFrom("assets/bgs/bg_16.png");
    getBackground().addSprite(bg, true);

    ui.init();
}
void SkinsScene::onUpdate(float dt) {
    ui.update(dt);
}
void SkinsScene::onDraw(RenderTarget& target) {
    ui.draw(target);
}