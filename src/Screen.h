//
// Created by xuhuipeng on 2021/5/26.
//

#ifndef PLAYGROUND_SCREEN_H
#define PLAYGROUND_SCREEN_H

#include <iostream>
#include <string>

using namespace std;


class Screen {
    friend class window_mgr;  // 不需要 include 其头文件

public:
    using pos = string::size_type;

    Screen() = default;

    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {};

    char get() const {
        return contents[cursor];
    }

    char get(pos ht, pos wd) const;

    Screen &move(pos r, pos c);

    void some_member() const;

    Screen &set(char);

    Screen &set(pos, pos, char);

    Screen &display(ostream &os) {
        do_display(os);
        return *this;
    };

    const Screen &display(ostream &os) const {
        do_display(os);
        return *this;
    }

    pos size() const;

private:
    Screen *j;
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    mutable size_t access_ctr;

    void do_display(ostream &os) const {
        os << contents;
    }

};


#endif //PLAYGROUND_SCREEN_H
