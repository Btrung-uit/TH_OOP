#pragma once
#include "../include/CNhanVien.h"
#include "../include/cNgay.h"

class CNhanVienVP : public CNhanVien
{
private:
    int SoNgayLamViec;

public:
    void Nhap() override;
    void TinhLuong() override;
    void Xuat() override;
    double getLuong();
    cNgay GetNgaySinh();
};