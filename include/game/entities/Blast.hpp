#ifndef EXPLOSION_HPP
#define EXPLOSION_HPP

#include <SFML/Graphics.hpp>
#include "engine/GameObject.hpp"
#include "engine/ObjectsPool.hpp"
#include "game/Presets.hpp"

using namespace Presets;
using namespace sf;

class Blast : public GameObject {
private:
    BlastInfo preset;
    Clock timer;
public:
    Blast(BlastInfo preset) : preset(preset) {}
    void onInit();
    void onUpdate(float dt);
};

#endif