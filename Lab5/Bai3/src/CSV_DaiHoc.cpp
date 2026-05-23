#include "../include/CSV_DaiHoc.h"
#include "../include/CTienIch.h"
#include <iostream>

using namespace std;

/**
 * @brief Hàm khởi tạo mặc định cho lớp Sinh viên hệ Đại học.
 * @param Không có.
 * @return Không có.
 */
CSV_DaiHoc::CSV_DaiHoc() : CSinhVien()
{
    TenLuanVan = "";
    DiemLuanVan = 0.0;
}

/**
 * @brief Nhập thông tin chi tiết cho sinh viên hệ Đại học từ bàn phím.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Gọi lại phương thức CSinhVien::Nhap() của lớp cha để thu thập dữ liệu định danh và học tập cơ bản.
 *       2. Sử dụng getline(cin >> ws, TenLuanVan) để nhận chuỗi tên luận văn tốt nghiệp và tự động xóa bỏ ký tự xuống dòng còn sót.
 *       3. Chạy vòng lặp vô hạn kết hợp hàm NhapSoThucAnToan() để lấy điểm luận văn, chặn điều kiện điểm số bắt buộc phải nằm trong thang [0.0 - 10.0].
 */
void CSV_DaiHoc::Nhap()
{
    CSinhVien::Nhap();

    cout << "Nhap ten luan van: ";
    getline(cin >> ws, TenLuanVan);

    cout << "Nhap diem bao ve luan van: ";
    while (true)
    {
        DiemLuanVan = NhapSoThucAnToan();

        if (DiemLuanVan >= 0.0 && DiemLuanVan <= 10.0)
        {
            break;
        }
        cout << "Diem khong hop le (0.0 - 10.0)! Vui long nhap lai: ";
    }
}

/**
 * @brief Xuất thông tin chi tiết của sinh viên hệ Đại học ra màn hình Console.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Gọi lại phương thức CSinhVien::Xuat() của lớp cha để hiển thị dữ liệu nền tảng, sau đó in các thuộc tính chuyên sâu gồm TenLuanVan, DiemLuanVan kèm nhãn phân loại hệ đào tạo.
 */
void CSV_DaiHoc::Xuat()
{
    CSinhVien::Xuat();

    cout << " | Luan van: " << TenLuanVan
         << "\nDiem LV: " << DiemLuanVan
         << " | He: Dai hoc\n";
}

/**
 * @brief Kiểm tra xem sinh viên hệ Đại học có đủ điều kiện xét công nhận tốt nghiệp hay không.
 * @param Không có.
 * @return true nếu đủ điều kiện tốt nghiệp, ngược lại trả về false.
 * @note Giải thuật: Trả về trực tiếp kết quả của biểu thức logic điều kiện kết hợp (toán tử &&) theo quy chế Đại học:
 *       - Tổng số tín chỉ tích lũy đạt tối thiểu từ 170 tín chỉ trở lên.
 *       - Điểm trung bình học tập (DiemTB) đạt từ 5.0 trở lên.
 *       - Điểm bảo vệ luận văn tốt nghiệp (DiemLuanVan) đạt từ 5.0 trở lên.
 */
bool CSV_DaiHoc::KiemTraTotNghiep()
{
    return (TongTinChi >= 170 && DiemTB >= 5.0 && DiemLuanVan >= 5.0);
}