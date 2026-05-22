#include "../include/CGiaoDich.h"
#include "../include/CTienIch.h"
#include <iostream>
#include <string>
using namespace std;

CGiaoDich::CGiaoDich()
{
    MaGiaoDich = "";
    DonGia = 0;
    DienTich = 0;
    ThanhTien = 0;
}

CGiaoDich::~CGiaoDich() {}

void CGiaoDich::Nhap()
{
    cout << "Nhap ma giao dich: ";
    getline(cin >> ws, MaGiaoDich);
    cout << "Nhap ngay giao dich:\n";
    NgayGiaoDich.Nhap();
    cout << "Nhap don gia: ";
    DonGia = NhapSoThucAnToan();
    cout << "Nhap dien tich: ";
    DienTich = NhapSoThucAnToan();
}

void CGiaoDich::Xuat()
{
    cout << "Ma giao dich: " << MaGiaoDich << ", Ngay giao dich: ";
    NgayGiaoDich.Xuat();
    cout << ", Don gia: " << DonGia << ", Dien tich: " << DienTich;
}

double CGiaoDich::getThanhTien() const
{
    return ThanhTien;
}

cNgay CGiaoDich::getNgayGiaoDich() const
{
    return NgayGiaoDich;
}