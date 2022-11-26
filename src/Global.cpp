#include <game/Global.hpp>

Global *Global::instance = nullptr;

Global& Global::get() {
    if (instance == nullptr)
        instance = new Global;
    
    return *instance;
}