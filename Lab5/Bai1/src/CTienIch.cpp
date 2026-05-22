#include "../include/CTienIch.h"
#include <iostream>
using namespace std;

/**
 * @brief Nhập và ép luồng dữ liệu số nguyên lớn hơn hoặc bằng 0,
 *        chặn các ký tự rác đi kèm.
 * @param Không có.
 * @return Giá trị số nguyên hợp lệ duy nhất trích xuất được
 *         từ dòng nhập.
 * @note Giải thuật:
 *       1. Sử dụng vòng lặp vô hạn để ép nhập đúng kiểu dữ liệu.
 *       2. Dùng hàm cin.peek() để quét kiểm tra toàn bộ các ký tự
 *          còn lại trên dòng sau số nguyên.
 *       3. Nếu phát hiện ký tự rác (không phải khoảng trắng, tab
 *          hay xuống dòng), đánh dấu chuỗi không hợp lệ và ép
 *          nhập lại.
 *       4. Dọn sạch cờ lỗi và bộ nhớ đệm luồng nếu dữ liệu sai
 *          quy chuẩn.
 */
int NhapSoNguyenAnToan()
{
    int giaTri;
    while (true)
    {
        if (cin >> giaTri && giaTri >= 0)
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
                return giaTri;
            }
        }
        cout << "Loi! Vui long nhap so nguyen duong!\nNhap lai: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}