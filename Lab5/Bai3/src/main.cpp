#include <iostream>
#include "../include/CQuanLyUIT.h"

using namespace std;

int main()
{
    CQuanLyUIT ucl;
    ucl.NhapDanhSach();
    ucl.XuatDanhSach();
    ucl.XuatDS_DuDieuKienTotNghiep();
    ucl.XuatDS_KhongDuDieuKienTotNghiep();
    ucl.TimSVDaiHoc_DiemMax();
    ucl.TimSVCaoDang_DiemMax();
    ucl.ThongKeKhongTotNghiepTungHe();
    return 0;
}