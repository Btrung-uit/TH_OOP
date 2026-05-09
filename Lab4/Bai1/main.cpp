#include "cSoPhuc.h"
#include <iostream>
using namespace std;

int main()
{
    cSoPhuc A, B;
    cout << "Nhap so phuc A\nNhap: ";
    cin >> A;
    cout << "Nhap so phuc B\nNhap: ";
    cin >> B;
    cout << "\nTinh toan 2 so phuc\n";
    cout << "A + B = " << A + B << "\n";
    cout << "A - B = " << A - B << "\n";
    cout << "A * B = " << A * B << "\n";
    cout << "A / B = " << A / B << "\n";
    cout << "\nSo sanh 2 so phuc\n";
    if (A == B)
    {
        cout << "Ket luan: A bang B\n";
    }
    else if (A != B)
    {
        cout << "Ket luan: A != B\n";
    }
}