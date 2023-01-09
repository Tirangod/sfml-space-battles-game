#include <game/scenes/GameScene.hpp>

void GameScene::onInit() {
    bg.loadFrom("assets/bgs/bg_14.png");
    getBackground().addSprite(bg, true);
    
    Player *player = new Player;
    ObjectsPool::AddObject(player);

    int n = 7;
    float offsetX = 0.f, shipW = 150.f;
    auto e = Presets::Enemy0;
    for (int i = 0; i < n; i++) {
        if (i == n/2) {
            e = Presets::Enemy2;
        } else {
            e = Presets::Enemy0;
        }
        offsetX = (GameWindow::GetSizef().x - shipW * n) / 2.f;
        Enemy *enemy = new Enemy(e);
        enemy->getSprite().setPosition({(float)(offsetX + shipW * 0.5f + shipW * i), 110.f});
        ObjectsPool::AddObject(enemy);
    }
    
    ui.init();
}

void GameScene::onUpdate(float dt) {
    ui.update(dt);

    if (Keyboard::isKeyPressed(Keyboard::Backspace))
        GameWindow::Shutdown();
}

void GameScene::onDraw(RenderTarget& target) {
    ui.draw(target);
}
