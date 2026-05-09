#include "cSoPhuc.h"
#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief Hàm khởi tạo số phức với phần thực và phần ảo.
 * @param t: Giá trị phần thực (mặc định 0).
 * @param a: Giá trị phần ảo (mặc định 0).
 */
cSoPhuc::cSoPhuc(double t, double a)
{
    thuc = t;
    ao = a;
}

// toán tử toán học

/**
 * @brief Nạp chồng toán tử cộng hai số phức.
 * @param khac: Số phức thứ hai.
 * @return Đối tượng cSoPhuc là tổng của hai số phức.
 * @note Giải thuật: Cộng phần thực với phần thực, phần ảo với phần ảo.
 */
cSoPhuc cSoPhuc::operator+(const cSoPhuc &khac) const
{
    return cSoPhuc(thuc + khac.thuc, ao + khac.ao);
}

/**
 * @brief Nạp chồng toán tử trừ hai số phức.
 * @param khac: Số phức thứ hai.
 * @return Đối tượng cSoPhuc là hiệu của hai số phức.
 * @note Giải thuật: Trừ phần thực với phần thực, phần ảo với phần ảo.
 */
cSoPhuc cSoPhuc::operator-(const cSoPhuc &khac) const
{
    return cSoPhuc(thuc - khac.thuc, ao - khac.ao);
}

/**
 * @brief Nạp chồng toán tử nhân hai số phức.
 * @param khac: Số phức thứ hai.
 * @return Đối tượng cSoPhuc là tích của hai số phức.
 * @note Giải thuật: Áp dụng công thức (a+bi)(c+di) = (ac-bd) + (ad+bc)i.
 */
cSoPhuc cSoPhuc::operator*(const cSoPhuc &khac) const
{
    double thucMoi = thuc * khac.thuc - ao * khac.ao;
    double aoMoi = thuc * khac.ao + ao * khac.thuc;
    return cSoPhuc(thucMoi, aoMoi);
}

/**
 * @brief Nạp chồng toán tử chia hai số phức.
 * @param khac: Số phức thứ hai.
 * @return Đối tượng cSoPhuc là thương của hai số phức.
 * @note Giải thuật: Nhân cả tử và mẫu với số phức liên hợp của mẫu số.
 *       Mẫu số = c^2 + d^2. Nếu mẫu bằng 0, trả về số phức (0,0).
 */
cSoPhuc cSoPhuc::operator/(const cSoPhuc &khac) const
{
    double mauSo = khac.thuc * khac.thuc + khac.ao * khac.ao;
    if (mauSo == 0)
        return cSoPhuc(0, 0);
    double thucMoi = (thuc * khac.thuc + ao * khac.ao) / mauSo;
    double aoMoi = (ao * khac.thuc - thuc * khac.ao) / mauSo;
    return cSoPhuc(thucMoi, aoMoi);
}

// toán thử so sánh

/**
 * @brief Nạp chồng toán tử so sánh bằng.
 * @param khac: Số phức thứ hai.
 * @return true nếu cả phần thực và phần ảo bằng nhau.
 */
bool cSoPhuc::operator==(const cSoPhuc &khac) const
{
    return (thuc == khac.thuc && ao == khac.ao);
}

/**
 * @brief Hàm hỗ trợ nhập số thực và kiểm tra tính hợp lệ.
 * @param is: Đối tượng luồng nhập (istream).
 * @return Giá trị số thực hợp lệ.
 */
bool cSoPhuc::operator!=(const cSoPhuc &khac) const
{
    return !(*this == khac);
}

/**
 * @brief Hàm hỗ trợ nhập số thực và kiểm tra tính hợp lệ.
 * @param is: Đối tượng luồng nhập (istream).
 * @return Giá trị số thực hợp lệ.
 * @note Giải thuật: nếu đầu vào không phải là double thì
 *       xóa bộ nhớ đệm và nhập lại đến khi nào thỏa mãn
 */
double NhapHopLe(istream &is)
{
    double so;
    while (true)
    {
        if (is >> so)
            return so;
        cout << "Gia tri khong hop le!\nVui long nhap so thuc!\nNhap lai: ";
        is.clear();
        is.ignore(10000, '\n');
    }
}

/**
 * @brief Nạp chồng toán tử nhập luồng (>>).
 * @param is: Đối tượng luồng nhập.
 * @param sp: Đối tượng số phức cần lưu giá trị.
 * @return Tham chiếu đến luồng nhập để nhập liên tiếp.
 */
istream &operator>>(istream &is, cSoPhuc &sp)
{
    cout << "Nhap phan tu thuc: ";
    sp.thuc = NhapHopLe(is);
    cout << "Nhap phan tu ao: ";
    sp.ao = NhapHopLe(is);
    return is;
}

/**
 * @brief Nạp chồng toán tử xuất luồng (<<).
 * @param os: Đối tượng luồng xuất.
 * @param sp: Đối tượng số phức cần in.
 * @return Tham chiếu đến luồng xuất.
 * @note Giải thuật: Xử lý các trường hợp đặc biệt để xuất theo chuẩn toán học:
 *       1. Nếu cả thực và ảo bằng 0, in số 0.
 *       2. Ẩn phần thực nếu bằng 0 (khi ảo khác 0).
 *       3. Xử lý dấu nối (+/-) giữa thực và ảo.
 *       4. Ẩn hệ số 1 trước đơn vị ảo i (in "i" thay vì "1i").
 */
ostream &operator<<(ostream &os, const cSoPhuc &sp)
{
    if (sp.thuc == 0 && sp.ao == 0)
    {
        os << 0;
        return os;
    }
    if (sp.thuc != 0)
    {
        os << sp.thuc;
    }
    if (sp.ao != 0)
    {
        if (sp.ao > 0 && sp.thuc != 0)
        {
            os << " + ";
        }
        else if (sp.ao < 0 && sp.thuc != 0)
        {
            os << " - ";
        }
        else if (sp.ao < 0 && sp.thuc == 0)
        {
            os << "-";
        }
        if (abs(sp.ao) != 1)
        {
            os << abs(sp.ao);
        }
        os << "i";
    }
    return os;
}
