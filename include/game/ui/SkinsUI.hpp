#ifndef SKINSUI_HPP
#define SKINSUI_HPP

#include <string>
#include "engine/effects/RampEffect.hpp"
#include "engine/ui/UIComponent.hpp"
#include "engine/ui/CompsGroup.hpp"
#include "engine/ui/KeyboardUI.hpp"
#include "engine/ui/UIButton.hpp"
#include "engine/ui/UIText.hpp"
#include "engine/GameWindow.hpp"
#include "engine/KeyEvents.hpp"
#include "engine/Scenes.hpp"
#include "game/entities/Player.hpp"
#include "game/Presets.hpp"

using namespace std;
using namespace sf;

class SkinsUI : public KeyboardUI {
private:
    UIText text;

    RampEffect *fadeIn;
    RampEffect *fadeOut;
    UIComponent panel;

    CompsGroup group;

    UIButton skin0;
    UIButton skin1;
    UIButton skin2;
    UIButton skin3;
public:
    void onInit();
    void onUpdate(float dt);
};

#endif