#include <iostream>
#include <cmath>
#include "cDaThuc.h"
using namespace std;

/**
 * @brief Hàm khởi tạo mặc định.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Khởi tạo đa thức bậc 0 với hệ số bằng 0.
 */
cDaThuc::cDaThuc()
{
    n = 0;
    heSo = new double[1];
    heSo[0] = 0;
}

/**
 * @brief Hàm khởi tạo đa thức với bậc cho trước.
 * @param bac: Bậc của đa thức.
 * @return Không có.
 * @note Giải thuật: Cấp phát mảng động heSo kích thước (bac + 1) và
 *       gán tất cả bằng 0.
 */
cDaThuc::cDaThuc(int bac)
{
    n = bac;
    heSo = new double[n + 1];
    for (int i = 0; i <= n; i++)
    {
        heSo[i] = 0;
    }
}

/**
 * @brief Hàm hủy đối tượng.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Giải phóng bộ nhớ mảng động heSo để tránh rò rỉ.
 */
cDaThuc::~cDaThuc()
{
    if (heSo)
        delete[] heSo;
}

/**
 * @brief Hàm khởi tạo sao chép (Copy Constructor).
 * @param khac: Đối tượng đa thức nguồn cần sao chép.
 * @return Không có.
 * @note Giải thuật: Tạo một vùng nhớ mới và sao chép toàn bộ bậc và
 *       hệ số từ đối tượng "khac".
 */
cDaThuc::cDaThuc(const cDaThuc &khac)
{
    n = khac.n;
    heSo = new double[n + 1];
    for (int i = 0; i <= n; i++)
    {
        heSo[i] = khac.heSo[i];
    }
}

/**
 * @brief Toán tử gán (Assignment Operator).
 * @param khac: Đối tượng đa thức nguồn cần gán.
 * @return Tham chiếu đến đối tượng hiện tại sau khi gán.
 * @note Giải thuật:
 *       1. Kiểm tra tự gán (this == &khac).
 *       2. Giải phóng vùng nhớ cũ, cấp phát vùng nhớ mới và sao chép dữ liệu.
 */
cDaThuc &cDaThuc::operator=(const cDaThuc &khac)
{
    if (this != &khac)
    {
        if (heSo)
        {
            delete[] heSo;
        }
        n = khac.n;
        heSo = new double[n + 1];
        for (int i = 0; i <= n; i++)
        {
            heSo[i] = khac.heSo[i];
        }
    }
    return *this;
}

/**
 * @brief Tính giá trị của đa thức tại x bằng sơ đồ Horner.
 * @param x: Giá trị của biến x cần tính.
 * @return Giá trị của đa thức (double).
 * @note Giải thuật: Sử dụng lược đồ Horner để tối ưu số phép nhân:
 *       P(x) = (...((a_n*x + a_n-1)*x + a_n-2)*x + ... + a_0).
 */
double cDaThuc::TinhGiaTri(double x) const
{
    double sum = heSo[0];
    for (int i = 1; i <= n; i++)
    {
        sum = sum * x + heSo[i];
    }
    return sum;
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
        cout << "Loi! Bac khong hop le!\nNhap lai: ";
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
// Operator >>, <<

/**
 * @brief Nạp chồng toán tử nhập luồng để cấu hình bậc và danh sách
 *        hệ số cho đa thức.
 * @param is: Tham chiếu đến đối tượng luồng nhập (istream), thường
 *        là cin.
 * @param p: Tham chiếu đến đối tượng cDaThuc cần lưu trữ dữ liệu
 *        sau khi nhập.
 * @return istream&: Trả về tham chiếu của luồng nhập để hỗ trợ cơ
 *         chế nhập liên tiếp.
 * @note Giải thuật:
 *       1. Gọi hàm NhapHopLe để lấy và kiểm tra tính hợp lệ của
 *          bậc đa thức n (n >= 0).
 *       2. Kiểm tra bộ nhớ cũ của mảng heSo; nếu tồn tại dữ liệu,
 *          tiến hành giải phóng bằng delete[] để tránh rò rỉ bộ nhớ.
 *       3. Cấp phát vùng nhớ mới cho mảng heSo với kích thước n + 1
 *          phần tử.
 *       4. Chạy vòng lặp từ 0 đến n, gọi hàm KiemTraDauVaoChoDouble
 *          để điền giá trị cho từng hệ số từ bậc cao đến bậc thấp.
 */
istream &operator>>(istream &is, cDaThuc &p)
{
    cout << "Nhap bac cua da thuc (n >= 0): ";
    p.n = NhapHopLe(is);

    // Giải phóng bộ nhớ cũ nếu có trước khi cấp phát mới
    if (p.heSo)
        delete[] p.heSo;

    p.heSo = new double[p.n + 1];
    for (int i = 0; i <= p.n; i++)
    {
        cout << "Nhap he so cua x^" << p.n - i << ": ";
        p.heSo[i] = KiemTraDauVaoChoDouble(is);
    }
    return is;
}

/**
 * @brief Nạp chồng toán tử xuất luồng để in đa thức ra màn hình
 *        theo định dạng thẩm mỹ toán học.
 * @param os: Tham chiếu đến đối tượng luồng xuất (ostream),
 *        thường là cout.
 * @param p: Tham chiếu hằng đến đối tượng cDaThuc cần hiển thị.
 * @return ostream&: Trả về tham chiếu của luồng xuất để hỗ trợ
 *         cơ chế in nối tiếp.
 * @note Giải thuật: Duyệt qua mảng hệ số để xây dựng chuỗi hiển
 *       thị tối ưu:
 *       1. Bỏ qua các phần tử có hệ số bằng 0.
 *       2. Xử lý dấu nối (" + " hoặc " - ") giữa các đơn thức dựa
 *          trên biến cờ DaInPhanTuDau.
 *       3. Trích xuất trị tuyệt đối của hệ số, ẩn giá trị 1 nếu
 *          đơn thức có biến x (bậc > 0).
 *       4. Hiển thị biến x kèm ký tự mũ "^" tương ứng nếu số mũ
 *          lớn hơn 1.
 *       5. Nếu đa thức trống (tất cả hệ số bằng 0), in ra giá trị
 *          mặc định là "0".
 */
ostream &operator<<(ostream &os, const cDaThuc &p)
{
    bool DaInPhanTuDau = false;
    for (int i = 0; i <= p.n; i++)
    {
        if (p.heSo[i] == 0)
            continue;
        int bac = p.n - i;
        if (p.heSo[i] > 0 && DaInPhanTuDau)
            os << " + ";
        if (p.heSo[i] < 0)
        {
            if (DaInPhanTuDau)
                os << " - ";
            else
                os << '-';
        }
        double triTuyetDoi = abs(p.heSo[i]);
        if (triTuyetDoi != 1 || bac == 0)
        {
            os << triTuyetDoi;
        }
        if (bac > 0)
        {
            os << "x";
            if (bac > 1)
                os << "^" << bac;
        }
        DaInPhanTuDau = true;
    }
    if (!DaInPhanTuDau)
        os << "0";
    return os;
}

// Toán tử +, -
/**
 * @brief Nạp chồng toán tử cộng để tính tổng của hai đa thức.
 * @param p: Tham chiếu hằng đến đối tượng đa thức thứ hai
 *        cần cộng.
 * @return cDaThuc: Một đối tượng đa thức mới lưu trữ kết quả phép
 *         tính tổng.
 * @note Giải thuật:
 *       1. Tìm bậc lớn nhất (bacMax) giữa đa thức hiện tại và đa
 *          thức p để làm bậc cho đa thức tổng.
 *       2. Khởi tạo đối tượng Tong với kích thước vùng nhớ tương
 *          ứng bacMax.
 *       3. Sử dụng vòng lặp duyệt từ bậc nhỏ nhất (bậc 0) tăng
 *          dần lên:
 *          - Trích xuất hệ số tương ứng qua chỉ số đảo `n - i`
 *          hoặc `p.n - i`.
 *          - Nếu chỉ số vượt quá bậc của đa thức nào, gán giá trị
 *          mặc định bằng 0.
 *       4. Cộng hai giá trị hệ số thu được và lưu vào vị trí tương
 *          ứng trong đa thức Tong.
 */
cDaThuc cDaThuc::operator+(const cDaThuc &p) const
{
    int bacMax = (n > p.n) ? n : p.n;
    cDaThuc Tong(bacMax);
    for (int i = 0; i <= bacMax; i++)
    {
        double heSo1 = (i <= n) ? heSo[n - i] : 0;
        double heSo2 = (i <= p.n) ? p.heSo[p.n - i] : 0;
        Tong.heSo[Tong.n - i] = heSo1 + heSo2;
    }
    return Tong;
}

/**
 * @brief Nạp chồng toán tử trừ để tính hiệu của hai đa thức.
 * @param p: Tham chiếu hằng đến đối tượng đa thức bị trừ.
 * @return cDaThuc: Một đối tượng đa thức mới lưu trữ kết quả phép
 *         tính hiệu.
 * @note Giải thuật: Thực hiện tương tự giải thuật của toán tử cộng,
 *       nhưng tiến hành lấy hiệu giữa hai hệ số đồng bậc
 *       (`heSo1 - heSo2`) trước khi điền vào đa thức kết quả Hieu.
 */
cDaThuc cDaThuc::operator-(const cDaThuc &p) const
{
    int bacMax = (n > p.n) ? n : p.n;
    cDaThuc Hieu(bacMax);
    for (int i = 0; i <= bacMax; i++)
    {
        double heSo1 = (i <= n) ? heSo[n - i] : 0;
        double heSo2 = (i <= p.n) ? p.heSo[p.n - i] : 0;
        Hieu.heSo[Hieu.n - i] = heSo1 - heSo2;
    }
    return Hieu;
}