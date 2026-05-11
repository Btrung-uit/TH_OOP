#pragma once
#include <iostream>

using namespace std;

class CDate
{
private:
    int ngay, thang, nam;

    // Các hàm phụ trợ nội bộ
    bool LaNamNhuan(int y) const;
    int SoNgayTrongThang(int m, int y) const;
    bool KiemTraNgay(int d, int m, int y) const;
    long ToDays() const; // Chuyển ngày hiện tại thành tổng số ngày từ mốc 1/1/1

public:
    CDate(int d = 1, int m = 1, int y = 2000);

    // Toán tử cộng/trừ số ngày
    CDate operator+(int days) const;
    CDate operator-(int days) const;

    // Toán tử tăng/giảm (Tiền tố & Hậu tố)
    CDate &operator++();   // ++a
    CDate operator++(int); // a++
    CDate &operator--();   // --a
    CDate operator--(int); // a--

    // Toán tử trừ giữa hai ngày (Khoảng cách)
    int operator-(const CDate &khac) const;

    // Nhập xuất
    friend istream &operator>>(istream &is, CDate &d);
    friend ostream &operator<<(ostream &os, const CDate &d);
};