#pragma once
#include <iostream>

using namespace std;

class cPhanSo
{
private:
    int tuSo;
    int mauSo;
    void RutGon();

public:
    cPhanSo(int tu = 0, int mau = 1);

    // Toán tử toán học
    cPhanSo operator+(const cPhanSo &khac) const;
    cPhanSo operator-(const cPhanSo &khac) const;
    cPhanSo operator*(const cPhanSo &khac) const;
    cPhanSo operator/(const cPhanSo &khac) const;

    // Toán tử so sánh
    bool operator==(const cPhanSo &khac) const;
    bool operator>(const cPhanSo &khac) const;
    bool operator<(const cPhanSo &khac) const;

    // Toán tử nhập xuất
    friend istream &operator>>(istream &is, cPhanSo &ps);
    friend ostream &operator<<(ostream &os, const cPhanSo &ps);
};