#include <engine/Scenes.hpp>

Scenes *Scenes::instance = nullptr;

Scenes::Scenes() {
    sceneIndex = -1;
}

Scenes& Scenes::Get() {
    if (instance == nullptr) {
        instance = new Scenes;
    }
    return *instance;
}

void Scenes::Update(float dt) {
    Get().GetCurrent()._update(dt);
}
void Scenes::Draw(RenderTarget& target) {
    Get().GetCurrent()._draw(target);
}

void Scenes::AddScene(Scene *scene) {
    Get().scenes.push_back(scene);
    if (Get().sceneIndex < 0) {
        Get().sceneIndex = 0;
        SetScene(0);
    }
}

void Scenes::SetScene(int index) {

    if (index < 0 || index == Get().scenes.size())
        index = 0;

    auto &prev = GetCurrent();
    Get().sceneIndex = index;
    auto &next = GetCurrent();
    prev._changed(next);
    next._init();
}

void Scenes::SetNext() {
    SetScene(Get().sceneIndex + 1);
}

Scene& Scenes::GetCurrent() {
    if (Get().scenes.empty()) {
        throw "There is no scene";
    }
    return *Get().scenes[Get().sceneIndex];
}