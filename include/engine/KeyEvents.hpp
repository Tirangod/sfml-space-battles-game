#ifndef KEYEVENTS_HPP
#define KEYEVENTS_HPP

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class KeyEvents {
private:
    static KeyEvents* instance;
    bool pressedKeys[Keyboard::KeyCount];
    bool releasedKeys[Keyboard::KeyCount];
public:
    static KeyEvents& Get();
    
    static bool isKeyPressed(Keyboard::Key key);
    static bool isKeyReleased(Keyboard::Key key);

    void setPressedKey(Keyboard::Key key);
    void setReleasedKey(Keyboard::Key key);
    void clearKeys();
};

#endif