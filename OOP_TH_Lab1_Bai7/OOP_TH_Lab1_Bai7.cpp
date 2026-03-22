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
bool isAlphaNum(string s) { // hàm kiểm tra sự hợp lệ của mã số chuyến bay
    if (s.length() == 0 || s.length() > 5) return false;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))) {
            return false;
        }
    }
    return true;
}
bool isLocation(string s) { // hàm kiểm tra sự hợp lệ của tên địa điểm
    if (s.length() == 0 || s.length() > 20) return false;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ')) {
            return false;
        }
    }
    return true;
}
bool namNhuan(int nam) {    // hàm kiểm tra năm nhuận
    return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
}
int soNgayTrongThang(int thang, int nam) { // hàm tính số ngày trong tháng
    switch (thang) {
        case 4: case 6: case 9: case 11: return 30;
        case 2: return namNhuan(nam) ? 29 : 28;
        default: return 31;
    }
}
bool kiemTraNgay(Date d) { // hàm kiểm tra tính hợp lệ của ngày tháng
    if (d.nam < 1 || d.thang < 1 || d.thang > 12 || d.ngay < 1) return false;
    if (d.ngay > soNgayTrongThang(d.thang, d.nam)) return false;
    return true;
}
bool kiemTraGio(Time t) { // hàm kiểm tra tính hợp lệ của giờ
    return (t.gio >= 0 && t.gio <= 23 && t.phut >= 0 && t.phut <= 59);
}
void nhap1CB(ChuyenBay &cb) { // hàm nhập 1 chuyến bay
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
void xuat1CB(ChuyenBay cb) { // hàm xuất 1 chuyến bay
    cout << "Ma: " << cb.maCB 
         << " | Ngay: " << cb.ngayBay.ngay << "/" << cb.ngayBay.thang << "/" << cb.ngayBay.nam
         << " | Gio: " << cb.gioBay.gio << ":" << cb.gioBay.phut
         << " | Tu: " << cb.noiDi << " -> Den: " << cb.noiDen << "\n";
}

void nhapDS(ChuyenBay* &ds, int &n) { // hàm nhập danh sách chuyến bay
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

void xuatDS(ChuyenBay* ds, int n) { // hàm xuất danh sách chuyến bay
    for (int i = 0; i < n; i++) {
        xuat1CB(ds[i]);
    }
}

void timKiem(ChuyenBay* ds, int n, string key, int type) { // hàm tìm kiếm chuyến bay
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

int soSanhThoiGian(ChuyenBay a, ChuyenBay b) { // hàm so sánh thời gian để sắp xếp
    // nếu thời gian a sau thời gian b thì trả về giá trị dương và đảo vị trí của 2 ngày
    if (a.ngayBay.nam != b.ngayBay.nam) return a.ngayBay.nam - b.ngayBay.nam;
    if (a.ngayBay.thang != b.ngayBay.thang) return a.ngayBay.thang - b.ngayBay.thang;
    if (a.ngayBay.ngay != b.ngayBay.ngay) return a.ngayBay.ngay - b.ngayBay.ngay;
    if (a.gioBay.gio != b.gioBay.gio) return a.gioBay.gio - b.gioBay.gio;
    return a.gioBay.phut - b.gioBay.phut;
}
void sapXep(ChuyenBay* ds, int n) { // hàm sắp xếp bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (soSanhThoiGian(ds[i], ds[j]) > 0) {
                swap(ds[i], ds[j]);
            }
        }
    }
}
void lietKeTheoNoiDiVaNgay(ChuyenBay* ds, int n, string noidi, Date ngay) { // tìm kiếm theo nơi đi và ngày 
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
int demChuyenBay(ChuyenBay* ds, int n, string noidi, string noiden) { // đếm chuyến bay có nơi đi và nơi đến
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