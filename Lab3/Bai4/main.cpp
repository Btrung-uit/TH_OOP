#include <iostream>
#include "cArray.h"
using namespace std;
/**
 * @brief Nhập và kiểm tra tính hợp lệ của số nguyên đầu vào.
 * @param Không có.
 * @return Giá trị số nguyên hợp lệ đã được nhập.
 * @note Giải thuật:
 *       1. Sử dụng vòng lặp vô tận (while true) để yêu cầu nhập dữ liệu cho đến khi thành công.
 *       2. Sử dụng cin >> x làm điều kiện kiểm tra:
 *          - Nếu nhập đúng kiểu số, trả về x và thoát hàm.
 *          - Nếu nhập sai thì loại bỏ kí tự rác và nhập lại.
 */
int KiemTraHopLe()
{
    int x;
    while (true)
    {
        if (cin >> x)
        {
            return x;
        }
        cout << "Gia tri khong hop le!\nVui long nhap lai: ";
        cin.clear();             // Xóa cờ lỗi của cin
        cin.ignore(10000, '\n'); // Dọn dẹp rác trong bộ nhớ đệm
    }
}
int main()
{
    cArray mang;
    mang.TaoMangNgauNhien();
    mang.XuatMang();
    cout << "\nTim so lan x xuat hien trong mang\n";
    cout << "Nhap x: ";
    int x = KiemTraHopLe();
    cout << "So lan " << x << " xuat hien trong mang: ";
    cout << mang.DemSoLanXuatHien(x) << "\n";
    cout << "\nKiem tra mang tang dan\n";
    cout << "Ket luan: ";
    if (mang.KiemTraTangDan())
    {
        cout << "Mang tang dan";
    }
    else
        cout << "Mang khong tang dan";
    cout << "\n";
    cout << "\nTim so le nho nhat trong mang\n";
    int minOdd = mang.TimLeNhoNhat();
    if (minOdd == 0)
    {
        cout << "Mang khong co so le!\n";
    }
    else
    {
        cout << "So le nho nhat trong mang la: " << minOdd << "\n";
    }
    cout << "\nTim so nguyen to lon nhat trong mang\n";
    int maxPrime = mang.TimSoNguyenToLonNhat();
    if (maxPrime == -1)
    {
        cout << "Mang khong co so nguyen to!\n";
    }
    else
    {
        cout << "So nguyen to lon nhat trong mang la: " << maxPrime << "\n";
    }
    cout << "\nSap xep mang theo thu tu tang dan\n";
    mang.SapXepTangDan();
    mang.XuatMang();
    cout << "\nSap xep mang theo thu tu giam dan\n";
    mang.SapXepGiamDan();
    mang.XuatMang();
}