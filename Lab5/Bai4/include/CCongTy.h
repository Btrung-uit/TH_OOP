#pragma once
#include "CNhanVien.h"

class CCongTy
{
private:
    CNhanVien **DanhSach;
    int SoLuong;

    double TinhLuongTrungBinh() const;

public:
    CCongTy();
    ~CCongTy();

    void NhapDanhSach();                          // a. Nhập danh sách
    void XuatDanhSach() const;                    // b. Xuất danh sách
    void XuatNhanVien_LuongDuoiTrungBinh() const; // c. Lương < Trung bình chung
    void XuatNhanVien_LuongMax() const;           // d. Lương cao nhất (Max)
    void XuatNhanVien_LuongMin() const;           // e. Lương thấp nhất (Min)
    void XuatLapTrinhVien_LuongMax() const;       // f. Dev lương cao nhất
    void XuatKiemChungVien_LuongMin() const;      // g. Tester lương thấp nhất
};