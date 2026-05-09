#include <iostream>
#include "cPhanSo.h"

using namespace std;

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
    cout << "Phan so 2: " << ps1 << "\n\n";

    // Thực hiện tính toán +, -, *, /
    cout << ps1 << " + " << ps2 << " = " << ps1 + ps2 << "\n";
    cout << ps1 << " - " << ps2 << " = " << ps1 - ps2 << "\n";
    cout << ps1 << " * " << ps2 << " = " << ps1 * ps2 << "\n";

    cout << ps1 << " / " << ps2 << " = ";
    if (ps2 == 0)
        cout << "Khong hop le!\n";
    else
        cout << ps1 / ps2 << "\n";

    cout << "\nSo sanh 2 phan so\n";
    if (ps1 > ps2)
        cout << "Ket luan: PS1 lon hon PS2\n";
    else if (ps1 < ps2)
        cout << "Ket luan: PS1 nho hon PS2\n";
    else
        cout << "Ket luan: Hai phan so bang nhau\n";
    return 0;
}