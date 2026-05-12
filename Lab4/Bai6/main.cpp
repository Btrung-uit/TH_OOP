#include <iostream>
#include <string>
#include "CVector.h"

using namespace std;

/**
 * @brief Nhập và ép luồng dữ liệu số thực, loại bỏ hoàn
 *        toàn các ký tự rác đi kèm.
 * @param không có.
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
        if (cin >> giaTri)
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
            cout << "Gia tri khong hop le!\nVui long nhap so thuc!\nNhap lai: ";
            continue;
        }
        cout << "Gia tri khong hop le!\nVui long nhap so thuc!\nNhap lai: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

int main()
{
    CVector v1, v2;

    cout << "NHAP VECTOR THU NHAT (v1)\n";
    cin >> v1;
    cout << "=> v1 = " << v1 << "\n\n";

    cout << "NHAP VECTOR THU HAI (v2)\n";
    cin >> v2;
    cout << "=> v2 = " << v2 << "\n\n";

    cout << "PHEP TOAN\n";

    // 1. Phép cộng
    cout << "1. Phep CONG hai vector (v1 + v2):\n";
    cout << v1 << " + " << v2 << "\n= ";
    try
    {
        CVector Tong = v1 + v2;
        cout << Tong << "\n\n"; // Chỉ in Tong nếu phép tính thành công
    }
    catch (const invalid_argument &e)
    {
        cout << e.what() << "\n\n"; // In ra câu lỗi thay vì in ()
    }
    // 2. Phép trừ
    cout << "2. Phep TRU hai vector (v1 - v2):\n";
    cout << v1 << " - " << v2 << "\n= ";
    try
    {
        CVector Hieu = v1 - v2;
        cout << Hieu << "\n\n";
    }
    catch (const invalid_argument &e)
    {
        cout << e.what() << "\n\n";
    }

    // 3. Tích vô hướng
    cout << "3. TICH VO HUONG hai vector (v1 * v2):\n";
    cout << v1 << " * " << v2 << "\n= ";
    try
    {
        double TichVoHuong = v1 * v2;
        cout << TichVoHuong << "\n\n";
    }
    catch (const invalid_argument &e)
    {
        cout << e.what() << "\n\n";
    }
    // 4. Nhân vector với một số thực (k)
    double k;
    cout << "4. Phep CO GIAN vector (v1 * k):\n";
    cout << "Nhap he so gian (k): ";
    k = KiemTraDauVaoChoDouble();
    cout << "   " << v1 << " * ";
    if (k < 0)
        cout << "(" << k << ")";
    else
        cout << k;
    cout << "\n= " << v1 * k << "\n";
    return 0;
}