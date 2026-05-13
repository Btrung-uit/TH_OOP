#include <iostream>
#include <string>

using namespace std;

// 1. TÍNH TRỪU TƯỢNG & ĐÓNG GÓI
class NhanVat {
protected: // Đóng gói: Chỉ cho phép lớp con truy cập
    string ten;
    int mau;

public:
    NhanVat(string _ten, int _mau) {
        ten = _ten;
        mau = _mau;
    }

    // Hàm thuần ảo (Tính trừu tượng) - Bắt buộc lớp con phải định nghĩa lại
    virtual void TanCong() = 0; 
    
    // Hàm ảo cho phép ghi đè (Tính đa hình)
    virtual void HienThiThongTin() {
        cout << "Ten: " << ten << " - Mau: " << mau << endl;
    }
};

// 2. TÍNH KẾ THỪA
class ChienBinh : public NhanVat {
private:
    int sucManh; // Thuộc tính riêng của ChienBinh

public:
    ChienBinh(string _ten, int _mau, int _sucManh) : NhanVat(_ten, _mau) {
        // Khởi tạo thuộc tính riêng của ChienBinh trong phần thân hàm
        sucManh = _sucManh;
    }

    // 3. TÍNH ĐA HÌNH (Ghi đè hàm của lớp cha)
    void TanCong() override {
        cout << ten << " chem kiem gay ra " << sucManh << " sat thuong!" << endl;
    }
    
    void HienThiThongTin() override {
        cout << "[Chien Binh] Ten: " << ten << " - Mau: " << mau << " - Suc manh: " << sucManh << endl;
    }
};

class PhapSu : public NhanVat {
private:
    int phepThuat;

public:
    PhapSu(string _ten, int _mau, int _phepThuat) : NhanVat(_ten, _mau), phepThuat(_phepThuat) {}

    void TanCong() override {
        cout << ten << " ban cau lua gay ra " << phepThuat * 2 << " sat thuong phep!" << endl;
    }
    
    void HienThiThongTin() override {
        cout << "[Phap Su] Ten: " << ten << " - Mau: " << mau << " - Phep thuat: " << phepThuat << endl;
    }
};

int main() {
    // Khởi tạo mảng con trỏ lớp cha có sức chứa 2 phần tử (Không dùng vector)
    NhanVat* danhSachNhanVat[2]; 

    // Gán đối tượng lớp con vào con trỏ lớp cha
    danhSachNhanVat[0] = new ChienBinh("Garen", 1000, 50);
    danhSachNhanVat[1] = new PhapSu("Ryze", 600, 80);

    // Duyệt mảng để thể hiện Tính Đa Hình
    for (int i = 0; i < 2; i++) {
        danhSachNhanVat[i]->HienThiThongTin();
        danhSachNhanVat[i]->TanCong();
        cout << "-------------------" << endl;
    }

    // Giải phóng bộ nhớ
    delete danhSachNhanVat[0];
    delete danhSachNhanVat[1];

    return 0;
}