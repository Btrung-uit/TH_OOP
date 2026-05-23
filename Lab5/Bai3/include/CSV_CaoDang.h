#pragma once
#include "CSinhVien.h"

class CSV_CaoDang : public CSinhVien
{
private:
    double DiemThiTotNghiep;

public:
    CSV_CaoDang();

    void Nhap() override;
    void Xuat() override;
    bool KiemTraTotNghiep() override;
};