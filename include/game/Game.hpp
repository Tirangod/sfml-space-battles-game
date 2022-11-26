#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "GameObject.hpp"
#include "Player.hpp"
#include "Global.hpp"

using namespace sf;
using namespace std;

class Game {
private:
    RenderWindow window;
    vector<GameObject*> objects;
    Clock clock;
    Global& global;

    void checkCollision();
    void updateObjects(float dt);
    void drawObjects();

public:
    Game();
    void run();

};


#endif