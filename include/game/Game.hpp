#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "entities/Player.hpp"
#include "entities/Enemy.hpp"
#include "engine/ObjectsPool.hpp"
#include "engine/GameObject.hpp"
#include "engine/Global.hpp"


using namespace sf;
using namespace std;

class Game {
private:
    RenderWindow window;
    Clock clock;
    Global::WindowInfo& winInfo;

    void checkCollision();
    void updateObjects(float dt);
    void drawObjects();

public:
    Game();
    void run();

};


#endif