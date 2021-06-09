//
// Created by xuhuipeng on 2021/5/16.
//

#ifndef PLAYGROUND_SALES_DATA_H
#define PLAYGROUND_SALES_DATA_H


#include <iostream>

using namespace std;

class SaleData {
    friend SaleData add(const SaleData &lhs, const SaleData &rhs);

    friend istream &read(istream &is, SaleData &item);

    friend ostream &print(ostream &os, const SaleData &item);

private:
    string bookNo;
    double revenue = 0.0;
    unsigned units_sold = 0;

public:
    SaleData() = default;

    SaleData(const string &s) : bookNo(s) {};

    SaleData(const string &s, const double p, const unsigned u) :
            bookNo(s), units_sold(u), revenue(p * u) {};

    SaleData(istream &is) {
        double price = 0.0;
        is >> bookNo >> units_sold >> price;
        revenue = price * units_sold;
    }

    string isbn() const { return bookNo; };

    double avgPrice() const;

    SaleData &combine(const SaleData &other);
};


ostream &print(ostream &os, const SaleData &item);

#endif //PLAYGROUND_SALES_DATA_H
