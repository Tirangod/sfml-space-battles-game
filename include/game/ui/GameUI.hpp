#ifndef GAMEUI_HPP
#define GAMEUI_HPP

#include "engine/effects/RampEffect.hpp"
#include "engine/ui/UIComponent.hpp"
#include "engine/ui/UI.hpp"
#include "engine/GameWindow.hpp"
//#include "engine/KeyEvents.hpp"
//#include "engine/Scenes.hpp"

using namespace std;
using namespace sf;

class GameUI : public UI {
private:
    RampEffect *fadeIn;
    UIComponent panel;
public:
    void onInit();
    void onUpdate(float dt);
};

#endif