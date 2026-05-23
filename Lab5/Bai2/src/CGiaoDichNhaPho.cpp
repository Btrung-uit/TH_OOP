#include "../include/CGiaoDichNhaPho.h"
#include "../include/CGiaoDich.h"
#include "../include/CTienIch.h"
#include <iostream>
using namespace std;

/**
 * @brief Nhập thông tin chi tiết cho giao dịch nhà phố.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Gọi phương thức CGiaoDich::Nhap() của lớp cha để lấy thông tin cơ bản (mã giao dịch, ngày, đơn giá, diện tích).
 *       2. Sử dụng vòng lặp vô hạn kết hợp hàm NhapSoNguyenAnToan() để bắt lựa chọn loại nhà. Nếu chọn 1 gán chuỗi "Cao cap", chọn 2 gán chuỗi "Thuong".
 *       3. Sử dụng vòng lặp thứ hai kết hợp getline(cin >> ws, DiaChi) để nhập chuỗi địa chỉ nhà phố, ép người dùng không được để trống dữ liệu.
 */
void CGiaoDichNhaPho::Nhap()
{
    CGiaoDich::Nhap();
    cout << "Nhap loai nha:\n1: Cao cap\n2: Thuong\nVui long nhap 1 hoac 2: ";
    int choose;
    while (true)
    {
        choose = NhapSoNguyenAnToan();
        if (choose == 1 || choose == 2)
        {
            LoaiNha = (choose == 1 ? "Cao cap" : "Thuong");
            break;
        }
        cout << "Lua chon khong hop le!\nVui long nhap 1 hoac 2: ";
    }
    cout << "Nhap dia chi: ";
    while (true)
    {
        getline(cin >> ws, DiaChi);
        if (DiaChi != "")
        {
            break;
        }
        cout << "Dia chi khong duoc de trong! Vui long nhap lai: ";
    }
}

/**
 * @brief Tính toán giá trị thành tiền của giao dịch nhà phố dựa trên phân loại chất lượng nhà.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Áp dụng công thức tính tiền dựa trên chất lượng phân cấp tài sản:
 *       - Nếu là nhà "Cao cap": Tính theo giá trị thực tế của diện tích nhân đơn giá gốc (ThanhTien = DienTich * DonGia).
 *       - Nếu là nhà "Thuong": Được áp dụng chính sách giảm trừ chiết khấu chi phí xây dựng hạ tầng, nhân thêm hệ số 0.9 (ThanhTien = DienTich * DonGia * 0.9).
 */
void CGiaoDichNhaPho::TinhThanhTien()
{
    if (LoaiNha == "Cao cap")
    {
        ThanhTien = DienTich * DonGia;
    }
    else
    {
        ThanhTien = DienTich * DonGia * 0.9;
    }
}

/**
 * @brief Xuất thông tin chi tiết của giao dịch nhà phố ra màn hình Console.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Gọi phương thức CGiaoDich::Xuat() của lớp cha để hiển thị các thông số nền tảng.
 *       2. In thông tin phân loại chất lượng nhà, địa chỉ cư trú và hiển thị giá trị ThanhTien qua bộ xử lý phân tách chữ số hàng nghìn DinhDangTien().
 */
void CGiaoDichNhaPho::Xuat()
{
    CGiaoDich::Xuat();
    cout << "\nLoai nha: " << LoaiNha
         << ", Dia chi: " << DiaChi
         << "\nThanh tien: " << DinhDangTien(ThanhTien)
         << " VND\n";
}