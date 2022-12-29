#include <engine/ui/UIProgressBar.hpp>

UIProgressBar::UIProgressBar(float startValue, float maxValue) 
{
    if (maxValue > 0) {
        max = maxValue;
    } else {
        maxValue = 1.0f;
    }

    setValue(startValue);

    //setup();
}

// Invokes when progressbar size or progress changes
void UIProgressBar::updateSize() {
    float maxWidth = background.getSize().x;
    foreground.setSize({maxWidth * getProgress(), background.getSize().y});
}

void UIProgressBar::onInit() {
    foreground.setOrigin(
        foreground.getLocalBounds().width / 2,
        foreground.getLocalBounds().height / 2
    );
    background.setOrigin(
        background.getLocalBounds().width / 2,
        background.getLocalBounds().height / 2
    );
    foreground.setFillColor(Color::Green);
    background.setFillColor({150, 150, 150});
    background.setOutlineColor({130, 110, 90});
    background.setOutlineThickness(3.f);
}

void UIProgressBar::onDraw(RenderTarget& target) {
    target.draw(background);
    target.draw(foreground);
}

void UIProgressBar::add(float amount) {
    float tempValue = value + amount;

    if (tempValue >= max) {
        tempValue = max;
    }else if (tempValue <= 0){
        tempValue = 0;
    }

    setValue(tempValue); // Already updates size
}

void UIProgressBar::setValue(float value) {
    if (value < 0 || value > max) {
        throw "Value is incorrect";
        return;
    }

    this->value = value;
    updateSize();
}

void UIProgressBar::setMax(float _max) {
    if (_max <= 0) {
        throw "Value is incorrect";
        return;
    }
    max = _max;
}

void UIProgressBar::setPosition(Vector2f pos) {
    foreground.setPosition(pos);
    background.setPosition(pos);
}

void UIProgressBar::setSize(Vector2f size) {
    foreground.setSize(size);
    background.setSize(size);
    updateSize();
}

float UIProgressBar::getProgress() { return value / max; }
float UIProgressBar::getValue() { return value; }
float UIProgressBar::getMax() { return max; }

FloatRect UIProgressBar::getBounds() { return background.getGlobalBounds(); }
Vector2f UIProgressBar::getSize() { return background.getSize(); }
RectangleShape& UIProgressBar::getForeground() { return foreground; }
RectangleShape& UIProgressBar::getBackground() { return background; }

