#include "../include/CNhanVien.h"
#include "../include/CTienIch.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Hàm khởi tạo mặc định cho lớp Nhân viên (lớp cha).
 * @param Không có.
 * @return Không có.
 */
CNhanVien::CNhanVien()
{
    MaNV = "";
    HoTen = "";
    Tuoi = 0;
    SDT = "";
    Email = "";
    LuongCoBan = 0;
}

/**
 * @brief Hàm hủy mặc định cho lớp Nhân viên (lớp cha).
 * @param Không có.
 * @return Không có.
 */
CNhanVien::~CNhanVien() {}
/**
 * @brief Nhập thông tin nền tảng, định danh cho một nhân viên từ bàn phím.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Sử dụng getline(cin >> ws, MaNV) để nhập mã nhân viên và dọn dẹp ký tự xuống dòng dư thừa trong bộ đệm.
 *       2. Gọi các hàm tiện ích KiemTraTenHopLe(), KiemTraSDTHopLe(), KiemTraEmailHopLe() để nhập và ép luồng dữ liệu đạt chuẩn quy định.
 *       3. Sử dụng vòng lặp while kết hợp NhapSoNguyenAnToan() để nhập tuổi, chặn khoảng biên logic lao động thực tế [18 - 61].
 *       4. Sử dụng vòng lặp while kết hợp NhapSoThucAnToan() để nhập lương, ép điều kiện không nhỏ hơn mức lương tối thiểu vùng pháp định (4.960.000 VND).
 */
void CNhanVien::Nhap()
{
    cout << "Nhap ma nhan vien: ";
    getline(cin >> ws, MaNV);
    cout << "Nhap ho va ten: ";
    HoTen = KiemTraTenHopLe();
    cout << "Nhap tuoi: ";
    while (true)
    {
        Tuoi = NhapSoNguyenAnToan();
        if (Tuoi >= 18 && Tuoi <= 61) // Để phù hợp với luật lao động
        {
            break;
        }
        cout << "Tuoi khong hop le!\nVui long nhap lai: ";
    }
    cout << "Nhap so dien thoai: ";
    SDT = KiemTraSDTHopLe();
    cout << "Nhap Email: ";
    Email = KiemTraEmailHopLe();
    cout << "Nhap luong co ban: ";
    while(true)
    {
        LuongCoBan = NhapSoThucAnToan();
        if (LuongCoBan >= 4960000) // Để phù hợp với luật lao động
        {
            break;
        }
        cout << "Luong co ban khong hop le!\nVui long nhap lai: ";
    }
}

/**
 * @brief Xuất thông tin cơ bản của nhân viên ra màn hình Console.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: In tuần tự các thuộc tính định danh cá nhân và liên lạc, kết hợp gọi hàm bổ trợ DinhDangTien(LuongCoBan) từ lớp tiện ích để hiển thị tiền tệ rõ ràng theo phân tách hàng nghìn.
 */
void CNhanVien::Xuat()
{
    cout << "Ma NV: " << MaNV
         << " | Ho va ten: " << HoTen
         << "\nTuoi: " << Tuoi
         << " | SDT: " << SDT
         << "\nEmail: " << Email
         << " | Luong Co Ban: " << DinhDangTien(LuongCoBan);
}