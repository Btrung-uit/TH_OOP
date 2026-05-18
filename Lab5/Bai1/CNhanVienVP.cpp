#include "CNhanVienVP.h"
#include "CTienIch.h"
#include <iostream>
#include <iomanip>
using namespace std;

void CNhanVienVP::Nhap()
{
    CNhanVien::Nhap();
    cout << "Nhap so ngay lam viec: ";
    SoNgayLamViec = NhapSoNguyenAnToan();
}
void CNhanVienVP::TinhLuong()
{
    luong = SoNgayLamViec * 100000;
}
void CNhanVienVP::Xuat()
{
    CNhanVien::Xuat();
    cout << "\nNgay lam viec: " << SoNgayLamViec << ", Luong: " << fixed << setprecision(0) << luong << " VND\n";
}

double CNhanVienVP::getLuong()
{
    return luong;
}
cNgay CNhanVienVP::GetNgaySinh()
{
    return NgaySinh;
}