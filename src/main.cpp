#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include "Sales_item.hpp"

using namespace std;

int main() {
    int array[2][4] = {{1,2,3,4}, {6,7,8,9}};
    for (int (*p)[4] = array; p != array + 2; ++p) {
//        cout << *p << endl;
        for (int *q = *p; q != *p + 4; ++q) {
            cout << *q << endl;
        }
    }

    cout << "***********************" << endl;

    for (auto &p: array) {
        for (auto q: p) {
            cout << q << endl;
        }
    }

    cout << "***********************" << endl;
    return 0;
}
