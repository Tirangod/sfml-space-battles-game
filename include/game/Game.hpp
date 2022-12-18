#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "engine/Interactions.hpp"
#include "engine/WindowInfo.hpp"
#include "engine/Scenes.hpp"
#include "game/scenes/MenuScene.hpp"
#include "game/scenes/GameScene.hpp"


using namespace sf;
using namespace std;

class Game {
private:
    RenderWindow window;
    Clock clock;
    
    int frames = 0;
    float time = 0;
public:
    Game();
    void run();
};


#endif