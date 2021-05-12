#include <iostream>
#include "chapter6.h"
#include <vector>

using namespace std;

int main() {
//    vector<int> a(10, 4);
    vector<int> a{1,2,3,4};  // g++ -Wall -std=c++11 -c main.cpp 可通过
    print(a.cbegin(), a.cend());
    return 0;
}