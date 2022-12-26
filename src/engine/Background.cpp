#include <engine/Background.hpp>

Background::Background() {
    defaultBehaviour = true;
    bgColor = {123, 154, 199}; //123, 56, 77
}

void Background::_draw(RenderTarget& target) {
    target.clear(bgColor);
    for (int i = 0; i < sprites.size(); i++) {
        target.draw(*sprites[i]);
    }
}

void Background::_update(float dt) {
    for (int i = 0; i < sprites.size(); i++) {
        sprites[i]->_update(dt);
        if (defaultBehaviour) {
            sprites[i]->getAnimator().play();
        } 
    }
}

void Background::setDefaultBehaviour(bool flag) { defaultBehaviour = flag; }

void Background::setColor(Color color) {
    bgColor = color;
}

GameSprite& Background::addSprite(GameSprite& sprite, bool fullscreen) {
    if (fullscreen) {
        float kx = GameWindow::Get().getSize().x / sprite.getBounds().width;
        float ky = GameWindow::Get().getSize().y / sprite.getBounds().height;
        sprite.setScale(kx, ky);
    }
    sprites.push_back(&sprite);
    return sprite;
}