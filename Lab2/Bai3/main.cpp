#include <iostream>
#include "SoPhuc.h"
using namespace std;

int main() {
    SoPhuc sp1, sp2;
    cout << "\nNhap so phuc thu nhat\n";
    sp1.Nhap();
    cout << "\nNhap so phuc thu hai\n";
    sp2.Nhap();
    cout << "So phuc 1: "; sp1.Xuat(); cout << endl;
    cout << "So phuc 2: "; sp2.Xuat(); cout << endl;
    // Thực hiện tính toán
    SoPhuc tong = sp1.TinhTong(sp2);
    SoPhuc hieu = sp1.TinhHieu(sp2);
    SoPhuc tich = sp1.TinhTich(sp2);
    SoPhuc thuong = sp1.TinhThuong(sp2);
    // In kết quả
    cout << "Tong = "; tong.Xuat(); cout << endl;
    cout << "Hieu = "; hieu.Xuat(); cout << endl;
    cout << "Tich = "; tich.Xuat(); cout << endl;
    cout << "Thuong: "; 
    if (sp2.LaSoKhong()) {
        cout << "Loi (Chia cho 0)";
    } else {
        cout << " = ";
        SoPhuc thuong = sp1.TinhThuong(sp2);
        thuong.Xuat(); 
        cout << endl;
    }
    return 0;
}