#include "../include/CGiaoDichDat.h"
#include <iostream>
#include <cctype>
using namespace std;

void CGiaoDichDat::Nhap()
{
    CGiaoDich::Nhap();
    cout << "Nhap loai dat: ";
    while(cin >> LoaiDat)
    {
        LoaiDat = toupper(LoaiDat);
        if(LoaiDat == 'A' || LoaiDat == 'B' || LoaiDat == 'C')
        {
            break;
        }
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Loai dat khong hop le!\nVui long nhap lai (A, B, C): ";
    }
}

void CGiaoDichDat::TinhThanhTien()
{
    if(LoaiDat == 'A')
    {
        ThanhTien = DienTich * DonGia * 1.5;
    }
    else
    {
        ThanhTien = DienTich * DonGia;
    }
}

void CGiaoDichDat::Xuat()
{
    CGiaoDich::Xuat();
    cout << ", Loai dat: " << LoaiDat 
         << ", Thanh Tien: " << ThanhTien 
         << " VND\n";
}