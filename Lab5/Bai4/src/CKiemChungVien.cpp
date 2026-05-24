#include "../include/CKiemChungVien.h"
#include "../include/CTienIch.h"
#include <iostream>
using namespace std;

/**
 * @brief Hàm khởi tạo mặc định cho lớp Kiểm chứng viên (Tester).
 * @param Không có.
 * @return Không có.
 */

CKiemChungVien::CKiemChungVien() : CNhanVien()
{
    SoLoi = 0;
}

/**
 * @brief Nhập thông tin chi tiết cho nhân viên thuộc vị trí Kiểm chứng viên.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Gọi lại phương thức CNhanVien::Nhap() của lớp cha để thu thập dữ liệu định danh và lương cơ bản.
 *       2. Sử dụng hàm tiện ích NhapSoNguyenAnToan() để nhận giá trị số lượng lỗi phát hiện (SoLoi) một cách an toàn từ bàn phím.
 */
void CKiemChungVien::Nhap()
{
    CNhanVien::Nhap();
    cout << "Nhap so loi phat hien: ";
    SoLoi = NhapSoNguyenAnToan();
}

/**
 * @brief Xuất thông tin chi tiết của Kiểm chứng viên ra màn hình Console.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Gọi lại phương thức CNhanVien::Xuat() của lớp cha để hiển thị thông tin nền tảng.
 *       2. In các thuộc tính đặc thù gồm chức vụ, số lỗi tìm thấy và gọi hàm TinhLuong() kết hợp bộ bổ trợ DinhDangTien() để xuất tổng lương thực nhận.
 */
void CKiemChungVien::Xuat()
{
    CNhanVien::Xuat();
    cout << "\nChuc vu: Kiem chung vien"
         << " | So loi: " << SoLoi
         << "\nTong luong: " << DinhDangTien(TinhLuong()) << " VND\n";
}

/**
 * @brief Tính toán tổng lương thực nhận của Kiểm chứng viên dựa trên số lỗi phát hiện.
 * @param Không có.
 * @return Tổng giá trị tiền lương thực nhận dưới dạng số thực (double).
 * @note Giải thuật: Áp dụng công thức tính thưởng theo hiệu suất kiểm thử (Bug Bounty):
 *       TongLuong = LuongCoBan + (SoLoi * 50000.0). Trong đó 50,000 VND là định mức tiền thưởng cố định cho mỗi lỗi/bug phát hiện thành công.
 */
double CKiemChungVien::TinhLuong()
{
    return LuongCoBan + (SoLoi * 50000.0);
}