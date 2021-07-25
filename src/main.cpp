//
// Created by xuhuipeng on 2021/5/16.
//

#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <stack>
#include <string>
#include <vector>
#include <functional>
// #include "Screen.h"
// #include "window_mgr.h"
// #include "leetcode.cpp"

using namespace std;

istream &func(istream &is) {
  string buf;
  while (is >> buf) {
    cout << buf << endl;
  }
  cout << is.rdstate() << endl;
  is.clear();
  cout << is.rdstate() << endl;
  return is;
}

bool lg_five(const string &s) {
    return s.size() >= 5;
}

bool lg_three(const int &num, const int &thre) {
    return num > thre;
}

int main() {
    vector<int> nums{1, 2, 3, 4, 5, 6};
    int thre = 3;
    auto f = bind(lg_three, placeholders::_1, thre);
    int a = count_if(nums.begin(), nums.end(), [&thre] (const int &num) {return num > thre;});
    cout << a << endl;
    int b = count_if(nums.begin(), nums.end(), f);
    cout << b << endl;
    // for_each(nums.begin(), nums.end(), [] (const int &num) {cout << num << endl;});
}