#include "CGiaoDichCanHo.h"
#include "CGiaoDich.h"
#include "CTienIch.h"
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
        cout << "So tang khong hop le!\Vui long long nhap lai (> 0): ";
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
    cout << ", Ma can ho: " << MaCan 
         << " , Vi tri tang: " << ViTriTang 
         << " , Thanh tien: " << ThanhTien 
         << " VND\n";
}