#include <iostream>
#include <iomanip>
#include <string>
#include "CDate.h"

using namespace std;

/**
 * @brief Nhập và ép luồng dữ liệu số nguyên lớn hơn hoặc bằng 0,
 *        loại bỏ hoàn toàn ký tự rác đi kèm.
 * @param thoiGian: Tham chiếu đến biến nguyên nhận giá trị thời
 *        gian cần kiểm tra.
 * @return Không có.
 * @note Giải thuật:
 *       1. Chạy vòng lặp vô hạn và đọc dữ liệu thông qua
 *          cin >> thoiGian kết hợp chặn điều kiện >= 0.
 *       2. Sử dụng cin.peek() duyệt từng ký tự kế sau để kiểm
 *          tra lỗi người dùng nhập số kèm chữ (Ví dụ: 120abc).
 *       3. Nếu xuất hiện ký tự lạ không phải khoảng trắng/tab,
 *          gán cờ lỗi chuoiHopLe = false để yêu cầu nhập lại.
 *       4. Tiến hành xóa cờ lỗi dữ liệu stream và dọn sạch
 *          buffer nếu đầu vào không đạt chuẩn.
 */
void KiemTraDauVaoChoNgay(int &thoiGian)
{
    while (true)
    {
        if (cin >> thoiGian && thoiGian >= 0)
        {
            bool chuoiHopLe = true;
            char c;
            while (true)
            {
                c = cin.peek();
                if (c == '\n' || c == EOF)
                    break;
                if (c != ' ' && c != '\t')
                    chuoiHopLe = false;
                cin.get();
            }
            if (chuoiHopLe)
            {
                if (cin.peek() == '\n')
                    cin.get();
                return;
            }
        }
        cout << "Loi! Thoi gian khong hop le!\nVui long nhap lai: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

/**
 * @brief Nhập và ép luồng dữ liệu số thực không âm, loại bỏ hoàn
 *        toàn các ký tự rác đi kèm.
 * @param giaTri: Tham chiếu đến biến kiểu double nhận giá trị
 *        nhập vào sau khi kiểm tra hợp lệ.
 * @return Không có.
 * @note Giải thuật:
 *       1. Sử dụng vòng lặp vô hạn và đọc dữ liệu thông qua toán
 *          tử cin >> giaTri kết hợp chặn điều kiện >= 0.
 *       2. Sử dụng cin.get(c) để quét từng ký tự còn lại trên
 *          cùng một dòng cho đến khi gặp ký tự xuống dòng (\n).
 *       3. Nếu phát hiện bất kỳ ký tự nào không phải khoảng trắng
 *          (' ') hoặc tab ('\t'), gán cờ chuoiHopLe = false để
 *          đánh dấu dòng nhập chứa ký tự rác
 *          (Ví dụ: nhập "3.14abc").
 *       4. Nếu chuỗi hợp lệ, thoát hàm để lưu giá trị. Ngược lại,
 *          tiến hành xóa cờ lỗi của stream, dọn sạch bộ nhớ đệm
 *          và yêu cầu người dùng nhập lại.
 */
void KiemTraDauVaoChoDouble(double &giaTri)
{
    while (true)
    {
        if (cin >> giaTri && giaTri >= 0)
        {
            bool chuoiHopLe = true;
            char c;
            while (cin.get(c) && c != '\n')
            {
                if (c != ' ' && c != '\t')
                {
                    chuoiHopLe = false;
                }
            }

            if (chuoiHopLe)
            {
                return;
            }
            cout << "Gia tri khong hop le!\nVui long nhap so thuc khong am!\nNhap lai: ";
            continue;
        }
        cout << "Gia tri khong hop le!\nVui long nhap so thuc khong am!\nNhap lai: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}
int main()
{

    // 1. NHẬP VÀ XUẤT NGÀY ĐẦU TIÊN
    CDate d1;
    cout << "NHAP NGAY DAU TIEN (d1)\n";
    cin >> d1;
    cout << "=> Ngay vua nhap: " << d1 << "\n\n";

    // 2. KIỂM THỬ TOÁN TỬ CỘNG, TRỪ SỐ NGUYÊN
    int k1, k2;
    cout << "Nhap so ngay muon CONG vao d1 (t >= 0): ";
    KiemTraDauVaoChoNgay(k1);
    cout << "Nhap so ngay muon TRU khoi d1 (t >= 0): ";
    KiemTraDauVaoChoNgay(k2);

    cout << "Ket qua (" << d1 << " + " << k1 << " ngay): " << d1 + k1 << "\n";
    cout << "Ket qua (" << d1 << " - " << k2 << " ngay): " << d1 - k2 << "\n\n";

    // 3. KIỂM THỬ TOÁN TỬ TĂNG/GIẢM (++ , --)
    CDate temp = d1;
    cout << "TOAN TU ++\n";
    cout << "Ngay ban dau: " << temp << "\n";
    cout << "Test hau to (temp++): " << temp++ << " (Gia tri in ra chua doi)\n";
    cout << "Ket qua sau temp++: " << temp << "\n";
    cout << "Test tien to (++temp): " << ++temp << " (Gia tri in ra tang ngay)\n";

    cout << "\nTOAN TU --\n";
    temp = d1;
    cout << "Ngay ban dau: " << temp << "\n";
    cout << "Test hau to (temp--): " << temp-- << " (Gia tri in ra chua doi)\n";
    cout << "Ket qua sau temp--: " << temp << "\n";
    cout << "Test tien to (--temp): " << --temp << " (Gia tri in ra giam ngay)\n\n";

    // 4. NHẬP VÀ XUẤT NGÀY THỨ HAI
    CDate d2;
    cout << "NHAP NGAY THU HAI (d2)\n";
    do
    {
        cin >> d2;
        if ((d2 - d1) < 0)
        {
            cout << "Loi! Ngay thu 2 phai >= " << d1 << " !\n";
            cout << "Vui long nhap lai d2: \n";
        }
    } while ((d2 - d1) < 0);

    cout << "=> Ngay vua nhap: " << d2 << "\n";
    int soNgayCachBiet = d2 - d1;
    cout << "Khoang cach giua d2 va d1: " << soNgayCachBiet << " ngay.\n\n";

    // 5. ỨNG DỤNG TÍNH LÃI SUẤT NGÂN HÀNG
    double soTienGoi, laiSuatNam;
    cout << "TINH LAI SUAT NGAN HANG\n";
    cout << "Nhap so tien goi (VND): ";
    KiemTraDauVaoChoDouble(soTienGoi);
    cout << "Nhap lai suat nam (%): ";
    KiemTraDauVaoChoDouble(laiSuatNam);

    // Tien lai = So tien * Lai suat * (So ngay / 365)
    double tienLai = soTienGoi * (laiSuatNam / 100.0) * (soNgayCachBiet / 365.0);
    cout << "\n------------------------------------------------\n";
    cout << "Ngay goi: " << d1 << " | Ngay rut: " << d2 << "\n";
    cout << "Thoi gian gui thuc te: " << soNgayCachBiet << " ngay.\n";
    cout << "Tien lai nhan duoc: " << fixed << setprecision(0) << tienLai << " VND\n";
    cout << "Tong so tien (Goc + Lai): " << soTienGoi + tienLai << " VND\n";
    cout << "------------------------------------------------\n";
    return 0;
}