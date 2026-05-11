#include "CDate.h"
#include <iomanip>
#include <limits>

/**
 * @brief Hàm khởi tạo đối tượng ngày tháng năm với các giá trị cho
 *        trước.
 * @param d: Giá trị ngày truyền vào.
 * @param m: Giá trị tháng truyền vào.
 * @param y: Giá trị năm truyền vào.
 * @return Không có.
 */
CDate::CDate(int d, int m, int y) : ngay(d), thang(m), nam(y) {}

/**
 * @brief Kiểm tra một năm có phải là năm nhuận theo lịch Gregory
 *        hay không.
 * @param y: Giá trị năm cần kiểm tra.
 * @return true nếu là năm nhuận, false nếu không phải.
 * @note Giải thuật: Năm nhuận là năm chia hết cho 400, hoặc chia
 *       hết cho 4 nhưng đồng thời không chia hết cho 100.
 */
bool CDate::LaNamNhuan(int y) const
{
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

/**
 * @brief Xác định số ngày tối đa trong một tháng thuộc một năm
 *        cụ thể.
 * @param m: Giá trị tháng cần kiểm tra.
 * @param y: Giá trị năm cần đối chiếu (để xét năm nhuận cho tháng 2).
 * @return Số ngày tối đa trong tháng đó (28, 29, 30 hoặc 31).
 * @note Giải thuật:
 *       - Tháng 2: Gọi hàm LaNamNhuan(y) để trả về 29 ngày nếu
 *         nhuận, ngược lại là 28 ngày.
 *       - Tháng 4, 6, 9, 11: Trả về 30 ngày.
 *       - Các tháng còn lại: Trả về 31 ngày.
 */
int CDate::SoNgayTrongThang(int m, int y) const
{
    switch (m)
    {
    case 2:
        return LaNamNhuan(y) ? 29 : 28;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    default:
        return 31;
    }
}

/**
 * @brief Kiểm tra tính hợp lệ về mặt lịch pháp của bộ ba
 *        Ngày/Tháng/Năm.
 * @param d: Giá trị ngày cần kiểm tra.
 * @param m: Giá trị tháng cần kiểm tra.
 * @param y: Giá trị năm cần kiểm tra.
 * @return true nếu ngày tháng năm tồn tại trên thực tế,
 *         false nếu không hợp lệ.
 * @note Giải thuật:
 *       1. Kiểm tra các giới hạn cơ bản tối thiểu: nam >= 1,
 *          tháng nằm trong đoạn [1, 12], ngày >= 1.
 *       2. Gọi hàm SoNgayTrongThang(m, y) để kiểm tra ngày d
 *          có vượt quá giới hạn ngày tối đa của tháng đó hay không.
 */
bool CDate::KiemTraNgay(int d, int m, int y) const
{
    if (y < 1 || m < 1 || m > 12 || d < 1)
        return false;
    if (d > SoNgayTrongThang(m, y))
        return false;
    return true;
}

/**
 * @brief Quy đổi mốc thời gian hiện tại thành tổng số ngày tính
 *        từ ngày 1/1/1.
 * @param Không có.
 * @return Tổng số ngày tích lũy tính từ mốc lịch gốc (long).
 * @note Giải thuật:
 *       1. Khởi tạo tổng số ngày bằng giá trị ngày hiện tại.
 *       2. Chạy vòng lặp cộng dồn số ngày của các năm trước đó
 *          (366 ngày nếu năm nhuận, 365 ngày nếu năm thường).
 *       3. Chạy vòng lặp cộng dồn số ngày của các tháng trước
 *          đó trong năm hiện tại bằng hàm SoNgayTrongThang().
 */
long CDate::ToDays() const
{
    long total = ngay;
    for (int y = 1; y < nam; y++)
        total += (LaNamNhuan(y) ? 366 : 365);
    for (int m = 1; m < thang; m++)
        total += SoNgayTrongThang(m, nam);
    return total;
}

// --- TOÁN TỬ CỘNG/TRỪ SỐ NGÀY ---

/**
 * @brief Nạp chồng toán tử cộng để tiến tới một số ngày nhất
 *        định trong tương lai.
 * @param days: Số ngày cần cộng thêm.
 * @return Đối tượng CDate mới chứa mốc ngày tháng sau khi cộng.
 * @note Giải thuật:
 *       1. Sao chép đối tượng hiện tại sang biến kết quả res và
 *          cộng trực tiếp số ngày vào thuộc tính ngay.
 *       2. Chạy vòng lặp while: Khi số ngày vượt quá giới hạn tối
 *          đa của tháng hiện tại, trừ bớt số ngày bằng
 *          SoNgayTrongThang() và tăng thuộc tính thang lên 1.
 *       3. Nếu thang vượt quá 12, reset về tháng 1 và tăng thuộc
 *          tính nam lên 1.
 */
CDate CDate::operator+(int days) const
{
    CDate res = *this;
    res.ngay += days;
    while (res.ngay > SoNgayTrongThang(res.thang, res.nam))
    {
        res.ngay -= SoNgayTrongThang(res.thang, res.nam);
        res.thang++;
        if (res.thang > 12)
        {
            res.thang = 1;
            res.nam++;
        }
    }
    return res;
}

/**
 * @brief Nạp chồng toán tử trừ để lùi lại một số ngày nhất định
 *        trong quá khứ.
 * @param days: Số ngày cần lùi lại.
 * @return Đối tượng CDate mới chứa mốc ngày tháng sau khi trừ,
 *         hoặc giữ nguyên nếu vượt quá mốc lịch gốc.
 * @note Giải thuật:
 *       1. Sử dụng hàm ToDays() để kiểm tra nếu tổng số ngày tích
 *          lũy nhỏ hơn hoặc bằng số ngày muốn trừ, in ra thông báo
 *          lỗi và trả về đối tượng ban đầu.
 *       2. Sao chép dữ liệu sang biến tạm res và trừ trực tiếp
 *          thuộc tính ngay cho số ngày truyền vào.
 *       3. Chạy vòng lặp while lùi thời gian khi thuộc tính
 *          ngay <= 0: Giảm thuộc tính thang, nếu thang <= 0 thì
 *          reset về tháng 12 và giảm thuộc tính nam. Cộng dồn số
 *          ngày tối đa của tháng mới vào thuộc tính ngay cho đến
 *          khi ngay > 0.
 */
CDate CDate::operator-(int days) const
{
    if (this->ToDays() <= days)
    {
        cout << "Loi! So ngay tru vuot qua moc 1/1/1\nTra ve ngay ban dau\n";
        return *this;
    }
    CDate res = *this;
    res.ngay -= days;
    while (res.ngay <= 0)
    {
        res.thang--;
        if (res.thang <= 0)
        {
            res.thang = 12;
            res.nam--;
        }
        res.ngay += SoNgayTrongThang(res.thang, res.nam);
    }
    return res;
}

// --- TIỀN TỐ & HẬU TỐ ---

/**
 * @brief Nạp chồng toán tử tăng 1 ngày - Dạng tiền tố (++d).
 * @param Không có.
 * @return CDate& Tham chiếu đến chính đối tượng hiện tại sau
 *         khi đã cộng thêm 1 ngày.
 * @note Giải thuật: Tận dụng toán tử cộng số ngày
 *       (*this = *this + 1) để cập nhật và trả về con trỏ *this.
 */
CDate &CDate::operator++()
{
    *this = *this + 1;
    return *this;
}

/**
 * @brief Nạp chồng toán tử tăng 1 ngày - Dạng hậu tố (d++).
 * @param int: Tham số giả định của C++ để phân biệt cấu trúc
 *        với tiền tố.
 * @return Đối tượng CDate lưu giá trị mốc thời gian TRƯỚC khi
 *         thực hiện phép tăng.
 * @note Giải thuật: Lưu lại trạng thái hiện tại vào biến tạm
 *       temp, gọi toán tử tiền tố để tăng đối tượng chính lên
 *       1 ngày, sau đó trả về biến temp.
 */
CDate CDate::operator++(int)
{
    CDate temp = *this;
    ++(*this);
    return temp;
}

/**
 * @brief Nạp chồng toán tử giảm 1 ngày - Dạng tiền tố (--d).
 * @param Không có.
 * @return CDate& Tham chiếu đến chính đối tượng hiện tại sau
 *        khi đã lùi 1 ngày.
 * @note Giải thuật: Tận dụng toán tử trừ số ngày
 *       (*this = *this - 1) để cập nhật và trả về con trỏ *this.
 */
CDate &CDate::operator--()
{
    *this = *this - 1;
    return *this;
}
/**
 * @brief Nạp chồng toán tử giảm 1 ngày - Dạng hậu tố (d--).
 * @param int: Tham số giả định của C++ để phân biệt cấu trúc
 *        với tiền tố.
 * @return Đối tượng CDate lưu giá trị mốc thời gian TRƯỚC khi
 *         thực hiện phép giảm.
 * @note Giải thuật: Lưu lại trạng thái hiện tại vào biến tạm
 *       temp, gọi toán tử tiền tố để giảm đối tượng chính đi
 *       1 ngày, sau đó trả về biến temp.
 */
CDate CDate::operator--(int)
{
    CDate temp = *this;
    --(*this);
    return temp;
}

// --- KHOẢNG CÁCH ---

/**
 * @brief Nạp chồng toán tử trừ hai đối tượng CDate để tính khoảng
 *        cách số ngày giữa chúng.
 * @param khac: Đối tượng mốc thời gian thứ hai cần đối chiếu
 *              khoảng cách.
 * @return Khoảng cách số ngày chênh lệch giữa hai mốc thời
 *         gian (int).
 * @note Giải thuật: Sử dụng hàm ToDays() để lấy tổng số ngày
 *       tích lũy từ mốc 1/1/1 của từng đối tượng, sau đó thực
 *       hiện phép trừ hiệu số giữa chúng và ép kiểu về int.
 */
int CDate::operator-(const CDate &khac) const
{
    return (int)(this->ToDays() - khac.ToDays());
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
    int thoiGian;
    while (true)
    {
        if (is >> thoiGian && thoiGian >= 1)
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
                return thoiGian;
            }
        }
        cout << "Loi! Thoi gian khong hop le!\nNhap lai: ";
        is.clear();
        is.ignore(10000, '\n');
    }
}

/**
 * @brief Nạp chồng toán tử nhập luồng nhằm cấu hình bộ giá trị
 *        Ngày/Tháng/Năm hợp lệ cho đối tượng CDate.
 * @param is: Tham chiếu đến đối tượng luồng nhập (istream).
 * @param d: Tham chiếu đến đối tượng CDate cần lưu trữ thông tin.
 * @return istream& Trả về tham chiếu của luồng nhập để hỗ trợ cơ
 *         chế nhập nối tiếp liên tục.
 * @note Giải thuật: Sử dụng vòng lặp vô hạn kết hợp với hàm phụ
 *       trợ NhapHopLe() để thu thập dữ liệu thô, sau đó gọi
 *       hàm d.KiemTraNgay() kiểm tra logic lịch thực tế.
 *       Vòng lặp chỉ kết thúc khi bộ ngày tháng năm nhập
 *       vào hoàn toàn đúng quy chuẩn lịch pháp.
 */
istream &operator>>(istream &is, CDate &d)
{
    while (true)
    {
        cout << "Nhap ngay: ";
        d.ngay = NhapHopLe(is);
        cout << "Nhap thang: ";
        d.thang = NhapHopLe(is);
        cout << "Nhap nam: ";
        d.nam = NhapHopLe(is);
        if (d.KiemTraNgay(d.ngay, d.thang, d.nam))
            break;
        cout << "Thoi gian khong hop le!\nVui long nhap lai\n";
    }
    return is;
}

/**
 * @brief Nạp chồng toán tử xuất luồng để in thông tin ngày tháng
 *        năm theo chuẩn hiển thị văn bản định dạng lịch.
 * @param os: Tham chiếu đến đối tượng luồng xuất (ostream).
 * @param d: Tham chiếu hằng đến đối tượng CDate cần in dữ liệu.
 * @return ostream& Trả về tham chiếu của luồng xuất để hỗ trợ cơ
 *         chế in liên tiếp.
 * @note Giải thuật: Sử dụng các cờ định dạng đầu ra `setw(2)` kết
 *       hợp ký tự lấp đầy `setfill('0')`
 *       nhằm đảm bảo hai thuộc tính ngày và tháng luôn được biểu
 *       diễn cố định bằng hai chữ số (Ví dụ: in ra màn hình chuỗi
 *       dạng 02/09/2026).
 */
ostream &operator<<(ostream &os, const CDate &d)
{
    os << setfill('0') << setw(2) << d.ngay << "/" << setw(2) << d.thang << "/" << d.nam;
    return os;
}