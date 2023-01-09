#ifndef SCENE_HPP
#define SCENE_HPP

#include <SFML/Graphics.hpp>

#include "ui/UI.hpp"
#include "ObjectsPool.hpp"
#include "Background.hpp"


using namespace std;
using namespace sf;

class Scene {
private:
    Background background;

    void updateObjects(float dt);
    void drawObjects(RenderTarget& target);
public:
    void _init();
    void _update(float dt);
    void _draw(RenderTarget& target);
    void _changed(Scene& scene);

    virtual void onInit();
    virtual void onUpdate(float dt);
    virtual void onDraw(RenderTarget& target);
    virtual void onChanged(Scene& scene);

    Background& getBackground();
};

#endif
