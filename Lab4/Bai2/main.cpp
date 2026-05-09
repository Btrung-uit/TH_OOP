#include <iostream>
#include "cPhanSo.h"

using namespace std;

/**
 * @brief Xuất biểu thức toán học của hai phân số với định dạng thẩm mỹ.
 * @param ps1: Tham chiếu hằng đến phân số thứ nhất (chỉ đọc).
 * @param ps2: Tham chiếu hằng đến phân số thứ hai,
 *             dùng để kiểm tra dấu và xuất (chỉ đọc).
 * @param toanTu: Tham chiếu hằng đến chuỗi ký tự đại diện phép toán.
 * @param ketQua: Tham chiếu hằng đến phân số là kết quả của phép
 *                tính (chỉ đọc).
 * @note Giải thuật:
 *      - Bước 1: Xuất phân số thứ nhất (ps1) và khoảng trắng kèm
 *                toán tử (toanTu).
 *      - Bước 2: Kiểm tra tính âm dương của phân số thứ hai (ps2)
 *                thông qua toán tử so sánh '<'.
 *      - Bước 3: Nếu ps2 là số âm, thực hiện bọc phân số này trong
 *                cặp ngoặc đơn " ( ) " để tránh hiện tượng hai dấu
 *                đứng cạnh nhau.
 *      - Bước 4: Nếu ps2 không âm, thực hiện xuất trực tiếp giá trị
 *                phân số.
 *      - Bước 5: Hoàn tất biểu thức bằng cách xuất dấu "=" và phân
 *                số kết quả (ketQua).
 */
void InPhepToan(const cPhanSo &ps1, const cPhanSo &ps2, const string &toanTu, const cPhanSo &ketQua)
{
    cout << ps1 << " " << toanTu << " ";

    // Kiểm tra nếu phân số 2 là âm thì để trong dấu ngoặc đơn
    if (ps2 < 0)
    {
        cout << "(" << ps2 << ")";
    }
    else
    {
        cout << ps2;
    }

    cout << " = " << ketQua << "\n";
}
int main()
{
    cPhanSo ps1, ps2;

    cout << "Nhap phan so thu nhat\n";
    cin >> ps1;
    cout << "Phan so vua nhap la\n";
    cout << "Phan so 1: " << ps1;
    cout << "\n\nNhap phan so thu hai\n";
    cin >> ps2;
    cout << "Phan so vua nhap la\n";
    cout << "Phan so 2: " << ps2 << "\n\n";

    // Thực hiện tính toán +, -, *, /
    InPhepToan(ps1, ps2, "+", ps1 + ps2);
    InPhepToan(ps1, ps2, "-", ps1 - ps2);
    InPhepToan(ps1, ps2, "*", ps1 * ps2);

    // Xu ly rieng phep chia de chong loi chia cho 0
    if (ps2 == 0)
    {
        cout << ps1 << " / 0 = Phep chia khong hop le!\n";
    }
    else
    {
        InPhepToan(ps1, ps2, "/", ps1 / ps2);
    }

    cout << "\nSo sanh 2 phan so\n";
    if (ps1 > ps2)
        cout << "Ket luan: PS1 lon hon PS2\n";
    else if (ps1 < ps2)
        cout << "Ket luan: PS1 nho hon PS2\n";
    else
        cout << "Ket luan: Hai phan so bang nhau\n";
    return 0;
}