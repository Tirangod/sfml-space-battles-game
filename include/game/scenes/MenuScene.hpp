#ifndef MENUSCENE_HPP
#define MENUSCENE_HPP

#include "engine/Scenes.hpp"
#include "engine/Scene.hpp"

using namespace std;
using namespace sf;

class MenuScene : public Scene {
public:
    void onInit();
    void onUpdate(float dt);

};

#endif