#include <iostream>
#include <cmath>
using namespace std;
struct Diem {
    float x;
    float y;
};
class TamGiac {
    private:
        Diem A, B, C;
        Diem xoayDiem(Diem p, float radian) {
            Diem Moi;
            Moi.x = p.x*cos(radian)-p.y*sin(radian);
            Moi.y = p.x*sin(radian) + p.y*cos(radian);
            return Moi;
        }
    public:
        TamGiac() {
            A.x = A.y = 0;
            B.x = B.y = 0;
            C.x = C.y = 0;
        }
        TamGiac(Diem a, Diem b, Diem c) {
            A = a;
            B = b;
            C = c;
        }
        void Nhap() {
            cout << "Nhap toa do diem A: ";
            cin >> A.x >> A.y;
            cout << "Nhap toa do diem B: ";
            cin >> B.x >> B.y;
            cout << "Nhap toa do diem C: ";
            cin >> C.x >> C.y;
        }
        void Xuat() {
            cout << "Tam Giac: A(" << A.x << ", " << A.y << "), B(" << B.x << ", " << B.y << "), C(" << C.x << ", " << C.y << ")" << endl;
        }
        void PhongTo(float k) {
            A.x *= k;
            A.y *= k;
            B.x *= k;
            B.y *= k;
            C.x *= k;
            C.y *= k;
            cout << "Da phong to tam giac len " << k << " lan!" << endl;
        }
        void ThuNho(float k) {
            if(k != 0) {
                A.x /= k;
                A.y /= k;
                B.x /= k;
                B.y /= k;
                C.x /= k;
                C.y /= k;
                cout << "Da thu nho tam giac di " << k <<" lan " << endl;
            }
        }
        void Quay(float GocDo) {
            float radian = GocDo*3.14159/180;
            A = xoayDiem(A, radian);
            B = xoayDiem(B, radian);
            C = xoayDiem(C, radian);
            cout << "Tam giac da xoay 1 goc " << GocDo << " do" << endl;
        }
};
int main() {
    TamGiac tg;
    tg.Nhap();
    tg.Xuat();
    tg.PhongTo(2);
    tg.Xuat();
    tg.ThuNho(2);
    tg.Xuat();
    tg.Quay(90);
    tg.Xuat();
}