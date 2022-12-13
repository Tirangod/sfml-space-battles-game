#include <cstdlib>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <bitset>
#include <typeinfo>

using namespace std;

class Base {
public:
    virtual void create() {}
};

class Object : public Base{
public:
    void create() {}
};

class Another {
public:
    virtual void create() {}
};

int main() {

    auto o = new Object;
    
    cout << ((bool)dynamic_cast<Another*>(o)) << endl;

    return EXIT_SUCCESS;
}
