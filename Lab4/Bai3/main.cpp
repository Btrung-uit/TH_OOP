#include <iostream>
#include <limits>
#include <windows.h> // Hỗ trợ hàm dịch chuyển con trỏ và Sleep
#include "CTime.h"

using namespace std;

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
// Hàm đưa con trỏ đến vị trí x (cột), y (hàng) trên màn hình Console
void GotoXY(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Hàm ẩn con trỏ nhấp nháy để màn hình đồng hồ không bị giật
void AnConTro()
{
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    cursor.dwSize = sizeof(cursor);
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

// Hàm mới: Tự động lấy chiều rộng hiện tại của màn hình Console
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