#include <iostream>
#include <limits>
#include <windows.h> // Hàm dịch chuyển con trỏ và Sleep
#include "CTime.h"

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
void KiemTraDauVao(int &thoiGian)
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
        else
        {
            cout << "Loi! Thoi gian khong hop le!\nVui long nhap lai: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

/**
 * @brief Di chuyển con trỏ hiển thị của hệ thống đến một tọa độ xác
 *        định trên màn hình Console.
 * @param x: Tọa độ vị trí theo cột (trục hoành - tính từ trái sang).
 * @param y: Tọa độ vị trí theo dòng (trục tung - tính từ trên xuống).
 * @return Không có.
 * @note Giải thuật: Khởi tạo cấu trúc COORD lưu cặp giá trị
 *       (x, y) mục tiêu, sau đó gọi hàm hệ thống
 *       SetConsoleCursorPosition của thư viện Windows API
 *       để dịch chuyển con trỏ.
 */
void GotoXY(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/**
 * @brief Ẩn con trỏ nhập liệu nhấp nháy trên cửa sổ dòng lệnh Console.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Khai báo cấu trúc CONSOLE_CURSOR_INFO, gán thuộc
 *       tính bVisible thành FALSE rồi truyền vào hàm
 *       SetConsoleCursorInfo giúp giao diện không bị hiện tượng nhấp
 *       nháy liên tục khi vẽ lại.
 */
void AnConTro()
{
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    cursor.dwSize = sizeof(cursor);
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

/**
 * @brief Tự động truy vấn và lấy giá trị chiều rộng thực tế hiện
 *        tại của cửa sổ Console.
 * @param Không có.
 * @return Giá trị số cột (chiều rộng) hiện tại của
 *         màn hình Console (int).
 * @note Giải thuật: Sử dụng hàm GetConsoleScreenBufferInfo để nạp
 *       thông tin hình học của Terminal vào cấu trúc dữ liệu, sau
 *       đó tính toán khoảng cách hiệu giữa lề phải (srWindow.Right)
 *       và lề trái (srWindow.Left) để tìm ra số cột.
 */
int LayChieuRongConsole()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

int main()
{
    CTime t1;
    cout << "Khoi tao thoi gian\n";
    cin >> t1;
    cout << "\nThoi gian vua nhap la: " << t1 << "\n";
    int thoiGianCong, thoiGianTru;
    cout << "\nNhap thoi gian muon cong them (t >= 0): ";
    KiemTraDauVao(thoiGianCong);
    cout << "Nhap thoi gian muon tru di (t >= 0): ";
    KiemTraDauVao(thoiGianTru);
    cout << "\nKiem tra phep cong (t1 + " << thoiGianCong << " giay): " << t1 + thoiGianCong << "\n";
    cout << "Kiem tra phep tru (t1 - " << thoiGianTru << " giay): " << t1 - thoiGianTru << "\n";

    // Test tiền tố, hậu tố
    CTime t2 = t1;
    // Tiền tố ++
    cout << "\nTien to ++\n";
    cout << "Gia tri t2 ban dau: " << t2 << "\n";
    cout << "Test hau to (t2++): " << t2++ << " (Gia tri in ra chua tang)\n";
    cout << "Ket qua sau t2++  : " << t2 << "\n";
    cout << "Test tien to (++t2): " << ++t2 << " (Gia tri in ra tang ngay)\n";

    t2 = t1;
    // Tiền tố --
    cout << "\nTien to --\n";
    cout << "Gia tri t2 ban dau: " << t2 << "\n";
    cout << "Test hau to (t2--): " << t2-- << " (Gia tri in ra chua tang)\n";
    cout << "Ket qua sau t2--  : " << t2 << "\n";
    cout << "Test tien to (--t2): " << --t2 << " (Gia tri in ra tang ngay)\n";
    cout << "\nBam Enter de kich hoat dong ho thoi gian thuc tren goc phai...";
    cin.ignore();
    cin.get();

    // Xóa màn hình
    system("cls");
    AnConTro();

    // Vòng lặp đồng hồ thời gian thực
    while (true)
    {
        // Tính toán tọa độ X sao cho đồng hồ luôn ôm sát lề phải
        int chieuRong = LayChieuRongConsole();
        int toaDoX = chieuRong - 15; // 14 ký tự đồng hồ + 1 khoảng lề

        // Đề phòng trường hợp Terminal bị kéo quá nhỏ (nhỏ hơn 15 cột)
        if (toaDoX < 0)
            toaDoX = 0;

        GotoXY(toaDoX, 0);

        cout << "[ " << t1 << " ]";

        t1++;
        Sleep(1000);
    }
    return 0;
}