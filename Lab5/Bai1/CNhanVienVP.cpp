#include "CNhanVienVP.h"
#include "CTienIch.h"
#include <iostream>
#include <iomanip>
using namespace std;

/**
 * @brief Nhập thông tin chi tiết cho nhân viên văn phòng.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Gọi lại phương thức Nhap() của lớp cha (CNhanVien) để thu thập các thông tin cơ bản (họ tên, ngày sinh).
 *       2. Sử dụng hàm tiện ích nội bộ NhapSoNguyenAnToan() để nhận số ngày công thực tế từ bàn phím một cách an toàn.
 */
void CNhanVienVP::Nhap()
{
    CNhanVien::Nhap();
    cout << "Nhap so ngay lam viec: ";
    SoNgayLamViec = NhapSoNguyenAnToan();
}

/**
 * @brief Tính toán tổng lương thực nhận của nhân viên văn phòng.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Áp dụng công thức tính lương theo đặc thù khối văn phòng:
 *       luong = SoNgayLamViec * 100000. Trong đó 100,000 VND là định mức tiền công cố định cho một ngày làm việc.
 */
void CNhanVienVP::TinhLuong()
{
    luong = SoNgayLamViec * 100000;
}

/**
 * @brief Xuất thông tin chi tiết của nhân viên văn phòng ra màn hình Console.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Gọi lại phương thức Xuat() của lớp cha (CNhanVien) để hiển thị họ tên và ngày sinh nền tảng.
 *       2. Sử dụng các bộ điều phối luồng `fixed` và `setprecision(0)` để in giá trị thuộc tính luong gọn gàng, làm tròn hàng đơn vị và không kèm phần thập phân rác.
 */
void CNhanVienVP::Xuat()
{
    CNhanVien::Xuat();
    cout << "\nNgay lam viec: " << SoNgayLamViec << ", Luong: " << fixed << setprecision(0) << luong << " VND\n";
}

/**
 * @brief Lấy giá trị tiền lương hiện tại của nhân viên văn phòng.
 * @param Không có.
 * @return Giá trị tổng lương thực nhận dưới dạng số thực (double).
 */
double CNhanVienVP::getLuong()
{
    return luong;
}

/**
 * @brief Lấy thông tin đối tượng ngày sinh của nhân viên văn phòng.
 * @param Không có.
 * @return Đối tượng kiểu cNgay chứa dữ liệu ngày/tháng/năm sinh.
 */
cNgay CNhanVienVP::GetNgaySinh()
{
    return NgaySinh;
}