#include "CNhanVienSX.h"
#include "CTienIch.h"
#include <iostream>
#include <iomanip>
using namespace std;
/**
 * @brief Nhập và ép luồng dữ liệu số thực dương, loại bỏ hoàn
 *        toàn các ký tự rác đi kèm.
 * @param Không có.
 * @return giaTri: double.
 * @note Giải thuật:
 *       1. Sử dụng vòng lặp vô hạn và đọc dữ liệu thông qua toán
 *          tử cin >> giaTri.
 *       2. Sử dụng cin.get(c) để quét từng ký tự còn lại trên
 *          cùng một dòng cho đến khi gặp ký tự xuống dòng (\n).
 *       3. Nếu phát hiện bất kỳ ký tự nào không phải khoảng trắng
 *          (' ') hoặc tab ('\t'), gán cờ chuoiHopLe = false để
 *          đánh dấu dòng nhập chứa ký tự rác
 *          (Ví dụ: nhập "3.14abc").
 *       4. Nếu chuỗi hợp lệ, thoát hàm để lưu giá trị. Ngược lại,
 *          tiến hành xóa cờ lỗi của stream, dọn sạch bộ nhớ đệm
 *          và yêu cầu người dùng nhập lại.
 */
double KiemTraDauVaoChoDouble()
{
    double giaTri;
    while (true)
    {
        if (cin >> giaTri && giaTri >= 0)
        {
            bool chuoiHopLe = true;
            char c;
            while (cin.get(c) && c != '\n')
            {
                if (c != ' ' && c != '\t')
                {
                    chuoiHopLe = false;
                }
            }

            if (chuoiHopLe)
            {
                return giaTri;
            }
            cout << "Gia tri khong hop le!\nVui long nhap so thuc duong!\nNhap lai: ";
            continue;
        }
        cout << "Gia tri khong hop le!\nVui long nhap so thuc duong!\nNhap lai: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

/**
 * @brief Nhập thông tin chi tiết cho nhân viên sản xuất.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Gọi lại phương thức Nhap() của lớp cha (CNhanVien) để thu thập các thông tin cơ bản (như họ tên, mã số).
 *       2. Sử dụng hàm KiemTraDauVaoChoDouble() để nhập và ép tính hợp lệ cho thuộc tính LuongCanBan.
 *       3. Sử dụng hàm NhapSoNguyenAnToan() từ thư viện tiện ích để nhận giá trị an toàn cho SoSanPham.
 */
void CNhanVienSX::Nhap()
{
    CNhanVien::Nhap();
    cout << "Nhap luong can ban: ";
    LuongCanBan = KiemTraDauVaoChoDouble();
    cout << "Nhap so san pham: ";
    SoSanPham = NhapSoNguyenAnToan();
}

/**
 * @brief Tính toán tổng lương thực nhận của nhân viên sản xuất.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Áp dụng công thức tính lương theo đặc thù sản xuất:
 *       luong = LuongCanBan + (SoSanPham * 5000). Trong đó 5,000 VND là đơn giá cố định trên mỗi sản phẩm.
 */
void CNhanVienSX::TinhLuong()
{
    luong = LuongCanBan + SoSanPham * 5000;
}

/**
 * @brief Xuất thông tin chi tiết của nhân viên sản xuất ra màn hình.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Gọi lại phương thức Xuat() của lớp cha (CNhanVien) để hiển thị thông tin nền tảng.
 *       2. Sử dụng bộ điều phối `fixed` và `setprecision(0)` để định dạng chuỗi hiển thị tiền lương tròn số, không kèm phần thập phân nhằm tối ưu giao diện.
 */
void CNhanVienSX::Xuat()
{
    CNhanVien::Xuat();
    cout << "\nLCB: " << LuongCanBan << ", SP: " << SoSanPham << ", Luong: " << fixed << setprecision(0) << luong << " VND\n";
}

/**
 * @brief Lấy giá trị tiền lương đã tính của nhân viên.
 * @param Không có.
 * @return Giá trị tổng lương thực nhận (double).
 */
double CNhanVienSX::getLuong()
{
    return luong;
}