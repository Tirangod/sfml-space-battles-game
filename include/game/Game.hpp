#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "GameObject.hpp"
#include "Player.hpp"

using namespace sf;
using namespace std;

class Game {
private:
    RenderWindow window;
    vector<GameObject*> objects;

    void checkCollision();
    void updateObjects(float dt);
    void drawObjects();

public:
    Game();
    void run();

};


#endif