#include "../include/CSinhVien.h"
#include "../include/CTienIch.h"
#include <iostream>

using namespace std;

/**
 * @brief Hàm khởi tạo mặc định cho lớp Sinh viên.
 * @param Không có.
 * @return Không có.
 */
CSinhVien::CSinhVien()
{
    MSSV = "";
    HoTen = "";
    DiaChi = "";
    TongTinChi = 0;
    DiemTB = 0.0;
}

/**
 * @brief Hàm hủy đối tượng Sinh viên.
 * @param Không có.
 * @return Không có.
 */
CSinhVien::~CSinhVien() {}

/**
 * @brief Nhập thông tin chi tiết cho một sinh viên từ bàn phím.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Sử dụng getline(cin >> ws, MSSV) và getline(cin >> ws, DiaChi) để thu thập chuỗi dữ liệu mã số, địa chỉ và tự động dọn sạch ký tự xuống dòng tồn đọng.
 *       2. Gọi hàm tiện ích KiemTraTenHopLe() để nhập và chuẩn hóa chuỗi họ tên sinh viên.
 *       3. Gọi các hàm bổ trợ NhapSoNguyenAnToan() và NhapSoThucAnToan() để ép luồng dữ liệu hợp lệ cho số tín chỉ và điểm trung bình tích lũy.
 */
void CSinhVien::Nhap()
{
    cout << "Nhap ma so sinh vien: ";
    getline(cin >> ws, MSSV);

    cout << "Nhap ho ten sinh vien: ";
    HoTen = KiemTraTenHopLe();

    cout << "Nhap dia chi: ";
    getline(cin >> ws, DiaChi);

    cout << "Nhap tong so tin chi tich luy: ";
    while (true)
    {
        TongTinChi = NhapSoNguyenAnToan();
        if (TongTinChi > 0 && TongTinChi <= 250)
        {
            break;
        }
        cout << "So tin chi khong hop le (1 - 250)! Vui long nhap lai: ";
    }

    cout << "Nhap diem trung binh tich luy: ";
    while (true)
    {
        DiemTB = NhapSoThucAnToan();
        if (DiemTB >= 0.0 && DiemTB <= 10.0)
        {
            break;
        }
        cout << "Diem trung binh khong hop le (0.0 - 10.0)! Vui long nhap lai: ";
    }
}

/**
 * @brief Xuất thông tin chi tiết của sinh viên ra màn hình Console.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: In tuần tự các thuộc tính định danh và học tập của sinh viên gồm MSSV, họ tên, địa chỉ, số tín chỉ và điểm trung bình theo cấu hình chuỗi phân tách trực quan.
 */
void CSinhVien::Xuat()
{
    cout << "MSSV: " << MSSV
         << " | Ho ten: " << HoTen
         << "\nDia chi: " << DiaChi
         << " | Tin chi: " << TongTinChi
         << "\nDiem TB: " << DiemTB;
}

/**
 * @brief Lấy giá trị điểm trung bình tích lũy của sinh viên.
 * @param Không có.
 * @return Giá trị điểm trung bình học tập dưới dạng số thực (double).
 */
double CSinhVien::getDiemTB() const
{
    return DiemTB;
}