#include "../include/CGiaoDichCanHo.h"
#include "../include/CGiaoDich.h"
#include "../include/CTienIch.h"
#include <iostream>
using namespace std;

void CGiaoDichCanHo::Nhap()
{
    CGiaoDich::Nhap();
    cout << "Nhap ma can ho: ";
    getline(cin >> ws, MaCan);
    cout << "Nhap vi tri tang (So nguyen > 0): ";
    while (true)
    {
        ViTriTang = NhapSoNguyenAnToan();
        if (ViTriTang > 0)
        {
            break;
        }
        cout << "So tang khong hop le!\nVui long long nhap lai (> 0): ";
    }
}

void CGiaoDichCanHo::TinhThanhTien()
{
    if (ViTriTang == 1)
    {
        ThanhTien = DienTich * DonGia * 2;
    }
    else if (ViTriTang >= 15)
    {
        ThanhTien = DienTich * DonGia * 1.2;
    }
    else
    {
        ThanhTien = DienTich * DonGia;
    }
}

void CGiaoDichCanHo::Xuat()
{
    CGiaoDich::Xuat();
    cout << "\nMa can ho: " << MaCan
         << ", Vi tri tang: " << ViTriTang
         << "\nThanh tien: " << DinhDangTien(ThanhTien)
         << " VND\n";
}