#include <iostream>
using namespace std;
class VuKhi {
    private:
        string ten;
        int satThuong;
        int doBen;
    public:
        VuKhi(string name = "", int damage = 0, int durability = 0) {
            ten = name;
            satThuong = damage;
            doBen = durability;
        }
        string XuatTenVuKhi() {
            return ten;
        }
        int XuatDoBen() {
            return doBen;
        }
        friend ostream &operator<<(ostream &os, VuKhi tool) {
            os << "Ten vu khi: " << tool.ten << endl;
            os << "Sat thuong: " << tool.satThuong << endl;
            os << "Do ben: " << tool.doBen;
            return os;
        }
        friend istream &operator>>(istream &is, VuKhi &tool) {
            cout << "Nhap ten vu khi: ";
            getline(is >> ws, tool.ten);
            cout << "Nhap sat thuong cua vu khi: ";
            is >> tool.satThuong;
            cout << "Nhap do ben cua vu khi: ";
            is >> tool.doBen;
            return is;
        }
        bool operator>(VuKhi other) {
            return this->satThuong > other.satThuong;
        }
        bool operator==(VuKhi other) {
            return (this->ten == other.ten) && (this->satThuong == other.satThuong);
        }
        VuKhi &operator+=(int n) {
            this->doBen += n;
            return *this;
        }
        VuKhi &operator-=(int n) {
            this->doBen -= n;
            if(this->doBen <= 0) {
                cout << "Do ben vu khi tro ve 0! Vu khi da bi vo!";
                this->doBen = 0;
            }
            return *this;
        }
};
int main() {
    VuKhi a, b;
    cin >> a;
    cin >> b;
    cout << a << endl << b << endl;
    if(a > b) {
        cout << "Vu khi " << a.XuatTenVuKhi();
    }
    else cout << "Vu khi " << b.XuatTenVuKhi();
    cout << " co sat thuong lon nhat" << endl;
    if(a == b) cout << "2 vat pham giong nhau";
    else cout << "2 vat pham khac nhau";
    cout << "\nSua chua vat pham" << endl;
    int n;
    cout << "Nhap do ben them vao: ";
    cin >> n;
    a += n;
    cout << a.XuatTenVuKhi() << " do ben duoc cong " << n << ", do ben hien tai " << a.XuatDoBen();
    cout << endl << "Ban danh 1 con quai bi tru 10 diem do ben!" << endl;
    a -= 10;
    cout << a.XuatTenVuKhi() << " do ben con lai " << a.XuatDoBen();
}