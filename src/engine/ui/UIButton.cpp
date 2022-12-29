#include <engine/ui/UIButton.hpp>

UIButton::UIButton() {
    padding = {0, 0};
    onClickCallback = []{};

    startColor = {3, 86, 252};
    clickColor = {0, 48, 145};

    clickSound.loadFrom("assets/audio/sounds/ui/select_sound.wav");
    selectSound.loadFrom("assets/audio/sounds/ui/choose_sound.wav");
    clickSound.setVolume(50.f);
    selectSound.setVolume(50.f);

    text.loadFont("assets/fonts/font_light.ttf");

    getBackground().setFillColor(startColor);
    getBackground().setOutlineThickness(5.f);
    getBackground().setOutlineColor(Color::Transparent);
}

void UIButton::onInit() {
    addChild(text);
    
    clickEffect = new RampEffect(startColor, clickColor);
    clickEffect->setEasingFunc(Effect::EaseOutExpo);
    clickEffect->setDuration(seconds(0.4f));
    clickEffect->addUIComponent(*this);
    clickEffect->setOnFinish([&]{
        getBackground().setFillColor(startColor);
    });
}
void UIButton::onDraw(RenderTarget& target) {
    target.draw(icon);
}
void UIButton::onUpdate(float dt) {
    clickEffect->update(dt);
}
void UIButton::onSelected() {
    getBackground().setOutlineColor(Color::Yellow);
    selectSound.play();
}
void UIButton::onUnselected() {
    getBackground().setOutlineColor(Color::Transparent);
}
void UIButton::onWhileSelected(float dt) {
    if (KeyEvents::isKeyPressed(Keyboard::Space)) {
        onClickCallback();
        clickSound.play();
        clickEffect->restart();
    }
}

void UIButton::alignTextCenter() {
    padding = getSize() / 2.f;
}

void UIButton::onUpdateTransform() { 
    icon.setPosition(getPosition() + padding);
    text.setPosition(getPosition() + padding);
}

void UIButton::setColor(Color color) {
    startColor = color;
}

void UIButton::setClickColor(Color color) {
    clickColor = color;
}

void UIButton::setOnClick(VoidCallback callback) {
    onClickCallback = callback;
}

void UIButton::setPadding(Vector2f _padding) {
    padding = _padding;
    onUpdateTransform();
}
void UIButton::setIcon(string path) {
    icon.loadFrom(path);
}
void UIButton::setString(string value) {
    text.setString(value);
}

Vector2f UIButton::getPadding() {
    return padding;
}
GameSprite& UIButton::getIcon() {
    return icon;
}
UIText& UIButton::getText() {
    return text;
}
string UIButton::getString() {
    return text.getText().getString();
}