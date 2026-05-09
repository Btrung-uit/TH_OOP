#pragma once
#include <iostream>
using namespace std;

class cSoPhuc
{
private:
    double thuc;
    double ao;

public:
    cSoPhuc(double thuc = 0, double ao = 0);

    // toán tử toán học
    cSoPhuc operator+(const cSoPhuc &khac) const;
    cSoPhuc operator-(const cSoPhuc &khac) const;
    cSoPhuc operator*(const cSoPhuc &khac) const;
    cSoPhuc operator/(const cSoPhuc &khac) const;

    // toán tử so sánh
    bool operator==(const cSoPhuc &khac) const;
    bool operator!=(const cSoPhuc &khac) const;

    // toán tử nhập xuất
    friend istream &operator>>(istream &is, cSoPhuc &sp);
    friend ostream &operator<<(ostream &os, const cSoPhuc &sp);
};