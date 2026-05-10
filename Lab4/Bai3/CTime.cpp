#include "CTime.h"
#include <iomanip>

// --- HÀM PHỤ TRỢ NỘI BỘ ---
/**
 * @brief Chuẩn hóa thời gian về định dạng hợp lệ (24 giờ).
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Quy đổi toàn bộ giờ, phút, giây hiện tại thành tổng
 *          số giây (tongGiay).
 *       2. Sử dụng phép chia lấy dư (%) cho 86400 (số giây
 *          trong một ngày) để xử lý tràn ngày.
 *       3. Nếu tổng số giây bị âm (do phép trừ thời gian),
 *          cộng thêm 86400 giây để vòng lại thời gian dương.
 *       4. Tách ngược lại tongGiay thành các giá trị gio, phut,
 *           giay hợp lệ.
 */
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
/**
 * @brief Hàm khởi tạo đối tượng thời gian với giờ, phút, giây
 *        cho trước.
 * @param h: Giá trị giờ truyền vào.
 * @param m: Giá trị phút truyền vào.
 * @param s: Giá trị giây truyền vào.
 * @return Không có.
 */
CTime::CTime(int h, int m, int s)
{
    gio = h;
    phut = m;
    giay = s;
    ChuanHoa();
}

// --- TOÁN TỬ CỘNG / TRỪ SỐ NGUYÊN ---
/**
 * @brief Nạp chồng toán tử cộng thêm một số giây vào thời gian
 *        hiện tại.
 * @param s: Số giây nguyên cần cộng thêm.
 * @return Đối tượng CTime mới chứa thời gian sau khi cộng.
 * @note Giải thuật: Khởi tạo một đối tượng CTime mới bằng cách
 *       truyền nguyên vẹn giờ, phút và cộng trực tiếp biến s
 *       vào tham số giây. Đối tượng mới này sẽ tự động gọi
 *       hàm ChuanHoa().
 */
CTime CTime::operator+(int s) const
{
    return CTime(gio, phut, giay + s);
}

/**
 * @brief Nạp chồng toán tử trừ đi một số giây từ thời gian
 *        hiện tại.
 * @param s: Số giây nguyên cần trừ đi.
 * @return Đối tượng CTime mới chứa thời gian sau khi trừ.
 * @note Giải thuật: Khởi tạo một đối tượng CTime mới bằng
 *       cách truyền nguyên vẹn giờ, phút và trừ trực tiếp
 *       biến s vào tham số giây. Đối tượng mới này sẽ tự
 *       động xử lý số giây âm trong hàm ChuanHoa().
 */
CTime CTime::operator-(int s) const
{
    return CTime(gio, phut, giay - s);
}

// --- TOÁN TỬ TĂNG / GIẢM (TIỀN TỐ) ---
/**
 * @brief Nạp chồng toán tử tăng 1 giây - Dạng tiền tố (++t).
 * @param Không có.
 * @return CTime&: Tham chiếu đến chính đối tượng hiện tại
 *         sau khi tăng.
 * @note Giải thuật: Tăng trực tiếp giá trị thuộc tính giay
 *       của đối tượng lên 1 đơn vị, gọi hàm ChuanHoa() để
 *       xử lý tràn và trả về con trỏ *this.
 */
CTime &CTime::operator++()
{
    giay++;
    ChuanHoa();
    return *this;
}

/**
 * @brief Nạp chồng toán tử giảm 1 giây - Dạng tiền tố (--t).
 * @param Không có.
 * @return CTime&: Tham chiếu đến chính đối tượng hiện tại
 *         sau khi giảm.
 * @note Giải thuật: Giảm trực tiếp giá trị thuộc tính giay
 *       của đối tượng xuống 1 đơn vị, gọi hàm ChuanHoa() để
 *       xử lý và trả về con trỏ *this.
 */
CTime &CTime::operator--()
{
    giay--;
    ChuanHoa();
    return *this;
}

// --- TOÁN TỬ TĂNG / GIẢM (HẬU TỐ) ---
/**
 * @brief Nạp chồng toán tử tăng 1 giây - Dạng hậu tố (t++).
 * @param int: Tham số giả định của C++ để phân biệt với tiền
 *        tố (không sử dụng trong hàm).
 * @return CTime: Đối tượng CTime lưu trạng thái thời gian
 *         TRƯỚC khi tăng.
 * @note Giải thuật:
 *       1. Tạo một đối tượng sao chép tạm thời (temp) để giữ
 *          lại giá trị hiện tại của đối tượng.
 *       2. Tăng giá trị giay của đối tượng chính lên 1 đơn vị
 *          và tiến hành ChuanHoa().
 *       3. Trả về đối tượng sao chép tạm thời temp.
 */
CTime CTime::operator++(int)
{
    CTime temp = *this; // Lưu lại trạng thái cũ
    giay++;
    ChuanHoa();
    return temp; // Trả về trạng thái trước khi tăng
}

/**
 * @brief Nạp chồng toán tử giảm 1 giây - Dạng hậu tố (t--).
 * @param int: Tham số giả định của C++ để phân biệt với tiền tố.
 * @return CTime: Đối tượng CTime lưu trạng thái thời gian TRƯỚC
 *         khi giảm.
 * @note Giải thuật:
 *       1. Tạo một đối tượng sao chép tạm thời (temp) để giữ lại
 *          giá trị hiện tại của đối tượng.
 *       2. Giảm giá trị giay của đối tượng chính xuống 1 đơn vị
 *          và tiến hành ChuanHoa().
 *       3. Trả về đối tượng sao chép tạm thời temp.
 */
CTime CTime::operator--(int)
{
    CTime temp = *this;
    giay--;
    ChuanHoa();
    return temp;
}

/**
 * @brief Nhập và kiểm tra tính hợp lệ của số nguyên đầu vào,
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
/**
 * @brief Nạp chồng toán tử nhập luồng để cấu hình các giá trị
 *        cho đối tượng CTime.
 * @param is: Tham chiếu đến đối tượng luồng nhập (istream).
 * @param t: Tham chiếu đến đối tượng CTime cần lưu dữ liệu.
 * @return istream&: Trả về tham chiếu của luồng nhập nhằm hỗ
 *         trợ việc nhập liên tiếp.
 * @note Giải thuật:
 *       1. Lần lượt dùng hàm phụ trợ NhapHopLe() để lấy dữ
 *          liệu cho giờ, phút, giây.
 *       2. Chặn điều kiện logic thời gian thực tế bằng các vòng
 *          lặp while: giờ thuộc [0, 23], phút và giây
 *          thuộc [0, 59].
 *       3. Gọi hàm t.ChuanHoa() cuối cùng để đảm bảo tính đồng
 *          bộ dữ liệu.
 */
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

/**
 * @brief Nạp chồng toán tử xuất luồng để in thời gian ra
 *        màn hình theo chuẩn điện tử.
 * @param os: Tham chiếu đến đối tượng luồng xuất (ostream).
 * @param t: Tham chiếu hằng đến đối tượng CTime cần hiển
 *           thị thông tin.
 * @return ostream&: Trả về tham chiếu của luồng xuất nhằm hỗ
 *         trợ việc in liên tiếp.
 * @note Giải thuật: Sử dụng công cụ căn lề `setw(2)` kết hợp
 *       ký tự lấp đầy `setfill('0')` để đảm bảo các thành
 *       phần giờ, phút, giây luôn được hiển thị cố định bằng
 *       2 chữ số (Ví dụ: 02:08:09).
 */
ostream &operator<<(ostream &os, const CTime &t)
{
    // Căn chỉnh thêm số 0 ở trước nếu chỉ có 1 chữ số
    os << setfill('0')
       << setw(2) << t.gio << ":"
       << setw(2) << t.phut << ":"
       << setw(2) << t.giay
       << setfill(' '); // Trả lại khoảng trắng
    return os;
}