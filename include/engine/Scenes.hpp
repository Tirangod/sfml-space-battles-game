#ifndef SCENES_HPP
#define SCENES_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "Scene.hpp"

using namespace std;
using namespace sf;

class Scenes {
private:
    static Scenes *instance;
    vector<Scene*> scenes;
    int sceneIndex;
public:
    Scenes();
    static Scenes& Get();
    static void Update(float dt);
    static void Draw(RenderTarget& target);
    static void AddScene(Scene *scene);
    static void SetScene(int index);
    static void SetNext();
    static Scene& GetCurrent();
};

#endif