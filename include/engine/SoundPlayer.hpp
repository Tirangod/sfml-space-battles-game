#ifndef SOUND_HPP
#define SOUND_HPP

#include <string>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class SoundPlayer : public Sound {
private:
    SoundBuffer buffer;
public:
    void loadFrom(string path);
};

#endif