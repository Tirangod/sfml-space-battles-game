#ifndef SKINSUI_HPP
#define SKINSUI_HPP

#include "engine/effects/RampEffect.hpp"
#include "engine/ui/UIComponent.hpp"
#include "engine/ui/KeyboardUI.hpp"
#include "engine/GameWindow.hpp"
//#include "engine/KeyEvents.hpp"
//#include "engine/Scenes.hpp"

using namespace std;
using namespace sf;

class SkinsUI : public KeyboardUI {
private:
    RampEffect *fadeIn;
    UIComponent panel;
public:
    void onInit();
    void onUpdate(float dt);
};

#endif