#pragma once
#include "Diem.h"
class cDaGiac
{
private:
    int n;
    Diem *dsDiem;
    bool KiemTraTatCaThangHang();

public:
    cDaGiac();
    cDaGiac(int soDinh);
    ~cDaGiac();
    void Nhap();
    void Xuat();
    void SapXepCacDinh();
    void KiemTraLoaiDaGiac();
    void TinhChuVi();
    void TinhDienTich();
    void TinhTien();
    void Quay();
    void PhongTo();
    void ThuNho();
};