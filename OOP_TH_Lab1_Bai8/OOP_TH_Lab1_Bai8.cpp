#include <iostream>
#include <string>

using namespace std;

struct Date {
    int ngay;
    int thang;
    int nam;
};

struct SoTietKiem {
    string maSo;
    string loaiTK;
    string hoTen;
    string cmnd;
    Date ngayMoSo;
    double soTienGui;
};

void xoaBoDem() { // hàm hỗ trợ dọn dẹp bộ đệm khi nhập sai kiểu dữ liệu
    cin.clear();
    cin.ignore(10000, '\n');
}

bool isAlphaNum(string s, int maxLen) { // hàm kiểm tra mã số hợp lệ (chữ, số)
    if (s.length() == 0 || s.length() > maxLen) return false;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))) {
            return false;
        }
    }
    return true;
}

bool isTextOnly(string s, int maxLen) { // hàm kiểm tra văn bản (chữ, khoảng trắng)
    if (s.length() == 0 || s.length() > maxLen) return false;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ')) {
            return false;
        }
    }
    return true;
}
bool KiemTraTen(string &ten) { // Kiểm tra tính hợp lệ của tên
    int lenght = ten.length();
    if(lenght > 30 || lenght == 0) return false; // Kiểm tra độ dài
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
bool isCMND(string s) { // hàm kiểm tra định dạng CMND (9 hoặc 12 số)
    if (s.length() != 9 && s.length() != 12) return false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}

bool namNhuan(int nam) { // hàm kiểm tra năm nhuận
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

int tinhSoNgay(Date d) { // hàm quy đổi ngày ra số nguyên tuyệt đối để tính khoảng cách
    int days = d.ngay;
    for (int y = 1; y < d.nam; y++) days += namNhuan(y) ? 366 : 365;
    for (int m = 1; m < d.thang; m++) days += soNgayTrongThang(m, d.nam);
    return days;
}

int khoangCachNgay(Date batDau, Date ketThuc) { // hàm tính khoảng cách giữa 2 ngày
    return tinhSoNgay(ketThuc) - tinhSoNgay(batDau);
}

int soSanhNgay(Date a, Date b) { // hàm so sánh thứ tự thời gian
    if (a.nam != b.nam) return a.nam - b.nam;
    if (a.thang != b.thang) return a.thang - b.thang;
    return a.ngay - b.ngay;
}

double nhapTien() { // hàm ép buộc nhập số tiền dương, chống sập luồng cin
    double tien;
    while (true) {
        if (cin >> tien && tien > 0) {
            xoaBoDem();
            return tien;
        }
        cout << "Loi: So tien phai la so duong (khong nhap chu hoac ky tu dac biet): ";
        xoaBoDem();
    }
}

bool KiemTraLoaiTaiKhoang(string loaiTK) {
    return (loaiTK == "ngan han" || loaiTK == "dai han");
}
bool kiemTraNgayHienTai(SoTietKiem* ds, int n, Date hienTai) {
    // Ngày hiện tại phải lớn hơn hoặc bằng ngày mở sổ của tất cả các sổ
    for (int i = 0; i < n; i++) {
        if (soSanhNgay(hienTai, ds[i].ngayMoSo) < 0) {
            return false; 
        }
    }
    return true;
}
void nhap1So(SoTietKiem &stk) { // hàm nhập 1 sổ tiết kiệm
    while (true) {
        cout << "Nhap ma so (toi da 5 ky tu): ";
        getline(cin, stk.maSo);
        if (isAlphaNum(stk.maSo, 5)) break;
        cout << "Loi: Ma so khong hop le.\n";
    }

    while (true) {
        cout << "Nhap loai tiet kiem (ngan han / dai han): ";
        getline(cin, stk.loaiTK);
        if (KiemTraLoaiTaiKhoang(stk.loaiTK)) break;
        cout << "Loi: Loai tiet kiem khong hop le.\n";
    }

    while (true) {
        cout << "Nhap ho ten khach hang (toi da 30 ky tu): ";
        getline(cin, stk.hoTen);
        if (KiemTraTen(stk.hoTen)) break;
        cout << "Loi: Ho ten khong hop le.\n";
    }

    while (true) {
        cout << "Nhap CMND (dung 9 hoac 12 so): ";
        getline(cin, stk.cmnd);
        if (isCMND(stk.cmnd)) break;
        cout << "Loi: CMND chi duoc chua so va phai co 9/12 ky tu.\n";
    }

    while (true) {
        cout << "Nhap ngay mo so (ngay thang nam cach nhau boi khoang trang): ";
        if (cin >> stk.ngayMoSo.ngay >> stk.ngayMoSo.thang >> stk.ngayMoSo.nam && kiemTraNgay(stk.ngayMoSo)) {
            xoaBoDem();
            break;
        }
        cout << "Loi: Ngay khong hop le hoac sai dinh dang.\n";
        xoaBoDem();
    }

    cout << "Nhap so tien gui (VND): ";
    stk.soTienGui = nhapTien();
}

void xuat1So(SoTietKiem stk) { // hàm xuất 1 sổ tiết kiệm
    cout << "Ma: " << stk.maSo << " | Loai TK: " << stk.loaiTK << " | Ho ten: " << stk.hoTen 
         << " | CMND: " << stk.cmnd << " | Ngay mo: " << stk.ngayMoSo.ngay << "/" << stk.ngayMoSo.thang << "/" << stk.ngayMoSo.nam
         << " | Tien gui: " << stk.soTienGui << " VND\n";
}

void nhapDS(SoTietKiem* &ds, int &n) { // hàm nhập danh sách sổ tiết kiệm
    cout << "Nhap so luong so tiet kiem: ";
    while (true) {
        if (cin >> n && n >= 0) {
            xoaBoDem();
            break;
        }
        cout << "Loi: Vui long nhap so nguyen duong: ";
        xoaBoDem();
    }

    ds = new SoTietKiem[n];
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap so tiet kiem thu " << i + 1 << " ---\n";
        nhap1So(ds[i]);
    }
}

void xuatDS(SoTietKiem* ds, int n) { // hàm xuất danh sách
    for (int i = 0; i < n; i++) {
        xuat1So(ds[i]);
    }
}

void tinhVaCapNhatLai(SoTietKiem &stk, double laiSuatNam, Date ngayHienTai) { // hàm tính tiền lãi
    int soNgay = khoangCachNgay(stk.ngayMoSo, ngayHienTai);
    if (soNgay <= 0) {
        cout << "Ngay hien tai khong hop le hoac chua phat sinh lai.\n";
        return;
    }
    
    double tienLai = stk.soTienGui * (laiSuatNam / 100.0) * (soNgay / 365.0);
    stk.soTienGui += tienLai;
    cout << "=> So ngay gui: " << soNgay << " ngay. Tien lai uoc tinh: " << tienLai << " VND\n";
}

void rutTien(SoTietKiem &stk, Date ngayHienTai) { // hàm rút tiền và phạt trước hạn
    cout << "=== RUTH TIEN GIAO DICH ===\n";
    cout << "Ban dang rut tien cho so: " << stk.maSo << "\n";
    
    int soNgayGui = khoangCachNgay(stk.ngayMoSo, ngayHienTai);
    bool truocHan = false;
    
    // Giả định: Dài hạn là > 180 ngày (6 tháng). Rút trước 180 ngày bị tính trước hạn.
    if (stk.loaiTK == "dai han" && soNgayGui <= 180) {
        cout << "CANH BAO: Ban dang rut tien truoc ky han! Lai suat ap dung se bi ha xuong 0.5%/nam.\n";
        truocHan = true;
    }
    
    double laiSuatThucTe = truocHan ? 0.5 : 5.0; // Giả định lãi thường là 5%
    double tienLai = stk.soTienGui * (laiSuatThucTe / 100.0) * (soNgayGui / 365.0);
    
    cout << "Nhap so tien can rut (nhap 0 de huy): ";
    double tienRut = nhapTien();
    
    if (tienRut > stk.soTienGui) {
        cout << "Giao dich that bai: So du khong du.\n";
    } else {
        stk.soTienGui -= tienRut;
        cout << "Rut thanh cong " << tienRut << " VND. Tien lai duoc cong vao the: " << tienLai << " VND\n";
        cout << "So du con lai: " << stk.soTienGui << " VND\n";
    }
}

void timKiem(SoTietKiem* ds, int n, string key, int type) { // hàm tìm kiếm (1: maSo, 2: cmnd)
    bool found = false;
    for (int i = 0; i < n; i++) {
        if ((type == 1 && ds[i].maSo == key) || (type == 2 && ds[i].cmnd == key)) {
            xuat1So(ds[i]);
            found = true;
        }
    }
    if (!found) cout << "Khong tim thay so tiet kiem.\n";
}

void lietKeTheoGiaiDoan(SoTietKiem* ds, int n, Date tuNgay, Date denNgay) { // liệt kê sổ mở trong khoảng thời gian
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (soSanhNgay(ds[i].ngayMoSo, tuNgay) >= 0 && soSanhNgay(ds[i].ngayMoSo, denNgay) <= 0) {
            xuat1So(ds[i]);
            found = true;
        }
    }
    if (!found) cout << "Khong co so nao mo trong giai doan nay.\n";
}

void sapXepTienGiamDan(SoTietKiem* ds, int n) { // sắp xếp tiền gửi giảm dần
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].soTienGui < ds[j].soTienGui) {
                swap(ds[i], ds[j]);
            }
        }
    }
}

void sapXepNgayTangDan(SoTietKiem* ds, int n) { // sắp xếp ngày mở sổ tăng dần
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (soSanhNgay(ds[i].ngayMoSo, ds[j].ngayMoSo) > 0) {
                swap(ds[i], ds[j]);
            }
        }
    }
}

int main() {
    int n = 0;
    SoTietKiem* ds = nullptr;

    nhapDS(ds, n);
    if (n == 0) {
        cout << "========== KET THUC ==========\n";
        return 0;
    }

    cout << "\n=== DANH SACH VUA NHAP ===\n";
    xuatDS(ds, n);
    cout << "============================\n";

    cout << "=== Tim so tiet kiem theo CMND ===\n";
    string cmndTim;
    while (true) {
        cout << "Nhap CMND de tim kiem: ";
        getline(cin, cmndTim);
        if (isCMND(cmndTim)) break;
        cout << "Loi: CMND khong hop le.\n";
    }
    timKiem(ds, n, cmndTim, 2);
    cout << "============================\n";
    cout << "=== Cap nhat lai suat cho TOAN BO so tiet kiem ===\n";
    Date hienTai;
    while (true) {
        cout << "Nhap ngay hien tai (ngay thang nam): ";
        if (cin >> hienTai.ngay >> hienTai.thang >> hienTai.nam && kiemTraNgay(hienTai)) {
            // Kiểm tra xem ngày hiện tại có hợp lệ so với toàn bộ danh sách không
            bool hopLe = true;
            for (int i = 0; i < n; i++) {
                if (soSanhNgay(hienTai, ds[i].ngayMoSo) < 0) {
                    hopLe = false;
                    cout << "Loi: Ngay hien tai khong duoc nho hon ngay mo so cua so [" << ds[i].maSo << "] (" 
                         << ds[i].ngayMoSo.ngay << "/" << ds[i].ngayMoSo.thang << "/" << ds[i].ngayMoSo.nam << ").\n";
                    break; 
                }
            }
            if (hopLe) {
                xoaBoDem();
                break; // Thoát vòng lặp nếu ngày hiện tại hoàn toàn hợp lệ
            }
        } else {
            cout << "Loi: Ngay khong hop le hoac sai dinh dang.\n";
        }
        xoaBoDem();
    }
    double laiSuat;
    cout << "Nhap lai suat (%/nam) ban muon tinh: ";
    laiSuat = nhapTien();
    cout << "\n--- BANG TINH LAI SUAT ---\n";
    for (int i = 0; i < n; i++) {
        cout << "So [" << ds[i].maSo << "] - " << ds[i].hoTen << ": ";
        tinhVaCapNhatLai(ds[i], laiSuat, hienTai);
    }
    cout << "============================\n";
    cout << "=== RUT TIEN ===\n";
    string maSoRut;
    bool timThay = false;
    cout << "Nhap ma so tiet kiem ban muon rut tien: ";
    getline(cin, maSoRut);
    for (int i = 0; i < n; i++) {
        if (ds[i].maSo == maSoRut) {
            rutTien(ds[i], hienTai);
            timThay = true;
            break;
        }
    }
    if (!timThay) cout << "Khong tim thay so tiet kiem nao co ma: " << maSoRut << "\n";
    cout << "============================\n";
    cout << "=== Sap xep tien gui giam dan ===\n";
    sapXepTienGiamDan(ds, n);
    xuatDS(ds, n);
    cout << "========== KET THUC ==========\n";

    delete[] ds;
    return 0;
}