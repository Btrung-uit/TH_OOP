#pragma once
#include "../include/cNgay.h"
#include <string>

class CGiaoDich
{
protected:
    std::string MaGiaoDich;
    cNgay NgayGiaoDich;
    double DonGia;
    double DienTich;
    double ThanhTien;
public:
    CGiaoDich();
    virtual ~CGiaoDich();
    virtual void Nhap();
    virtual void Xuat();
    virtual void TinhThanhTien() = 0;
    
    double getThanhTien() const;
    cNgay getNgayGiaoDich() const;
};