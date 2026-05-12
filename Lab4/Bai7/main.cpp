#include <iostream>
#include <string>
#include "CMatrix.h"
#include "CVector.h"

using namespace std;

// Hàm hỗ trợ xuất dấu ngoặc cho số âm
void InSo(double k)
{
    if (k < 0)
        cout << "(" << k << ")";
    else
        cout << k;
}

/**
 * @brief Nhập và ép luồng dữ liệu số thực, loại bỏ hoàn
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
    cout << "1. NHAP MA TRAN 1\n";
    CMatrix MT1;
    cin >> MT1;
    cout << "MT1 vua nhap:\n"
         << MT1 << "\n";

    cout << "2. TINH TOAN VOI SO THUC\n";
    double k;
    cout << "Nhap mot so thuc k: ";
    k = KiemTraDauVaoChoDouble();

    cout << "MT1 + ";
    InSo(k);
    cout << " :\n";
    cout << (MT1 + k) << "\n";

    cout << "MT1 - ";
    InSo(k);
    cout << " :\n";
    cout << (MT1 - k) << "\n";

    cout << "MT1 * ";
    InSo(k);
    cout << " :\n";
    cout << (MT1 * k) << "\n";

    cout << "MT1 / ";
    InSo(k);
    cout << " :\n";
    try
    {
        cout << (MT1 / k) << "\n";
    }
    catch (const invalid_argument &e)
    {
        cout << e.what() << "\n\n";
    }

    cout << "3. TINH TOAN VOI VECTOR\n";
    CVector v;
    cin >> v; // Nhập vector
    cout << "Tich MT1 * v:\n";
    try
    {
        cout << (MT1 * v) << "\n\n";
    }
    catch (const invalid_argument &e)
    {
        cout << e.what() << "\n\n";
    }

    cout << "4. TINH TOAN VOI MA TRAN 2\n";
    CMatrix MT2;
    cin >> MT2;
    cout << "MT2 vua nhap:\n"
         << MT2 << "\n";

    cout << "MT1 + MT2:\n";
    try
    {
        cout << (MT1 + MT2) << "\n";
    }
    catch (const invalid_argument &e)
    {
        cout << e.what() << "\n\n";
    }

    cout << "MT1 - MT2:\n";
    try
    {
        cout << (MT1 - MT2) << "\n";
    }
    catch (const invalid_argument &e)
    {
        cout << e.what() << "\n\n";
    }

    cout << "MT1 * MT2:\n";
    try
    {
        cout << (MT1 * MT2) << "\n";
    }
    catch (const invalid_argument &e)
    {
        cout << e.what() << "\n\n";
    }
    return 0;
}