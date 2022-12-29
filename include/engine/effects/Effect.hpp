#ifndef EFFECT_HPP
#define EFFECT_HPP

#include <cmath>
#include <vector>

#include <SFML/Graphics.hpp>

#include "engine/ui/CompsGroup.hpp"
#include "engine/GameSprite.hpp"
#include "engine/Aliases.hpp"

class GameSprite;

using namespace aliases;
using namespace std;
using namespace sf;

class Effect {
private:
    vector<GameSprite*> sprites;
    vector<Shape*> shapes;
    bool effectStarted;
    bool effectFinished;
    bool repeated;
    float elapsedTime;
    float _t;
    float _f;
    Time duration;
    EasingFunc easingFunc;
    VoidCallback startCallback;
    VoidCallback finishCallback;
public:
    Effect();
    void init();
    void update(float dt);
    virtual void play(float dt) {}
    virtual void started() {}
    virtual void finished() {}
    
    void start();
    void stop();
    void restart();

    void setOnStart(VoidCallback callback);
    void setOnFinish(VoidCallback callback);

    void addSprite(GameSprite& sprite);
    void addShape(Shape& shape);
    void addUIComponent(UIComponent& comp);
    void addCompsGroup(CompsGroup& group);

    void setRepeated(bool flag);
    void setDuration(Time duration);
    void setEasingFunc(EasingFunc func);

    bool isStarted();
    bool isFinished();
    //bool isRepeated();
    
    float t();
    float f();
    Time getTime();
    Time getDuration();
    EasingFunc getEasingFunc();
    vector<GameSprite*>& getSprites();
    vector<Shape*>& getShapes();

    static float Linear(float x);
    static float EaseOutCirc(float x);
    static float EaseOutExpo(float x);
};

#endif
