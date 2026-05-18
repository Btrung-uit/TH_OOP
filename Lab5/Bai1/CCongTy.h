#pragma once
#include "CNhanVienSX.h"
#include "CNhanVienVP.h"
class CCongTy
{
private:
    CNhanVienSX **DanhSachSX;
    int SoLuongSX;
    CNhanVienVP **DanhSachVP;
    int SoLuongVP;

public:
    CCongTy();
    ~CCongTy();

    void NhapDanhSach();
    void XuatDanhSach();
    void TinhLuong();
    double TinhTongLuong();
    void TimNVSXLuongThapNhat();
    void TimNVVPTuoiCaoNhat();
};