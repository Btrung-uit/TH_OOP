#include "cNgay.h"
#include <iostream>
#include <iomanip>
using namespace std;

void NhapGiaTri(int &data)
{
    while (true)
    {
        if (cin >> data && data > 0)
        {
            break;
        }
        cout << "Gia tri khong hop le! Nhap lai: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void NhapNgayThangNam(int &ngay, int &thang, int &nam)
{
    cout << "Nhap ngay: ";
    NhapGiaTri(ngay);

    cout << "Nhap thang: ";
    NhapGiaTri(thang);

    cout << "Nhap nam: ";
    NhapGiaTri(nam);
}

bool namNhuan(int nam)
{
    return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
}

int soNgayTrongThang(int thang, int nam)
{
    switch (thang)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return namNhuan(nam) ? 29 : 28;
    default:
        return 31;
    }
}

bool KiemTraNgayThangNamHopLe(int ngay, int thang, int nam)
{
    if (nam < 1 || thang < 1 || thang > 12 || ngay < 1)
        return false;
    if (ngay > soNgayTrongThang(thang, nam))
        return false;
    return true;
}

cNgay::cNgay()
{
    ngay = 1;
    thang = 1;
    nam = 2000;
}

void cNgay::Nhap()
{
    while (true)
    {
        NhapNgayThangNam(ngay, thang, nam);
        if (KiemTraNgayThangNamHopLe(ngay, thang, nam))
            return;
        cout << "Ngay thang nam khong hop le!\n Vui long nhap lai: ";
    }
}

void cNgay::Xuat()
{
    cout << right << setfill('0') << setw(2) << ngay << "/"
         << setw(2) << thang << "/"
         << left << setfill(' ') << nam;
}

int cNgay::getNam()
{
    return nam;
}