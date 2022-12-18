#include <game/scenes/GameScene.hpp>

void GameScene::onInit() {
    
    Player *player = new Player;
    ObjectsPool::AddObject(player);

    for (int i = 0; i < 1; i++) {
        Enemy *enemy = new Enemy;
        enemy->getSprite().setPosition({(float)(150 + 100 * i), 100.f});
        ObjectsPool::AddObject(enemy);
    }
}