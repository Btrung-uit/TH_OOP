#include <iostream>
#include "../include/CCongTy.h"

using namespace std;

int main()
{
    CCongTy congTy;

    // Yêu cầu 1: Nhập danh sách nhân viên sản xuất, danh sách nhân viên văn phòng
    congTy.NhapDanhSach();

    // Yêu cầu 2: Tính lương cho từng nhân viên
    congTy.TinhLuong();

    // Yêu cầu 3: Xuất thông tin danh sách các nhân viên
    congTy.XuatDanhSach();

    // Yêu cầu 4: Tính tổng lương mà công ty phải trả cho các nhân viên
    cout << "\n---------------------------------------------\n";
    cout << "Tong luong cong ty phai tra: " << (long long)congTy.TinhTongLuong() << " VND\n";
    cout << "---------------------------------------------\n\n";

    // Yêu cầu 5: Cho biết nhân viên sản xuất nào có lương thấp nhất
    congTy.TimNVSXLuongThapNhat();

    // Yêu cầu 6: Cho biết nhân viên văn phòng nào có tuổi cao nhất
    congTy.TimNVVPTuoiCaoNhat();

    return 0;
}