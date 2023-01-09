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

static BlastInfo BlastWhite{
    "assets/sprites/blast/blast_0.png",
    {1, 1},
    {6, 6},
    milliseconds(10)
};
static BlastInfo BlastRed{
    "assets/sprites/blast/blast_2.png",
    {1, 1},
    {8, 8},
    milliseconds(10)
};
static BlastInfo BlastGreen{
    "assets/sprites/blast/blast_2_1.png",
    {1, 1},
    {8, 8},
    seconds(0.5f)
};
static BlastInfo BlastBlue{
    "assets/sprites/blast/blast_2_2.png",
    {1, 1},
    {8, 8},
    seconds(0.5f)
};
static BlastInfo BlastYellow{
    "assets/sprites/blast/blast_2_3.png",
    {1, 1},
    {8, 8},
    seconds(0.5),
};
static BlastInfo BlastExplosion{
    "assets/sprites/blast/blast_3.png",
    {2.2f, 2.2f},
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

static BulletInfo BulletBlue{
    BlastBlue,
    {0.6f, 0.6f},
    "assets/sprites/bullets/bullet_1.png",
    500.f,
    5.f
};
static BulletInfo BulletYellow{
    BlastYellow,
    {0.4f, 0.6f},
    "assets/sprites/bullets/bullet_7.png",
    480.f,
    10.f
};
static BulletInfo BulletRed{
    BlastRed,
    {0.4f, 0.6f},
    "assets/sprites/bullets/bullet_18.png",
    450.f,
    15.f
};
static BulletInfo BulletGreen{
    BlastGreen,
    {0.4f, 0.6f},
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

static PlayerInfo PlayerBlue{
    BulletBlue,
    "assets/sprites/player/blue_01.png",
    "assets/audio/sounds/fire/fire0.wav",
    110.f,
    370.f,
    35.f
};
static PlayerInfo PlayerYellow{
    BulletYellow,
    "assets/sprites/player/orange_03.png",
    "assets/audio/sounds/fire/fire0.wav",
    130.f,
    380.f,
    65.f
};
static PlayerInfo PlayerRed{
    BulletRed,
    "assets/sprites/player/red_01.png",
    "assets/audio/sounds/fire/fire2.wav",
    150.f,
    400.f,
    55.f
};
static PlayerInfo PlayerGreen{
    BulletGreen,
    "assets/sprites/player/green_06.png",
    "assets/audio/sounds/fire/fire3.wav",
    170.f,
    350.f,
    90.f
};


struct EnemyInfo {
    BlastInfo blast;
    string skinPath;
    Vector2f scale;
    float maxHP;
    float hpBarKY;
    //float speed;
};

static EnemyInfo Enemy0{
    BlastExplosion,
    "assets/sprites/enemies/Ship1.png",
    {2, 2},
    111.f,
    1.5f
};
static EnemyInfo Enemy1{
    BlastExplosion,
    "assets/sprites/enemies/Ship2.png",
    {1.5f, 1.5f},
    333.f,
    0.65f
};
static EnemyInfo Enemy2{
    BlastExplosion,
    "assets/sprites/enemies/Ship3.png",
    {1.2f, 1.2f},
    666.f,
    0.65f
};

}

#endif