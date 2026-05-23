#include "../include/CGiaoDichCanHo.h"
#include "../include/CGiaoDich.h"
#include "../include/CTienIch.h"
#include <iostream>
using namespace std;

/**
 * @brief Nhập thông tin chi tiết cho giao dịch căn hộ.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Gọi phương thức CGiaoDich::Nhap() của lớp cha để lấy thông tin cơ bản (mã giao dịch, ngày, đơn giá, diện tích).
 *       2. Sử dụng getline(cin >> ws, MaCan) để nhận chuỗi mã căn hộ từ luồng nhập một cách an toàn.
 *       3. Chạy vòng lặp while để kiểm tra điều kiện biến số tầng nhập từ hàm NhapSoNguyenAnToan(), chặn giá trị ViTriTang phải lớn hơn 0.
 */
void CGiaoDichCanHo::Nhap()
{
    CGiaoDich::Nhap();
    cout << "Nhap ma can ho: ";
    getline(cin >> ws, MaCan);
    cout << "Nhap vi tri tang (So nguyen > 0): ";
    while (true)
    {
        ViTriTang = NhapSoNguyenAnToan();
        if (ViTriTang > 0)
        {
            break;
        }
        cout << "So tang khong hop le!\nVui long long nhap lai (> 0): ";
    }
}

/**
 * @brief Tính toán giá trị thành tiền của giao dịch căn hộ dựa trên hệ số tầng.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Áp dụng công thức tính tiền có nhân hệ số ưu tiên vị trí:
 *       - Nếu tầng bằng 1 (Tầng trệt kinh doanh): Nhân thêm hệ số 2.0 (ThanhTien = Diện tích * Đơn giá * 2).
 *       - Nếu tầng từ 15 trở lên (Căn hộ view cao / Penthouse): Nhân thêm hệ số 1.2 (ThanhTien = Diện tích * Đơn giá * 1.2).
 *       - Các tầng trung tâm còn lại: Giữ nguyên giá gốc (ThanhTien = Diện tích * Đơn giá).
 */
void CGiaoDichCanHo::TinhThanhTien()
{
    if (ViTriTang == 1)
    {
        ThanhTien = DienTich * DonGia * 2;
    }
    else if (ViTriTang >= 15)
    {
        ThanhTien = DienTich * DonGia * 1.2;
    }
    else
    {
        ThanhTien = DienTich * DonGia;
    }
}

/**
 * @brief Xuất thông tin chi tiết của giao dịch căn hộ ra màn hình Console.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Gọi phương thức CGiaoDich::Xuat() của lớp cha để hiển thị mốc dữ liệu nền tảng.
 *       2. In các thuộc tính đặc thù gồm mã căn, số tầng và định dạng số chuỗi tiền tệ ThanhTien qua hàm bổ trợ DinhDangTien().
 */
void CGiaoDichCanHo::Xuat()
{
    CGiaoDich::Xuat();
    cout << "\nMa can ho: " << MaCan
         << ", Vi tri tang: " << ViTriTang
         << "\nThanh tien: " << DinhDangTien(ThanhTien)
         << " VND\n";
}