#include "CNhanVienSX.h"
#include <iostream>
using namespace std;

void CNhanVienSX::Nhap()
{
    CNhanVien::Nhap();
    cout << "Nhap luong can ban: ";
    cin >> LuongCanBan;
    cout << "Nhap so san pham: ";
    cin >> SoSanPham;
}
void CNhanVienSX::TinhLuong()
{
    luong = LuongCanBan + SoSanPham * 5000;
}
void CNhanVienSX::Xuat()
{
    CNhanVien::Xuat();
    cout << " | Luong can ban: " << LuongCanBan << " | So san pham: " << SoSanPham << " | Luong: " << luong << "\n";
}

double CNhanVienSX::getLuong()
{
    return luong;
}