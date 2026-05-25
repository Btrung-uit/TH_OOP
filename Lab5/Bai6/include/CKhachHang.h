#pragma once
#include <string>
#include <fstream>

class CKhachHang
{
protected:
    std::string TenKH;
    int SoLuong;
    double DonGia;

public:
    CKhachHang();
    virtual ~CKhachHang() = default;

    virtual void DocFile(std::ifstream &in, bool &flag);

    virtual void GhiFile(std::ofstream &out);

    virtual double TinhTien() = 0;
};