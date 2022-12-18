#include <cstdlib>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <bitset>
#include <typeinfo>

using namespace std;


int main() {

    vector<int> vec = {1, 2, 3, 4, 5};

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
        vec.pop_back();
    }

    return EXIT_SUCCESS;
}
