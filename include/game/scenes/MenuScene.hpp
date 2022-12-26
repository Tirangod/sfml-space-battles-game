#ifndef MENUSCENE_HPP
#define MENUSCENE_HPP

#include <SFML/Audio.hpp>

#include "engine/effects/ResizeEffect.hpp"
#include "engine/effects/RampEffect.hpp"
#include "engine/Scenes.hpp"
#include "engine/Scene.hpp"
#include "game/ui/MainMenuUI.hpp"

using namespace std;
using namespace sf;

class MenuScene : public Scene {
private:
    //ResizeEffect *resize;

    MainMenuUI ui;

    GameSprite bg;
    GameSprite planet0;
    GameSprite planet1;
    GameSprite planet2;
    GameSprite planet3;
    GameSprite planet4;
    GameSprite gameNameCaption;
    
    Music music;
public:
    void onInit();
    void onUpdate(float dt);
    void onDraw(RenderTarget& target);
    void onChanged(Scene& scene);

};

#endif