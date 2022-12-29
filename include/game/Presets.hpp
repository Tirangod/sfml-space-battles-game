#ifndef PRESETS_HPP
#define PRESETS_HPP

#include <string>
#include <iostream>
#include <SFML/System.hpp>

using namespace std;
using namespace sf;

namespace Presets {

struct BlastInfo {
    string animImagePath;
    Vector2f scale;
    Vector2i animGrid;
    Time animDuration;
};

static BlastInfo Blast0{
    "assets/sprites/blast/blast_0.png",
    {1, 1},
    {6, 6},
    milliseconds(10)
};
static BlastInfo Blast1{
    "assets/sprites/blast/blast_2.png",
    {1, 1},
    {8, 8},
    milliseconds(10)
};
static BlastInfo Blast2{
    "assets/sprites/blast/blast_2_1.png",
    {1, 1},
    {8, 8},
    seconds(0.5f)
};
static BlastInfo Blast3{
    "assets/sprites/blast/blast_2_2.png",
    {3, 3},
    {8, 8},
    seconds(0.5f)
};
static BlastInfo Blast4{
    "assets/sprites/blast/blast_2_3.png",
    {1, 1},
    {8, 8},
    seconds(0.5),
};
static BlastInfo Blast5{
    "assets/sprites/blast/blast_3.png",
    {2, 2},
    {8, 8},
    seconds(0.5)
};


struct BulletInfo {
    BlastInfo blast;
    Vector2f scale;
    string skinPath;
    float speed;
    float damage;
};

static BulletInfo Bullet0{
    Blast1,
    {0.6f, 0.6f},
    "assets/sprites/bullets/bullet_0.png",
    500.f,
    5.f
};
static BulletInfo Bullet1{
    Blast2,
    {0.6f, 0.6f},
    "assets/sprites/bullets/bullet_8.png",
    480.f,
    10.f
};
static BulletInfo Bullet2{
    Blast3,
    {0.6f, 0.6f},
    "assets/sprites/bullets/bullet_18.png",
    450.f,
    15.f
};
static BulletInfo Bullet3{
    Blast4,
    {0.6f, 0.6f},
    "assets/sprites/bullets/bullet_12.png",
    400.f,
    25.f
};


struct PlayerInfo {
    BulletInfo bullet;
    string skinPath;
    string fireSoundPath;
    float maxHP;
    float speed;
    float shootingDelay;
};

static PlayerInfo Player0{
    Bullet0,
    "assets/sprites/player/blue_01.png",
    "assets/audio/sounds/fire/fire0.wav",
    110.f,
    370.f,
    55.f
};
static PlayerInfo Player1{
    Bullet1,
    "assets/sprites/player/orange_03.png",
    "assets/audio/sounds/fire/fire1.wav",
    130.f,
    380.f,
    35.f
};
static PlayerInfo Player2{
    Bullet2,
    "assets/sprites/player/red_01.png",
    "assets/audio/sounds/fire/fire2.wav",
    150.f,
    400.f,
    25.f
};
static PlayerInfo Player3{
    Bullet3,
    "assets/sprites/player/green_06.png",
    "assets/audio/sounds/fire/fire3.wav",
    170.f,
    350.f,
    10.f
};


struct EnemyInfo {
    BlastInfo blast;
    string skinPath;
    Vector2f scale;
    float maxHP;
    //float speed;
};

static EnemyInfo Enemy0{
    Blast3,
    "assets/sprites/enemies/Ship1.png",
    {2, 2},
    180.f
};
static EnemyInfo Enemy1{
    Blast3,
    "assets/sprites/enemies/Ship2.png",
    {1.5f, 1.5f},
    310.f
};
static EnemyInfo Enemy2{
    Blast3,
    "assets/sprites/enemies/Ship3.png",
    {1.2f, 1.2f},
    999.f
};

}

#endif