//
// Created by xuhuipeng on 2021/5/26.
//

#include "Screen.h"

Screen& Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

void Screen::some_member() const {
    ++access_ctr;
}

Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char c) {
    pos row = r * width;
    contents[row + col] = c;
    return *this;
}

Screen::pos Screen::size() const {
    return height * width;
}

Screen::pos verify(Screen::pos ht) {
    return ht < 100? ht : 100;
}

void Screen::setHeight(pos ht) {
    height = verify(ht);
    return;
}

