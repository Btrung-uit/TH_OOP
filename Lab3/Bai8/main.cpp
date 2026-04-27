#include <iostream>
#include "cQuanLyNVSX.h"

using namespace std;

int main()
{
    cQuanLyNVSX quanLy;
    cout << "   CHUONG TRINH QUAN LY NHAN VIEN SX    \n\n";
    quanLy.NhapDanhSach();
    quanLy.XuatDanhSach();
    quanLy.TimNVLuongThapNhat();
    cout << "\nTong luong cong ty phai tra la: " << quanLy.TinhTongLuong() << "\n";
    int namHienTai = 2026;
    quanLy.TimNVTuoiCaoNhat(namHienTai);
    cout << "\nTien hanh sap xep danh sach...       \n";
    quanLy.SapXepTangDanTheoLuong();
    quanLy.XuatDanhSach();
    return 0;
}