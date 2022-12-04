#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "engine/ui/ProgressBar.hpp"
#include "engine/ParticleSystem.hpp"
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

    Particles::System particles;

    bool isShooting = false;
    float shootingCooldown = 0.f;
    float shootingDelay = 20.f;

    ProgressBar healthBar;

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