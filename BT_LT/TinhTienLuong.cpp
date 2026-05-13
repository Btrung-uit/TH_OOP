#include <iostream>
#include <string>
using namespace std;
class NhanVien {
    private:
        string hoTen;
        string ngaySinh;
    protected:
        double luongCoBan;
    public:
        virtual void nhap() {
            cout << "Nhap ho va ten: ";
            cin.ignore();
            getline(cin, hoTen);
            cout << "Nhap ngay thang nam sinh(dd/mm/yyyy): ";
            cin >> ngaySinh;
            cout << "Nhap luong co ban: ";
            cin >> luongCoBan;
        }
        virtual double tinhLuong() = 0;
        virtual void xuat() {
            cout << "Ho va ten: " << hoTen << " | Ngay sinh: " << ngaySinh << " | Luong co ban: " << luongCoBan;
        }
        string getHoTen() {
            return hoTen;
        }
        virtual ~NhanVien() {}
};
class NhanVienSanXuat: public NhanVien {
    private:
        int soSanPham;
    public:
        void nhap() override {
            NhanVien::nhap();
            cout << "Nhap so san pham: ";
            cin >> soSanPham;
        }
        double tinhLuong() override {
            return luongCoBan + soSanPham * 2000;
        }
        void xuat() override {
            NhanVien::xuat();
            cout << " | So san pham: " << soSanPham << " | Luong: " << tinhLuong() << endl;
        }
};
class NhanVienQuanLy: public NhanVien {
    private:
        double heSoChucVu;
        double thuong;
    public:
        void nhap() override {
            NhanVien::nhap();
            cout << "Nhap he so chuc vu: ";
            cin >> heSoChucVu;
            cout << "Nhap thuong: ";
            cin >> thuong;
        }
        double tinhLuong() override {
            return luongCoBan * heSoChucVu + thuong;
        }
        void xuat() override {
            NhanVien::xuat();
            cout << " | He so chuc vu: " << heSoChucVu << " | Thuong: " << thuong << " | Luong: " << tinhLuong() << endl;
        }
};
void TimKiemNhanVien(NhanVien *ds[], int n, string name) {
    cout << "TIM KIEM: " << name << "\n";
    bool found = false;
    for(int i = 0; i < n; i++) {
        if(ds[i]->getHoTen().find(name) != string::npos) {
            ds[i]->xuat();
            found = true;
        }
    }
    if(!found) {
        cout << "Khong tim thay nhan vien co ten " << name << endl;
    }
}