#pragma once
#include <string>

class CNhanVien
{
protected:
    std::string MaNV;
    std::string HoTen;
    int Tuoi;
    std::string SDT;
    std::string Email;
    double LuongCoBan;
public:
    CNhanVien();
    virtual ~CNhanVien();
    virtual void Nhap();
    virtual void Xuat();
    virtual double TinhLuong() = 0;
};