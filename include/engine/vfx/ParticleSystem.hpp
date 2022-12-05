#ifndef PARTICLESYSTEM_HPP
#define PARTICLESYSTEM_HPP

#include <array>
#include <SFML/Graphics.hpp>

#include "engine/GameObject.hpp"

using namespace sf;
using namespace std;

namespace Particles {

class Particle {
private:
    Vector2f pos;
    Color color;
};

class Emitter {
private:
    Particle **particles;
    int size;

public:
};

class System : public GameObject {
private:
    vector<Emitter> emitters;
public: 

};

}

#endif