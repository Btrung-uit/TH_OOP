#pragma once
#include "Diem.h"
class cDaGiac
{
private:
    int n;
    Diem *dsDiem;

public:
    cDaGiac();
    cDaGiac(int soDinh);
    ~cDaGiac();
    void Nhap();
    void Xuat();
    void KiemTraLoaiDaGiac();
    void TinhChuVi();
    void TinhDienTich();
    void TinhTien();
    void Quay();
    void PhongTo();
    void ThuNho();
};