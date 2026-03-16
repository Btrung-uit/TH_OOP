#include <iostream>
#include <cmath>
using namespace std;
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}
void rutgon(int a, int b) {
    if(a == 0) {
        cout << 0;
        return;
    }
    int c = gcd(abs(a), abs(b));
    a/=c;
    b/=c;
    if(b < 0) {
        a = -a;
        b = -b;
    }
    if(b == 1) {
        cout << a;
        return;
    }
    else {
        cout << a << '/' << b << endl;
    }
}
int main() {
    int t1, m1, t2, m2;
    cout << "Nhap tu so cua phan so thu nhat: ";
    cin >> t1;
    cout << "Nhap mau so cua phan so thu nhat: ";
    while(cin >> m1) {
        if(m1 != 0) break;
        cout << "Mau khong hop le! Vui long nhap mau khac 0: ";
    }
    cout << "Nhap tu so cua phan so thu hai: ";
    cin >> t2;
    cout << "Nhap mau so cua phan so thu hai: ";
    while(cin >> m2) {
        if(m2 != 0) break;
        cout << "Mau khong hop le! Vui long nhap mau khac 0: ";
    }
    cout << "Phan so thu nhat sau khi rut gon la: ";
    rutgon(t1,m1);
    cout << "Phan so thu hai sau khi rut gon la: ";
    rutgon(t2,m2);
}
