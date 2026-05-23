#include "../include/CGiaoDichNhaPho.h"
#include "../include/CGiaoDich.h"
#include "../include/CTienIch.h"
#include <iostream>
using namespace std;

void CGiaoDichNhaPho::Nhap()
{
    CGiaoDich::Nhap();
    cout << "Nhap loai nha:\n1: Cao cap\n2: Thuong\nVui long nhap 1 hoac 2: ";
    int choose;
    while (true)
    {
        choose = NhapSoNguyenAnToan();
        if (choose == 1 || choose == 2)
        {
            LoaiNha = (choose == 1 ? "Cao cap" : "Thuong");
            break;
        }
        cout << "Lua chon khong hop le!\nVui long nhap 1 hoac 2: ";
    }
    cout << "Nhap dia chi: ";
    while (true)
    {
        getline(cin >> ws, DiaChi);
        if (DiaChi != "")
        {
            break;
        }
        cout << "Dia chi khong duoc de trong! Vui long nhap lai: ";
    }
}
void CGiaoDichNhaPho::TinhThanhTien()
{
    if (LoaiNha == "Cao cap")
    {
        ThanhTien = DienTich * DonGia;
    }
    else
    {
        ThanhTien = DienTich * DonGia * 0.9;
    }
}

void CGiaoDichNhaPho::Xuat()
{
    CGiaoDich::Xuat();
    cout << "\nLoai nha: " << LoaiNha
         << ", Dia chi: " << DiaChi
         << "\nThanh tien: " << DinhDangTien(ThanhTien)
         << " VND\n";
}