#include <iostream>
#include <cmath> // dùng cho hàm abs
#include <limits> // lấy giá trị tối đa của luồng nhập
using namespace std;
struct PhanSo {
    int tuso, mauso;
};
int KiemTra() { // hàm kiểm tra điều kiện đầu vào có phải là số nguyên không, nếu không phải là số nguyên thì nhập lại
    int n;
    while(true) {
        if(cin >> n) {
            // nếu đúng là số nguyên thì thoát vòng lặp
            break;
        }
        else {
            // nếu là chữ hoặc kí tự đặc biệt
            cout << "Dau vao khong hop le! Vui long nhap lai so nguyen: ";
            cin.clear(); // xóa trạng thái lỗi của đối tượng cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // bỏ qua toàn bộ kí tự rác trong bộ nhớ đệm
        }
    }
    // trả về số nguyên hợp lệ
    return n;
}
void Nhap(PhanSo &p) { // hàm nhập phân số
    cout << "Nhap tu so: ";
    p.tuso = KiemTra();
    cout << "Nhap mau so: ";
    p.mauso = KiemTra();
    while(p.mauso == 0) { // kiểm tra xem mẫu có khác 0 không, nếu bằng 0 thì nhập lại
        cout << "Mau so khong duoc bang 0! Vui long nhap so khac 0: ";
        p.mauso = KiemTra();
    }
}
int ucln(int a, int b) { // hàm tìm ước chung lớn nhất của tử và mẫu
    if(b == 0) return a;
    return ucln(b, a%b);
}
void RutGon(PhanSo &p) { // hàm thực hiện rút gọn phân số
    int tuso = abs(p.tuso); // chuyển số âm thành dương
    int mauso = abs(p.mauso); // chuyển số âm thành dương
    int uocChung = ucln(tuso, mauso); // tìm ước chung
    p.tuso/=uocChung; // thực hiện chia tử cho ước chung tìm được ở trên để rút gọn
    p.mauso/=uocChung; // thực hiện chia mẫu cho ước chung tìm được ở trên để rút gọn
}
void XuatPhanSo(int tuso, int mauso) {
    if(tuso == 0) { // kiểm tra xem tử có phải là số 0 không nếu là số 0 thì xuất 0 ngay lập tức
        cout << 0 << endl;
        return;
    }
    if(mauso < 0) { // kiểm tra xem mẫu có phải là số âm không, nếu bé hơn thì đổi dấu tử và mẫu
        tuso = -tuso;
        mauso = -mauso;
    }
    if(mauso == 1) { // nếu mẫu là 1 thì xuất tử ngay lập tức
        cout << tuso << endl;
        return;
    }
    else { // xuất phân số
        cout << tuso << '/' << mauso <<endl;
    }   
}
void Tong(PhanSo p1, PhanSo p2) {
    cout << "Tong hai phan so la: ";
    int tuso = p1.tuso*p2.mauso + p1.mauso*p2.tuso;
    int mauso = p1.mauso*p2.mauso;
    int uocChung = ucln(tuso, mauso);
    tuso /= uocChung;
    mauso /= uocChung;
    XuatPhanSo(tuso, mauso);
}
void Hieu(PhanSo p1, PhanSo p2) {
    cout << "Hieu hai phan so la: ";
    int tuso = p1.tuso*p2.mauso - p1.mauso*p2.tuso;
    int mauso = p1.mauso*p2.mauso;
    int uocChung = ucln(tuso, mauso);
    tuso /= uocChung;
    mauso /= uocChung;
    XuatPhanSo(tuso, mauso);
}
void Tich(PhanSo p1, PhanSo p2) {
    cout << "Tich hai phan so la: ";
    int tuso = p1.tuso*p2.tuso;
    int mauso = p1.mauso*p2.mauso;
    int uocChung = ucln(tuso, mauso);
    tuso /= uocChung;
    mauso /= uocChung;
    XuatPhanSo(tuso, mauso);
}
void Thuong(PhanSo p1, PhanSo p2) {
    cout << "Thuong hai phan so la: ";
    int tuso = p1.tuso*p2.mauso;
    int mauso = p1.mauso*p2.tuso;
    int uocChung = ucln(tuso, mauso);
    tuso /= uocChung;
    mauso /= uocChung;
    XuatPhanSo(tuso, mauso);
}
void TinhToan(PhanSo p1, PhanSo p2) { // hàm xuất phân số
    Tong(p1, p2);
    Hieu(p1, p2);
    Tich(p1, p2);
    Thuong(p1, p2);
}
int main() {
    PhanSo p1,p2;
    cout << "Nhap phan so thu nhat:\n";
    Nhap(p1);
    cout << "Nhap phan so thu hai:\n";
    Nhap(p2);
    TinhToan(p1, p2);
    return 0;   
}