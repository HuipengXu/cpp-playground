#include <iostream>
#include "chapter6.h"
#include <vector>

using namespace std;


int count() {
    static int cnt = 0;
    return ++cnt;
}

int main() {
    vector<int> a = {1,2,3,4,5};
    print(a.cbegin(), a.cend());
    return 0;
}