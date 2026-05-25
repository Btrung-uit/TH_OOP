#include "CKhachHangA.h"

/**
 * @brief Hàm khởi tạo mặc định cho lớp Khách hàng loại A.
 * @param Không có.
 * @return Không có.
 */
CKhachHangA::CKhachHangA() : CKhachHang() {}

/**
 * @brief Tính toán tổng số tiền thanh toán của Khách hàng loại A bao gồm thuế giá trị gia tăng.
 * @param Không có.
 * @return Giá trị tổng tiền hóa đơn thực nhận dưới dạng số thực (double).
 * @note Giải thuật:
 *       1. Tính số tiền gốc ban đầu bằng công thức tích số: SoLuong * DonGia.
 *       2. Áp dụng chính sách thuế phát sinh cho đối tượng khách hàng nhóm A bằng cách nhân thêm hệ số 1.1 (tương đương cộng thêm 10% thuế VAT) và trả về kết quả.
 */
double CKhachHangA::TinhTien()
{
    double tienGoc = SoLuong * DonGia;
    return tienGoc * 1.1;
}