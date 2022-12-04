#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <typeinfo>
#include <functional>

#include "GameObject.hpp"

using namespace std;

namespace Utils {

static long Hash(string str) {
    return hash<string>{}(str);
}

class TypeHash {
private:
    long hash;
};

}

#endif