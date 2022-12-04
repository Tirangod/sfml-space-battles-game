#include <cstdlib>
#include <iostream>
#include <vector>
#include <list>
#include <bitset>
#include <typeinfo>

using namespace std;

class Object {
public:
    ~Object() {
        cout << "Object deleted" << endl;
    }
};

class SomeClass : public Object {
public:
    virtual ~SomeClass() {
        cout << "SomeClass deleted" << endl;
    }
};

int main() {

    auto c = new SomeClass;

    cout << typeid(SomeClass).name() << endl;
    auto str = string(typeid(c).name());
    cout << str.substr(1, str.length()) << endl;

    return EXIT_SUCCESS;
}
