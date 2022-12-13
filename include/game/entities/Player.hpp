#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "engine/ui/UIProgressBar.hpp"
#include "engine/ObjectsPool.hpp"
#include "engine/GameObject.hpp"
#include "engine/WindowInfo.hpp"
#include "Bullet.hpp"

using namespace sf;
using namespace std;

class Player : public GameObject {
private:
    Vector2f moveDir;
    float speed;
    float hp;

    bool canShooting;
    bool isShooting;
    float shootingCooldown;
    float shootingDelay;

    UIProgressBar healthBar;

    void onShot();
    void shooting(float dt);
    void controll();
    void move(float dt);
public:
    Player() {}
    void onInit();
    void onDraw(RenderTarget &target);
    void onUpdate(float dt);
};

#endif