#include <iostream>
#include <string>
using namespace std;
class Nguoi {
    private:
        string ten;
        int namSinh;
    public:
        Nguoi(string t = "", int n = 0) : ten(t), namSinh(n) {}
        virtual ~Nguoi() {}
        virtual void nhap(istream &in) {
            cout << "Nhap ten: ";
            getline(in >> ws, ten);
            cout << "Nhap nam sinh: ";
            in >> namSinh;

        }
        virtual void xuat(ostream &out) const {
            out << "Ten: " << ten << " | nam sinh: " << namSinh;
        }
        friend istream &operator>>(istream &in, Nguoi &ng) {
            ng.nhap(in);
            return in;
        }
        friend ostream &operator<<(ostream &out, const Nguoi &ng) {
            ng.xuat(out);
            return out;
        }
};
class GiaoVien : public Nguoi {
    private:
        double luong;
    public:
        GiaoVien(string t = "", int n = 0, double luong = 0) : Nguoi(t, n), luong(l) {}
        void nhap(istream &in) override {
            Nguoi::nhap(in);
            cout << "Nhap luong: ";
            in >> luong;
        }
        void xuat(ostream &out) const override {
            Nguoi::xuat(out);
            out << " | luong: " << luong;
        }
};
class SinhVienNam : public Nguoi {
    private:
        double chieuCao;
    public:
        SinhVienNam(string t = "", int n = 0, double h = 0) : Nguoi(t,n), chieuCao(h) {}
        void nhap(istream &in) override {
            cout << "Nhap chieu cao: ";
            in >> chieuCao;
        }
        void xuat(ostream &out) const override {
            cout << " | chieu cao: ";
            out << chieuCao;
        }
};
