#include <engine/Utils.hpp>

float Utils::Clamp(float value, float min, float max) {
    if (value <= min)
        return min;
    else if (value >= max)
        return max;
    return value;
}

float Utils::Clamp1(float value) {
    return Utils::Clamp(value, 0.f, 100.f);
}