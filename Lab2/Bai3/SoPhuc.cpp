#include <iostream>
#include <cmath>
#include "SoPhuc.h"
using namespace std;

/*
 * Hàm: Nhap
 * Chức năng: Yêu cầu người dùng nhập phần thực và phần ảo của số phức từ bàn phím.
 * Input: Không có (dữ liệu được lấy từ luồng nhập cin).
 * Output: Cập nhật trực tiếp giá trị vào thuộc tính iThuc và iAo của đối tượng gọi hàm.
 */
void SoPhuc::Nhap() {
    cout << "Nhap phan thuc: ";
    cin >> iThuc;
    cout << "Nhap phan ao: ";
    cin >> iAo;
}
/*
 * Hàm: LaSoKhong
 * Chức năng: Kiểm tra xem số phức có phải là số không không.
 * Input: iThuc, iAo.
 * Output: nếu là 0 thì trả về true khác 0 trả về false.
 */
bool SoPhuc::LaSoKhong() {
    return (iThuc == 0 && iAo == 0);
}
/*
 * Hàm: Xuat
 * Chức năng: Hiển thị số phức ra màn hình console theo định dạng "a + b*i" hoặc "a - b*i".
 * Input: Không có.
 * Output: In chuỗi ký tự biểu diễn số phức ra màn hình.
 */
void SoPhuc::Xuat() {
    // Trường hợp 1: Số bằng 0
    if (iThuc == 0 && iAo == 0) {
        cout << 0;
        return;
    }
    
    // Trường hợp 2: Có phần thực thì in phần thực ra trước
    if (iThuc != 0) {
        cout << iThuc;
    }
    
    // Trường hợp 3: Xử lý phần ảo
    if (iAo != 0) {
        // In dấu nối giữa thực và ảo
        if (iAo > 0 && iThuc != 0) cout << " + ";
        if (iAo < 0 && iThuc != 0) cout << " - ";
        if (iAo < 0 && iThuc == 0) cout << "-"; // Dấu trừ đứng đầu nếu không có phần thực
        
        // Lấy trị tuyệt đối để in số
        double absAo = abs(iAo);
        if (absAo != 1) {
            cout << absAo << "*i"; // In số bình thường nếu không phải số 1
        } else {
            cout << "i"; // Ẩn số 1 đi
        }
    }
}

/*
 * Hàm: TinhTong
 * Chức năng: Tính tổng của số phức hiện tại và một số phức khác: (a+c) + (b+d)i.
 * Input: SoPhuc a (Số phức thứ hai cần đem cộng).
 * Output: SoPhuc (Một đối tượng số phức mới lưu kết quả của phép cộng).
 */
SoPhuc SoPhuc::TinhTong(SoPhuc a) {
    SoPhuc kq;
    kq.iThuc = iThuc + a.iThuc;
    kq.iAo = iAo + a.iAo;
    return kq;
}

/*
 * Hàm: TinhHieu
 * Chức năng: Tính hiệu của số phức hiện tại trừ đi một số phức khác: (a-c) + (b-d)i.
 * Input: SoPhuc a (Số phức thứ hai cần đem trừ).
 * Output: SoPhuc (Một đối tượng số phức mới lưu kết quả của phép trừ).
 */
SoPhuc SoPhuc::TinhHieu(SoPhuc a) {
    SoPhuc kq;
    kq.iThuc = iThuc - a.iThuc;
    kq.iAo = iAo - a.iAo;
    return kq;
}

/*
 * Hàm: TinhTich
 * Chức năng: Tính tích của hai số phức theo công thức: (ac - bd) + (ad + bc)i.
 * Input: SoPhuc a (Số phức thứ hai cần đem nhân).
 * Output: SoPhuc (Một đối tượng số phức mới lưu kết quả của phép nhân).
 */
SoPhuc SoPhuc::TinhTich(SoPhuc a) {
    SoPhuc kq;
    kq.iThuc = (iThuc * a.iThuc) - (iAo * a.iAo);
    kq.iAo = (iThuc * a.iAo) + (iAo * a.iThuc);
    return kq;
}

/*
 * Hàm: TinhThuong
 * Chức năng: Tính thương của phép chia hai số phức. Có kiểm tra lỗi chia cho 0.
 * Input: SoPhuc a (Số phức đóng vai trò làm số chia).
 * Output: SoPhuc (Đối tượng số phức mới lưu kết quả. Nếu số chia bằng 0, báo lỗi và trả về 0+0i).
 */
SoPhuc SoPhuc::TinhThuong(SoPhuc a) {
    // Tính mẫu số chung: c^2 + d^2
    double mauSo = (a.iThuc * a.iThuc) + (a.iAo * a.iAo);
    
    if (mauSo == 0) {
        SoPhuc kq;
        kq.iThuc = 0;
        kq.iAo = 0;
        return kq;
    }
    
    SoPhuc kq;
    kq.iThuc = ((iThuc * a.iThuc) + (iAo * a.iAo)) / mauSo;
    kq.iAo = ((iAo * a.iThuc) - (iThuc * a.iAo)) / mauSo;
    return kq;
}