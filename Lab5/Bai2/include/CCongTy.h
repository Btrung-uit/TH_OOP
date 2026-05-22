#pragma once
#include "CGiaoDich.h"
#include "CGiaoDichDat.h"
#include "CGiaoDichNhaPho.h"
#include "CGiaoDichCanHo.h"

class CCongTy
{
private:
    CGiaoDich **DanhSachGD;
    int SoLuongGD;
public:
    CCongTy();
    ~CCongTy();
    void NhapDanhSach();
    void XuatDanhSach();
    void ThongKeSoLuongTungLoai();
    double TinhTrungBinhThanhTienCuaCanHo();
    void NhaPhoGiaTriCaoNhat();
    void XuatDanhSachThang12Nam2024();
};
