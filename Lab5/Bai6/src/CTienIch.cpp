#include "../include/CTienIch.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

/**
 * @brief Đọc một chuỗi ký tự an toàn từ luồng tệp tin đầu vào.
 * @param in: Tham chiếu đến đối tượng luồng đọc tệp tin (ifstream).
 * @return Chuỗi ký tự (string) thu trích được từ tệp tin.
 * @note Giải thuật: Sử dụng phương thức `getline` kết hợp bộ điều phối luồng `ws` để tự động dọn sạch các ký tự khoảng trắng hoặc ký tự xuống dòng (\n) còn tồn đọng trước khi đọc nội dung văn bản.
 */
string CTienIch::DocChuoiAnToan(ifstream &in)
{
    string chuoi;

    getline(in >> ws, chuoi);
    return chuoi;
}

/**
 * @brief Chuẩn hóa chuỗi họ tên về dạng viết hoa chữ cái đầu của mỗi từ (Title Case) và loại bỏ khoảng trắng thừa.
 * @param ten: Chuỗi họ tên thô ban đầu cần thực hiện chuẩn hóa.
 * @return Chuỗi họ tên mới đã được làm sạch và chuyển đổi đúng định dạng toán học chữ viết.
 * @note Giải thuật:
 *       1. Duyệt qua từng ký tự của chuỗi đầu vào, sử dụng biến cờ hiệu `inWord` để nhận diện trạng thái bắt đầu của một từ mới.
 *       2. Ký tự đầu tiên của từ sẽ được ép viết hoa bằng hàm `toupper()`, các ký tự tiếp sau của từ đó được ép viết thường bằng `tolower()`.
 *       3. Bỏ qua các khoảng trắng thừa giữa các từ và tiến hành cắt bỏ ký tự khoảng trắng dư ở cuối chuỗi bằng phương thức `pop_back()`.
 */
string CTienIch::ChuanHoaTen(string ten)
{
    string kq = "";
    bool inWord = false;

    for (int i = 0; i < ten.length(); i++)
    {
        if (ten[i] != ' ')
        {
            if (!inWord)
            {

                kq += toupper(ten[i]);
                inWord = true;
            }
            else
            {

                kq += tolower(ten[i]);
            }
        }
        else
        {
            if (inWord)
            {
                kq += ' ';
                inWord = false;
            }
        }
    }

    if (!kq.empty() && kq.back() == ' ')
    {
        kq.pop_back();
    }

    return kq;
}

/**
 * @brief Định dạng một số tiền kiểu số thực thành chuỗi văn bản phân tách hàng nghìn bằng dấu chấm.
 * @param tien: Giá trị số tiền cần xử lý định dạng (double).
 * @return Chuỗi văn bản đại diện số tiền đã được định dạng (string).
 * @note Giải thuật:
 *       1. Ép kiểu số thực về dạng số nguyên lớn `long long` để triệt tiêu phần thập phân, sau đó chuyển sang dạng chuỗi bằng hàm `to_string()`.
 *       2. Sử dụng vòng lặp duyệt ngược chuỗi từ vị trí cách 3 ký tự từ cuối lên, liên tục chèn ký tự dấu chấm "." bằng phương thức `insert()` để phân tách các lớp hàng nghìn, hàng triệu.
 */
string CTienIch::DinhDangTien(double tien)
{

    long long soNguyen = static_cast<long long>(tien);
    string strTien = to_string(soNguyen);

    int insertPosition = strTien.length() - 3;
    while (insertPosition > 0)
    {
        strTien.insert(insertPosition, ".");
        insertPosition -= 3;
    }

    return strTien;
}

/**
 * @brief Đọc và kiểm tra tính hợp lệ của một số nguyên không âm từ luồng tệp tin đầu vào.
 * @param in: Tham chiếu đến đối tượng luồng đọc tệp tin (ifstream).
 * @param trangThaiHopLe: Tham chiếu đến biến boolean dùng để đánh dấu trạng thái dữ liệu đọc được thành công hay thất bại.
 * @return Giá trị số nguyên hợp lệ đọc được, hoặc trả về 0 nếu dữ liệu sai quy chuẩn.
 * @note Giải thuật: Sử dụng toán tử trích xuất luồng `in >> giaTri` kết hợp mệnh đề điều kiện chặn số không âm (`giaTri >= 0`). Nếu thỏa mãn, bật cờ hiệu `trangThaiHopLe = true`, ngược lại gán bằng `false`.
 */
int CTienIch::DocSoNguyen(ifstream &in, bool &trangThaiHopLe)
{
    int giaTri;

    if (in >> giaTri && giaTri >= 0)
    {
        trangThaiHopLe = true;
        return giaTri;
    }

    trangThaiHopLe = false;
    return 0;
}

/**
 * @brief Đọc và kiểm tra tính hợp lệ của một số thực không âm từ luồng tệp tin đầu vào.
 * @param in: Tham chiếu đến đối tượng luồng đọc tệp tin (ifstream).
 * @param trangThaiHopLe: Tham chiếu đến biến boolean dùng để ghi nhận trạng thái luồng đọc.
 * @return Giá trị số thực hợp lệ đọc được, hoặc trả về 0.0 nếu dữ liệu sai quy chuẩn.
 * @note Giải thuật: Thực hiện tương tự quy trình đọc số nguyên, áp dụng toán tử luồng trích xuất giá trị số thực và kiểm tra biên số thực không âm (`giaTri >= 0.0`) để cấu hình trạng thái cờ hiệu trả về cho hệ thống.
 */
double CTienIch::DocSoThuc(ifstream &in, bool &trangThaiHopLe)
{
    double giaTri;

    if (in >> giaTri && giaTri >= 0.0)
    {
        trangThaiHopLe = true;
        return giaTri;
    }

    trangThaiHopLe = false;
    return 0.0;
}