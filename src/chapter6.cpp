//
// Created by xuhuipeng on 2021/5/11.
//

#include <iostream>
#include <vector>
#include "chapter6.h"

using namespace std;

void print(vector<int>::const_iterator beg,
           vector<int>::const_iterator end)
{
    for (;beg != end; ++beg) {
        cout << *beg << endl;
    }
}