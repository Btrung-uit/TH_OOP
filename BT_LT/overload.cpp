#include <iostream>
using namespace std;
class Diem {
    private:
        double x, y;
    public:
        Diem(double hoanhdo = 0, double tungdo = 0) {
            x = hoanhdo;
            y = tungdo;
        }
        friend ostream& operator<<(ostream &os, Diem d) {
            os << "(" << d.x << ", " << d.y << ")";
            return os;  
        }
        friend istream& operator>>(istream &is, Diem &d) {
            cout << "Nhap x: "; is >> d.x;
            cout << "Nhap y: "; is >> d.y;
            return is; 
        }
        Diem operator+(Diem other) {
            Diem ketqua;
            ketqua.x = this->x + other.x;
            ketqua.y = this->y + other.y;
            return ketqua;
        }
        Diem operator-(Diem other) {
            Diem ketqua;
            ketqua.x = this->x - other.x;
            ketqua.y = this->y - other.y;
            return ketqua;
        }
};
int main() {
    Diem A, B;
    cin >> A >> B;
    cout << A << " " << B << endl;
    cout << A + B << endl;
    cout << A - B << endl;
}