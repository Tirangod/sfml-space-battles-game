#include <engine/effects/Effect.hpp>

Effect::Effect() {
    init();
}

void Effect::init() {
    effectStarted = true;
    effectFinished = true;
    repeated = false;
    elapsedTime = 0;
    duration = seconds(0.5f);
    easingFunc = Linear;
    startCallback = []{};
    finishCallback = []{};
}

void Effect::update(float dt) {
    if (effectFinished && effectStarted)
        return;

    if (!effectStarted) {
        started();
        startCallback();
        effectStarted = true;
    }
    
    elapsedTime += dt;
    
    float __t = 1.f - getTime() / getDuration();
    _t = (__t <= 1.f) ? __t : 1.f;
    _f = getEasingFunc()(_t);

    play(dt);

    if (seconds(elapsedTime) >= duration) {
        effectFinished = !repeated;
        elapsedTime = 0;
        finishCallback();
        finished();
    }
}

void Effect::start() {
    effectStarted = false;
    effectFinished = false;
}

void Effect::stop() {
    effectStarted = true;
    effectFinished = true;
    elapsedTime = 0;
}

void Effect::restart() {
    stop();
    start();
}

void Effect::setOnStart(VoidCallback callback) {
    startCallback = callback;
}
void Effect::setOnFinish(VoidCallback callback) {
    finishCallback = callback;
}

void Effect::addSprite(GameSprite& sprite) {
    sprites.push_back(&sprite);
}

void Effect::addShape(Shape& shape) {
    shapes.push_back(&shape);
}

void Effect::setRepeated(bool flag) {
    repeated = flag;
}
void Effect::setDuration(Time _duration) {
    duration = _duration;
}
void Effect::setEasingFunc(EasingFunc func) {
    easingFunc = func;
}

bool Effect::isStarted() {
    return effectStarted;
}
bool Effect::isFinished() {
    return effectFinished;
}

float Effect::t() {
    return _t;
}

float Effect::f() {
    return _f;
}

Time Effect::getTime() {
    return seconds(getDuration().asSeconds() - elapsedTime);
}

Time Effect::getDuration() {
    return duration;
}

EasingFunc Effect::getEasingFunc() {
    return easingFunc;
}

vector<GameSprite*>& Effect::getSprites() {
    return sprites;
}
vector<Shape*>& Effect::getShapes() {
    return shapes;
}


float Effect::Linear(float x) {
    return x;
}
float Effect::EaseOutCirc(float x) {
    return sqrtf(1.f - powf(x - 1.f, 2.f));
}
float Effect::EaseOutExpo(float x) {
    return x >= 1.f ? 1.f : 1.f - powf(2.f, -10.f * x);
}