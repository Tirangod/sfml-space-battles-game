#ifndef SKINSSCENE_HPP
#define SKINSSCENE_HPP

#include "engine/GameSprite.hpp"
#include "engine/Scenes.hpp"
#include "engine/Scene.hpp"
#include "game/ui/SkinsUI.hpp"

using namespace std;
using namespace sf;

class SkinsScene : public Scene {
private:
    GameSprite bg;
    SkinsUI ui;
public:
    void onInit();
    void onUpdate(float dt);
    void onDraw(RenderTarget& target);
};

#endif