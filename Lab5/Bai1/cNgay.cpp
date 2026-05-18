#include "cNgay.h"
#include <iostream>
#include <iomanip>
using namespace std;

/**
 * @brief Nhập và kiểm tra một giá trị nguyên dương.
 * @param Không có.
 * @return Số nguyên dương hợp lệ
 * @note Giải thuật: Sử dụng vòng lặp while để ép người dùng nhập số nguyên dương.
 *       Xử lý xóa bộ nhớ đệm (cin.clear, cin.ignore) nếu người dùng nhập sai kiểu dữ liệu.
 */
int NhapSoNguyenAnToan()
{
    int giaTri;
    while (true)
    {
        if (cin >> giaTri && giaTri >= 0)
        {
            char c;
            bool chuoiHopLe = true;
            while (cin.get(c) && c != '\n')
            {
                if (c != ' ' && c != '\t')
                {
                    chuoiHopLe = false;
                }
            }
            if (chuoiHopLe)
            {
                return giaTri;
            }
        }
        cout << "Gia tri khong hop le! Vui long nhap mot so nguyen khong am: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

/**
 * @brief Nhập bộ ba giá trị Ngày, Tháng, Năm từ bàn phím.
 * @param ngay, thang, nam: Các tham chiếu để lưu giá trị nhập vào.
 * @return Không có.
 */
void NhapNgayThangNam(int &ngay, int &thang, int &nam)
{
    cout << "Nhap ngay: ";
    ngay = NhapSoNguyenAnToan();

    cout << "Nhap thang: ";
    thang = NhapSoNguyenAnToan();

    cout << "Nhap nam: ";
    nam = NhapSoNguyenAnToan();
}

/**
 * @brief Kiểm tra một năm có phải là năm nhuận hay không.
 * @param nam: Giá trị năm cần kiểm tra.
 * @return true nếu là năm nhuận, false nếu không phải.
 * @note Giải thuật: Theo lịch Gregory, năm nhuận là năm chia hết cho 400
 *                   hoặc chia hết cho 4 nhưng không chia hết cho 100.
 */
bool namNhuan(int nam)
{
    return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
}

/**
 * @brief Trả về số ngày tối đa trong một tháng cụ thể của một năm.
 * @param thang, nam: Tháng và năm cần tra cứu.
 * @return Số ngày trong tháng (28, 29, 30 hoặc 31).
 * @note Giải thuật:
 *       - Tháng 4, 6, 9, 11 có 30 ngày.
 *       - Tháng 2 có 29 ngày nếu là năm nhuận, ngược lại có 28 ngày.
 *       - Các tháng còn lại có 31 ngày.
 */
int soNgayTrongThang(int thang, int nam)
{
    switch (thang)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return namNhuan(nam) ? 29 : 28;
    default:
        return 31;
    }
}

/**
 * @brief Kiểm tra tính hợp lệ của một bộ Ngày/Tháng/Nam.
 * @param ngay, thang, nam: Các giá trị cần kiểm tra.
 * @return true nếu ngày tháng tồn tại trong thực tế, ngược lại trả về false.
 * @note Giải thuật:
 *       1. Kiểm tra giới hạn cơ bản: năm >= 1, tháng từ 1-12, ngày >= 1.
 *       2. Kiểm tra ngày nhập vào có vượt quá số ngày tối đa của tháng đó hay không.
 */
bool KiemTraNgayThangNamHopLe(int ngay, int thang, int nam)
{
    if (nam < 1 || thang < 1 || thang > 12 || ngay < 1)
        return false;
    if (ngay > soNgayTrongThang(thang, nam))
        return false;
    return true;
}

/**
 * @brief Hàm khởi tạo mặc định cho lớp cNgay.
 * @note Giải thuật: Thiết lập ngày mặc định là 01/01/2000.
 */
cNgay::cNgay()
{
    ngay = 1;
    thang = 1;
    nam = 2000;
}

/**
 * @brief Nhập dữ liệu cho đối tượng ngày và kiểm tra tính hợp lệ.
 * @note Giải thuật: Gọi hàm NhapNgayThangNam để lấy dữ liệu, sau đó sử dụng
 *       KiemTraNgayThangNamHopLe để bắt người dùng nhập lại cho đến khi đúng.
 */
void cNgay::Nhap()
{
    while (true)
    {
        NhapNgayThangNam(ngay, thang, nam);
        if (KiemTraNgayThangNamHopLe(ngay, thang, nam))
            return;
        cout << "Ngay thang nam khong hop le!\n Vui long nhap lai: ";
    }
}

/**
 * @brief Xuất ngày tháng năm theo định dạng dd/mm/yyyy.
 * @note Giải thuật: Sử dụng hàm setw(2) và setfill('0') để đảm bảo ngày và tháng
 *       luôn hiển thị đủ 2 chữ số (ví dụ: 01/05/2023 thay vì 1/5/2023).
 */
void cNgay::Xuat()
{
    cout << right << setfill('0') << setw(2) << ngay << "/"
         << setw(2) << thang << "/"
         << left << setfill(' ') << nam;
}

/**
 * @brief Lấy giá trị năm của đối tượng.
 * @return Giá trị năm (int).
 */
int cNgay::getNam()
{
    return nam;
}