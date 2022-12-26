#ifndef GAMESETTINGS_HPP
#define GAMESETTINGS_HPP

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "SoundPlayer.hpp"
#include "GameWindow.hpp"
#include "Utils.hpp"

using namespace std;
using namespace sf;

class GameSettings {
private:
    static GameSettings *instance;

    float effectsVolume;
    float musicVolume;
    float uiVolume;

    vector<SoundPlayer*> effectSounds;
    vector<SoundPlayer*> uiSounds;
    vector<Music*> music;

    GameSettings();
public:
    static GameSettings& Get();

    static void AddEffectSound(SoundPlayer& sound);
    static void AddUISound(SoundPlayer& sound);
    static void AddMusic(Music& music);

    static void SetMusicVolume(float value);
    static void SetUIVolume(float value);
    static void SetEffectsVolume(float value);

    static float GetMusicVolume();
    static float GetUIVolume();
    static float GetEffectsVolume();
};

#endif