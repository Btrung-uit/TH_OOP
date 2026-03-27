#include <iostream>
#include "PhanSo.h"
#include <cmath> // Cần thêm thư viện này để dùng hàm abs()
using namespace std;

/*
 * Hàm: UCLN
 * Chức năng: Tìm Ước chung lớn nhất của hai số nguyên bằng thuật toán Euclid (đệ quy).
 * Input: int a, int b (Hai số nguyên cần tìm UCLN).
 * Output: int (Giá trị Ước chung lớn nhất).
 */
int UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}

/*
 * Hàm: Nhap
 * Chức năng: Yêu cầu người dùng nhập tử số và mẫu số từ bàn phím. Có kiểm tra điều kiện mẫu số phải khác 0.
 * Input: Không có (dữ liệu được lấy từ luồng nhập cin).
 * Output: Cập nhật trực tiếp giá trị vào thuộc tính iTu và iMau của đối tượng gọi hàm.
 */
void PhanSo::Nhap() {
    cout << "Nhap tu: ";
    cin >> iTu;
    do {
        cout << "Nhap mau (khac 0): ";
        cin >> iMau;
    } while (iMau == 0);
}

/*
 * Hàm: Xuat
 * Chức năng: Hiển thị phân số ra màn hình theo định dạng "Tử/Mẫu". Báo lỗi nếu mẫu số bằng 0.
 * Input: Không có.
 * Output: In chuỗi ký tự ra màn hình console (luồng cout).
 */
void PhanSo::Xuat() {
    if (iMau == 0) {
        cout << "Loi";
    } else {
        cout << iTu << "/" << iMau;
    }
}

/*
 * Hàm: RutGon
 * Chức năng: Rút gọn phân số về dạng tối giản và chuẩn hóa dấu (đưa dấu âm lên tử số).
 * Input: Không có (sử dụng dữ liệu iTu, iMau hiện tại của đối tượng).
 * Output: Cập nhật lại giá trị iTu và iMau của đối tượng về dạng tối giản.
 */
void PhanSo::RutGon() {
    // Sử dụng abs() để đảm bảo UCLN luôn tính trên số dương
    int ucln = UCLN(abs(iTu), abs(iMau));
    iTu /= ucln;
    iMau /= ucln;

    // Đưa dấu về tử
    if (iMau < 0) {
        iTu = -iTu;
        iMau = -iMau;
    }
}

/*
 * Hàm: Tong
 * Chức năng: Tính tổng của phân số hiện tại và một phân số khác. Kết quả trả về đã được rút gọn.
 * Input: PhanSo ps (Phân số thứ hai cần đem cộng).
 * Output: PhanSo (Một đối tượng phân số mới lưu kết quả của phép cộng).
 */
PhanSo PhanSo::Tong(PhanSo ps) {
    PhanSo kq;
    kq.iTu = iTu * ps.iMau + ps.iTu * iMau;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}

/*
 * Hàm: Hieu
 * Chức năng: Tính hiệu của phân số hiện tại trừ đi một phân số khác. Kết quả trả về đã được rút gọn.
 * Input: PhanSo ps (Phân số thứ hai cần đem trừ).
 * Output: PhanSo (Một đối tượng phân số mới lưu kết quả của phép trừ).
 */
PhanSo PhanSo::Hieu(PhanSo ps) {
    PhanSo kq;
    kq.iTu = iTu * ps.iMau - ps.iTu * iMau;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}

/*
 * Hàm: Tich
 * Chức năng: Tính tích của phân số hiện tại nhân với một phân số khác. Kết quả trả về đã được rút gọn.
 * Input: PhanSo ps (Phân số thứ hai cần đem nhân).
 * Output: PhanSo (Một đối tượng phân số mới lưu kết quả của phép nhân).
 */
PhanSo PhanSo::Tich(PhanSo ps) {
    PhanSo kq;
    kq.iTu = iTu * ps.iTu;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}

/*
 * Hàm: Thuong
 * Chức năng: Tính thương của phân số hiện tại chia cho một phân số khác. Có kiểm tra lỗi chia cho 0.
 * Input: PhanSo ps (Phân số đóng vai trò làm số chia).
 * Output: PhanSo (Đối tượng phân số mới lưu kết quả phép chia. Nếu số chia bằng 0, trả về phân số 0/0).
 */
PhanSo PhanSo::Thuong(PhanSo ps) {
    if (ps.iTu == 0) {
        cout << "Loi";
        PhanSo kq;
        kq.iTu = 0;
        kq.iMau = 0; // Đánh dấu lỗi
        return kq;
    }
    PhanSo kq;
    kq.iTu = iTu * ps.iMau;
    kq.iMau = iMau * ps.iTu;
    kq.RutGon();
    return kq;
}

/*
 * Hàm: SoSanh
 * Chức năng: So sánh giá trị của phân số hiện tại với một phân số khác bằng phương pháp nhân chéo.
 * Input: PhanSo ps (Phân số cần đem ra so sánh).
 * Output: int (Trả về 1 nếu lớn hơn, 0 nếu bằng nhau, -1 nếu nhỏ hơn).
 */
int PhanSo::SoSanh(PhanSo ps) {
    int left = iTu * ps.iMau;
    int right = ps.iTu * iMau;

    if (left > right) return 1;
    if (left == right) return 0;
    return -1;
}