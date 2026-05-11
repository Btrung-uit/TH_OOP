#pragma once
#include <iostream>

using namespace std;

class cDaThuc
{
private:
    int n;
    double *heSo;

public:
    cDaThuc();
    cDaThuc(int);
    ~cDaThuc();
    cDaThuc(const cDaThuc &);
    cDaThuc &operator=(const cDaThuc &);

    // Thêm const vì hàm này không làm thay đổi dữ liệu của đa thức
    double TinhGiaTri(double) const;

    // Nạp chồng toán tử toán học
    cDaThuc operator+(const cDaThuc &) const;
    cDaThuc operator-(const cDaThuc &) const;

    // Nạp chồng toán tử nhập/xuất (friend)
    friend istream &operator>>(istream &is, cDaThuc &p);
    friend ostream &operator<<(ostream &os, const cDaThuc &p);
};