#include "CVector.h"
#include <iostream>
using namespace std;

CVector::CVector()
{
    n = 0;
    thanhPhan = new double[1];
    thanhPhan[0] = 0;
}
CVector::CVector(int soChieu)
{
    n = soChieu;
    thanhPhan = new double[n];
    for (int i = 0; i < n; i++)
    {
        thanhPhan[i] = 0;
    }
}
CVector::~CVector()
{
    delete[] thanhPhan;
}
CVector::CVector(const CVector &khac)
{
    n = khac.n;
    thanhPhan = new double[n];
    for (int i = 0; i < n; i++)
    {
        thanhPhan[i] = khac.thanhPhan[i];
    }
}
CVector &CVector::operator=(const CVector &khac)
{
    if (this != &khac)
    {
        if (thanhPhan)
        {
            delete[] thanhPhan;
        }
        n = khac.n;
        thanhPhan = new double[n];
        for (int i = 0; i < n; i++)
        {
            thanhPhan[i] = khac.thanhPhan[i];
        }
    }
    return *this;
}
CVector CVector::operator+(const CVector &khac) const
{
    if (this->n != khac.n)
    {
        return CVector(0);
    }
    CVector temp(this->n);
    temp.thanhPhan = new double[temp.n];
    for (int i = 0; i < temp.n; i++)
    {
        temp.thanhPhan[i] = this->thanhPhan[i] + khac.thanhPhan[i];
    }
    return temp;
}
CVector CVector::operator-(const CVector &khac) const
{
    if (this->n != khac.n)
    {
        return CVector(0);
    }
    CVector temp(this->n);
    temp.thanhPhan = new double[temp.n];
    for (int i = 0; i < temp.n; i++)
    {
        temp.thanhPhan[i] = this->thanhPhan[i] - khac.thanhPhan[i];
    }
    return temp;
}
double CVector::operator*(const CVector &khac) const
{
    if (this->n != khac.n)
        return 0;
    double Tong = 0;
    for (int i = 0; i < n; i++)
    {
        Tong += this->thanhPhan[i] * khac.thanhPhan[i];
    }
    return Tong;
}
CVector CVector::operator*(double k) const
{
    CVector temp = *this;
    for (int i = 0; i < temp.n; i++)
    {
        temp.thanhPhan[i] *= k;
    }
    return temp;
}
/**
 * @brief Nhập và ép luồng dữ liệu số nguyên lớn hơn hoặc bằng 1,
 *        chặn các ký tự rác đi kèm.
 * @param is: Tham chiếu đến đối tượng luồng nhập (istream).
 * @return Giá trị số nguyên hợp lệ duy nhất trích xuất được
 *         từ dòng nhập.
 * @note Giải thuật:
 *       1. Sử dụng vòng lặp vô hạn để ép nhập đúng kiểu dữ liệu.
 *       2. Dùng hàm is.peek() để quét kiểm tra toàn bộ các ký tự
 *          còn lại trên dòng sau số nguyên.
 *       3. Nếu phát hiện ký tự rác (không phải khoảng trắng, tab
 *          hay xuống dòng), đánh dấu chuỗi không hợp lệ và ép
 *          nhập lại.
 *       4. Dọn sạch cờ lỗi và bộ nhớ đệm luồng nếu dữ liệu sai
 *          quy chuẩn.
 */
int NhapHopLe(istream &is)
{
    int bac;
    while (true)
    {
        if (is >> bac && bac >= 0)
        {
            bool chuoiHopLe = true;
            char c;
            while (true)
            {
                c = is.peek();
                if (c == '\n' || c == EOF)
                    break;
                if (c != ' ' && c != '\t')
                    chuoiHopLe = false;
                is.get();
            }
            if (chuoiHopLe)
            {
                if (is.peek() == '\n')
                    is.get();
                return bac;
            }
        }
        cout << "Loi! So chieu khong hop le!\nNhap lai: ";
        is.clear();
        is.ignore(10000, '\n');
    }
}

/**
 * @brief Nhập và ép luồng dữ liệu số thực, loại bỏ hoàn
 *        toàn các ký tự rác đi kèm.
 * @param is: Đối tượng luồng nhập (istream).
 * @return giaTri: double.
 * @note Giải thuật:
 *       1. Sử dụng vòng lặp vô hạn và đọc dữ liệu thông qua toán
 *          tử is >> giaTri.
 *       2. Sử dụng is.get(c) để quét từng ký tự còn lại trên
 *          cùng một dòng cho đến khi gặp ký tự xuống dòng (\n).
 *       3. Nếu phát hiện bất kỳ ký tự nào không phải khoảng trắng
 *          (' ') hoặc tab ('\t'), gán cờ chuoiHopLe = false để
 *          đánh dấu dòng nhập chứa ký tự rác
 *          (Ví dụ: nhập "3.14abc").
 *       4. Nếu chuỗi hợp lệ, thoát hàm để lưu giá trị. Ngược lại,
 *          tiến hành xóa cờ lỗi của stream, dọn sạch bộ nhớ đệm
 *          và yêu cầu người dùng nhập lại.
 */
double KiemTraDauVaoChoDouble(istream &is)
{
    double giaTri;
    while (true)
    {
        if (is >> giaTri)
        {
            bool chuoiHopLe = true;
            char c;
            while (is.get(c) && c != '\n')
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
            cout << "Gia tri khong hop le!\nVui long nhap so thuc!\nNhap lai: ";
            continue;
        }
        cout << "Gia tri khong hop le!\nVui long nhap so thuc!\nNhap lai: ";
        is.clear();
        is.ignore(10000, '\n');
    }
}

istream &operator>>(istream &is, CVector &p)
{
    if (p.thanhPhan)
        delete[] p.thanhPhan;
    cout << "Nhap so chieu cua vector: ";
    p.n = NhapHopLe(is);
    p.thanhPhan = new double[p.n];
    for (int i = 0; i < p.n; i++)
    {
        cout << "Nhap toa do thu " << i + 1 << ": ";
        p.thanhPhan[i] = KiemTraDauVaoChoDouble(is);
    }
    return is;
}
ostream &operator<<(ostream &os, const CVector &p)
{
    os << "(";
    for (int i = 0; i < p.n; i++)
    {
        os << p.thanhPhan[i];
        if (i < p.n - 1)
            os << ", ";
    }
    os << ")";
    return os;
}