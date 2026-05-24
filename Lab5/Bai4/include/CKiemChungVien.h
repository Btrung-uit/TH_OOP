#pragma once
#include "../include/CNhanVien.h"
class CKiemChungVien : public CNhanVien
{
private:
    int SoLoi;

public:
    CKiemChungVien();
    void Nhap() override;
    void Xuat() override;
    double TinhLuong() override;
};