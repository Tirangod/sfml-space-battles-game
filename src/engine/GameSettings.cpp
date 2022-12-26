#include <engine/GameSettings.hpp>

GameSettings *GameSettings::instance = nullptr;

GameSettings::GameSettings() {
    
}

GameSettings& GameSettings::Get() {
    if (instance == nullptr)
        instance = new GameSettings;
    return *instance;
}

void GameSettings::AddUISound(SoundPlayer& sound) {
    Get().uiSounds.push_back(&sound);
}
void GameSettings::AddEffectSound(SoundPlayer& sound) {
    Get().effectSounds.push_back(&sound);
}
void GameSettings::AddMusic(Music& _music) {
    Get().music.push_back(&_music);
}

void GameSettings::SetMusicVolume(float value) {
    auto& self = Get();
    self.musicVolume = Utils::Clamp1(value) / 2.f;
    
    for(int i = 0; self.music.size(); i++) {
        self.music[i]->setVolume(self.musicVolume);
    }
}
void GameSettings::SetUIVolume(float value) {
    auto& self = Get();
    self.uiVolume = Utils::Clamp1(value) / 2.f;
    
    for(int i = 0; self.uiSounds.size(); i++) {
        self.uiSounds[i]->setVolume(self.uiVolume);
    }
}
void GameSettings::SetEffectsVolume(float value) {
    auto& self = Get();
    self.effectsVolume = Utils::Clamp1(value) / 2.f;

    for(int i = 0; self.effectSounds.size(); i++) {
        self.effectSounds[i]->setVolume(self.effectsVolume);
    }
}

float GameSettings::GetMusicVolume() {
    return Get().musicVolume;
}
float GameSettings::GetUIVolume() {
    return Get().uiVolume;
}
float GameSettings::GetEffectsVolume() {
    return Get().effectsVolume;
}