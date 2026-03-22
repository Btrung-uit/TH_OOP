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

/*
 * Hàm xoaBoDem: Dọn dẹp bộ đệm của cin khi người dùng nhập sai kiểu dữ liệu.
 * Đầu vào: Không có tham số.
 * Đầu ra: Không có giá trị trả về. Trạng thái lỗi của cin được xóa và các ký tự rác bị loại bỏ.
 */
void xoaBoDem() { 
    cin.clear();
    cin.ignore(10000, '\n');
}

/*
 * Hàm isAlphaNum: Kiểm tra mã số có hợp lệ (chỉ chứa chữ/số và độ dài phù hợp).
 * Đầu vào: Chuỗi s (mã số cần kiểm tra) và số nguyên maxLen (độ dài tối đa cho phép).
 * Đầu ra: Trả về true nếu hợp lệ, ngược lại trả về false.
 */
bool isAlphaNum(string s, int maxLen) { 
    if (s.length() == 0 || s.length() > maxLen) return false;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))) {
            return false;
        }
    }
    return true;
}

/*
 * Hàm isTextOnly: Kiểm tra chuỗi chỉ chứa chữ cái và khoảng trắng.
 * Đầu vào: Chuỗi s (chuỗi cần kiểm tra) và số nguyên maxLen (độ dài tối đa cho phép).
 * Đầu ra: Trả về true nếu hợp lệ, ngược lại trả về false.
 */
bool isTextOnly(string s, int maxLen) { 
    if (s.length() == 0 || s.length() > maxLen) return false;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ')) {
            return false;
        }
    }
    return true;
}

/*
 * Hàm KiemTraTen: Kiểm tra ràng buộc khắt khe cho tên người (không khoảng trắng thừa, viết hoa/thường chuẩn).
 * Đầu vào: Biến tham chiếu ten kiểu string.
 * Đầu ra: Trả về true nếu tên hợp chuẩn, ngược lại trả về false.
 */
bool KiemTraTen(string &ten) { 
    int lenght = ten.length();
    if(lenght > 30 || lenght == 0) return false; 
    if(ten[0] == ' ' || ten[lenght - 1] == ' ') return false; 
    for(int i = 0; ten[i] != '\0'; i++) {
        if(ten[i] == ' ') {
            if(i + 1 < lenght && ten[i+1] == ' ') return false; 
            continue;
        }
        if((ten[i] < 'A' || ten[i] > 'Z') && (ten[i] < 'a' || ten[i] > 'z')) return false; 
        bool chuDau = (i == 0 || ten[i-1] ==  ' '); 
        if(chuDau) { 
            if(ten[i] < 'A' || ten[i] > 'Z') return false;
            }
        else {
            if(ten[i] < 'a' || ten[i] > 'z') return false; 
        }
    }
    return true;
}

/*
 * Hàm isCMND: Kiểm tra định dạng Căn cước công dân / Chứng minh nhân dân.
 * Đầu vào: Chuỗi s (số CMND cần kiểm tra).
 * Đầu ra: Trả về true nếu chuỗi chỉ chứa số và có độ dài chính xác 9 hoặc 12, ngược lại trả về false.
 */
bool isCMND(string s) { 
    if (s.length() != 9 && s.length() != 12) return false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}

/*
 * Hàm namNhuan: Kiểm tra tính chất năm nhuận của một năm dương lịch.
 * Đầu vào: Số nguyên nam (ví dụ: 2024).
 * Đầu ra: Trả về true nếu là năm nhuận, false nếu là năm thường.
 */
bool namNhuan(int nam) { 
    return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
}

/*
 * Hàm soNgayTrongThang: Xác định số lượng ngày trong một tháng cụ thể.
 * Đầu vào: Số nguyên thang (1-12) và nam.
 * Đầu ra: Trả về số nguyên đại diện cho số ngày tối đa của tháng đó.
 */
int soNgayTrongThang(int thang, int nam) { 
    switch (thang) {
        case 4: case 6: case 9: case 11: return 30;
        case 2: return namNhuan(nam) ? 29 : 28;
        default: return 31;
    }
}

/*
 * Hàm kiemTraNgay: Kiểm tra sự tồn tại thực tế của một mốc thời gian.
 * Đầu vào: Biến d thuộc kiểu struct Date.
 * Đầu ra: Trả về true nếu cấu trúc ngày-tháng-năm hợp lệ, ngược lại trả về false.
 */
bool kiemTraNgay(Date d) { 
    if (d.nam < 1 || d.thang < 1 || d.thang > 12 || d.ngay < 1) return false;
    if (d.ngay > soNgayTrongThang(d.thang, d.nam)) return false;
    return true;
}

/*
 * Hàm tinhSoNgay: Quy đổi mốc ngày tháng năm thành một số nguyên tuyệt đối (số ngày từ mốc 0).
 * Đầu vào: Biến d thuộc kiểu struct Date.
 * Đầu ra: Trả về số lượng ngày tích lũy tính đến mốc thời gian đó.
 */
int tinhSoNgay(Date d) { 
    int days = d.ngay;
    for (int y = 1; y < d.nam; y++) days += namNhuan(y) ? 366 : 365;
    for (int m = 1; m < d.thang; m++) days += soNgayTrongThang(m, d.nam);
    return days;
}

/*
 * Hàm khoangCachNgay: Tính độ lệch (số ngày) giữa hai mốc thời gian.
 * Đầu vào: Biến batDau và ketThuc thuộc kiểu struct Date.
 * Đầu ra: Trả về một số nguyên là khoảng cách ngày giữa hai thời điểm.
 */
int khoangCachNgay(Date batDau, Date ketThuc) { 
    return tinhSoNgay(ketThuc) - tinhSoNgay(batDau);
}

/*
 * Hàm soSanhNgay: So sánh xem ngày nào xảy ra trước/sau.
 * Đầu vào: Hai biến a và b thuộc kiểu struct Date.
 * Đầu ra: Trả về số > 0 nếu a sau b, số < 0 nếu a trước b, số 0 nếu bằng nhau.
 */
int soSanhNgay(Date a, Date b) { 
    if (a.nam != b.nam) return a.nam - b.nam;
    if (a.thang != b.thang) return a.thang - b.thang;
    return a.ngay - b.ngay;
}

/*
 * Hàm nhapTien: Yêu cầu người dùng nhập số tiền bảo đảm hợp lệ (số dương, không phải chữ).
 * Đầu vào: Không có tham số, yêu cầu nhập từ bàn phím.
 * Đầu ra: Trả về một số thực (double) lớn hơn 0.
 */
double nhapTien() { 
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

/*
 * Hàm KiemTraLoaiTaiKhoang: Kiểm tra loại tiết kiệm có nằm trong danh mục cho phép hay không.
 * Đầu vào: Chuỗi loaiTK.
 * Đầu ra: Trả về true nếu là "ngan han" hoặc "dai han", ngược lại trả về false.
 */
bool KiemTraLoaiTaiKhoang(string loaiTK) {
    return (loaiTK == "ngan han" || loaiTK == "dai han");
}

/*
 * Hàm kiemTraNgayHienTai: Kiểm tra ngày hiện tại có lớn hơn hoặc bằng ngày mở của tất cả sổ hay không.
 * Đầu vào: Con trỏ ds chứa mảng sổ tiết kiệm, số lượng n, và biến hienTai kiểu Date.
 * Đầu ra: Trả về true nếu ngày hiện tại hợp lệ so với tất cả các sổ, ngược lại trả về false.
 */
bool kiemTraNgayHienTai(SoTietKiem* ds, int n, Date hienTai) {
    for (int i = 0; i < n; i++) {
        if (soSanhNgay(hienTai, ds[i].ngayMoSo) < 0) {
            return false; 
        }
    }
    return true;
}

/*
 * Hàm nhap1So: Nhập thông tin và kiểm tra tính hợp lệ cho một sổ tiết kiệm.
 * Đầu vào: Biến tham chiếu stk kiểu SoTietKiem. Dữ liệu thực tế lấy từ bàn phím.
 * Đầu ra: Không có giá trị trả về. Biến stk được cập nhật dữ liệu hợp lệ.
 */
void nhap1So(SoTietKiem &stk) { 
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

/*
 * Hàm xuat1So: In chi tiết thông tin của một sổ tiết kiệm ra màn hình.
 * Đầu vào: Biến stk kiểu SoTietKiem chứa dữ liệu cần in.
 * Đầu ra: Không có giá trị trả về. Xuất chuỗi định dạng ra console.
 */
void xuat1So(SoTietKiem stk) { 
    cout << "Ma: " << stk.maSo << " | Loai TK: " << stk.loaiTK << " | Ho ten: " << stk.hoTen 
         << " | CMND: " << stk.cmnd << " | Ngay mo: " << stk.ngayMoSo.ngay << "/" << stk.ngayMoSo.thang << "/" << stk.ngayMoSo.nam
         << " | Tien gui: " << stk.soTienGui << " VND\n";
}

/*
 * Hàm nhapDS: Khởi tạo mảng động và nhập dữ liệu cho nhiều sổ tiết kiệm.
 * Đầu vào: Con trỏ ds (quản lý mảng) và số lượng n truyền tham chiếu.
 * Đầu ra: Không có giá trị trả về. Mảng ds được cấp phát vùng nhớ và nhập đủ dữ liệu.
 */
void nhapDS(SoTietKiem* &ds, int &n) { 
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

/*
 * Hàm xuatDS: In toàn bộ danh sách các sổ tiết kiệm.
 * Đầu vào: Con trỏ ds chứa mảng dữ liệu và số lượng n phần tử.
 * Đầu ra: Không có giá trị trả về. Gọi hàm xuat1So lặp lại n lần.
 */
void xuatDS(SoTietKiem* ds, int n) { 
    for (int i = 0; i < n; i++) {
        xuat1So(ds[i]);
    }
}

/*
 * Hàm tinhVaCapNhatLai: Tính tiền lãi dựa trên số ngày gửi và cập nhật lại số dư.
 * Đầu vào: Biến tham chiếu stk kiểu SoTietKiem, số thực laiSuatNam và biến ngayHienTai.
 * Đầu ra: Không có giá trị trả về. Số dư (soTienGui) trong stk sẽ được cộng thêm phần tiền lãi.
 */
void tinhVaCapNhatLai(SoTietKiem &stk, double laiSuatNam, Date ngayHienTai) { 
    int soNgay = khoangCachNgay(stk.ngayMoSo, ngayHienTai);
    if (soNgay <= 0) {
        cout << "Ngay hien tai khong hop le hoac chua phat sinh lai.\n";
        return;
    }
    
    double tienLai = stk.soTienGui * (laiSuatNam / 100.0) * (soNgay / 365.0);
    stk.soTienGui += tienLai;
    cout << "=> So ngay gui: " << soNgay << " ngay. Tien lai uoc tinh: " << tienLai << " VND\n";
}

/*
 * Hàm rutTien: Thực hiện giao dịch rút tiền, tính toán phạt lãi suất nếu rút trước hạn.
 * Đầu vào: Biến tham chiếu stk kiểu SoTietKiem và biến ngayHienTai.
 * Đầu ra: Không có giá trị trả về. Cập nhật lại số dư sau khi trừ đi số tiền rút.
 */
void rutTien(SoTietKiem &stk, Date ngayHienTai) { 
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

/*
 * Hàm timKiem: Tìm và in các sổ tiết kiệm khớp với từ khóa cung cấp.
 * Đầu vào: Mảng ds, số lượng n, chuỗi key cần tìm, và biến nguyên type phân loại tìm kiếm.
 * Đầu ra: Không có giá trị trả về. Xuất thông tin các sổ thỏa mãn điều kiện.
 */
void timKiem(SoTietKiem* ds, int n, string key, int type) { 
    bool found = false;
    for (int i = 0; i < n; i++) {
        if ((type == 1 && ds[i].maSo == key) || (type == 2 && ds[i].cmnd == key)) {
            xuat1So(ds[i]);
            found = true;
        }
    }
    if (!found) cout << "Khong tim thay so tiet kiem.\n";
}

/*
 * Hàm lietKeTheoGiaiDoan: Lọc các sổ tiết kiệm được mở trong một khoảng thời gian nhất định.
 * Đầu vào: Mảng ds, số lượng n, biến tuNgay và denNgay kiểu Date.
 * Đầu ra: Không có giá trị trả về. Xuất thông tin các sổ nằm trong giai đoạn quy định.
 */
void lietKeTheoGiaiDoan(SoTietKiem* ds, int n, Date tuNgay, Date denNgay) { 
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (soSanhNgay(ds[i].ngayMoSo, tuNgay) >= 0 && soSanhNgay(ds[i].ngayMoSo, denNgay) <= 0) {
            xuat1So(ds[i]);
            found = true;
        }
    }
    if (!found) cout << "Khong co so nao mo trong giai doan nay.\n";
}

/*
 * Hàm sapXepTienGiamDan: Sắp xếp danh sách sổ tiết kiệm theo số tiền gửi từ cao xuống thấp.
 * Đầu vào: Con trỏ ds chứa mảng và số lượng n phần tử.
 * Đầu ra: Không có giá trị trả về. Các phần tử trong mảng ds bị đổi chỗ trực tiếp.
 */
void sapXepTienGiamDan(SoTietKiem* ds, int n) { 
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].soTienGui < ds[j].soTienGui) {
                swap(ds[i], ds[j]);
            }
        }
    }
}

/*
 * Hàm sapXepNgayTangDan: Sắp xếp danh sách sổ tiết kiệm theo ngày mở sổ từ sớm đến muộn.
 * Đầu vào: Con trỏ ds chứa mảng và số lượng n phần tử.
 * Đầu ra: Không có giá trị trả về. Các phần tử trong mảng ds bị đổi chỗ trực tiếp.
 */
void sapXepNgayTangDan(SoTietKiem* ds, int n) { 
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
