#ifndef GAMESCENE_HPP
#define GAMESCENE_HPP

#include "engine/Scenes.hpp"
#include "engine/Scene.hpp"
#include "game/entities/Player.hpp"
#include "game/entities/Enemy.hpp"

using namespace std;
using namespace sf;

class GameScene : public Scene {
public:
    void onInit();
    
};

#endif