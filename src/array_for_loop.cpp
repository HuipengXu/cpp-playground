#include <iostream>
#include <string>

using namespace std;
using int_array = int[4];

int main() {
    int array[2][4] = {{1,2,3,4}, {6,7,8,9}};
    cout << array << endl;
    cout << *array << endl;
    cout << **array << endl;
    cout << "***********************" << endl;
    for (int (*p)[4] = array; p != array + 2; ++p) {
        cout << p << endl;
        cout << *p << endl;
        cout << **p << endl;
        for (int *q = *p; q != *p + 4; ++q) {
            cout << *q << endl;
        }
    }

    cout << "***********************" << endl;

    for (int_array *p = array; p != array + 2; ++p) {
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

    for (auto p = array; p != array + 2; ++p) {
        for (auto q = *p; q != *p + 4; ++q) {
            cout << *q << endl;
        }
    }

    cout << "***********************" << endl;

    for (auto p = begin(array); p != end(array); ++p) {
        for (auto q = begin(*p); q != end(*p); ++q) {
            cout << *q << endl;
        }
    }
    return 0;
}
