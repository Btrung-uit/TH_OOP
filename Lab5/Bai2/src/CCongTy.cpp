#include "CCongTy.h"
#include "CGiaoDich.h"
#include "CGiaoDichDat.h"
#include "CGiaoDichNhaPho.h"
#include "CGiaoDichCanHo.h"
#include "CTienIch.h"
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
}

void CCongTy::XuatDanhSach()
{
    if (SoLuongGD == 0)
    {
        cout << "Danh sach rong!\n";
        return;
    }
    cout << "---Danh sach giao dich---\n";
    cout << "\n===Giao dich dat===\n";
    for (int i = 0; i < SoLuongGD; i++)
    {
        if (dynamic_cast<CGiaoDichDat *>(DanhSachGD[i]) != nullptr)
        {
            DanhSachGD[i]->Xuat();
        }
    }

    cout << "\n===Giao dich nha pho===\n";
    for (int i = 0; i < SoLuongGD; i++)
    {
        if (dynamic_cast<CGiaoDichNhaPho *>(DanhSachGD[i]) != nullptr)
        {
            DanhSachGD[i]->Xuat();
        }
    }

    cout << "\n===Giao dich can ho===\n";
    for (int i = 0; i < SoLuongGD; i++)
    {
        if (dynamic_cast<CGiaoDichCanHo *>(DanhSachGD[i]) != nullptr)
        {
            DanhSachGD[i]->Xuat();
        }
    }
}