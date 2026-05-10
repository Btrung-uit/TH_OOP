#include "cPhanSo.h"
#include <cmath>
#include <limits>

/**
 * @brief Tìm ước số chung lớn nhất (UCLN) của hai số nguyên.
 * @param a, b: Hai số nguyên cần tìm UCLN.
 * @return Giá trị UCLN (số dương).
 * @note Giải thuật: Sử dụng thuật toán Euclid (thực hiện phép
 *       chia lấy dư liên tiếp cho đến khi số dư bằng 0).
 */
int TimUCLN(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

/**
 * @brief Nhập và kiểm tra tính toàn vẹn của số nguyên đầu vào,
 *        chặn tuyệt đối số thập phân và chuỗi rác.
 * @param is: Tham chiếu đến đối tượng luồng nhập dữ liệu
 *            (thường là cin hoặc luồng file).
 * @return int Giá trị số nguyên đã được xác thực hợp lệ.
 * @note Giải thuật:
 *      - Bước 1: Trích xuất thử một số nguyên từ đầu luồng nhập.
 *      - Bước 2: Dùng peek() kiểm tra các ký tự còn lại trên dòng.
 *      - Bước 3: Nếu phát hiện ký tự không phải khoảng trắng
 *                (như dấu chấm, chữ cái), đánh dấu đầu vào sai.
 *      - Bước 4: Nếu đầu vào hợp lệ, bỏ qua ký tự newline và trả về.
 *      - Bước 5: Nếu lỗi, dọn dẹp luồng (clear, ignore) và yêu cầu nhập lại.
 */
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
        cout << "Loi! Vui long nhap so nguyen!\nNhap lai: ";
        is.clear();
        is.ignore(10000, '\n');
    }
}

/**
 * @brief Hàm khởi tạo phân số với tử và mẫu cho trước.
 * @param tu: Giá trị tử số.
 * @param mau: Giá trị mẫu số.
 * @return Không có.
 * @note Giải thuật: Gán giá trị, chặn trường hợp mẫu
 *       bằng 0 (mặc định về 1) và tự động gọi RutGon().
 */
cPhanSo::cPhanSo(int tu, int mau)
{
    tuSo = tu;
    // Chặn mẫu số bằng 0 lúc khởi tạo
    mauSo = (mau == 0) ? 1 : mau;
    RutGon();
}

/**
 * @brief Rút gọn phân số về dạng tối giản và chuẩn hóa dấu.
 * @return Không có.
 * @note Giải thuật:
 *       1. Tìm UCLN của tử và mẫu.
 *       2. Chia cả tử và mẫu cho UCLN.
 *       3. Nếu mẫu số âm, đưa dấu trừ lên tử số để mẫu số
 *          luôn dương.
 */
void cPhanSo::RutGon()
{
    if (mauSo == 0)
        return;
    int ucln = TimUCLN(tuSo, mauSo);
    tuSo /= ucln;
    mauSo /= ucln;
    if (mauSo < 0)
    { // Đưa dấu trừ lên tử số
        tuSo = -tuSo;
        mauSo = -mauSo;
    }
}

// Toán tử toán học

/**
 * @brief Nạp chồng toán tử cộng hai phân số.
 * @param khac: Phân số thứ hai.
 * @return Đối tượng cPhanSo mới đã được rút gọn.
 * @note Giải thuật: Sử dụng công thức (a/b + c/d) = (ad + bc) / bd.
 */
cPhanSo cPhanSo::operator+(const cPhanSo &khac) const
{
    int tuSoMoi = tuSo * khac.mauSo + khac.tuSo * mauSo;
    int mauSoMoi = mauSo * khac.mauSo;
    return cPhanSo(tuSoMoi, mauSoMoi);
}

/**
 * @brief Nạp chồng toán tử trừ hai phân số.
 * @param khac: Phân số thứ hai.
 * @return Đối tượng cPhanSo mới đã được rút gọn.
 * @note Giải thuật: Sử dụng công thức (a/b - c/d) = (ad - bc) / bd.
 */
cPhanSo cPhanSo::operator-(const cPhanSo &khac) const
{
    int tuSoMoi = tuSo * khac.mauSo - khac.tuSo * mauSo;
    int mauSoMoi = mauSo * khac.mauSo;
    return cPhanSo(tuSoMoi, mauSoMoi);
}

/**
 * @brief Nạp chồng toán tử chia hai phân số.
 * @param khac: Phân số thứ hai.
 * @return Đối tượng cPhanSo mới đã được rút gọn.
 * @note Giải thuật: Nhân với phân số nghịch đảo. Kiểm tra lỗi
 *       nếu tử số của phân số chia bằng 0.
 */
cPhanSo cPhanSo::operator*(const cPhanSo &khac) const
{
    int tuSoMoi = tuSo * khac.tuSo;
    int mauSoMoi = mauSo * khac.mauSo;
    return cPhanSo(tuSoMoi, mauSoMoi);
}

/**
 * @brief Nạp chồng toán tử so sánh bằng.
 * @param khac: Phân số thứ hai.
 * @return Đối tượng cPhanSo mới đã được rút gọn.
 * @note Giải thuật: So sánh tử với tử và mẫu với mẫu
 *       (do phân số đã luôn được tối giản).
 */
cPhanSo cPhanSo::operator/(const cPhanSo &khac) const
{
    if (khac.tuSo == 0)
    {
        cout << "Loi! Chia cho phan so 0! ";
        return cPhanSo(0, 1);
    }
    int tuSoMoi = tuSo * khac.mauSo;
    int mauSoMoi = mauSo * khac.tuSo;
    return cPhanSo(tuSoMoi, mauSoMoi);
}

// Toán tử so sánh

/**
 * @brief Nạp chồng toán tử so sánh bằng.
 * @param khac: Phân số thứ hai.
 * @return true nếu cả tử số và mẫu số của hai phân số bằng nhau.
 * @note Giải thuật: So sánh tử với tử và mẫu với mẫu
 *       (do phân số đã luôn được tối giản).
 */
bool cPhanSo::operator==(const cPhanSo &khac) const
{
    return (tuSo == khac.tuSo && mauSo == khac.mauSo);
}

/**
 * @brief Nạp chồng toán tử so sánh lớn hơn.
 * @param khac: Phân số thứ hai.
 * @return true nếu giá trị của phân số 1 lớn hơn phân số 2.
 * @note Giải thuật: Ép kiểu sang double để thực hiện phép
 *       so sánh giá trị thập phân.
 */
bool cPhanSo::operator>(const cPhanSo &khac) const
{
    double ps1 = (double)tuSo / mauSo;
    double ps2 = (double)khac.tuSo / khac.mauSo;
    return ps1 > ps2;
}

/**
 * @brief Nạp chồng toán tử so sánh lớn hơn.
 * @param khac: Phân số thứ hai.
 * @return true nếu giá trị của phân số 1 nhỏ hơn phân số 2.
 * @note Giải thuật: Ép kiểu sang double để thực hiện phép
 *       so sánh giá trị thập phân.
 */
bool cPhanSo::operator<(const cPhanSo &khac) const
{
    double ps1 = (double)tuSo / mauSo;
    double ps2 = (double)khac.tuSo / khac.mauSo;
    return ps1 < ps2;
}

// Toán tử nhập xuất

/**
 * @brief Nạp chồng toán tử nhập luồng để nhập phân số từ bàn phím.
 * @param is: Tham chiếu đến đối tượng luồng nhập (istream).
 * @param ps: Tham chiếu đến đối tượng cPhanSo để lưu giá trị nhập vào.
 * @return istream&: Trả về tham chiếu của luồng nhập để hỗ trợ việc
 *                   nhập liên tiếp.
 * @note Giải thuật:
 *       1. Gọi hàm NhapHopLe để lấy giá trị nguyên cho tử số.
 *       2. Sử dụng vòng lặp để nhập mẫu số, yêu cầu nhập lại nếu giá
 *          trị bằng 0.
 *       3. Tự động gọi hàm RutGon() để chuẩn hóa phân số ngay sau khi nhập.
 */
istream &operator>>(istream &is, cPhanSo &ps)
{
    cout << "Nhap tu so: ";
    ps.tuSo = NhapHopLe(is);
    while (true)
    {
        cout << "Nhap mau so (khac 0): ";
        ps.mauSo = NhapHopLe(is);
        if (ps.mauSo != 0)
            break;
        cout << "Mau so phai khac 0!\nVui long nhap lai!\n";
    }
    ps.RutGon();
    return is;
}

/**
 * @brief Nạp chồng toán tử xuất luồng để in phân số ra màn hình.
 * @param os: Tham chiếu đến đối tượng luồng xuất (ostream).
 * @param ps: Tham chiếu hằng đến đối tượng cPhanSo cần xuất.
 * @return ostream&: Trả về tham chiếu của luồng xuất để hỗ trợ
 *         việc in liên tiếp.
 * @note Giải thuật: Kiểm tra các trường hợp đặc biệt để in theo
 *       định dạng tối ưu:
 *       1. Nếu tử số bằng 0, chỉ in "0".
 *       2. Nếu mẫu số bằng 1, chỉ in giá trị tử số (in số nguyên).
 *       3. Các trường hợp còn lại in theo định dạng "tuSo/mauSo".
 */
ostream &operator<<(ostream &os, const cPhanSo &ps)
{
    if (ps.tuSo == 0)
        os << "0";
    else if (ps.mauSo == 1)
        os << ps.tuSo;
    else
        os << ps.tuSo << "/" << ps.mauSo;
    return os;
}