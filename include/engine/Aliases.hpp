#ifndef ALIASES_HPP
#define ALIASES_HPP

#include <functional>

namespace aliases {

using EasingFunc = std::function<float(float)>;
using VoidCallback = std::function<void(void)>;

}

#endif