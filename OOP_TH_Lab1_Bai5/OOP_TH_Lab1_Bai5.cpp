#include <iostream>
#include <limits>
using namespace std;

struct Date {
    int ngay, thang, nam;
};

/*
 * Hàm KiemTra: Kiểm tra và nhập một số nguyên dương từ người dùng.
 * Đầu vào: Không có tham số đầu vào. Hàm sẽ yêu cầu người dùng nhập từ bàn phím.
 * Đầu ra: Trả về một số nguyên dương hợp lệ.
 */
int KiemTra() { // hàm kiểm tra điều kiện đầu vào có phải là số nguyên dương không, nếu không phải là số nguyên dương thì nhập lại
    int n;
    while(true) {
        cin >> n;
        if(n > 0) {
            // nếu đúng là số nguyên dương thì thoát vòng lặp
            break;
        }
        else {
            // nếu là chữ hoặc kí tự đặc biệt
            cout << "Dau vao khong hop le! Vui long nhap lai so nguyen duong: ";
            cin.clear(); // xóa trạng thái lỗi của đối tượng cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // bỏ qua toàn bộ kí tự rác trong bộ nhớ đệm
        }
    }
    // trả về số nguyên dương hợp lệ
    return n;
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
 * Hàm KiemTraNgay: Kiểm tra tính hợp lệ của ngày tháng năm.
 * Đầu vào: Một biến Date d (truyền bằng giá trị) chứa ngày, tháng, năm.
 * Đầu ra: Trả về true nếu ngày hợp lệ, false nếu không.
 */
bool KiemTraNgay(Date d) { 
    if (d.nam < 1 || d.thang < 1 || d.thang > 12 || d.ngay < 1) return false;
    if (d.ngay > soNgayTrongThang(d.thang, d.nam)) return false;
    return true;
}
/*
 * Hàm Nhap: Nhập ngày, tháng, năm cho một ngày và kiểm tra tính hợp lệ của ngày tháng năm.
 * Đầu vào: Tham chiếu đến một biến Date hientai (được truyền bằng tham chiếu để thay đổi giá trị).
 * Đầu ra: Không trả về giá trị, nhưng thay đổi giá trị của hientai.
 */
void Nhap(Date &hientai) {
    while(true) {
        cout << "Nhap ngay: ";
        hientai.ngay = KiemTra();
        cout << "Nhap thang: ";
        hientai.thang = KiemTra();
        cout << "Nhap nam: ";
        hientai.nam = KiemTra();
        if(KiemTraNgay(hientai)) break;
        cout << "Loi ngay thang nam! Vui long nhap lai:\n";
    }
}
/*
 * Hàm xuat: Xuất ngày ra màn hình theo định dạng ngày/tháng/năm.
 * Đầu vào: Một biến Date hientai (truyền bằng giá trị).
 * Đầu ra: Không trả về giá trị, nhưng in ra màn hình.
 */
void xuat(Date hientai) { // hàm xuất ngày
    cout << hientai.ngay << "/" << hientai.thang << "/" << hientai.nam << endl;
}

/*
 * Hàm ngayKeTiep: Tính ngày kế tiếp của ngày hiện tại.
 * Đầu vào: Tham chiếu đến một biến Date hientai (được truyền bằng tham chiếu để thay đổi giá trị).
 * Đầu ra: Không trả về giá trị, nhưng thay đổi hientai thành ngày kế tiếp và in ra màn hình.
 */
void ngayKeTiep(Date &hientai) { // hàm tìm ngày kế tiếp
    hientai.ngay++; // tăng ngày
    int thang = hientai.thang;
    int ngay_max = soNgayTrongThang(hientai.thang, hientai.nam);
    if(hientai.ngay > ngay_max) { // nếu ngày sau khi tăng lớn hơn ngày tối đa thì trừ ngày hiện tại và tăng tháng và nếu tháng sau khi tăng lớn hơn 12 thì tăng năm
        hientai.ngay = 1;
        hientai.thang++;
        if(hientai.thang > 12) {
            hientai.thang = 1;
            hientai.nam++;
        }
    }
    xuat(hientai); // xuất Date
}

/*
 * Hàm ngayTruoc: Tính ngày trước đó của ngày hiện tại.
 * Đầu vào: Tham chiếu đến một biến Date hientai (được truyền bằng tham chiếu để thay đổi giá trị).
 * Đầu ra: Không trả về giá trị, nhưng thay đổi hientai thành ngày trước đó và in ra màn hình (hoặc thông báo lỗi nếu không thể).
 */
void ngayTruoc(Date &hientai) { // hàm tính toán ngày trước đó
    if(hientai.ngay == 1 && hientai.thang == 1 && hientai.nam == 0) { // trường hợp ngày 1 tháng 1 năm 0 không tính được
        cout << "Loi! khong the tim duoc ngay truoc do" << endl;
        return;
    }
    hientai.ngay--; // lùi 1 ngày
    if(hientai.ngay == 0) {
        hientai.thang--; // nếu ngày bằng 0 lùi 1 tháng
        if(hientai.thang == 0) { 
            hientai.thang = 12; // tháng lùi về bằng 0 nên sẽ trở thành tháng 12
            hientai.nam--; // nếu tháng bằng 0 lùi 1 năm
        }
        hientai.ngay = soNgayTrongThang(hientai.thang, hientai.nam); // tính ngày sau khi lùi
    }
    xuat(hientai); // xuất Date
}

/*
 * Hàm ngayTrongNam: Tính ngày đó là ngày thứ bao nhiêu trong năm.
 * Đầu vào: Một biến Date hientai (truyền bằng giá trị).
 * Đầu ra: Trả về số thứ tự của ngày trong năm.
 */
int ngayTrongNam(Date hientai) { // hàm tìm ngày đó là ngày thứ bao nhiêu trong năm
    int count = 0;
    for(int i = 1; i < hientai.thang; i++) {
        count += soNgayTrongThang(i, hientai.nam);
    }
    count += hientai.ngay;
    return count;
}

/*
 * Hàm main: Hàm chính của chương trình, nhập ngày và tính toán ngày kế tiếp, ngày trước đó, và thứ tự trong năm.
 * Đầu vào: Không có tham số.
 * Đầu ra: Trả về 0 khi chương trình kết thúc thành công.
 */
int main() {
    Date hientai;
    Nhap(hientai); // nhập ngày tháng năm
    Date ketiep = hientai;
    cout << "Ngay ke tiep la: ";
    ngayKeTiep(ketiep);
    Date truoc = hientai;
    cout << "Ngay truoc do la: ";
    ngayTruoc(truoc);
    cout << hientai.ngay << "/" << hientai.thang << "/" << hientai.nam << " la ngay thu: " << ngayTrongNam(hientai);
    return 0;
}
