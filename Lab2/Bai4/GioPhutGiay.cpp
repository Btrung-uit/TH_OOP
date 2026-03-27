#include <iostream>
#include <iomanip> // Cần thư viện này để format số 0 ở trước (ví dụ: 09:05:02)
#include "GioPhutGiay.h"
using namespace std;

/*
 * Hàm: Nhap
 * Chức năng: Yêu cầu người dùng nhập giờ, phút, giây từ bàn phím. Có kiểm tra tính hợp lệ.
 * Input: Không có (dữ liệu lấy từ bàn phím).
 * Output: Cập nhật giá trị vào thuộc tính iGio, iPhut, iGiay của đối tượng gọi hàm.
 */
void GioPhutGiay::Nhap() {
    bool hopLe;
    do {
        hopLe = true;
        cout << "Nhap gio (0-23): ";
        cin >> iGio;
        cout << "Nhap phut (0-59): ";
        cin >> iPhut;
        cout << "Nhap giay (0-59): ";
        cin >> iGiay;
        // Rào điều kiện: Giờ [0, 23], Phút [0, 59], Giây [0, 59]
        if (iGio < 0 || iGio > 23 || iPhut < 0 || iPhut > 59 || iGiay < 0 || iGiay > 59) {
            cout << "-> Thoi gian khong hop le! Vui long nhap lai.\n\n";
            hopLe = false;
        }
    } while (!hopLe);
}
/*
 * Hàm: Xuat
 * Chức năng: Hiển thị thời gian ra màn hình theo định dạng chuẩn HH:MM:SS.
 * Input: Không có.
 * Output: In chuỗi thời gian ra màn hình console.
 */
void GioPhutGiay::Xuat() {
    // Sử dụng setfill('0') và setw(2) để tự động thêm số 0 vào trước các số < 10
    cout << setfill('0') << setw(2) << iGio << ":"
         << setfill('0') << setw(2) << iPhut << ":"
         << setfill('0') << setw(2) << iGiay;
}
/*
 * Hàm: TinhCongThemMotGiay
 * Chức năng: Cộng thêm 1 giây vào thời gian của đối tượng truyền vào, tự động tính toán nhớ phút, nhớ giờ.
 * Input: GioPhutGiay a (Đối tượng thời gian gốc cần cộng thêm 1 giây).
 * Output: GioPhutGiay (Một đối tượng thời gian mới đã được cộng thêm 1 giây).
 */
GioPhutGiay GioPhutGiay::TinhCongThemMotGiay(GioPhutGiay a) {
    GioPhutGiay kq = a; // Copy toàn bộ dữ liệu từ đối tượng a sang đối tượng kq (kết quả)
    kq.iGiay++; // Cộng thêm 1 giây
    // Xử lý tràn giây (nhớ lên phút)
    if (kq.iGiay >= 60) {
        kq.iGiay = 0;
        kq.iPhut++;
        // Xử lý tràn phút (nhớ lên giờ)
        if (kq.iPhut >= 60) {
            kq.iPhut = 0;
            kq.iGio++;
            // Xử lý tràn giờ (qua ngày mới)
            if (kq.iGio >= 24) {
                kq.iGio = 0;
            }
        }
    }
    return kq;
}