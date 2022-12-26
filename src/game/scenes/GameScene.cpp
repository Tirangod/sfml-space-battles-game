#include <game/scenes/GameScene.hpp>

void GameScene::onInit() {
    bg.loadFrom("assets/bgs/bg_14.png");
    getBackground().addSprite(bg, true);
    
    Player *player = new Player;
    ObjectsPool::AddObject(player);

    for (int i = 0; i < 5; i++) {
        Enemy *enemy = new Enemy;
        enemy->getSprite().setPosition({(float)(150 + 150 * i), 150.f});
        ObjectsPool::AddObject(enemy);
    }
    
    ui.init();
}

void GameScene::onUpdate(float dt) {
    ui.update(dt);
}

void GameScene::onDraw(RenderTarget& target) {
    ui.draw(target);
}
