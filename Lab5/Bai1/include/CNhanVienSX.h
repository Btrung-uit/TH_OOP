#pragma once
#include "../include/CNhanVien.h"
class CNhanVienSX : public CNhanVien
{
private:
    double LuongCanBan;
    int SoSanPham;

public:
    void Nhap() override;
    void TinhLuong() override;
    void Xuat() override;
    double getLuong();
};