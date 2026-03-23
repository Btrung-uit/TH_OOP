#include <iostream>
#include <cmath> // dùng cho hàm abs
#include <limits> // lấy giá trị tối đa của luồng nhập
using namespace std;
struct PhanSo {
    int tuso, mauso;
};

/*
 * Hàm KiemTra: Kiểm tra và nhập một số nguyên từ người dùng.
 * Đầu vào: Không có tham số đầu vào. Hàm sẽ yêu cầu người dùng nhập từ bàn phím.
 * Đầu ra: Trả về một số nguyên hợp lệ.
 */
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

/*
 * Hàm Nhap: Nhập tử số và mẫu số cho một phân số.
 * Đầu vào: Tham chiếu đến một biến PhanSo p (được truyền bằng tham chiếu để thay đổi giá trị).
 * Đầu ra: Không trả về giá trị, nhưng thay đổi giá trị của p.
 */
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

/*
 * Hàm ucln: Tính ước chung lớn nhất của hai số nguyên.
 * Đầu vào: Hai số nguyên a và b.
 * Đầu ra: Trả về ước chung lớn nhất của a và b.
 */
int ucln(int a, int b) { // hàm tìm ước chung lớn nhất của tử và mẫu
    if(b == 0) return a;
    return ucln(b, a%b);
}

/*
 * Hàm RutGon: Rút gọn phân số bằng cách chia tử và mẫu cho ước chung lớn nhất.
 * Đầu vào: Tham chiếu đến tử số và mẫu số (được truyền bằng tham chiếu để thay đổi giá trị).
 * Đầu ra: Không trả về giá trị, nhưng thay đổi giá trị của tuso và mauso để rút gọn.
 */
void RutGon(int &tuso, int &mauso) { // hàm thực hiện rút gọn phân số
    int uocChung = ucln(abs(tuso), abs(mauso)); // tìm ước chung
    tuso/=uocChung; // thực hiện chia tử cho ước chung tìm được ở trên để rút gọn
    mauso/=uocChung; // thực hiện chia mẫu cho ước chung tìm được ở trên để rút gọn
}

/*
 * Hàm XuatPhanSo: Xuất phân số ra màn hình.
 * Đầu vào: Tử số và mẫu số (truyền bằng giá trị).
 * Đầu ra: Không trả về giá trị, nhưng in ra màn hình.
 */
void XuatPhanSo(int tuso, int mauso) { // hàm xuất phân số
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

/*
 * Hàm Tong: Tính tổng của hai phân số.
 * Đầu vào: Hai phân số p1 và p2 (truyền bằng giá trị).
 * Đầu ra: Không trả về giá trị, nhưng in tổng ra màn hình.
 */
void Tong(PhanSo p1, PhanSo p2) { // hàm tính tổng 2 phân số
    cout << "Tong hai phan so la: ";
    int tuso = p1.tuso*p2.mauso + p1.mauso*p2.tuso;
    int mauso = p1.mauso*p2.mauso;
    RutGon(tuso, mauso);
    XuatPhanSo(tuso, mauso);
}

/*
 * Hàm Hieu: Tính hiệu của hai phân số.
 * Đầu vào: Hai phân số p1 và p2 (truyền bằng giá trị).
 * Đầu ra: Không trả về giá trị, nhưng in hiệu ra màn hình.
 */
void Hieu(PhanSo p1, PhanSo p2) { // hàm tính hiệu 2 phân số
    cout << "Hieu hai phan so la: ";
    int tuso = p1.tuso*p2.mauso - p1.mauso*p2.tuso;
    int mauso = p1.mauso*p2.mauso;
    RutGon(tuso, mauso);
    XuatPhanSo(tuso, mauso);
}

/*
 * Hàm Tich: Tính tích của hai phân số.
 * Đầu vào: Hai phân số p1 và p2 (truyền bằng giá trị).
 * Đầu ra: Không trả về giá trị, nhưng in tích ra màn hình.
 */
void Tich(PhanSo p1, PhanSo p2) { // hàm tính tích 2 phân số
    cout << "Tich hai phan so la: ";
    int tuso = p1.tuso*p2.tuso;
    int mauso = p1.mauso*p2.mauso;
    RutGon(tuso, mauso);
    XuatPhanSo(tuso, mauso);
}

/*
 * Hàm Thuong: Tính thương của hai phân số.
 * Đầu vào: Hai phân số p1 và p2 (truyền bằng giá trị).
 * Đầu ra: Không trả về giá trị, nhưng in thương ra màn hình.
 */
void Thuong(PhanSo p1, PhanSo p2) { // hàm tính thương 2 phân số
    cout << "Thuong hai phan so la: ";
    if (p2.tuso == 0) {
        cout << "Khong the chia do phan so thu 2 bang 0!" << endl;
        return;
    }
    int tuso = p1.tuso*p2.mauso;
    int mauso = p1.mauso*p2.tuso;
    RutGon(tuso, mauso);
    XuatPhanSo(tuso, mauso);
}

/*
 * Hàm TinhToan: Thực hiện tất cả các phép tính (tổng, hiệu, tích, thương) trên hai phân số.
 * Đầu vào: Hai phân số p1 và p2 (truyền bằng giá trị).
 * Đầu ra: Không trả về giá trị, nhưng in kết quả của tất cả các phép tính ra màn hình.
 */
void TinhToan(PhanSo p1, PhanSo p2) { // hàm tính toán
    Tong(p1, p2);
    Hieu(p1, p2);
    Tich(p1, p2);
    Thuong(p1, p2);
}

/*
 * Hàm main: Hàm chính của chương trình, thực hiện nhập hai phân số và tính toán các phép tính trên chúng.
 * Đầu vào: Không có tham số.
 * Đầu ra: Trả về 0 khi chương trình kết thúc thành công.
 */
int main() {
    PhanSo p1,p2;
    cout << "Nhap phan so thu nhat:\n";
    Nhap(p1);
    cout << "Nhap phan so thu hai:\n";
    Nhap(p2);
    TinhToan(p1, p2);
    return 0;   
}
