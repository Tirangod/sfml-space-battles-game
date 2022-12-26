#include <engine/Scene.hpp>

void Scene::updateObjects(float dt) {
    for (auto object : ObjectsPool::GetObjects())
        if (object->isActive())
            object->_update(dt);
}

void Scene::drawObjects(RenderTarget& window) {
    for (auto object : ObjectsPool::GetObjects())
        if (object->isVisible())
            object->_draw(window);
}

void Scene::_init() {
    onInit();
}
void Scene::_update(float dt) {
    background._update(dt);
    updateObjects(dt);
    onUpdate(dt);
}
void Scene::_draw(RenderTarget& target) {
    background._draw(target);
    drawObjects(target);
    onDraw(target);
}
void Scene::_changed(Scene& scene) {
    onChanged(scene);
    ObjectsPool::RemoveAll();
}

void Scene::onInit() {}
void Scene::onUpdate(float dt) {}
void Scene::onDraw(RenderTarget& target) {}
void Scene::onChanged(Scene& scene) {}

Background& Scene::getBackground() { return background; }