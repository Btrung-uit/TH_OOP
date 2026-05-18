#include "CNhanVien.h"
#include <iostream>
using namespace std;

CNhanVien::CNhanVien()
{
    HoTen = "";
    luong = 0;
}
CNhanVien::~CNhanVien() {}
void CNhanVien::Nhap()
{
    cout << "Nhap ho ten: ";
    getline(cin, HoTen);
    NgaySinh.Nhap();
}
void CNhanVien::Xuat()
{
    cout << "Ho ten: " << HoTen << " | Ngay sinh: ";
    NgaySinh.Xuat();
}
cNgay CNhanVien::getNgaySinh() const
{
    return NgaySinh;
}