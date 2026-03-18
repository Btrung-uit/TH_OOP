#include <iostream>
#include <limits>
using namespace std;

struct Date {
    int ngay, thang, nam;
};
int KiemTra() { // hàm kiểm tra điều kiện đầu vào có phải là số nguyên dương không, nếu không phải là số nguyên dương thì nhập lại
    int n;
    while(true) {
        cin >> n;
        if(n > 0) {
            // nếu đúng là số nguyên dương thì thoát vòng lặp
            break;
        }
        else {
            // nếu là chữ hoặc kí tự đặc biệt
            cout << "Dau vao khong hop le! Vui long nhap lai so nguyen duong: ";
            cin.clear(); // xóa trạng thái lỗi của đối tượng cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // bỏ qua toàn bộ kí tự rác trong bộ nhớ đệm
        }
    }
    // trả về số nguyên dương hợp lệ
    return n;
}
void Nhap(Date &hientai) {
    cout << "Nhap ngay: ";
    hientai.ngay = KiemTra();
    cout << "Nhap thang: ";
    hientai.thang = KiemTra();
    cout << "Nhap nam: ";
    hientai.nam = KiemTra();
}
bool namNhuan(int nam) { // hàm kiểm tra năm nhuận
    return (nam % 400 == 0) || ((nam % 4 == 0) && nam % 100 != 0); 
}
void xuat(Date hientai) { // hàm xuất ngày
    cout << hientai.ngay << "/" << hientai.thang << "/" << hientai.nam << endl;
}
void ngayKeTiep(Date &hientai) { // hàm tìm ngày kế tiếp
    hientai.ngay++; // tăng ngày
    int thang = hientai.thang;
    int ngay_max;
    if(thang == 2) {
        if(namNhuan(hientai.nam)) { // kiểm tra xem năm nhuận
            ngay_max = 29;
        } else {
            ngay_max = 28;
        }
    } else if(thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12) {
        ngay_max = 31;
    } else {
        ngay_max = 30;
    }
    if(hientai.ngay > ngay_max) { // nếu ngày sau khi tăng lớn hơn ngày tối đa thì trừ ngày hiện tại và tăng tháng và nếu tháng sau khi tăng lớn hơn 12 thì tăng năm
        hientai.ngay -= ngay_max;
        hientai.thang++;
        if(hientai.thang > 12) {
            hientai.thang = 1;
            hientai.nam++;
        }
    }
    xuat(hientai); // xuất Date
}
int soNgayTrongThang(int thang, int nam) { // hàm tìm số ngày của tháng
    switch(thang) {
        case 4: case 6: case 9: case 11:
            return 30;  
        case 2:
            return namNhuan(nam) ? 29 : 28;
        default:
            return 31;
    }
}
void ngayTruoc(Date &hientai) { // hàm tính toán ngày trước đó
    if(hientai.ngay == 1 && hientai.thang == 1 && hientai.nam == 0) { // trường hợp ngày 1 tháng 1 năm 0 không tính được
        cout << "Loi! khong the tim duoc ngay truoc do" << endl;
        return;
    }
    hientai.ngay--; // lùi 1 ngày
    if(hientai.ngay == 0) {
        hientai.thang--; // nếu ngày bằng 0 lùi 1 tháng
        if(hientai.thang == 0) { 
            hientai.thang = 12; // tháng lùi về bằng 0 nên sẽ trở thành tháng 12
            hientai.nam--; // nếu tháng bằng 0 lùi 1 năm
        }
        hientai.ngay = soNgayTrongThang(hientai.thang, hientai.nam); // tính ngày sau khi lùi
    }
    xuat(hientai); // xuất Date
}
int ngayTrongNam(Date hientai) { // hàm tìm ngày đó là ngày thứ bao nhiêu trong năm
    int count = 0;
    for(int i = 1; i < hientai.thang; i++) {
        count += soNgayTrongThang(hientai.thang, hientai.nam);
    }
    count += hientai.ngay;
    return count;
}
int main() {
    Date hientai;
    Nhap(hientai); // nhập ngày tháng năm
    Date ketiep = hientai;
    cout << "Ngay hien tai la: ";
    ngayKeTiep(ketiep);
    Date truoc = hientai;
    cout << "Ngay truoc do la: ";
    ngayTruoc(truoc);
    cout << hientai.ngay << "/" << hientai.thang << "/" << hientai.nam << " la ngay thu: " << ngayTrongNam(hientai);
    return 0;
}