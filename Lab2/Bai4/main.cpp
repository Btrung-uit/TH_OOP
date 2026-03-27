#include <iostream>
#include "GioPhutGiay.h"
using namespace std;

int main() {
    GioPhutGiay tgGoc, tgSau1Giay;
    cout << "Nhap thoi gian\n";
    tgGoc.Nhap();
    cout << "Thoi gian ban dau: "; 
    tgGoc.Xuat(); 
    cout << endl;
    tgSau1Giay = tgGoc.TinhCongThemMotGiay(tgGoc);
    cout << "Thoi gian sau khi +1 giay: "; 
    tgSau1Giay.Xuat(); 
    cout << endl;
    return 0;
}