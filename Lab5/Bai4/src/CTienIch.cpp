#include "../include/CTienIch.h"
#include <iostream>
#include <string>
#include <regex>
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

/**
 * @brief Nhập và ép luồng dữ liệu số thực dương, loại bỏ hoàn
 *        toàn các ký tự rác đi kèm.
 * @param Không có.
 * @return giaTri: double.
 * @note Giải thuật:
 *       1. Sử dụng vòng lặp vô hạn và đọc dữ liệu thông qua toán
 *          tử cin >> giaTri.
 *       2. Sử dụng cin.get(c) để quét từng ký tự còn lại trên
 *          cùng một dòng cho đến khi gặp ký tự xuống dòng (\n).
 *       3. Nếu phát hiện bất kỳ ký tự nào không phải khoảng trắng
 *          (' ') hoặc tab ('\t'), gán cờ chuoiHopLe = false để
 *          đánh dấu dòng nhập chứa ký tự rác
 *          (Ví dụ: nhập "3.14abc").
 *       4. Nếu chuỗi hợp lệ, thoát hàm để lưu giá trị. Ngược lại,
 *          tiến hành xóa cờ lỗi của stream, dọn sạch bộ nhớ đệm
 *          và yêu cầu người dùng nhập lại.
 */
double NhapSoThucAnToan()
{
    double giaTri;
    while (true)
    {
        if (cin >> giaTri && giaTri >= 0)
        {
            bool chuoiHopLe = true;
            char c;
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
            cout << "Gia tri khong hop le!\nVui long nhap so thuc duong!\nNhap lai: ";
            continue;
        }
        cout << "Gia tri khong hop le!\nVui long nhap so thuc duong!\nNhap lai: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

/**
 * @brief Kiểm tra tính hợp lệ của họ tên (Chuẩn hóa tên).
 * @param ten: Tham chiếu đến chuỗi họ tên cần kiểm tra.
 * @return true nếu tên hợp lệ, false nếu vi phạm quy tắc.
 * @note Giải thuật:
 *       1. Kiểm tra độ dài (không trống và không quá 26 ký tự).
 *       2. Kiểm tra khoảng trắng ở đầu/cuối chuỗi hoặc có 2 khoảng trắng liên tiếp.
 *       3. Kiểm tra ký tự đặc biệt/số: Chỉ cho phép chữ cái A-Z, a-z và khoảng trắng.
 *       4. Kiểm tra quy tắc viết hoa: Chữ cái đầu mỗi từ phải viết hoa, các chữ sau
 *          phải viết thường.
 */
bool KiemTraTen(string &ten)
{
    int lenght = ten.length();
    if (lenght > 26 || lenght == 0)
        return false;
    if (ten[0] == ' ' || ten[lenght - 1] == ' ')
        return false;
    for (int i = 0; ten[i] != '\0'; i++)
    {
        if (ten[i] == ' ')
        {
            if (i + 1 < lenght && ten[i + 1] == ' ')
                return false;
            continue;
        }
        if ((ten[i] < 'A' || ten[i] > 'Z') && (ten[i] < 'a' || ten[i] > 'z'))
            return false;
        bool chuDau = (i == 0 || ten[i - 1] == ' ');
        if (chuDau)
        {
            if (ten[i] < 'A' || ten[i] > 'Z')
                return false;
        }
        else
        {
            if (ten[i] < 'a' || ten[i] > 'z')
                return false;
        }
    }
    return true;
}

/**
 * @brief Đọc và trả về họ tên hợp lệ từ người dùng.
 *
 * @return Chuỗi họ tên đã được kiểm tra hợp lệ.
 * @note Giải thuật:
 *       1. Sử dụng `getline(cin >> ws, name)` để đọc một dòng và loại bỏ khoảng trắng đầu.
 *       2. Gọi `KiemTraTen(name)` để kiểm tra tính hợp lệ của họ tên.
 *       3. Nếu hợp lệ, trả về tên.
 *       4. Nếu không hợp lệ, in thông báo lỗi và yêu cầu người dùng nhập lại.
 */
std::string KiemTraTenHopLe()
{
    string name;
    while (true)
    {
        getline(cin >> ws, name);
        if (KiemTraTen(name))
        {
            return name;
        }
        else
        {
            cout << "Ten khong hop le!\nVui long nhap lai: ";
        }
    }
}

/**
 * @brief Kiểm tra tính hợp lệ của email mà không dùng regex.
 *
 * @param email Chuỗi email cần kiểm tra.
 * @return true Nếu email hợp lệ theo quy tắc cơ bản.
 * @return false Nếu email không hợp lệ.
 *
 * @note Giải thuật:
 *       1. Kiểm tra độ dài tối thiểu của email (ít nhất a@b.co).
 *       2. Tìm vị trí ký tự '@' và dấu '.' cuối cùng.
 *       3. Đảm bảo có đúng một '@' và nó không nằm ở đầu.
 *       4. Đảm bảo dấu '.' nằm sau '@' và không liền ngay sau '@'.
 *       5. Kiểm tra phần đuôi tên miền có ít nhất 2 ký tự.
 *       6. Kiểm tra tất cả ký tự đều thuộc tập ký tự cho phép.
 */
bool isValidEmail(const std::string &email)
{
    // 1. Kiểm tra độ dài cơ bản (ít nhất phải có a@b.co -> 6 ký tự)
    if (email.length() < 6)
        return false;

    // 2. Tìm vị trí của ký tự '@' và dấu '.' cuối cùng
    size_t atIdx = email.find('@');
    size_t dotIdx = email.rfind('.'); // Tìm dấu chấm từ cuối chuỗi lên

    // 3. '@' phải tồn tại, không nằm ở đầu, và chỉ có DUY NHẤT 1 ký tự '@'
    if (atIdx == std::string::npos || atIdx == 0)
        return false;
    if (email.find('@', atIdx + 1) != std::string::npos)
        return false;

    // 4. Dấu '.' phải nằm sau dấu '@' và không được nằm ngay cạnh nhau (ví dụ: @.)
    if (dotIdx == std::string::npos || dotIdx <= atIdx + 1)
        return false;

    // 5. Đuôi tên miền sau dấu '.' cuối cùng phải có ít nhất 2 ký tự (ví dụ: .com, .vn)
    if (email.length() - 1 - dotIdx < 2)
        return false;

    // 6. Kiểm tra các ký tự hợp lệ trong email
    for (size_t i = 0; i < email.length(); ++i)
    {
        char c = email[i];

        // Kiểm tra chữ cái, chữ số, và các ký tự đặc biệt cho phép
        bool isValidChar = (c >= 'a' && c <= 'z') ||
                           (c >= 'A' && c <= 'Z') ||
                           (c >= '0' && c <= '9') ||
                           c == '@' || c == '.' || c == '_' || c == '-' || c == '+';

        if (!isValidChar)
            return false;
    }

    return true;
}

/**
 * @brief Đọc và xác thực email hợp lệ từ người dùng.
 *
 * @return Chuỗi email hợp lệ đã được kiểm tra.
 *
 * @note Giải thuật:
 *       1. Đọc một dòng email từ đầu vào với getline(cin >> ws, email).
 *       2. Gọi isValidEmailNoRegex(email) để kiểm tra tính hợp lệ.
 *       3. Nếu email hợp lệ, trả về chuỗi email đó.
 *       4. Nếu không hợp lệ, in thông báo lỗi và yêu cầu nhập lại.
 */
std::string KiemTraEmailHopLe()
{
    string email;
    while (true)
    {
        getline(cin >> ws, email);
        if (isValidEmail(email))
        {
            return email;
        }
        cout << "Email khong hop le!\nVui long nhap lai: ";
    }
}

/**
 * @brief Kiểm tra tính hợp lệ của số điện thoại di động Việt Nam mà không dùng regex thủ công.
 *
 * @param input Chuỗi số điện thoại cần kiểm tra (hỗ trợ các định dạng khác nhau).
 * @return true Nếu số điện thoại hợp lệ theo định dạng di động Việt Nam.
 * @return false Nếu số điện thoại không hợp lệ.
 *
 * @note Giải thuật:
 *       1. Làm sạch chuỗi bằng cách loại bỏ các ký tự phân tách (dấu cách, dấu chấm, dấu gạch ngang).
 *       2. Chuyển đổi định dạng quốc tế (+84 hoặc 84) về định dạng chuẩn bắt đầu với 0.
 *       3. Sử dụng regex kiểm tra cấu trúc: bắt đầu 0, theo sau bởi đầu số hợp lệ, kết thúc 7 chữ số.
 *       4. So khớp chuỗi đã làm sạch với regex pattern và trả về kết quả.
 */
bool isValidVNPhoneNumber(const std::string &input)
{
    // 1. Làm sạch chuỗi: Loại bỏ các ký tự phân tách phổ biến như dấu cách, dấu chấm, dấu gạch ngang
    std::string cleanInput = "";
    for (char c : input)
    {
        if (c != ' ' && c != '.' && c != '-')
        {
            cleanInput += c;
        }
    }

    // 2. Chuyển đổi định dạng quốc tế (+84 hoặc 84) về định dạng chuẩn đầu 0
    if (cleanInput.rfind("+84", 0) == 0)
    { // Nếu bắt đầu bằng "+84"
        cleanInput = "0" + cleanInput.substr(3);
    }
    else if (cleanInput.rfind("84", 0) == 0 && cleanInput.length() == 11)
    { // Nếu bắt đầu bằng "84" và dài 11 số
        cleanInput = "0" + cleanInput.substr(2);
    }

    // 3. Sử dụng Regex để kiểm tra cấu trúc đầu số di động 10 số của Việt Nam
    // Giải thích biểu thức: Bắt đầu bằng 0, theo sau là một trong các đầu số hợp lệ, và kết thúc bằng 7 chữ số bất kỳ.
    static const std::regex phone_pattern(
        "^0(3[2-9]|5[125689]|7[0156-9]|8[1-689]|9[0-57-9])[0-9]{7}$");

    // 4. So khớp và trả về kết quả
    return std::regex_match(cleanInput, phone_pattern);
}

/**
 * @brief Đọc và xác thực số điện thoại Việt Nam hợp lệ từ người dùng.
 *
 * @return Chuỗi số điện thoại hợp lệ đã được kiểm tra.
 *
 * @note Giải thuật:
 *       1. Đọc một dòng số điện thoại từ đầu vào với getline(cin >> ws, sdt).
 *       2. Gọi isValidVNPhoneNumber(sdt) để kiểm tra tính hợp lệ của số điện thoại.
 *       3. Nếu số điện thoại hợp lệ, trả về chuỗi số điện thoại đó.
 *       4. Nếu không hợp lệ, in thông báo lỗi và yêu cầu người dùng nhập lại.
 */
std::string KiemTraSDTHopLe()
{
    string sdt;
    while (true)
    {
        getline(cin >> ws, sdt);
        if (isValidVNPhoneNumber(sdt))
        {
            return sdt;
        }
        cout << "So dien thoai khong hop le!\nVui long nhap lai: ";
    }
}

/**
 * @brief Định dạng giá trị tiền thành chuỗi có phân cách hàng nghìn bằng dấu chấm.
 *
 * @param tien Giá trị tiền (kiểu double). Phần thập phân (nếu có) sẽ bị loại bỏ trước khi định dạng.
 * @return Chuỗi chứa giá trị tiền đã được định dạng, ví dụ "1.234.567".
 * @note Giải thuật:
 *       1. Ép kiểu `double` sang `long long` để loại bỏ phần thập phân.
 *       2. Chuyển số nguyên thu được thành `std::string`.
 *       3. Duyệt chuỗi từ phải sang trái và chèn dấu `'.'` sau mỗi 3 chữ số.
 *       4. Trả về chuỗi đã định dạng.
 */
std::string DinhDangTien(double tien)
{
    long long t = (long long)tien;
    std::string s = std::to_string(t);
    int n = s.length();
    for (int i = n - 3; i > 0; i -= 3)
    {
        s.insert(i, ".");
    }
    return s;
}