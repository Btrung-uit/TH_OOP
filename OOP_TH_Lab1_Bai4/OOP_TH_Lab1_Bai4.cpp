#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

/*
 * Hàm KiemTra: Kiểm tra và nhập một số thực từ người dùng.
 * Đầu vào: Không có tham số đầu vào. Hàm sẽ yêu cầu người dùng nhập từ bàn phím.
 * Đầu ra: Trả về một số thực hợp lệ.
 */
double KiemTra() { // hàm kiểm tra điều kiện đầu vào có phải là số thực không, nếu không phải là số nguyên thì nhập lại
    double n;
    while(true) {
        if(cin >> n) {
            // nếu đúng là số thực thì thoát vòng lặp
            break;
        }
        else {
            // nếu là chữ hoặc kí tự đặc biệt
            cout << "Dau vao khong hop le! Vui long nhap lai: ";
            cin.clear(); // xóa trạng thái lỗi của đối tượng cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // bỏ qua toàn bộ kí tự rác trong bộ nhớ đệm
        }
    }
    // trả về số thực hợp lệ
    return n;
}

/*
 * Hàm tinhSin: Tính giá trị sin(x) bằng cách sử dụng chuỗi Taylor với độ chính xác 0.00001.
 * Đầu vào: Một số thực x (góc tính bằng radian).
 * Đầu ra: Trả về giá trị sin(x) dưới dạng double.
 */
double tinhSin(double x) { // hàm tính sin(x)
    double sum = x; // giá trị sin(x) sẽ được trả về
    double soHang = x;  // đây là giá trị để so sánh với độ chính xác để biết khi nào dừng vòng lặp
    int mauSo = 3; // đây là số để tính giai thừa trong công thức
    while(abs(soHang) >= 0.00001) { // vòng lặp bắt đầu
        soHang = -soHang * x * x/(mauSo * (mauSo-1)); // tính số hiện tại để cộng vào sum và dùng để so sánh với độ chính xác
        sum += soHang; // cộng vào sum
        mauSo += 2; // tăng biến soHang lên 2 để phù hợp với công thức
    }
    return sum; // trả về sum tức sin(x) cần tìm
}

/*
 * Hàm main: Hàm chính của chương trình, nhập giá trị x và tính sin(x).
 * Đầu vào: Không có tham số.
 * Đầu ra: Trả về 0 khi chương trình kết thúc thành công.
 */
int main() {
    double x;
    cout << "Nhap gia tri cua x: ";
    x = KiemTra();
    cout << "Gia tri cua sin(x) voi do chinh xac 0.00001 la: " << tinhSin(x);
}
