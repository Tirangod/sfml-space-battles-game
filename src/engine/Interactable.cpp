#include <engine/Interactable.hpp>

//bool Interactable::intersects(GameObject *other) { return false; }
void Interactable::onCollisionStay(GameObject *other) {}
void Interactable::onCollisionEnter(GameObject *other) { throw "Not implemented yet!"; }
void Interactable::onCollisionExit(GameObject *other) { throw "Not implemented yet!"; }

void Interactable::setAlreadyCollided(bool flag) { alreadyCollided = flag; }
void Interactable::setCollisionEnded(bool flag) { collisionEnded = flag; }

bool Interactable::isAlreadyCollided() { return alreadyCollided; }
bool Interactable::isCollisionEnded() { return collisionEnded; }