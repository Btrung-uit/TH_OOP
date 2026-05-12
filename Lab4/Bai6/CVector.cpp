#include "CVector.h"
#include <iostream>
#include <stdexcept>
using namespace std;

/**
 * @brief Hàm khởi tạo mặc định cho đối tượng không gian vector.
 * @param Không có.
 * @return Không có.
 */
CVector::CVector()
{
    n = 0;
    thanhPhan = new double[1];
    thanhPhan[0] = 0;
}

/**
 * @brief Hàm khởi tạo đối tượng vector với số chiều cho trước.
 * @param soChieu: Số lượng thành phần tọa độ của không gian vector.
 * @return Không có.
 */
CVector::CVector(int soChieu)
{
    n = soChieu;
    thanhPhan = new double[n];
    for (int i = 0; i < n; i++)
    {
        thanhPhan[i] = 0;
    }
}

/**
 * @brief Hàm hủy đối tượng để giải phóng bộ nhớ.
 * @param Không có.
 * @return Không có.
 */
CVector::~CVector()
{
    delete[] thanhPhan;
}

/**
 * @brief Hàm khởi tạo sao chép (Copy Constructor) để thiết lập vùng
 *        nhớ độc lập.
 * @param khac: Đối tượng nguồn cần sao chép dữ liệu.
 * @return Không có.
 */
CVector::CVector(const CVector &khac)
{
    n = khac.n;
    thanhPhan = new double[n];
    for (int i = 0; i < n; i++)
    {
        thanhPhan[i] = khac.thanhPhan[i];
    }
}

/**
 * @brief Nạp chồng toán tử gán để sao chép sâu giá trị giữa hai đối
 *        tượng vector.
 * @param khac: Đối tượng nguồn chứa dữ liệu cần gán.
 * @return CVector& Tham chiếu đến đối tượng hiện tại sau khi đã
 *         đồng bộ bộ nhớ.
 * @note Giải thuật:
 *       1. Kiểm tra điều kiện tự gán địa chỉ (this != &khac).
 *       2. Giải phóng bộ nhớ động cũ của mảng thanhPhan nếu đang
 *          tồn tại.
 *       3. Cấp phát vùng nhớ mới tương ứng với số chiều của
 *          vector nguồn.
 *       4. Dùng vòng lặp sao chép từng phần tử tọa độ và
 *          trả về con trỏ *this.
 */
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
/**
 * @brief Nạp chồng toán tử cộng hai đối tượng vector đồng số chiều.
 * @param khac: Đối tượng vector thứ hai tham gia phép cộng.
 * @return CVector: Một đối tượng vector mới lưu kết quả của phép
 *         tính tổng.
 * @note Giải thuật:
 *       1. Kiểm tra số chiều giữa hai đối tượng. Nếu lệch nhau,
 *          báo lỗi và trả về một vector rỗng CVector(0).
 *       2. Khởi tạo đối tượng tạm temp có số chiều bằng n và cấp
 *          phát vùng nhớ mảng động.
 *       3. Dùng vòng lặp cộng từng tọa độ tương ứng của hai
 *          vector gốc (`this->thanhPhan[i] + khac.thanhPhan[i]`)
 *          lưu vào biến temp.
 */
CVector CVector::operator+(const CVector &khac) const
{
    if (this->n != khac.n)
    {
        throw invalid_argument("Loi! Khong the cong 2 vector khac so chieu!");
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

/**
 * @brief Nạp chồng toán tử trừ hai đối tượng vector đồng số chiều.
 * @param khac: Đối tượng vector bị trừ.
 * @return CVector: Một đối tượng vector mới lưu kết quả của phép
 *         tính hiệu.
 * @note Giải thuật: Kiểm tra điều kiện số chiều tương tự toán tử
 *       cộng, sau đó dùng vòng lặp để lấy hiệu các tọa độ đồng
 *       vị trí lưu vào đối tượng temp.
 */
CVector CVector::operator-(const CVector &khac) const
{
    if (this->n != khac.n)
    {
        throw invalid_argument("Loi! Khong the tru 2 vector khac so chieu!");
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

/**
 * @brief Nạp chồng toán tử nhân hai đối tượng vector để tính tích
 *        vô hướng (Dot Product).
 * @param khac: Đối tượng vector thứ hai tham gia phép nhân.
 * @return Giá trị vô hướng kết quả của phép toán nhân (double).
 * @note Giải thuật:
 *       1. Kiểm tra sự tương thích về số chiều của không gian;
 *          nếu không khớp, trả về giá trị mặc định 0.
 *       2. Khởi tạo biến tích lũy Tong = 0.
 *       3. Chạy vòng lặp tính tổng các tích của từng thành phần tọa
 *          độ tương ứng: Tong += (thanhPhan[i] * khac.thanhPhan[i]).
 */
double CVector::operator*(const CVector &khac) const
{
    if (this->n != khac.n)
    {
        throw invalid_argument("Loi! Khong the nhan 2 vector khac so chieu!");
        return 0;
    }
    double Tong = 0;
    for (int i = 0; i < n; i++)
    {
        Tong += this->thanhPhan[i] * khac.thanhPhan[i];
    }
    return Tong;
}

/**
 * @brief Nạp chồng toán tử nhân một số vô hướng với đối tượng
 *        vector.
 * @param k: Hệ số tỉ lệ thuộc kiểu số thực double.
 * @return CVector: Đối tượng vector mới sau khi đã co giãn
 *         kích thước.
 * @note Giải thuật: Sao chép toàn bộ trạng thái hiện tại
 *       sang đối tượng tạm temp thông qua hàm khởi tạo sao
 *       chép, sau đó dùng vòng lặp nhân hệ số k vào tất cả
 *       các thành phần tọa độ của temp.
 */
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

/**
 * @brief Nạp chồng toán tử nhập luồng để thiết lập cấu hình số
 *        chiều và giá trị tọa độ cho không gian vector.
 * @param is: Tham chiếu đến đối tượng luồng nhập (istream).
 * @param p: Tham chiếu đến đối tượng CVector nhận giá trị sau khi
 *           xử lý dòng nhập.
 * @return istream&: Trả về tham chiếu của luồng nhập để hỗ trợ cơ
 *         chế nhập nối tiếp.
 * @note Giải thuật:
 *       1. Giải phóng mảng động cũ p.thanhPhan để chống tràn rò
 *          rỉ dữ liệu.
 *       2. Gọi hàm NhapHopLe() thu thập số chiều hợp lệ gán vào
 *          thuộc tính p.n.
 *       3. Khởi tạo mảng động mới tương ứng với kích thước p.n.
 *       4. Sử dụng vòng lặp kết hợp hàm KiemTraDauVaoChoDouble()
 *          để điền giá trị số thực cho từng trục tọa độ.
 */
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

/**
 * @brief Nạp chồng toán tử xuất luồng biểu diễn vector dưới dạng
 *        chuỗi toán học.
 * @param os: Tham chiếu đến đối tượng luồng xuất (ostream).
 * @param p: Tham chiếu hằng đến đối tượng CVector cần hiển thị
 *           thông tin.
 * @return ostream&: Trả về tham chiếu của luồng xuất để hỗ trợ
 *         in nối tiếp dữ liệu.
 * @note Giải thuật: In ký tự mở ngoặc "(", dùng vòng lặp xuất
 *       tuần tự các phần tử trong mảng cách nhau bởi dấu phẩy
 *       ", ", và kết thúc bằng ký tự đóng ngoặc ")".
 */
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