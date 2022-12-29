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
    int operator* (int i) {
        cout << i*i << endl;
        return i*i;
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


    o.operator*(1);

    return EXIT_SUCCESS;
}
