//
// Created by xuhuipeng on 2021/5/26.
//

#include "window_mgr.h"

void window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}