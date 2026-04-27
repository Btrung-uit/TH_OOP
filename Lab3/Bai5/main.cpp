#include <iostream>
#include "cDaThuc.h"
using namespace std;
int main()
{
    cDaThuc P;
    cout << "Nhap da thuc P\n";
    P.Nhap();
    cout << "Da thuc vua nhap la\nP(X) = ";
    P.Xuat();
    cout << "\nTinh gia tri cua da thuc khi biet x\nNhap x: ";
    double x;
    while (true)
    {
        if (cin >> x)
            break;
        cout << "Gia tri khong hop le!\nVui long nhap lai: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cout << "Gia tri cua bieu thuc khi x = " << x << " la\n";
    cout << "P(" << x << ") = " << P.TinhGiaTri(x);
    cDaThuc Q;
    cout << "\nNhap da thuc Q\n";
    Q.Nhap();
    cout << "Da thuc vua nhap la\nQ(X) = ";
    Q.Xuat();
    cout << "\nCong hai da thuc\n";
    cout << "P + Q = ";
    cDaThuc Tong;
    Tong = P.Cong(Q);
    Tong.Xuat();
    cout << "\nTru hai da thuc\n";
    cout << "P - Q = ";
    cDaThuc Hieu;
    Hieu = P.Tru(Q);
    Hieu.Xuat();
}