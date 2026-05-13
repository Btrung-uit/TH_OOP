#include <iostream>
#include <cmath>
using namespace std;
struct Diem {
    float x;
    float y;
};
class DaGiac {
    private:
        Diem dinh[100];
        int soDinh;
        Diem xoayDiem(Diem p, float radian) {
            Diem Moi;
            Moi.x = p.x*cos(radian) - p.y*sin(radian);
            Moi.y = p.x*sin(radian) + p.y*cos(radian);
            return Moi;
        }
    public:
        DaGiac() {
            soDinh = 0;
        }   
        ~DaGiac() {}
        void nhap() {
            cout << "Nhap so luong dinh cua da giac(3-100): ";
            cin >> soDinh;
            while(soDinh < 3 || soDinh > 100) {
                cout << "Vui long nhap lai so dinh: ";
                cin >> soDinh;
            }
            for(int i = 0; i < soDinh; i++) {
                cout << "Nhap diem " << i + 1 << ": ";
                cin >> dinh[i].x >> dinh[i].y;
            }
        }
        void xuat() {
            for(int i = 0; i < soDinh; i++) {
                cout << "Dinh " << i+1 << " [" << dinh[i].x << ", " << dinh[i].y << "]" << endl;
            }
        }
        void phongTo(float k) {
            for(int i = 0; i < soDinh; i++) {
                dinh[i].x *= k;
                dinh[i].y *= k;
            }
            cout << "Da phong to da giac len " << k << " lan" << endl;
        }
        void thuNho(float k) {
            for(int i = 0; i < soDinh; i++) {
                dinh[i].x /= k;
                dinh[i].y /= k;
            }
            cout << "Da thu nho da giac di " << k << " lan" << endl;
        }
        void quay(float gocDo) {
            float radian = gocDo*3.14159/180;
            for(int i = 0; i < soDinh; i++) {
                dinh[i] = xoayDiem(dinh[i], radian);
            }
            cout << "Da xoay da giac " << gocDo << " do" << endl;
        }
};
int main() {
    DaGiac hinh;
    hinh.nhap();
    hinh.xuat();
    hinh.phongTo(2);
    hinh.xuat();
    hinh.thuNho(2);
    hinh.xuat();
    hinh.quay(90);
    hinh.xuat();
}