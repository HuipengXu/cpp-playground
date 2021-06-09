//
// Created by xuhuipeng on 2021/5/26.
//

#ifndef PLAYGROUND_WINDOW_MGR_H
#define PLAYGROUND_WINDOW_MGR_H

#include <iostream>
#include <vector>
#include "Screen.h"

using namespace std;


class window_mgr {
public:
    using ScreenIndex = vector<Screen>::size_type;

    void clear(ScreenIndex);

private:
    vector<Screen> screens{Screen(24, 80, ' ')};
};


#endif //PLAYGROUND_WINDOW_MGR_H
