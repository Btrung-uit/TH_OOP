#pragma once
#include "Diem.h"
class cTamGiac
{
private:
    Diem a, b, c;

public:
    cTamGiac();
    cTamGiac(Diem, Diem, Diem);
    ~cTamGiac(void);
    void Nhap();
    void Xuat();
    void KiemTraLoaiTamGiac();
    void TinhChuVi();
    void TinhDienTich();
    void TinhTien();
    void Quay();
    void PhongTo();
    void ThuNho();
};