#include <iostream>
#include "cArray.h"
using namespace std;
int main()
{
    cArray mang;
    mang.TaoMangNgauNhien();
    mang.XuatMang();
    cout << "\nTim so lan x xuat hien trong mang\n";
    cout << "Nhap x: ";
    int x;
    cin >> x;
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