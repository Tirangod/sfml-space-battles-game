#include <engine/ui/UIText.hpp>

void UIText::onInit() {
}
void UIText::onDraw(RenderTarget& target) {
    target.draw(text);
}
void UIText::onUpdate(float dt) {

}
void UIText::onSelected() {

}
void UIText::onWhileSelected(float dt) {

}

void UIText::loadFont(string path) {
    font.loadFromFile(path);
    text.setFont(font);
}
void UIText::setFontSize(int size) {
    text.setCharacterSize(size);
}
void UIText::setString(string value) {
    text.setString(value);
}
void UIText::setColor(Color color) {
    text.setFillColor(color);
}
void UIText::setPosition(Vector2f pos) {
    text.setPosition(pos);
}

void UIText::alignCenter() {
    text.setOrigin({
        text.getGlobalBounds().width / 2,
        text.getGlobalBounds().height / 2
    });
}


Text& UIText::getText() {
    return text;
}