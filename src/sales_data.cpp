//
// Created by xuhuipeng on 2021/5/16.
//

#include "sales_data.h"

SaleData &SaleData::combine(const SaleData &other) {
    revenue += other.revenue;
    units_sold += other.units_sold;
    return *this;
}

double SaleData::avgPrice() const {
    if (units_sold == 0) {
        return 0;
    } else {
        return revenue / units_sold;
    }
}

SaleData SaleData::add(const SaleData &lhs, const SaleData &rhs) {
//    SaleData sum = lhs;
//    sum.combine(rhs);
//    return sum;
    SaleData sum;
    sum.units_sold = lhs.units_sold + rhs.units_sold;
    sum.revenue = lhs.revenue + rhs.revenue;
    return sum;
}

istream &read(istream &is, SaleData &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

ostream &print(ostream &os, const SaleData &item) {
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avgPrice();
    return os;
}