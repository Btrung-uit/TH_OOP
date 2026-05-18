#include "CCongTy.h"
#include <iostream>
using namespace std;

CCongTy::CCongTy()
{
    DanhSachSX = nullptr;
    SoLuongSX = 0;
    DanhSachVP = nullptr;
    SoLuongVP = 0;
}
CCongTy::~CCongTy()
{
    if (DanhSachSX)
    {
        for (int i = 0; i < SoLuongSX; i++)
        {
            delete DanhSachSX[i];
        }
        delete DanhSachSX;
    }
    if (DanhSachVP)
    {
        for (int i = 0; i < SoLuongVP; i++)
        {
            delete DanhSachVP[i];
        }
        delete DanhSachVP;
    }
}

int CCongTy::NhapSoNguyenAnToan()
{
    int giaTri;
    while (true)
    {
        if (cin >> giaTri && giaTri >= 0)
        {
            char c;
            bool chuoiHopLe = true;
            while (cin.get(c) && c != '\n')
            {
                if (c != ' ' && c != '\t')
                {
                    chuoiHopLe = false;
                }
            }
            if (chuoiHopLe)
            {
                return giaTri;
            }
        }
        cout << "Gia tri khong hop le! Vui long nhap mot so nguyen khong am: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}
void CCongTy::NhapDanhSach()
{
    cout << "Nhap danh sach nhan vien san xuat\n";
    cout << "Nhap so luong nhan vien san xuat: ";
    SoLuongSX = NhapSoNguyenAnToan();
    DanhSachSX = new CNhanVienSX *[SoLuongSX];
    for (int i = 0; i < SoLuongSX; i++)
    {
        cout << "Nhan vien san xuat thu " << i + 1 << ":\n";
        DanhSachSX[i] = new CNhanVienSX();
        DanhSachSX[i]->Nhap();
    }

    cout << "\nNhap danh sach nhan vien van phong\n";
    cout << "Nhap so luong nhan vien van phong: ";
    SoLuongVP = NhapSoNguyenAnToan();
    DanhSachVP = new CNhanVienVP *[SoLuongVP];
    for (int i = 0; i < SoLuongVP; i++)
    {
        cout << "Nhan vien van phong thu " << i + 1 << ":\n";
        DanhSachVP[i] = new CNhanVienVP();
        DanhSachVP[i]->Nhap();
    }
}

void CCongTy::XuatDanhSach()
{
    cout << "\nDanh Sach nhan vien\n";
    cout << "Danh sach nhan vien san xuat\n";
    if (SoLuongSX == 0)
    {
        cout << "Danh sach trong\n";
    }
    for (int i = 0; i < SoLuongSX; i++)
    {
        DanhSachSX[i]->Xuat();
    }

    cout << "\nDanh sach nhan vien van phong\n";
    if (SoLuongVP == 0)
    {
        cout << "Danh sach trong\n";
    }
    for (int i = 0; i < SoLuongVP; i++)
    {
        DanhSachVP[i]->Xuat();
    }
}

void CCongTy::TinhLuong()
{
    for (int i = 0; i < SoLuongSX; i++)
    {
        DanhSachSX[i]->TinhLuong();
    }
    for (int i = 0; i < SoLuongVP; i++)
    {
        DanhSachVP[i]->TinhLuong();
    }
}

double CCongTy::TinhTongLuong()
{
    double TongLuong = 0;
    for (int i = 0; i < SoLuongSX; i++)
    {
        TongLuong += DanhSachSX[i]->getLuong();
    }
    for (int i = 0; i < SoLuongVP; i++)
    {
        TongLuong += DanhSachVP[i]->getLuong();
    }
    return TongLuong;
}

void CCongTy::TimNVSXLuongThapNhat()
{
    if (SoLuongSX == 0)
    {
        cout << "Khong co nhan vien san xuat\n";
        return;
    }
    CNhanVienSX *nvMin = DanhSachSX[0];
    for (int i = 1; i < SoLuongSX; i++)
    {
        if (DanhSachSX[i]->getLuong() < nvMin->getLuong())
        {
            nvMin = DanhSachSX[i];
        }
    }
    cout << "Nhan vien san xuat co muc luong thap nhat la:\n";
    nvMin->Xuat();
}

void CCongTy::TimNVVPTuoiCaoNhat()
{
    if (SoLuongVP == 0)
    {
        cout << "\n[Thong bao] Khong co nhan vien van phong nao trong he thong de so sanh!\n";
        return;
    }

    CNhanVienVP *nvGiaNhat = DanhSachVP[0];
    int namSinhMin = DanhSachVP[0]->GetNgaySinh().getNam();

    for (int i = 1; i < SoLuongVP; i++)
    {
        int namSinhCur = DanhSachVP[i]->GetNgaySinh().getNam();
        if (namSinhCur < namSinhMin)
        {
            namSinhMin = namSinhCur;
            nvGiaNhat = DanhSachVP[i];
        }
    }

    cout << "Nhan vien van phong co tuoi cao nhat la:\n";
    nvGiaNhat->Xuat();
}