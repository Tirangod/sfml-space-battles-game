#include <engine/GameSprite.hpp>

GameSprite::GameSprite() 
: animator(*this)
{
    set = false;
}

void GameSprite::_update(float dt) {
    animator._update(dt);
}

void GameSprite::alignCenter() {
    alignX();
    alignY();
}
void GameSprite::alignX() {
    setOrigin(
        getLocalBounds().width / 2,
        getOrigin().y
    );
}
void GameSprite::alignY() {
    setOrigin(
        getOrigin().x,
        getLocalBounds().height / 2
    );
}
void GameSprite::alignTop() {
    setOrigin(
        getOrigin().x,
        0
    );
}
void GameSprite::alignBottom() {
    setOrigin(
        getOrigin().x,
        getGlobalBounds().height
    );
}
void GameSprite::alignLeft() {
    setOrigin(
        0,
        getOrigin().y
    );
}
void GameSprite::alignRight() {
    setOrigin(
        getGlobalBounds().width,
        getOrigin().y
    );
}

void GameSprite::loadFrom(string path) {
    texture.loadFromFile(path);
    setTexture(texture);
    set = true;
}

void GameSprite::create(Vector2u size) {
    texture.create(size.x, size.y);
    setTexture(texture);
    set = true;
}

//TODO: FIX. Getting nan from global bounds values
FloatRect GameSprite::getBounds() {
    return getGlobalBounds();
}

bool GameSprite::isSet() {
    return set;
}

SpriteAnimator& GameSprite::getAnimator() { return animator; }