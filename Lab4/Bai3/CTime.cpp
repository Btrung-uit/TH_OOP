#include "CTime.h"
#include <iomanip>

// --- HÀM PHỤ TRỢ NỘI BỘ ---
void CTime::ChuanHoa()
{
    long long tongGiay = gio * 3600 + phut * 60 + giay;

    tongGiay = tongGiay % 86400; // 86400 giây = 1 ngày
    if (tongGiay < 0)
    {
        tongGiay += 86400;
    }

    gio = tongGiay / 3600;
    phut = (tongGiay % 3600) / 60;
    giay = tongGiay % 60;
}

// --- PHƯƠNG THỨC THIẾT LẬP ---
CTime::CTime(int h, int m, int s)
{
    gio = h;
    phut = m;
    giay = s;
    ChuanHoa();
}

// --- TOÁN TỬ CỘNG / TRỪ SỐ NGUYÊN ---
CTime CTime::operator+(int s) const
{
    return CTime(gio, phut, giay + s);
}

CTime CTime::operator-(int s) const
{
    return CTime(gio, phut, giay - s);
}

// --- TOÁN TỬ TĂNG / GIẢM (TIỀN TỐ) ---
CTime &CTime::operator++()
{
    giay++;
    ChuanHoa();
    return *this;
}

CTime &CTime::operator--()
{
    giay--;
    ChuanHoa();
    return *this;
}

// --- TOÁN TỬ TĂNG / GIẢM (HẬU TỐ) ---
CTime CTime::operator++(int)
{
    CTime temp = *this; // Lưu lại trạng thái cũ
    giay++;
    ChuanHoa();
    return temp; // Trả về trạng thái trước khi tăng
}

CTime CTime::operator--(int)
{
    CTime temp = *this;
    giay--;
    ChuanHoa();
    return temp;
}

int NhapHopLe(istream &is)
{
    int so;
    while (true)
    {
        if (is >> so)
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
                return so;
            }
        }
        cout << "Loi! Thoi gian khong hop le!\nNhap lai: ";
        is.clear();
        is.ignore(10000, '\n');
    }
}
// --- TOÁN TỬ NHẬP / XUẤT ---
istream &operator>>(istream &is, CTime &t)
{
    cout << "Nhap gio: ";
    while (true)
    {
        t.gio = NhapHopLe(is);
        if (t.gio >= 0 && t.gio <= 23)
            break;
        cout << "Gio khong hop le!\nVui long nhap lai: ";
    }
    cout << "\nNhap phut: ";
    while (true)
    {
        t.phut = NhapHopLe(is);
        if (t.phut >= 0 && t.phut <= 59)
            break;
        cout << "Phut khong hop le!\nVui long nhap lai: ";
    }
    cout << "\nNhap giay: ";
    while (true)
    {
        t.giay = NhapHopLe(is);
        if (t.giay >= 0 && t.giay <= 59)
            break;
        cout << "Giay khong hop le!\nVui long nhap lai: ";
    }
    t.ChuanHoa();
    return is;
}

ostream &operator<<(ostream &os, const CTime &t)
{
    // Căn chỉnh thêm số 0 ở trước nếu chỉ có 1 chữ số (VD: 09:05:01)
    os << setfill('0')
       << setw(2) << t.gio << ":"
       << setw(2) << t.phut << ":"
       << setw(2) << t.giay
       << setfill(' '); // Trả lại khoảng trắng
    return os;
}