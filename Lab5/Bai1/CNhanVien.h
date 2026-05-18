#pragma once
#include "cNgay.h"
#include <string>
using namespace std;
class CNhanVien
{
protected:
    string HoTen;
    cNgay NgaySinh;
    double luong;

public:
    CNhanVien();
    virtual ~CNhanVien();
    virtual void Nhap();
    virtual void Xuat();
    virtual void TinhLuong() = 0;
    cNgay getNgaySinh() const;
};