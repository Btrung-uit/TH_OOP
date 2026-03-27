#include <iostream>
#include "NgayThangNam.h"
using namespace std;

// Hàm kiểm tra năm nhuận
// Đầu vào: int nam
// Đầu ra: bool (true nếu là năm nhuận, false nếu không)
bool namNhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

// Hàm yêu cầu nhập lại ngày tháng năm khi dữ liệu không hợp lệ
// Đầu vào: tham chiếu int &ngay, int &thang, int &nam
// Đầu ra: cập nhật tham chiếu ngày/tháng/năm
void NhapLai(int &ngay, int &thang, int &nam) {
    cout << "Ngay thang nam khong hop le!\n";
    cout << "Vui long nhap lai: ";
    cin >> ngay >> thang >> nam;
}

// Hàm trả về số ngày của một tháng trong năm cụ thể
// Đầu vào: int thang, int nam
// Đầu ra: int so ngay trong thang
int soNgayTrongThang(int thang, int nam) {
    switch(thang) {
        case 2: 
            return namNhuan(nam) ? 29 : 28;
        case 4: case 6: case 9: case 11:
            return 30;
        default:
            return 31;
    }
}

// Hàm kiểm tra tính hợp lệ của ngày tháng năm
// Đầu vào: tham chiếu int &ngay, int &thang, int &nam
// Đầu ra: bool (true nếu hợp lệ, false nếu không)
bool KiemTraNgay(int &ngay, int &thang, int &nam) { 
    if (nam < 1 || thang < 1 || thang > 12 || ngay < 1) return false;
    if (ngay > soNgayTrongThang(thang, nam)) return false;
    return true;
}

// Hàm tính và hiển thị ngày tiếp theo của ngày đã cho
// Đầu vào: int ngay, int thang, int nam
// Đầu ra: hiển thị ngày tiếp theo ra console
void NgayTiepTheo(int ngay, int thang, int nam) {
    ngay++;
    int ngay_max = soNgayTrongThang(thang, nam);
    if(ngay > ngay_max) {
        ngay = 1;
        thang++;
        if(thang > 12) {
            thang = 1;
            nam++;
        }
    }
    cout << "Ngay tiep theo la: ";
    cout << ngay << '/' << thang << '/' << nam << endl;
}

// Hàm nhập ngày cho đối tượng NgayThangNam
// Đầu vào: không có (sử dụng thành viên iNgay, iThang, iNam)
// Đầu ra: cập nhật thành viên đối tượng NgayThangNam
void NgayThangNam::Nhap() {
    cout << "Nhap ngay thang nam: ";
    cin >> iNgay >> iThang >> iNam;
    while(!KiemTraNgay(iNgay, iThang, iNam)) {
        NhapLai(iNgay, iThang, iNam);
    }
}

// Hàm xuất ngày của đối tượng NgayThangNam
// Đầu vào: không có (sử dụng thành viên iNgay, iThang, iNam)
// Đầu ra: hiển thị ngày
void NgayThangNam::Xuat() {
    cout << "Ngay vua nhap la: ";
    cout << iNgay << '/' << iThang << '/' << iNam << endl;
}

// Hàm tính ngày tiếp theo cho đối tượng NgayThangNam và hiển thị
// Đầu vào: không có (sử dụng thành viên iNgay, iThang, iNam)
// Đầu ra: hiển thị ngày tiếp theo 
void NgayThangNam::TinhNgayThangNamTiepTheo() {
    int ngay = iNgay;
    int thang = iThang;
    int nam = iNam;
    NgayTiepTheo(ngay, thang, nam);
}
