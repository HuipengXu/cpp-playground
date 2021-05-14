//
// Created by xuhuipeng on 2021/5/12.
//

#include <iostream>
#include <vector>

//#define NDEBUG;

#include <cassert>

using namespace std;

void func(int a, int b, int c) {
    cout << a << " " << b << " " << c << endl;
}

void func(int a, int b, int c = 23);

void func(int a, int b = 56, int c);

constexpr size_t scale(size_t cnt) { return cnt * 4; };

void printVector(vector<int> a) {
    if (!a.empty()) {
        #ifndef NDEBUG
        cout << a.size() << endl;
        #endif
        a.pop_back();
        printVector(a);
    }
    return;
}

void (*f(int a))(vector<int>) {
    cout << "return func pointer" << endl;
    return printVector;
}

auto f1(int a) -> void (*) (vector<int>) {
    cout << "return func pointer" << endl;
    return printVector;
}

decltype(printVector) *f2(int a) {
    cout << "return func pointer" << endl;
    return printVector;
}

int sum(int a, int b) {
    return a + b;
}

using pf = void (*) (vector<int>);
int main() {
    vector<int> a(3, 4);
//    auto ff = f(4);
//    ff(a);
//    pf fff = f1(5);
//    fff(a);
//    void (*ffff)(vector<int>) = f1(6);
//    ffff(a);
//    void (*fffff)(vector<int>) = f2(6);
//    fffff(a);

    vector<int (*) (int, int)> arrayPf(3, sum);
    for (auto pfi: arrayPf) {
        cout << pfi(4, 5) << endl;
    }
    return 0;
};