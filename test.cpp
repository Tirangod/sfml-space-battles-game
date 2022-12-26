#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <bitset>
#include <typeinfo>

using namespace std;


class Object {
public:
    Object() {
        cout << "HEllo" << endl;
    }
};

class Subject : Object {
public:
    Subject() {
        cout << "FUCK" << endl;
    }
};

int main() {

    Object o;
    Subject s;

    return EXIT_SUCCESS;
}
