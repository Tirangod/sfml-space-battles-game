#ifndef WINDOWINFO_HPP
#define WINDOWINFO_HPP

#include <string>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class GameWindow : public RenderWindow {
    static GameWindow *instance;

    int windowStyle;
    bool fullscreen;
    VideoMode videoMode;

    GameWindow();
    void createWindow();
public:
    static GameWindow& Get();
    static void Shutdown();

    static void SetFullscreen(bool flag);
    
    static Vector2f GetSizef();
    static bool IsOutofScreen(Vector2f pos);
    static bool IsFullscreen();
};

#endif