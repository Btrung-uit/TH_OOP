#include "CKhachHangB.h"
#include "CTienIch.h"
#include <algorithm>

using namespace std;

/**
 * @brief Hàm khởi tạo mặc định cho lớp Khách hàng loại B.
 * @param Không có.
 * @return Không có.
 */
CKhachHangB::CKhachHangB() : CKhachHang()
{
    SoNamThanThiet = 0;
}

/**
 * @brief Đọc thông tin chi tiết của Khách hàng loại B từ tệp tin đầu vào.
 * @param in: Tham chiếu đến đối tượng luồng đọc tệp tin (ifstream).
 * @param flag: Tham chiếu đến biến boolean dùng để đánh dấu trạng thái luồng đọc.
 * @return Không có.
 * @note Giải thuật:
 *       1. Gọi lại phương thức CKhachHang::DocFile() của lớp cha để đọc các thông tin chung (tên, số lượng, đơn giá) và kiểm tra cờ lỗi flag.
 *       2. Tiếp tục sử dụng hàm tiện ích CTienIch::DocSoNguyen() để trích xuất dữ liệu số năm gắn bó (SoNamThanThiet) của khách hàng nhóm B và cập nhật trạng thái cờ hiệu.
 */
void CKhachHangB::DocFile(ifstream &in, bool &flag)
{

    CKhachHang::DocFile(in, flag);
    if (flag == false)
    {
        return;
    }

    SoNamThanThiet = CTienIch::DocSoNguyen(in, flag);
    if (flag == false)
    {
        return;
    }
}

/**
 * @brief Tính toán tổng số tiền thanh toán của Khách hàng loại B dựa trên số năm thân thiết và thuế phát sinh.
 * @param Không có.
 * @return Giá trị tổng tiền hóa đơn thực nhận dưới dạng số thực (double).
 * @note Giải thuật:
 *       1. Xác định tỷ lệ phần trăm khuyến mãi (phanTramKM) bằng cách nhân số năm gắn bó với 5% (0.05), kết hợp hàm std::max() để tìm phần trăm khuyến mãi, nếu thấp hơn 50% thì lấy 50% và ngược lại.
 *       2. Tính số tiền gốc ban đầu theo công thức tích số thông thường: SoLuong * DonGia.
 *       3. Thực hiện khấu trừ số tiền giảm giá theo tỷ lệ vừa tính được: tienGoc * (1.0 - phanTramKM).
 *       4. Áp dụng thuế phụ thu 10% bằng cách nhân kết quả sau cùng với hệ số 1.1 và trả về giá trị tiền thanh toán.
 */
double CKhachHangB::TinhTien()
{

    double phanTramKM = max(SoNamThanThiet * 0.05, 0.5);
    if (phanTramKM > 1.0)
    {
        phanTramKM = 1.0;
    }
    double tienGoc = SoLuong * DonGia;
    double tienSauGiamGia = tienGoc * (1.0 - phanTramKM);

    return tienSauGiamGia * 1.1;
}