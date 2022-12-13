#include <engine/GameSprite.hpp>

GameSprite::GameSprite() 
: animator(*this)
{
    
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

SpriteAnimator& GameSprite::getAnimator() { return animator; }