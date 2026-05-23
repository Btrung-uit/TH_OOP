#pragma once
#include <string>

class CSinhVien
{
protected:
    std::string MSSV;
    std::string HoTen;
    std::string DiaChi;
    int TongTinChi;
    double DiemTB;

public:
    CSinhVien();
    virtual ~CSinhVien();

    virtual void Nhap();
    virtual void Xuat();
    
    virtual bool KiemTraTotNghiep() = 0;
    
    double getDiemTB() const;
};