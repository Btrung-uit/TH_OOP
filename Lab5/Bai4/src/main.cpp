#include <iostream>
#include "../include/CCongTy.h"

using namespace std;

int main()
{
    CCongTy cty;
    cty.NhapDanhSach();
    cty.XuatDanhSach();
    cty.XuatNhanVien_LuongDuoiTrungBinh();
    cty.XuatNhanVien_LuongMax();
    cty.XuatNhanVien_LuongMin();
    cty.XuatLapTrinhVien_LuongMax();
    cty.XuatKiemChungVien_LuongMin();
    return 0;
}