#include <iostream>
using namespace std;
class ConNguoi {
    public:
        virtual void speak() {
            cout << "Xin chao!\n";
        }
        virtual ~ConNguoi() {};
};
class Trung : public ConNguoi {
    public:
        void speak() override {
            cout << "Toi la Trung\n";
        }
};
class Minh : public ConNguoi {
    public:
        void speak() override {
            cout << "Toi la Minh\n";
        }
};
int main() {
    ConNguoi *a[3];
    a[0] = new Trung();
    a[1] = new Minh();
    a[2] = new ConNguoi();
    for(int i = 0; i < 3; i++) {
        a[i]->speak();
    }
}
