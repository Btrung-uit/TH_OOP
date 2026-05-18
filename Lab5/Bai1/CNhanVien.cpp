#include "CNhanVien.h"
#include <iostream>
using namespace std;
/**
 * @brief Kiểm tra tính hợp lệ của họ tên (Chuẩn hóa tên).
 * @param ten: Tham chiếu đến chuỗi họ tên cần kiểm tra.
 * @return true nếu tên hợp lệ, false nếu vi phạm quy tắc.
 * @note Giải thuật:
 *       1. Kiểm tra độ dài (không trống và không quá 26 ký tự).
 *       2. Kiểm tra khoảng trắng ở đầu/cuối chuỗi hoặc có 2 khoảng trắng liên tiếp.
 *       3. Kiểm tra ký tự đặc biệt/số: Chỉ cho phép chữ cái A-Z, a-z và khoảng trắng.
 *       4. Kiểm tra quy tắc viết hoa: Chữ cái đầu mỗi từ phải viết hoa, các chữ sau
 *          phải viết thường.
 */
bool KiemTraTen(string &ten)
{ // Kiểm tra tính hợp lệ của tên
    int lenght = ten.length();
    if (lenght > 26 || lenght == 0)
        return false; // Kiểm tra độ dài
    if (ten[0] == ' ' || ten[lenght - 1] == ' ')
        return false; // kiểm tra đầu chuỗi có dấu cách hay cuối chuỗi có dấu cách không
    for (int i = 0; ten[i] != '\0'; i++)
    {
        if (ten[i] == ' ')
        {
            if (i + 1 < lenght && ten[i + 1] == ' ')
                return false; // Kiểm tra có nhiều dấu cách trong tên hay không
            continue;
        }
        if ((ten[i] < 'A' || ten[i] > 'Z') && (ten[i] < 'a' || ten[i] > 'z'))
            return false;                            // kiểm tra xem có kí tự đặc biệt hay số không
        bool chuDau = (i == 0 || ten[i - 1] == ' '); // đặt cờ cho chữ đầu
        if (chuDau)
        { // nếu là chữ đầu kiểm tra xem có viết hoa không
            if (ten[i] < 'A' || ten[i] > 'Z')
                return false;
        }
        else
        {
            if (ten[i] < 'a' || ten[i] > 'z')
                return false; // nếu chữ bình thường kiểm tra xem có viết thường không
        }
    }
    return true;
}

CNhanVien::CNhanVien()
{
    HoTen = "";
    luong = 0;
}
CNhanVien::~CNhanVien() {}
void CNhanVien::Nhap()
{
    cout << "Nhap Ho ten (toi da 26 ki tu): ";
    while (true)
    {
        getline(cin >> ws, HoTen);
        if (KiemTraTen(HoTen))
            break;
        cout << "Ho ten khong hop le!\nVui long nhap lai: ";
    }
    cout << "Nhap ngay sinh:\n";
    NgaySinh.Nhap();
}
void CNhanVien::Xuat()
{
    cout << "Ho ten: " << HoTen << ", Ngay sinh: ";
    NgaySinh.Xuat();
}
cNgay CNhanVien::getNgaySinh() const
{
    return NgaySinh;
}