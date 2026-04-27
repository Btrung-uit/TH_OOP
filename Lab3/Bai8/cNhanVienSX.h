#pragma once
#include <string>
#include "cNgay.h"

using namespace std;

class cNhanVienSX
{
private:
    string maNV;
    string hoTen;
    cNgay ngaySinh;
    int soSanPham;
    double donGia;

public:
    cNhanVienSX();

    string getMaNV();
    void setMaNV(string);

    string getHoTen();
    void setHoTen(string);

    int getSoSanPham();
    void setSoSanPham(int);

    double getDonGia();
    void setDonGia(double);

    void Nhap();
    void Xuat();
    double TinhLuong();
    int getTuoi(int);
};