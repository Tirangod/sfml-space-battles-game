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
    ~Object() {
        cout << "Object" << endl;
    }
};

class Subject : Object {
public:
    ~Subject() {
        cout << "Subject" << endl;
    }
};

int main() {

    auto o = new Subject;

    delete o;

    return EXIT_SUCCESS;
}
