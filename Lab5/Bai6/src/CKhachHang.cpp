#include "CKhachHang.h"
#include "CTienIch.h"

using namespace std;

/**
 * @brief Hàm khởi tạo mặc định cho lớp Khách hàng (lớp cha).
 * @param Không có.
 * @return Không có.
 */
CKhachHang::CKhachHang()
{
    TenKH = "";
    SoLuong = 0;
    DonGia = 0.0;
}

/**
 * @brief Đọc và cấu hình thông tin khách hàng từ luồng tệp tin đầu vào.
 * @param in: Tham chiếu đến đối tượng luồng đọc tệp tin (ifstream).
 * @param flag: Tham chiếu đến biến boolean dùng để ghi nhận trạng thái đọc dữ liệu của tệp tin.
 * @return Không có.
 * @note Giải thuật:
 *       1. Gọi liên tiếp tổ hợp hàm `DocChuoiAnToan()` và `ChuanHoaTen()` từ lớp tiện ích để trích xuất, làm sạch chuỗi họ tên khách hàng gán vào thuộc tính TenKH.
 *       2. Gọi hàm `DocSoNguyen()` để cấu hình thuộc tính SoLuong, thực hiện kiểm tra biến cờ `flag`; nếu trạng thái trả về là false (lỗi định dạng file rác) thì lập tức thoát hàm (`return`).
 *       3. Tiếp tục gọi hàm `DocSoThuc()` để thiết lập thuộc tính DonGia, áp dụng mệnh đề bắt lỗi biến cờ tương tự để bảo vệ luồng dữ liệu an toàn.
 */
void CKhachHang::DocFile(ifstream &in, bool &flag)
{

    TenKH = CTienIch::ChuanHoaTen(CTienIch::DocChuoiAnToan(in));

    SoLuong = CTienIch::DocSoNguyen(in, flag);
    if (flag == false)
    {
        return;
    }

    DonGia = CTienIch::DocSoThuc(in, flag);
    if (flag == false)
    {
        return;
    }
}

/**
 * @brief Ghi dữ liệu hóa đơn kết quả của khách hàng xuống luồng tệp tin đầu ra.
 * @param out: Tham chiếu đến đối tượng luồng ghi tệp tin (ofstream).
 * @return Không có.
 * @note Giải thuật:
 *       1. Xuất chuỗi họ tên TenKH đã chuẩn hóa xuống dòng đầu tiên của tệp tin đích.
 *       2. Gọi phương thức ảo TinhTien() nội tại để tính toán giá trị hóa đơn, đi qua bộ lọc `DinhDangTien()` của lớp tiện ích để ghi số tiền đã phân tách dấu chấm rõ ràng xuống dòng tiếp theo.
 */
void CKhachHang::GhiFile(ofstream &out)
{

    out << TenKH << "\n";

    out << CTienIch::DinhDangTien(TinhTien()) << "\n";
}