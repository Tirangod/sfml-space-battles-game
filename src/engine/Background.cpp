#include <engine/Background.hpp>

Background::Background() {
    bgColor = {123, 154, 199}; //123, 56, 77
}

void Background::draw(RenderTarget& target) {
    target.clear(bgColor);
    for (int i = 0; i < sprites.size(); i++) {
        target.draw(sprites[i]);
    }
}

void Background::setColor(Color color) {
    bgColor = color;
}

GameSprite& Background::addSprite(GameSprite& sprite) {
    sprites.push_back(sprite);
    return sprite;
}