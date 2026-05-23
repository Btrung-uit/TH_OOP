#include "../include/CGiaoDichDat.h"
#include "../include/CTienIch.h"
#include <iostream>
#include <cctype>
using namespace std;

/**
 * @brief Nhập thông tin chi tiết cho giao dịch đất nền.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Gọi phương thức CGiaoDich::Nhap() của lớp cha để thu thập dữ liệu nền tảng (mã giao dịch, ngày, đơn giá, diện tích).
 *       2. Chạy vòng lặp while nhận ký tự loại đất và sử dụng hàm toupper() để tự động chuyển đổi sang chữ hoa (chuẩn hóa dữ liệu).
 *       3. Kiểm tra ký tự nhập vào; nếu thuộc tập hợp {'A', 'B', 'C'} thì thoát vòng lặp, ngược lại tiến hành xóa cờ lỗi luồng, dọn bộ nhớ đệm và yêu cầu nhập lại.
 */
void CGiaoDichDat::Nhap()
{
    CGiaoDich::Nhap();
    cout << "Nhap loai dat (A, B, C): ";
    while (cin >> LoaiDat)
    {
        LoaiDat = toupper(LoaiDat);
        if (LoaiDat == 'A' || LoaiDat == 'B' || LoaiDat == 'C')
        {
            break;
        }
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Loai dat khong hop le!\nVui long nhap lai (A, B, C): ";
    }
}

/**
 * @brief Tính toán giá trị thành tiền của giao dịch đất dựa trên phân loại đất.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Áp dụng công thức tính tiền dựa trên hệ số giá trị loại đất:
 *       - Nếu là Đất loại A (vị trí đắc địa): Nhân thêm hệ số 1.5 (ThanhTien = Diện tích * Đơn giá * 1.5).
 *       - Nếu là Đất loại B hoặc C: Tính theo đơn giá gốc không nhân hệ số (ThanhTien = Diện tích * DonGia).
 */
void CGiaoDichDat::TinhThanhTien()
{
    if (LoaiDat == 'A')
    {
        ThanhTien = DienTich * DonGia * 1.5;
    }
    else
    {
        ThanhTien = DienTich * DonGia;
    }
}

/**
 * @brief Xuất thông tin chi tiết của giao dịch đất nền ra màn hình Console.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Gọi phương thức CGiaoDich::Xuat() của lớp cha để hiển thị các thông số cơ bản.
 *       2. In thông tin phân loại đất hiện tại và chuỗi giá trị ThanhTien đã qua bộ xử lý phân tách chữ số hàng nghìn DinhDangTien().
 */
void CGiaoDichDat::Xuat()
{
    CGiaoDich::Xuat();
    cout << "\nLoai dat: " << LoaiDat
         << ", Thanh tien: " << DinhDangTien(ThanhTien)
         << " VND\n";
}