//
// Created by xuhuipeng on 2021/5/16.
//

#include <iostream>
#include "sales_data.h"

using namespace std;




int main() {
    SaleData ds1;
    print(cout, ds1) << endl;
    SaleData ds2("hello class");
    print(cout, ds2) << endl;
    SaleData ds3("hello class1", 5.0, 4);
    print(cout, ds3) << endl;
    SaleData ds4(cin);
    print(cout, ds4) << endl;
    return 0;
}