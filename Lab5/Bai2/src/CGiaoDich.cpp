#include "../include/CGiaoDich.h"
#include "../include/CTienIch.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Hàm khởi tạo mặc định cho lớp Giao dịch (lớp cha).
 * @param Không có.
 * @return Không có.
 */
CGiaoDich::CGiaoDich()
{
    MaGiaoDich = "";
    DonGia = 0;
    DienTich = 0;
    ThanhTien = 0;
}

/**
 * @brief Hàm hủy đối tượng Giao dịch.
 * @param Không có.
 * @return Không có.
 */
CGiaoDich::~CGiaoDich() {}

/**
 * @brief Nhập thông tin cơ bản cho một giao dịch bất động sản.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Sử dụng getline(cin >> ws, MaGiaoDich) để nhập chuỗi mã giao dịch và tự động loại bỏ các ký tự khoảng trắng thừa đầu dòng.
 *       2. Gọi phương thức Nhap() của thuộc tính NgayGiaoDich (đối tượng lớp cNgay) để nhập mốc thời gian thực hiện giao dịch.
 *       3. Lần lượt gọi hàm tiện ích NhapSoThucAnToan() để thu thập dữ liệu số thực không âm cho thuộc tính DonGia và DienTich.
 */
void CGiaoDich::Nhap()
{
    cout << "Nhap ma giao dich: ";
    getline(cin >> ws, MaGiaoDich);
    cout << "Nhap ngay giao dich:\n";
    NgayGiaoDich.Nhap();
    cout << "Nhap don gia (VND): ";
    DonGia = NhapSoThucAnToan();
    cout << "Nhap dien tich (m^2): ";
    DienTich = NhapSoThucAnToan();
}

/**
 * @brief Xuất thông tin nền tảng của giao dịch ra màn hình Console.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Hiển thị mã giao dịch và gọi phương thức Xuat() nội tại của đối tượng NgayGiaoDich để in mốc thời gian.
 *       2. Gọi hàm bổ trợ DinhDangTien(DonGia) để định dạng chuỗi phân tách chữ số hàng nghìn cho tiền tệ, kết hợp in thông số diện tích theo quy chuẩn đơn vị m^2.
 */
void CGiaoDich::Xuat()
{
    cout << "Ma giao dich: " << MaGiaoDich << ", Ngay giao dich: ";
    NgayGiaoDich.Xuat();
    cout << "\nDon gia: " << DinhDangTien(DonGia) << " VND/m^2, Dien tich: " << DienTich << " m^2";
}

/**
 * @brief Lấy giá trị thành tiền của giao dịch.
 * @param Không có.
 * @return Giá trị tổng tiền tính toán của giao dịch (double).
 */
double CGiaoDich::getThanhTien() const
{
    return ThanhTien;
}

/**
 * @brief Lấy thông tin đối tượng ngày thực hiện giao dịch.
 * @param Không có.
 * @return Đối tượng kiểu cNgay chứa dữ liệu ngày/tháng/năm diễn ra giao dịch.
 */
cNgay CGiaoDich::getNgayGiaoDich() const
{
    return NgayGiaoDich;
}