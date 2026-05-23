#include "../include/CCongTy.h"
#include "../include/CGiaoDich.h"
#include "../include/CGiaoDichDat.h"
#include "../include/CGiaoDichNhaPho.h"
#include "../include/CGiaoDichCanHo.h"
#include "../include/CTienIch.h"
#include <iostream>
using namespace std;

CCongTy::CCongTy()
{
    DanhSachGD = nullptr;
    SoLuongGD = 0;
}

CCongTy::~CCongTy()
{
    if (DanhSachGD)
    {
        for (int i = 0; i < SoLuongGD; i++)
        {
            delete DanhSachGD[i];
        }
        delete[] DanhSachGD;
    }
}

void CCongTy::NhapDanhSach()
{
    cout << "Nhap so luong giao dich: ";
    SoLuongGD = NhapSoNguyenAnToan();

    DanhSachGD = new CGiaoDich *[SoLuongGD];
    cout << "--Tien hanh giao dich---\n";
    cout << "Cac lua chon giao dich:\n1: Giao dich Dat\n2: Giao dich Nha pho\n3: Giao dich can ho chung cu\n";
    for (int i = 0; i < SoLuongGD; i++)
    {
        cout << "---Giao dich thu " << i + 1 << "---\n";
        cout << "Nhap lua chon: ";
        int choose;
        while (true)
        {
            choose = NhapSoNguyenAnToan();
            if (choose >= 1 && choose <= 3)
            {
                break;
            }
            cout << "Lua chon khong hop le!\nVui long nhap lai (1->3): ";
        }
        if (choose == 1)
        {
            DanhSachGD[i] = new CGiaoDichDat();
        }
        else if (choose == 2)
        {
            DanhSachGD[i] = new CGiaoDichNhaPho();
        }
        else
        {
            DanhSachGD[i] = new CGiaoDichCanHo();
        }
        DanhSachGD[i]->Nhap();
    }
    for (int i = 0; i < SoLuongGD; i++)
    {
        DanhSachGD[i]->TinhThanhTien();
    }
}

void CCongTy::XuatDanhSach()
{
    cout << "\n---Danh sach giao dich---\n";
    if (SoLuongGD == 0)
    {
        cout << "Danh sach rong!\n";
        return;
    }
    cout << "===Giao dich dat===\n";
    for (int i = 0; i < SoLuongGD; i++)
    {
        if (dynamic_cast<CGiaoDichDat *>(DanhSachGD[i]) != nullptr)
        {
            DanhSachGD[i]->Xuat();
        }
    }

    cout << "===Giao dich nha pho===\n";
    for (int i = 0; i < SoLuongGD; i++)
    {
        if (dynamic_cast<CGiaoDichNhaPho *>(DanhSachGD[i]) != nullptr)
        {
            DanhSachGD[i]->Xuat();
        }
    }

    cout << "===Giao dich can ho===\n";
    for (int i = 0; i < SoLuongGD; i++)
    {
        if (dynamic_cast<CGiaoDichCanHo *>(DanhSachGD[i]) != nullptr)
        {
            DanhSachGD[i]->Xuat();
        }
    }
}

void CCongTy::ThongKeSoLuongTungLoai()
{
    cout << "\n---Danh sach so luong giao dich---\n";
    if (SoLuongGD == 0)
    {
        cout << "Danh sach rong!\n";
        return;
    }
    cout << "So luong giao dich dat: ";
    int count = 0;
    for (int i = 0; i < SoLuongGD; i++)
    {
        if (dynamic_cast<CGiaoDichDat *>(DanhSachGD[i]) != nullptr)
        {
            count++;
        }
    }
    cout << count << "\n";
    cout << "So luong giao dich nha pho: ";
    count = 0;
    for (int i = 0; i < SoLuongGD; i++)
    {
        if (dynamic_cast<CGiaoDichNhaPho *>(DanhSachGD[i]) != nullptr)
        {
            count++;
        }
    }
    cout << count << "\n";
    cout << "So luong giao dich can ho: ";
    count = 0;
    for (int i = 0; i < SoLuongGD; i++)
    {
        if (dynamic_cast<CGiaoDichCanHo *>(DanhSachGD[i]) != nullptr)
        {
            count++;
        }
    }
    cout << count << "\n";
}

double CCongTy::TinhTrungBinhThanhTienCuaCanHo()
{
    cout << "\n--Tinh trung binh thanh tien can ho---\n";
    double sum = 0;
    int count = 0;
    for (int i = 0; i < SoLuongGD; i++)
    {
        if (dynamic_cast<CGiaoDichCanHo *>(DanhSachGD[i]) != nullptr)
        {
            sum += DanhSachGD[i]->getThanhTien();
            count++;
        }
    }
    if (count == 0)
    {
        return -1;
    }
    else
    {
        return sum / count;
    }
}

void CCongTy::NhaPhoGiaTriCaoNhat()
{
    cout << "\n---Giao dich nha pho co gia tri cao nhat---\n";
    if (SoLuongGD == 0)
    {
        cout << "Danh sach rong!\n\n";
        return;
    }
    CGiaoDich *temp = DanhSachGD[0];
    bool isFound = false;
    if (dynamic_cast<CGiaoDichNhaPho *>(temp) != nullptr)
    {
        isFound = true;
    }
    for (int i = 1; i < SoLuongGD; i++)
    {
        if (dynamic_cast<CGiaoDichNhaPho *>(DanhSachGD[i]) != nullptr)
        {
            if (DanhSachGD[i]->getThanhTien() > temp->getThanhTien())
            {
                isFound = true;
                temp = DanhSachGD[i];
            }
        }
    }
    if (isFound)
    {
        for (int i = 0; i < SoLuongGD; i++)
        {
            if (dynamic_cast<CGiaoDichNhaPho *>(DanhSachGD[i]) != nullptr)
            {
                if (DanhSachGD[i]->getThanhTien() == temp->getThanhTien())
                {
                    DanhSachGD[i]->Xuat();
                    cout << "\n";
                }
            }
        }
    }
    else
    {
        cout << "Khong co giao dich nha pho!\n\n";
    }
}

void CCongTy::XuatDanhSachThang12Nam2024()
{
    cout << "---Danh sach giao dich Thang 12 Nam 2024---\n";
    if (SoLuongGD == 0)
    {
        cout << "Danh sach rong!\n";
        return;
    }
    bool isFound = false;
    for (int i = 0; i < SoLuongGD; i++)
    {
        if (DanhSachGD[i]->getNgayGiaoDich().getNam() == 2024 && DanhSachGD[i]->getNgayGiaoDich().getThang() == 12)
        {
            isFound = true;
            DanhSachGD[i]->Xuat();
            cout << "\n";
        }
    }
    if (!isFound)
    {
        cout << "Khong co giao dich nao o thang 12 nam 2024\n";
    }
}