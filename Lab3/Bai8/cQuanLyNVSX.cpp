#include "cQuanLyNVSX.h"
#include <iostream>

using namespace std;

cQuanLyNVSX::cQuanLyNVSX()
{
    n = 0;
    dsNV = nullptr;
}

cQuanLyNVSX::~cQuanLyNVSX()
{
    if (dsNV != nullptr)
    {
        delete[] dsNV;
    }
}

void cQuanLyNVSX::NhapDanhSach()
{
    cout << "Nhap so luong nhan vien: ";
    while (true)
    {
        if (cin >> n && n > 0)
        {
            break;
        }
        cout << "So luong khong hop le! Nhap lai: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    if (dsNV != nullptr)
    {
        delete[] dsNV;
    }
    dsNV = new cNhanVienSX[n];

    for (int i = 0; i < n; i++)
    {
        cout << "--- Nhap thong tin nhan vien thu " << i + 1 << " ---\n";
        dsNV[i].Nhap();
        bool trungMa;
        do
        {
            trungMa = false;
            for (int j = 0; j < i; j++)
            {
                if (dsNV[j].getMaNV() == dsNV[i].getMaNV())
                {
                    trungMa = true;
                    break;
                }
            }
            if (trungMa)
            {
                cout << "Ma nhan vien nay da ton tai!\nVui long nhap lai: ";
                string maMoi;
                while (true)
                {
                    cin >> maMoi;
                    if (maMoi.length() <= 8)
                        break;
                    cout << "Ma nhan vien khong hop le!\nVui long nhap lai: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                dsNV[i].setMaNV(maMoi);
            }
        } while (trungMa);
    }
}

void cQuanLyNVSX::XuatDanhSach()
{
    cout << "\nDANH SACH NHAN VIEN SAN XUAT:\n";
    cout << "----------------------------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        dsNV[i].Xuat();
    }
    cout << "----------------------------------------------------------------------------------------\n";
}

void cQuanLyNVSX::TimNVLuongThapNhat()
{
    if (n == 0)
        return;

    double minLuong = dsNV[0].TinhLuong();
    for (int i = 1; i < n; i++)
    {
        if (dsNV[i].TinhLuong() < minLuong)
        {
            minLuong = dsNV[i].TinhLuong();
        }
    }

    cout << "\nNHAN VIEN CO LUONG THAP NHAT:\n";
    cout << "----------------------------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        if (dsNV[i].TinhLuong() == minLuong)
        {
            dsNV[i].Xuat();
        }
    }
    cout << "----------------------------------------------------------------------------------------\n";
}

double cQuanLyNVSX::TinhTongLuong()
{
    double tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong += dsNV[i].TinhLuong();
    }
    return tong;
}

void cQuanLyNVSX::TimNVTuoiCaoNhat(int namHienTai)
{
    if (n == 0)
        return;

    int maxTuoi = dsNV[0].getTuoi(namHienTai);
    for (int i = 1; i < n; i++)
    {
        if (dsNV[i].getTuoi(namHienTai) > maxTuoi)
        {
            maxTuoi = dsNV[i].getTuoi(namHienTai);
        }
    }

    cout << "\nNHAN VIEN CO TUOI CAO NHAT (" << maxTuoi << " TUOI):\n";
    cout << "----------------------------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        if (dsNV[i].getTuoi(namHienTai) == maxTuoi)
        {
            dsNV[i].Xuat();
        }
    }
    cout << "----------------------------------------------------------------------------------------\n";
}

void cQuanLyNVSX::SapXepTangDanTheoLuong()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (dsNV[i].TinhLuong() > dsNV[j].TinhLuong())
            {
                cNhanVienSX temp = dsNV[i];
                dsNV[i] = dsNV[j];
                dsNV[j] = temp;
            }
        }
    }
    cout << "\nDa sap xep danh sach tang dan theo luong.\n";
}