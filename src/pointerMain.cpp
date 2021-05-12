//
// Created by xuhuipeng on 2021/5/11.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//bool containUpperCase(const string &s) {
////    for (auto ch: s) {
////        if (isupper(ch)) {
////            return true;
////        }
////    }
////    return false;
//    return any_of(s.cbegin(), s.cend(), [](char ch){return isupper(ch);});
//}

//void toLowerCase(string &s) {
//    for (auto &ch: s) {
//        ch = tolower(ch);
//    }
//}

void print(string::const_iterator beg,
           string::const_iterator end)
{
    for (;beg != end; ++beg) {
        cout << *beg << endl;
    }
}

int cmp(const int &a, const int *b)
{
    return (a > *b) ? a : *b;
}


void print(const int *array, const int &size) {
    const int *begin = array;
    for (; array != (begin + size); ++array) {
        cout << *array << endl;
    }
}


void print(int (&ia)[3]) {
    for (int *begin = ia; begin != ia + 3; ++begin) {
        cout << *begin << endl;
    }
}

int main2(int argc, char *argv[]) {
//    string s("Hello World");
//    cout << containUpperCase(s) << endl;
//    toLowerCase(s);
//    print(s.cbegin(), s.cend());
//    int a = 10, b = 4;
//    cout << cmp(a, &b) << endl;
//    int array[3] = {32,1,3};
//    print(array, end(array) - begin(array));
//    print(array);
    for (int i = 0; i != argc; ++i) {
        cout << *(argv + i) << endl;
    }
    cout << argv[argc] << endl;
    return 0;
}

int sum(initializer_list<int> intArray) {
    int sum = 0;
    for (const int &num: intArray) {
        sum += num;
    }
    return sum;
}

int fact(int val) {
    if (val != 0) {
        return fact(val - 1) * val;
    }
    return 1;
}

void recurPrint(vector<int>::const_iterator beg, vector<int>::const_iterator end) {
    if (beg != end) {
        cout << *beg++ << endl;
        recurPrint(beg, end);
    }
}


int a[5] = {1,2,3,4,5};

int (*returnArray())[5] {
    return &a;
}

auto returnArray1() -> int(*)[5] {
    return &a;
}

int main(int argc, char **argv) {
//    int (*p)[5] = returnArray1();
//    cout << *(*p + 4) << endl;
    cout << *(a + 1) << endl;
    return EXIT_SUCCESS;
}