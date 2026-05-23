#pragma once
#include "CSinhVien.h"
#include <string>

class CSV_DaiHoc : public CSinhVien
{
private:
    std::string TenLuanVan;
    double DiemLuanVan;

public:
    CSV_DaiHoc();

    void Nhap() override;
    void Xuat() override;
    bool KiemTraTotNghiep() override;
};