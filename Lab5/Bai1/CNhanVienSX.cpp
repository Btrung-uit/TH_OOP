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
        if (cin >> giaTri && giaTri)
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

void CNhanVienSX::Nhap()
{
    CNhanVien::Nhap();
    cout << "Nhap luong can ban: ";
    LuongCanBan = KiemTraDauVaoChoDouble();
    cout << "Nhap so san pham: ";
    SoSanPham = NhapSoNguyenAnToan();
}
void CNhanVienSX::TinhLuong()
{
    luong = LuongCanBan + SoSanPham * 5000;
}
void CNhanVienSX::Xuat()
{
    CNhanVien::Xuat();
    cout << "\nLCB: " << LuongCanBan << ", SP: " << SoSanPham << ", Luong: " << fixed << setprecision(0) << luong << " VND\n";
}

double CNhanVienSX::getLuong()
{
    return luong;
}