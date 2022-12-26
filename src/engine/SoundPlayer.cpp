#include <engine/SoundPlayer.hpp>

void SoundPlayer::loadFrom(string path) {
    buffer.loadFromFile(path);
    setBuffer(buffer);
} 