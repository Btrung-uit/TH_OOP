#include "CKhachHangC.h"

/**
 * @brief Hàm khởi tạo mặc định cho lớp Khách hàng loại C.
 * @param Không có.
 * @return Không có.
 */
CKhachHangC::CKhachHangC() : CKhachHang() {}

/**
 * @brief Tính toán tổng số tiền thanh toán của Khách hàng loại C sau khi giảm giá 50% và áp thuế.
 * @param Không có.
 * @return Giá trị tổng tiền hóa đơn thực nhận dưới dạng số thực (double).
 * @note Giải thuật:
 *       1. Tính số tiền gốc ban đầu bằng công thức tích số: SoLuong * DonGia.
 *       2. Áp dụng chính sách ưu đãi đặc biệt mặc định giảm 50% cho đối tượng khách hàng nhóm C: tienSauGiamGia = tienGoc * 0.5.
 *       3. Cộng thêm 10% thuế giá trị gia tăng phát sinh bằng cách nhân kết quả với hệ số 1.1 và trả về.
 */
double CKhachHangC::TinhTien()
{
    double tienGoc = SoLuong * DonGia;
    double tienSauGiamGia = tienGoc * 0.5;
    return tienSauGiamGia * 1.1;
}