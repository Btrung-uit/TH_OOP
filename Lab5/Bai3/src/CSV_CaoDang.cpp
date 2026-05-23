#include "../include/CSV_CaoDang.h"
#include "../include/CTienIch.h"
#include <iostream>

using namespace std;

/**
 * @brief Hàm khởi tạo mặc định cho lớp Sinh viên hệ Cao đẳng.
 * @param Không có.
 * @return Không có.
 */
CSV_CaoDang::CSV_CaoDang() : CSinhVien()
{
    DiemThiTotNghiep = 0.0;
}

/**
 * @brief Nhập thông tin chi tiết cho sinh viên hệ Cao đẳng.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Gọi lại phương thức CSinhVien::Nhap() của lớp cha để thu thập dữ liệu định danh và học tập cơ bản.
 *       2. Chạy vòng lặp vô hạn kết hợp hàm NhapSoThucAnToan() để lấy điểm thi tốt nghiệp.
 *       3. Chặn điều kiện số học: Điểm số bắt buộc phải nằm trong thang điểm chuẩn [0.0 - 10.0] mới cho phép thoát vòng lặp.
 */
void CSV_CaoDang::Nhap()
{
    CSinhVien::Nhap();

    cout << "Nhap diem thi tot nghiep: ";
    while (true)
    {
        DiemThiTotNghiep = NhapSoThucAnToan();

        if (DiemThiTotNghiep >= 0.0 && DiemThiTotNghiep <= 10.0)
        {
            break;
        }
        cout << "Diem khong hop le (0.0 - 10.0)! Vui long nhap lai: ";
    }
}

/**
 * @brief Xuất thông tin chi tiết của sinh viên hệ Cao đẳng ra màn hình Console.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Gọi lại phương thức CSinhVien::Xuat() của lớp cha để in các thông số nền tảng, sau đó hiển thị thêm thuộc tính đặc thù DiemThiTotNghiep kèm nhãn phân loại hệ đào tạo.
 */
void CSV_CaoDang::Xuat()
{
    CSinhVien::Xuat();

    cout << " | Diem thi TN: " << DiemThiTotNghiep
         << " | He: Cao Dang\n";
}

/**
 * @brief Kiểm tra xem sinh viên hệ Cao đẳng có đủ điều kiện xét công nhận tốt nghiệp hay không.
 * @param Không có.
 * @return true nếu đủ điều kiện tốt nghiệp, ngược lại trả về false.
 * @note Giải thuật: Áp dụng quy chế đào tạo khối Cao đẳng thông qua mệnh đề logic kết hợp đồng thời (toán tử &&):
 *       - Tổng số tín chỉ tích lũy đạt tối thiểu từ 120 tín chỉ trở lên.
 *       - Điểm trung bình học tập (DiemTB) đạt từ 5.0 trở lên.
 *       - Điểm thi tốt nghiệp khóa luận/môn chuyên môn (DiemThiTotNghiep) đạt từ 5.0 trở lên.
 */
bool CSV_CaoDang::KiemTraTotNghiep()
{
    if (TongTinChi >= 120 && DiemTB >= 5.0 && DiemThiTotNghiep >= 5.0)
    {
        return true;
    }
    return false;
}