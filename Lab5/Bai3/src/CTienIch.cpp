#include "../include/CTienIch.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Nhập và ép luồng dữ liệu số nguyên lớn hơn hoặc bằng 0,
 *        chặn các ký tự rác đi kèm.
 * @param Không có.
 * @return Giá trị số nguyên hợp lệ duy nhất trích xuất được
 *         từ dòng nhập.
 * @note Giải thuật:
 *       1. Sử dụng vòng lặp vô hạn để ép nhập đúng kiểu dữ liệu.
 *       2. Dùng hàm cin.peek() để quét kiểm tra toàn bộ các ký tự
 *          còn lại trên dòng sau số nguyên.
 *       3. Nếu phát hiện ký tự rác (không phải khoảng trắng, tab
 *          hay xuống dòng), đánh dấu chuỗi không hợp lệ và ép
 *          nhập lại.
 *       4. Dọn sạch cờ lỗi và bộ nhớ đệm luồng nếu dữ liệu sai
 *          quy chuẩn.
 */
int NhapSoNguyenAnToan()
{
    int giaTri;
    while (true)
    {
        if (cin >> giaTri && giaTri >= 0)
        {
            bool chuoiHopLe = true;
            char c;
            while (true)
            {
                c = cin.peek();
                if (c == '\n' || c == EOF)
                    break;
                if (c != ' ' && c != '\t')
                    chuoiHopLe = false;
                cin.get();
            }
            if (chuoiHopLe)
            {
                if (cin.peek() == '\n')
                    cin.get();
                return giaTri;
            }
        }
        cout << "Loi! Vui long nhap so nguyen duong!\nNhap lai: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

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
double NhapSoThucAnToan()
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
{
    int lenght = ten.length();
    if (lenght > 26 || lenght == 0)
        return false;
    if (ten[0] == ' ' || ten[lenght - 1] == ' ')
        return false;
    for (int i = 0; ten[i] != '\0'; i++)
    {
        if (ten[i] == ' ')
        {
            if (i + 1 < lenght && ten[i + 1] == ' ')
                return false;
            continue;
        }
        if ((ten[i] < 'A' || ten[i] > 'Z') && (ten[i] < 'a' || ten[i] > 'z'))
            return false;
        bool chuDau = (i == 0 || ten[i - 1] == ' ');
        if (chuDau)
        {
            if (ten[i] < 'A' || ten[i] > 'Z')
                return false;
        }
        else
        {
            if (ten[i] < 'a' || ten[i] > 'z')
                return false;
        }
    }
    return true;
}

/**
 * @brief Đọc và trả về họ tên hợp lệ từ người dùng.
 *
 * @return Chuỗi họ tên đã được kiểm tra hợp lệ.
 * @note Giải thuật:
 *       1. Sử dụng `getline(cin >> ws, name)` để đọc một dòng và loại bỏ khoảng trắng đầu.
 *       2. Gọi `KiemTraTen(name)` để kiểm tra tính hợp lệ của họ tên.
 *       3. Nếu hợp lệ, trả về tên.
 *       4. Nếu không hợp lệ, in thông báo lỗi và yêu cầu người dùng nhập lại.
 */
std::string KiemTraTenHopLe()
{
    string name;
    while (true)
    {
        getline(cin >> ws, name);
        if (KiemTraTen(name))
        {
            return name;
        }
        else
        {
            cout << "Ten khong hop le!\nVui long nhap lai: ";
        }
    }
}