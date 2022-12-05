#include <cstdlib>
#include <iostream>
#include <vector>
#include <list>
#include <bitset>
#include <typeinfo>

using namespace std;


int main() {

    list<int> ls = {10, 8, 6, 4, 2, 0};

    int i = 0;
    for (auto it = ls.begin(); it != ls.end(); ++it) {
        if (i == 2) {
            ls.remove()
        }
        cout << *it << endl;
        i++;
    }
    cout << "-----------" << endl;
    for (auto it = ls.begin(); it != ls.end(); ++it) {
        cout << *it << endl;
    }

    return EXIT_SUCCESS;
}
