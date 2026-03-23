#include <iostream>
#include <limits>
#include <iomanip>
#include <string>

using namespace std;
struct HocSinh {
    string ten;
    double toan, van, anh;
};
typedef HocSinh Hs;

/*
 * Hàm KiemTraSo: Kiểm tra và nhập số lượng học sinh (1-100).
 * Đầu vào: Không có tham số đầu vào. Hàm sẽ yêu cầu người dùng nhập từ bàn phím.
 * Đầu ra: Trả về một số nguyên hợp lệ trong khoảng 1-100.
 */
int KiemTraSo() { // hàm kiểm tra đầu vào: số học sinh là số nguyên dương và trong khoảng 1-100
    int n;
    while(true) {
        if(cin >> n) {
            if(n > 0 && n <= 100) {
                // nếu đúng thì trả về và thoát vòng lặp
                return n; // trả về số nguyên dương hợp lệ
            }
            // nếu nhập số nhưng không đúng điều kiện 1-100, yêu cầu nhập lại
            cout << "So luong khong hop le! Vui long nhap lai so luong hoc sinh (1-100): ";
        } else {
            // nếu là chữ hoặc kí tự đặc biệt
            cout << "Dau vao khong hop le! Vui long nhap lai so luong hoc sinh (1-100): ";
            cin.clear(); // xóa trạng thái lỗi của đối tượng cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // bỏ qua toàn bộ kí tự rác trong bộ nhớ đệm
        }
    }
}

/*
 * Hàm KiemTraDiem: Kiểm tra và nhập điểm số (0-10).
 * Đầu vào: Không có tham số đầu vào. Hàm sẽ yêu cầu người dùng nhập từ bàn phím.
 * Đầu ra: Trả về một số thực hợp lệ trong khoảng 0-10.
 */
double KiemTraDiem() { // Hàm kiểm tra nhập điểm hợp lệ trong khoảng 0-10, gồm cả xử lý sai kiểu và sai miền
    double n;
    while(true) {
        if(cin >> n) {
            if(n >= 0 && n <= 10) {
                // nhập đúng điều kiện, xoá phần thừa trong bộ đệm để chuẩn bị cho getline() nếu cần
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return n; // trả về số điểm hợp lệ
            }
            // giá trị số nhưng ngoài miền 0-10, yêu cầu nhập lại
            cout << "Diem khong hop le! Vui long nhap lai diem (0-10): ";
        } else {
            // nếu nhập không phải số (ký tự/dấu), reset và bỏ bộ đệm rồi yêu cầu lại
            cout << "Dau vao khong hop le! Vui long nhap lai so diem (0-10): ";
            cin.clear(); // xóa trạng thái lỗi của đối tượng cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // bỏ qua toàn bộ kí tự rác trong bộ nhớ đệm
        }
    }
}

/*
 * Hàm KiemTraTen: Kiểm tra tính hợp lệ của tên học sinh.
 * Đầu vào: Tham chiếu đến chuỗi ten (được truyền bằng tham chiếu để có thể thay đổi nếu cần).
 * Đầu ra: Trả về true nếu tên hợp lệ, false nếu không.
 */
bool KiemTraTen(string &ten) { // Kiểm tra tính hợp lệ của tên
    int lenght = ten.length();
    if(lenght > 26 || lenght == 0) return false; // Kiểm tra độ dài
    if(ten[0] == ' ' || ten[lenght - 1] == ' ') return false; // kiểm tra đầu chuỗi có dấu cách hay cuối chuỗi có dấu cách không
    for(int i = 0; ten[i] != '\0'; i++) {
        if(ten[i] == ' ') {
            if(i + 1 < lenght && ten[i+1] == ' ') return false; // Kiểm tra có nhiều dấu cách trong tên hay không
            continue;
        }
        if((ten[i] < 'A' || ten[i] > 'Z') && (ten[i] < 'a' || ten[i] > 'z')) return false; // kiểm tra xem có kí tự đặc biệt hay số không
        bool chuDau = (i == 0 || ten[i-1] ==  ' '); // đặt cờ cho chữ đầu
        if(chuDau) { // nếu là chữ đầu kiểm tra xem có viết hoa không
            if(ten[i] < 'A' || ten[i] > 'Z') return false;
            }
        else {
            if(ten[i] < 'a' || ten[i] > 'z') return false; // nếu chữ bình thường kiểm tra xem có viết thường không
        }
    }
    return true;
}

/*
 * Hàm NhapHocSinh: Nhập thông tin của một học sinh.
 * Đầu vào: Tham chiếu đến một biến Hs hs (được truyền bằng tham chiếu để thay đổi giá trị).
 * Đầu ra: Không trả về giá trị, nhưng thay đổi giá trị của hs.
 */
void NhapHocSinh(Hs &hs) { // hàm nhập 1 học sinh
    while(true) {
        getline(cin, hs.ten);
        if(KiemTraTen(hs.ten)) {
            break;
        }
        else {
            cout << "Ten khong hop le (chu so, ki tu dac biet, sai in hoa, hoac qua 26 ki tu)!" << endl;
            cout << "Vui long nhap lai ten: ";
        }
    }
    // nhập điểm toán, văn, anh
    cout << "Nhap diem Toan: "; hs.toan = KiemTraDiem();
    cout << "Nhap diem Van: "; hs.van = KiemTraDiem();
    cout << "Nhap diem Anh: "; hs.anh = KiemTraDiem();
}

/*
 * Hàm Nhap: Nhập danh sách học sinh.
 * Đầu vào: Mảng ds[] và tham chiếu đến n (được truyền bằng tham chiếu để thay đổi giá trị).
 * Đầu ra: Không trả về giá trị, nhưng thay đổi nội dung của ds và n.
 */
void Nhap(Hs ds[], int &n) { // hàm nhập danh sách học sinh
    n = KiemTraSo();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // xóa bộ nhớ đệm để chuẩn bị nhập tên
    for(int i = 0; i < n; i++) {
        cout << "Nhap ten hoc sinh thu " << i+1 << ": ";
        NhapHocSinh(ds[i]);
    }
}

/*
 * Hàm caculate: Tính điểm trung bình của một học sinh.
 * Đầu vào: Một biến Hs hs (truyền bằng giá trị).
 * Đầu ra: Trả về điểm trung bình dưới dạng double.
 */
double caculate(Hs hs) { // hàm tính điểm trung bình
    return (hs.toan*2 + hs.van + hs.anh)/4;
}

/*
 * Hàm phanLoaiHocSinh: Phân loại học sinh dựa trên điểm trung bình.
 * Đầu vào: Mảng ds[] và số n (số học sinh).
 * Đầu ra: Không trả về giá trị, nhưng in ra phân loại của từng học sinh.
 */
void phanLoaiHocSinh(Hs ds[], int n) { // hàm phân loại học sinh
    cout << "======================================Phan loai hoc sinh========================================" << endl;
    for(int i = 0; i < n; i++) {
        double dtb = caculate(ds[i]);
        cout << "Ten: " << ds[i].ten << "    \t| Diem trung binh " << setprecision(2) << fixed << dtb << "\t\t| Xep loai: ";
        if(dtb < 5) cout << "Yeu" << endl;
        else if(dtb >= 5 && dtb < 6.5) cout << "Trung binh" << endl;
        else if(dtb >= 6.5 && dtb < 8) cout << "Kha" << endl;
        else if(dtb >= 8 && dtb < 9) cout << "Gioi" << endl;
        else cout << "Xuat sac" << endl;
    }
}

/*
 * Hàm HocSinhCoDiemTrungBinhCaoNhat: Tìm và in các học sinh có điểm trung bình cao nhất.
 * Đầu vào: Mảng ds[] và số n (số học sinh).
 * Đầu ra: Không trả về giá trị, nhưng in ra thông tin các học sinh có điểm trung bình cao nhất.
 */
void HocSinhCoDiemTrungBinhCaoNhat(Hs ds[], int n) { // hàm tìm các học sinh có điểm trung bình cao nhất
    double max_dtb = 0;
    for(int i = 0; i < n; i++) {
        if(caculate(ds[i]) > max_dtb) {
            max_dtb = caculate(ds[i]);
        }
    }
    cout << "============================Hoc sinh co diem trung binh cao nhat================================" << endl;
    cout << "================================================================================================" << endl;
    for(int i = 0; i < n; i++) {
        if(caculate(ds[i]) == max_dtb) {
            cout << "Ten: " << ds[i].ten << " | Diem Toan: " << ds[i].toan << " | Diem Van: " << ds[i].van << " | Diem Anh: " << ds[i].anh << " | Diem trung binh: " << setprecision(2) << fixed << caculate(ds[i]) << endl;
        }
    }
}

/*
 * Hàm chuyenChuThuong: Chuyển đổi chuỗi thành chữ thường.
 * Đầu vào: Chuỗi str (truyền bằng giá trị).
 * Đầu ra: Trả về chuỗi đã chuyển thành chữ thường.
 */
string chuyenChuThuong(string str) { // chuyển đổi các tên trong danh sách thành chữ thường hết cho dễ tìm
    string ketQua = "";
    for(int i = 0; i < str.length(); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            ketQua += (str[i] + 32); // Cộng 32 trong mã ASCII để đổi chữ Hoa thành chữ thường
        } else {
            ketQua += str[i];
        }
    }
    return ketQua;
}

/*
 * Hàm TimKiemTheoTen: Tìm kiếm học sinh theo tên (không phân biệt hoa thường, một phần tên).
 * Đầu vào: Mảng ds[], số n, và chuỗi tuKhoa.
 * Đầu ra: Không trả về giá trị, nhưng in ra kết quả tìm kiếm.
 */
void TimKiemTheoTen(Hs ds[], int n, string tuKhoa) { // Hàm tìm kiếm theo tên (Không phân biệt hoa thường, một phần tên)
    cout << "================================================================================================" << endl;
    cout << ">>> KET QUA TIM KIEM CHO TU KHOA \"" << tuKhoa << "\":" << endl;
    cout << "================================================================================================" << endl;
    bool timThay = false; // đặt cờ
    string tuKhoaThuong = chuyenChuThuong(tuKhoa); // Chuyển từ khóa về chữ thường
    for(int i = 0; i < n; i++) {
        string tenThuong = chuyenChuThuong(ds[i].ten); // Chuyển tên học sinh hiện tại về chữ thường
        // Dùng hàm find() để tìm chuỗi con. Nếu tìm thấy, find() trả về vị trí index, nếu không trả về string::npos
        if(tenThuong.find(tuKhoaThuong) != string::npos) {
            timThay = true;
            cout << "Ten: " << ds[i].ten << "| Diem Toan: " << ds[i].toan << " | Diem Van: " << ds[i].van << " | Diem Anh: " << ds[i].anh << " | Diem trung binh: " << setprecision(2) << fixed << caculate(ds[i]) << endl;
        }
    }
    if(!timThay) {
        cout << "Khong tim thay hoc sinh nao co tu khoa \"" << tuKhoa << "\"" << endl;
    }
}

/*
 * Hàm DanhSachDiemToanThapNhat: Tìm và in danh sách học sinh có điểm Toán thấp nhất.
 * Đầu vào: Mảng ds[] và số n (số học sinh).
 * Đầu ra: Không trả về giá trị, nhưng in ra danh sách học sinh có điểm Toán thấp nhất.
 */
void DanhSachDiemToanThapNhat(Hs ds[], int n) {
    double min_toan = ds[0].toan;
    for(int i = 1; i < n; i++) {
        if(ds[i].toan < min_toan) {
            min_toan = ds[i].toan;
        }
    }
    cout << "================================================================================================" << endl;
    cout << "\n======================DANH SACH HOC SINH CO DIEM TOAN THAP NHAT (" << min_toan << " diem)=====================" << endl;
    for(int i = 0; i < n; i++) {
        if(ds[i].toan == min_toan) {
            cout << "Ten: "<< ds[i].ten << " | Diem Toan: " << ds[i].toan << endl;
        }
    }
}

/*
 * Hàm main: Hàm chính của chương trình, thực hiện nhập danh sách học sinh, phân loại, tìm học sinh điểm cao nhất, tìm kiếm theo tên, và in danh sách điểm Toán thấp nhất.
 * Đầu vào: Không có tham số.
 * Đầu ra: Trả về 0 khi chương trình kết thúc thành công.
 */
int main() {
    // Hàm main điều khiển luồng: nhập danh sách, phân loại, in học sinh điểm cao nhất, tìm kiếm và kết thúc.
    Hs ds[100];
    int n;
    cout << "Nhap so luong hoc sinh (0-100): ";
    Nhap(ds, n);
    phanLoaiHocSinh(ds, n);
    HocSinhCoDiemTrungBinhCaoNhat(ds, n);
    string tuKhoa;
    cout << "================================================================================================" << endl;
    cout << "Nhap ten/tu khoa can tim kiem (bam Enter de bo qua): ";
    getline(cin, tuKhoa); 
    if(tuKhoa.length() > 0) {
        TimKiemTheoTen(ds, n, tuKhoa);
    }
    DanhSachDiemToanThapNhat(ds, n);
    cout << "================================================================================================" << endl;
    cout << "========================================KET THUC================================================\n";
    return 0;
}
