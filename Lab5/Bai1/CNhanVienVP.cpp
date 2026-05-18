#include "CNhanVienVP.h"
#include <iostream>
using namespace std;

void CNhanVienVP::Nhap()
{
    CNhanVien::Nhap();
    cout << "Nhap so ngay lam viec: ";
    cin >> SoNgayLamViec;
}
void CNhanVienVP::TinhLuong()
{
    luong = SoNgayLamViec * 100000;
}
void CNhanVienVP::Xuat()
{
    CNhanVien::Xuat();
    cout << " | So ngay lam viec: " << SoNgayLamViec << " | Luong: " << luong << "\n";
}

double CNhanVienVP::getLuong()
{
    return luong;
}
cNgay CNhanVienVP::GetNgaySinh()
{
    return NgaySinh;
}