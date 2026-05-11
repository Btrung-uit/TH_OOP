#include <iostream>
#include "cDaThuc.h"
using namespace std;

/**
 * @brief Nhập và ép luồng dữ liệu số thực, loại bỏ hoàn
 *        toàn các ký tự rác đi kèm.
 * @param giaTri: Tham chiếu đến biến kiểu double nhận giá trị
 *        nhập vào sau khi kiểm tra hợp lệ.
 * @return Không có.
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
void KiemTraDauVaoChoDouble(double &giaTri)
{
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
                return;
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
    cDaThuc P, Q;

    cout << "--- NHAP DA THUC P ---\n";
    cin >> P;
    cout << "=> P(X) = " << P << "\n\n";
    cout << "--- TINH GIA TRI DA THUC P ---\n";
    cout << "Nhap x: ";
    double x;
    KiemTraDauVaoChoDouble(x);
    cout << "P(" << x << ") = " << P.TinhGiaTri(x) << "\n\n";

    cout << "--- NHAP DA THUC Q ---\n";
    cin >> Q;
    cout << "=> Q(X) = " << Q << "\n\n";

    cout << "--- KET QUA PHEP TOAN ---\n";
    cDaThuc Tong = P + Q;
    cout << "P + Q = " << Tong << "\n";

    cDaThuc Hieu = P - Q;
    cout << "P - Q = " << Hieu << "\n\n";

    return 0;
}