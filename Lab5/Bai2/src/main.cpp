#include "../include/CCongTy.h"
#include "../include/CTienIch.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    CCongTy VAKALAND;
    VAKALAND.NhapDanhSach();
    VAKALAND.XuatDanhSach();
    VAKALAND.ThongKeSoLuongTungLoai();
    double TrungBinhThanhTien = VAKALAND.TinhTrungBinhThanhTienCuaCanHo();
    if (TrungBinhThanhTien == -1)
    {
        cout << "Khong co giao dich can ho!\n";
    }
    else
    {
        cout << "Trung binh thanh tien can ho la: " << fixed << setprecision(0) << DinhDangTien(TrungBinhThanhTien) << " VND\n";
    }

    VAKALAND.NhaPhoGiaTriCaoNhat();
    VAKALAND.XuatDanhSachThang12Nam2024();
}