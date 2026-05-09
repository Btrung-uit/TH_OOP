#include "cSoPhuc.h"
#include <iostream>
using namespace std;

int main()
{
    cSoPhuc A, B;
    cout << "Nhap so phuc A\n";
    cin >> A;
    cout << "So phuc vua nhap la\nA = ";
    cout << A;
    cout << "\n\nNhap so phuc B\n";
    cin >> B;
    cout << "So phuc vua nhap la\nB = ";
    cout << B;
    cout << "\nTinh toan 2 so phuc\n";
    cout << "A + B = " << A + B << "\n";
    cout << "A - B = " << A - B << "\n";
    cout << "A * B = " << A * B << "\n";
    cout << "A / B = ";
    if (B == 0)
    {
        cout << "Phep chia khong hop le!\n";
    }
    else
    {
        cout << A / B << "\n";
    }
    cout << "\nSo sanh 2 so phuc\n";
    if (A == B)
    {
        cout << "Ket luan: A bang B\n";
    }
    else if (A != B)
    {
        cout << "Ket luan: A khac B\n";
    }
}