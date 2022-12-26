#ifndef GAMESCENE_HPP
#define GAMESCENE_HPP

#include "engine/GameSprite.hpp"
#include "engine/Scenes.hpp"
#include "engine/Scene.hpp"
#include "game/entities/Player.hpp"
#include "game/entities/Enemy.hpp"
#include "game/ui/GameUI.hpp"

using namespace std;
using namespace sf;

class GameScene : public Scene {
private:
    GameSprite bg;
    GameUI ui;
public:
    void onInit();
    void onUpdate(float dt);
    void onDraw(RenderTarget& target);
};

#endif