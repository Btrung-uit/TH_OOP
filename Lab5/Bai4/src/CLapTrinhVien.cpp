#include "../include/CLapTrinhVien.h"
#include "../include/CTienIch.h"
#include <iostream>
using namespace std;

/**
 * @brief Hàm khởi tạo mặc định cho lớp Lập trình viên.
 * @param Không có.
 * @return Không có.
 */
CLapTrinhVien::CLapTrinhVien() : CNhanVien()
{
    GioOvertime = 0;
}

/**
 * @brief Nhập thông tin chi tiết cho nhân viên thuộc vị trí Lập trình viên.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Gọi lại phương thức CNhanVien::Nhap() của lớp cha để thu thập dữ liệu định danh và lương cơ bản.
 *       2. Sử dụng hàm tiện ích NhapSoThucAnToan() để nhận giá trị số giờ làm thêm (Overtime) một cách an toàn từ bàn phím.
 */
void CLapTrinhVien::Nhap()
{
    CNhanVien::Nhap();
    cout << "Nhap gio lam them (Overtime): ";
    GioOvertime = NhapSoThucAnToan();
}

/**
 * @brief Xuất thông tin chi tiết của Lập trình viên ra màn hình Console.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Gọi lại phương thức CNhanVien::Xuat() của lớp cha để hiển thị thông tin nền tảng.
 *       2. In các thuộc tính đặc thù gồm chức vụ, số giờ làm thêm và gọi hàm TinhLuong() kết hợp bộ bổ trợ DinhDangTien() để xuất tổng lương thực nhận.
 */
void CLapTrinhVien::Xuat()
{
    CNhanVien::Xuat();
    cout << "\nChuc vu: Lap trinh vien"
         << " | So gio OT: " << GioOvertime << "h"
         << "\nTong Luong: " << DinhDangTien(TinhLuong()) << " VND\n";
}

/**
 * @brief Tính toán tổng lương thực nhận của Lập trình viên dựa trên số giờ làm thêm.
 * @param Không có.
 * @return Tổng giá trị tiền lương thực nhận dưới dạng số thực (double).
 * @note Giải thuật: Áp dụng công thức tính lương đặc thù cho khối công nghệ:
 *       TongLuong = LuongCoBan + (GioOvertime * 200000). Trong đó 200,000 VND là định mức thù lao cố định cho mỗi giờ OT.
 */
double CLapTrinhVien::TinhLuong()
{
    return LuongCoBan + (GioOvertime * 200000);
}