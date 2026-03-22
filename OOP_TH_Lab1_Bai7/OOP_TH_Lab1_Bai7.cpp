#include <iostream>
#include <string>

using namespace std;

struct Date {
    int ngay;
    int thang;
    int nam;
};

struct Time {
    int gio;
    int phut;
};

struct ChuyenBay {
    string maCB;
    Date ngayBay;
    Time gioBay;
    string noiDi;
    string noiDen;
};

/*
 * Hàm isAlphaNum: Kiểm tra tính hợp lệ của mã số chuyến bay.
 * Đầu vào: Chuỗi s (Mã chuyến bay cần kiểm tra).
 * Đầu ra: Trả về true nếu độ dài từ 1-5 và chỉ chứa chữ cái hoặc số, ngược lại trả về false.
 */
bool isAlphaNum(string s) { 
    if (s.length() == 0 || s.length() > 5) return false;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))) {
            return false;
        }
    }
    return true;
}

/*
 * Hàm isLocation: Kiểm tra tính hợp lệ của tên địa điểm.
 * Đầu vào: Chuỗi s (Tên địa điểm cần kiểm tra).
 * Đầu ra: Trả về true nếu độ dài từ 1-20 và chỉ chứa chữ cái hoặc khoảng trắng, ngược lại trả về false.
 */
bool isLocation(string s) { 
    if (s.length() == 0 || s.length() > 20) return false;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ')) {
            return false;
        }
    }
    return true;
}

/*
 * Hàm namNhuan: Kiểm tra một năm cụ thể có phải là năm nhuận hay không.
 * Đầu vào: Số nguyên nam (Năm cần kiểm tra).
 * Đầu ra: Trả về true nếu là năm nhuận, ngược lại trả về false.
 */
bool namNhuan(int nam) {    
    return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
}

/*
 * Hàm soNgayTrongThang: Tính toán số lượng ngày tối đa của một tháng trong năm.
 * Đầu vào: Hai số nguyên thang và nam.
 * Đầu ra: Trả về số nguyên là số ngày của tháng đó (28, 29, 30 hoặc 31).
 */
int soNgayTrongThang(int thang, int nam) { 
    switch (thang) {
        case 4: case 6: case 9: case 11: return 30;
        case 2: return namNhuan(nam) ? 29 : 28;
        default: return 31;
    }
}

/*
 * Hàm kiemTraNgay: Xác thực dữ liệu ngày tháng năm có tồn tại trên thực tế không.
 * Đầu vào: Biến d thuộc kiểu cấu trúc Date.
 * Đầu ra: Trả về true nếu ngày tháng năm hợp lý, ngược lại trả về false.
 */
bool kiemTraNgay(Date d) { 
    if (d.nam < 1 || d.thang < 1 || d.thang > 12 || d.ngay < 1) return false;
    if (d.ngay > soNgayTrongThang(d.thang, d.nam)) return false;
    return true;
}

/*
 * Hàm kiemTraGio: Xác thực dữ liệu giờ phút có đúng định dạng 24h không.
 * Đầu vào: Biến t thuộc kiểu cấu trúc Time.
 * Đầu ra: Trả về true nếu giờ (0-23) và phút (0-59) hợp lệ, ngược lại trả về false.
 */
bool kiemTraGio(Time t) { 
    return (t.gio >= 0 && t.gio <= 23 && t.phut >= 0 && t.phut <= 59);
}

/*
 * Hàm nhap1CB: Thực hiện nhập liệu và kiểm tra tính hợp lệ cho một chuyến bay.
 * Đầu vào: Biến tham chiếu cb kiểu ChuyenBay. Dữ liệu thực tế được lấy từ bàn phím.
 * Đầu ra: Không có giá trị trả về (void). Biến cb sẽ chứa dữ liệu chuyến bay hoàn chỉnh và hợp lệ.
 */
void nhap1CB(ChuyenBay &cb) { 
    while (true) {
        cout << "Nhap ma chuyen bay: ";
        getline(cin, cb.maCB);
        if (isAlphaNum(cb.maCB)) break;
        cout << "Loi: Ma toi da 5 ky tu, khong chua khoang trang/ky tu dac biet.\n";
    }
    while (true) {
        cout << "Nhap ngay bay (ngay thang nam): ";
        cin >> cb.ngayBay.ngay >> cb.ngayBay.thang >> cb.ngayBay.nam;
        if (kiemTraNgay(cb.ngayBay)) break;
        cout << "Loi: Ngay khong hop le.\n";
    }
    while (true) {
        cout << "Nhap gio bay (gio phut): ";
        cin >> cb.gioBay.gio >> cb.gioBay.phut;
        if (kiemTraGio(cb.gioBay)) break;
        cout << "Loi: Gio khong hop le.\n";
    }
    cin.ignore();
    while (true) {
        cout << "Nhap noi di: ";
        getline(cin, cb.noiDi);
        if (isLocation(cb.noiDi)) break;
        cout << "Loi: Noi di toi da 20 ky tu, khong chua so/ky tu dac biet.\n";
    }
    while (true) {
        cout << "Nhap noi den: ";
        getline(cin, cb.noiDen);
        if (isLocation(cb.noiDen)) break;
        cout << "Loi: Noi den toi da 20 ky tu, khong chua so/ky tu dac biet.\n";
    }
}

/*
 * Hàm xuat1CB: In thông tin chi tiết của một chuyến bay ra màn hình.
 * Đầu vào: Biến cb kiểu ChuyenBay chứa dữ liệu cần in.
 * Đầu ra: Không có giá trị trả về (void). Xuất chuỗi thông tin ra console.
 */
void xuat1CB(ChuyenBay cb) { 
    cout << "Ma: " << cb.maCB 
         << " | Ngay: " << cb.ngayBay.ngay << "/" << cb.ngayBay.thang << "/" << cb.ngayBay.nam
         << " | Gio: " << cb.gioBay.gio << ":" << cb.gioBay.phut
         << " | Tu: " << cb.noiDi << " -> Den: " << cb.noiDen << "\n";
}

/*
 * Hàm nhapDS: Khởi tạo mảng động và nhập dữ liệu cho danh sách nhiều chuyến bay.
 * Đầu vào: Con trỏ ds (quản lý mảng) và số nguyên n (số lượng chuyến bay) truyền dạng tham chiếu.
 * Đầu ra: Không có giá trị trả về (void). Cấp phát bộ nhớ cho mảng ds và lưu toàn bộ dữ liệu người dùng nhập.
 */
void nhapDS(ChuyenBay* &ds, int &n) { 
    cout << "Nhap so luong chuyen bay: ";
    while(cin >> n) {
        if(n < 0) {
            cout << "Vui long nhap n >= 0: ";
        }
        else break;
    }
    cin.ignore();
    ds = new ChuyenBay[n];
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap chuyen bay thu " << i + 1 << " ---\n";
        nhap1CB(ds[i]);
    }
}

/*
 * Hàm xuatDS: In toàn bộ danh sách các chuyến bay hiện có.
 * Đầu vào: Con trỏ ds (chứa mảng chuyến bay) và số nguyên n (số lượng phần tử).
 * Đầu ra: Không có giá trị trả về (void). Gọi hàm xuat1CB lặp lại n lần.
 */
void xuatDS(ChuyenBay* ds, int n) { 
    for (int i = 0; i < n; i++) {
        xuat1CB(ds[i]);
    }
}

/*
 * Hàm timKiem: Quét mảng để tìm và in các chuyến bay khớp với từ khóa.
 * Đầu vào: Mảng ds, số lượng n, từ khóa key (chuỗi), và type (1: theo mã, 2: theo nơi đi, 3: theo nơi đến).
 * Đầu ra: Không có giá trị trả về (void). In ra các chuyến bay thỏa mãn điều kiện hoặc thông báo không tìm thấy.
 */
void timKiem(ChuyenBay* ds, int n, string key, int type) { 
    bool found = false;
    for (int i = 0; i < n; i++) {
        if ((type == 1 && ds[i].maCB == key) ||
            (type == 2 && ds[i].noiDi == key) ||
            (type == 3 && ds[i].noiDen == key)) {
            xuat1CB(ds[i]);
            found = true;
        }
    }
    if (!found) cout << "Khong tim thay ket qua.\n";
}

/*
 * Hàm soSanhThoiGian: So sánh mốc thời gian khởi hành giữa 2 chuyến bay.
 * Đầu vào: Hai biến a và b kiểu ChuyenBay cần so sánh.
 * Đầu ra: Trả về số > 0 nếu a bay sau b, số < 0 nếu a bay trước b, số 0 nếu cùng thời điểm.
 */
int soSanhThoiGian(ChuyenBay a, ChuyenBay b) { 
    if (a.ngayBay.nam != b.ngayBay.nam) return a.ngayBay.nam - b.ngayBay.nam;
    if (a.ngayBay.thang != b.ngayBay.thang) return a.ngayBay.thang - b.ngayBay.thang;
    if (a.ngayBay.ngay != b.ngayBay.ngay) return a.ngayBay.ngay - b.ngayBay.ngay;
    if (a.gioBay.gio != b.gioBay.gio) return a.gioBay.gio - b.gioBay.gio;
    return a.gioBay.phut - b.gioBay.phut;
}

/*
 * Hàm sapXep: Sắp xếp danh sách chuyến bay theo thời gian tăng dần (từ sớm đến muộn).
 * Đầu vào: Con trỏ ds (chứa mảng chuyến bay) và số nguyên n (số lượng phần tử).
 * Đầu ra: Không có giá trị trả về (void). Các phần tử trong mảng ds bị thay đổi thứ tự.
 */
void sapXep(ChuyenBay* ds, int n) { 
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (soSanhThoiGian(ds[i], ds[j]) > 0) {
                swap(ds[i], ds[j]);
            }
        }
    }
}

/*
 * Hàm lietKeTheoNoiDiVaNgay: Tìm và in các chuyến bay khởi hành từ một địa điểm vào một ngày cụ thể.
 * Đầu vào: Mảng ds, số lượng n, chuỗi noidi, và biến ngay kiểu Date.
 * Đầu ra: Không có giá trị trả về (void). In kết quả ra màn hình hoặc báo lỗi nếu không có.
 */
void lietKeTheoNoiDiVaNgay(ChuyenBay* ds, int n, string noidi, Date ngay) { 
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (ds[i].noiDi == noidi && 
            ds[i].ngayBay.ngay == ngay.ngay && 
            ds[i].ngayBay.thang == ngay.thang && 
            ds[i].ngayBay.nam == ngay.nam) {
            xuat1CB(ds[i]);
            found = true;
        }
    }
    if (!found) cout << "Khong co chuyen bay nao phu hop.\n";
}

/*
 * Hàm demChuyenBay: Đếm số lượng chuyến bay có chung lộ trình (nơi đi - nơi đến).
 * Đầu vào: Mảng ds, số lượng n, chuỗi noidi và chuỗi noiden.
 * Đầu ra: Trả về số nguyên đại diện cho tổng số chuyến bay khớp với lộ trình.
 */
int demChuyenBay(ChuyenBay* ds, int n, string noidi, string noiden) { 
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i].noiDi == noidi && ds[i].noiDen == noiden) {
            count++;
        }
    }
    return count;
}

int main() {
    int n = 0;
    ChuyenBay* ds = nullptr;

    nhapDS(ds, n);
    if(n == 0) {
        cout << "==========KET THUC==========\n";
        return 0;
    }
    cout << "\n=== DANH SACH VUA NHAP ===\n";
    xuatDS(ds, n);
    cout << "============================\n";
    cout << "=== Tim chuyen bay theo ma chuyen bay ===\n";
    cout << "Nhap ma chuyen bay muon tim kiem: ";
    string s;
    getline(cin , s);
    cout << "\n=== KIEM TRA MA CHUYEN BAY '" << s << "' ===\n";
    timKiem(ds, n, s, 1); 
    cout << "============================\n";


    cout << "\n=== DANH SACH DA SAP XEP ===\n";
    sapXep(ds, n);
    xuatDS(ds, n);
    cout << "============================\n";
    string diaDiem;
    cout << "=== Tim kiem chuyen bay co noi khoi hanh va ngay di cu the ===\n";
    while (true) {
        cout << "Nhap noi khoi hanh cu the de hien thi danh sach: ";
        getline(cin, diaDiem);
        if (isLocation(diaDiem)) break;
        cout << "Loi: Noi di toi da 20 ky tu, khong chua so/ky tu dac biet.\n";
    }
    Date thoiGian;
    while(true) {
        cout << "Nhap thoi gian cu the de hien thi danh sach: ";
        cin >> thoiGian.ngay >> thoiGian.thang >> thoiGian.nam;
        if (kiemTraNgay(thoiGian)) break;
        cout << "Loi: Ngay khong hop le.\n";
    }
    cin.ignore();
    cout << "\n=== TIM CHUYEN BAY TU "<< diaDiem << " NGAY " << thoiGian.ngay << "/" << thoiGian.thang << "/" << thoiGian.nam << " ===\n";
    lietKeTheoNoiDiVaNgay(ds, n, diaDiem, thoiGian);
    cout << "============================\n";
    string noiDi;
    cout << "=== Dem so luong chuyen bay co noi di va noi den ===\n";
    while (true) {
        cout << "Nhap noi khoi hanh cu the de hien thi danh sach: ";
        getline(cin, noiDi);
        if (isLocation(noiDi)) break;
        cout << "Loi: Noi di toi da 20 ky tu, khong chua so/ky tu dac biet.\n";
    }
    string noiDen;
    while (true) {
        cout << "Nhap noi den cu the de hien thi danh sach: ";
        getline(cin, noiDen);
        if (isLocation(noiDen)) break;
        cout << "Loi: Noi den toi da 20 ky tu, khong chua so/ky tu dac biet.\n";
    }
    cout << "\n=== SO CHUYEN BAY TU " << noiDi << " DEN " << noiDen << "===\n";
    int soLuong = demChuyenBay(ds, n, noiDi, noiDen);
    cout << "Co " << soLuong << " chuyen bay thoa man.\n";
    cout << "==========KET THUC==========\n";
    delete[] ds;
    return 0;
}
