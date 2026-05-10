#pragma once
#include <iostream>

using namespace std;

class CTime
{
private:
    int gio;
    int phut;
    int giay;

    // Hàm nội bộ tự động đưa thời gian về chuẩn 00:00:00 -> 23:59:59
    void ChuanHoa();

public:
    // Phương thức thiết lập
    CTime(int h = 0, int m = 0, int s = 0);

    // Toán tử cộng/trừ với một số nguyên (giây)
    CTime operator+(int s) const;
    CTime operator-(int s) const;

    // Toán tử ++, -- (Tiền tố: ++a, --a) -> Trả về tham chiếu
    CTime &operator++();
    CTime &operator--();

    // Toán tử ++, -- (Hậu tố: a++, a--) -> Có thêm tham số 'int' ảo, trả về bản sao
    CTime operator++(int);
    CTime operator--(int);

    // Toán tử nhập xuất
    friend istream &operator>>(istream &is, CTime &t);
    friend ostream &operator<<(ostream &os, const CTime &t);
};