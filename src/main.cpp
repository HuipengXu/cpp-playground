//
// Created by xuhuipeng on 2021/5/16.
//

#include <iostream>
#include "Screen.h"
#include "window_mgr.h"

using namespace std;




int main() {
    Screen::pos a = 6;
    Screen::pos b = 5;
    Screen myScreen(a, b, 'X');
    myScreen.move(a, b).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
    return 0;
}