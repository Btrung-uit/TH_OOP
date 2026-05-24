#pragma once
#include "../include/CNhanVien.h"
class CLapTrinhVien : public CNhanVien
{
private:
    double GioOvertime;

public:
    CLapTrinhVien();
    void Nhap() override;
    void Xuat() override;
    double TinhLuong() override;
};