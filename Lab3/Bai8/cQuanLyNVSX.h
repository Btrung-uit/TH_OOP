#pragma once
#include "cNhanVienSX.h"

class cQuanLyNVSX
{
private:
    int n;
    cNhanVienSX *dsNV;

public:
    cQuanLyNVSX();
    ~cQuanLyNVSX();
    void NhapDanhSach();
    void XuatDanhSach();
    void TimNVLuongThapNhat();
    double TinhTongLuong();
    void TimNVTuoiCaoNhat(int namHienTai);
    void SapXepTangDanTheoLuong();
};