#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "engine/vfx/ParticleSystem.hpp"
#include "engine/ui/UIProgressBar.hpp"
#include "engine/ObjectsPool.hpp"
#include "engine/GameObject.hpp"
#include "engine/Global.hpp"
#include "Bullet.hpp"

using namespace sf;
using namespace std;

class Player : public GameObject {
private:
    Vector2f moveDir;
    float speed;
    float hp;

    bool isShooting = false;
    float shootingCooldown = 0.f;
    float shootingDelay = 20.f;

    Particles::System sys;
    UIProgressBar healthBar;

    void onShot();
    void shooting(float dt);
    void controll();
    void move(float dt);
public:
    Player();
    void onDraw(RenderTarget &target);
    void onUpdate(float dt);
};

#endif