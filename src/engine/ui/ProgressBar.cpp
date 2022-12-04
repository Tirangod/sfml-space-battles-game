#include <engine/ui/ProgressBar.hpp>

ProgressBar::ProgressBar(float startValue, float maxValue) 
{
    if (maxValue > 0) {
        max = maxValue;
    } else {
        maxValue = 1.0f;
    }

    setValue(startValue);

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

// Invokes when progressbar size or proress changes
void ProgressBar::updateSize() {
    float maxWidth = background.getSize().x;
    foreground.setSize({maxWidth * getProgress(), background.getSize().y});
}

void ProgressBar::draw(RenderTarget& target) {
    target.draw(background);
    target.draw(foreground);
}

void ProgressBar::add(float amount) {
    float tempValue = value + amount;

    if (tempValue >= max) {
        value = max;
        return;
    }else if (tempValue <= 0){
        value = 0;
        return;
    }

    value = tempValue;
    updateSize();
}

void ProgressBar::setValue(float value) {
    if (value < 0 || value > max) {
        throw "Value is incorrect";
        return;
    }

    this->value = value;
    updateSize();
}

void ProgressBar::setPosition(Vector2f pos) {
    foreground.setPosition(pos);
    background.setPosition(pos);
}

void ProgressBar::setSize(Vector2f size) {
    foreground.setSize(size);
    background.setSize(size);
    updateSize();
}

float ProgressBar::getProgress() { return value / max; }