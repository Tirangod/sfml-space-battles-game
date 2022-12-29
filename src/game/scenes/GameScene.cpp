#include <game/scenes/GameScene.hpp>

void GameScene::onInit() {
    bg.loadFrom("assets/bgs/bg_14.png");
    getBackground().addSprite(bg, true);
    
    Player *player = new Player;
    ObjectsPool::AddObject(player);

    for (int i = 0; i < 5; i++) {
        Enemy *enemy = new Enemy(Presets::Enemy0);
        enemy->getSprite().setPosition({(float)(150 + 150 * i), 150.f});
        ObjectsPool::AddObject(enemy);
    }
    
    ui.init();
}

void GameScene::onUpdate(float dt) {
    ui.update(dt);

    if (Keyboard::isKeyPressed(Keyboard::Backspace))
        Scenes::SetScene(1);
}

void GameScene::onDraw(RenderTarget& target) {
    ui.draw(target);
}
