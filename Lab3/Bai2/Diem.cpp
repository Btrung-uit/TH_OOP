#include <iostream>
#include <cmath>
#include <iomanip>
#include "Diem.h"
using namespace std;
/**
 * @brief Hàm khởi tạo mặc định.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Khởi tạo một Điểm với tọa độ mặc định (0,0).
 */
Diem::Diem() {}
/**
 * @brief Hàm khởi tạo có tham số.
 * @param hoanh, tung: tọa độ (x, y) của điểm
 * @return Không có.
 * @note Giải thuật: Gán trực tiếp giá trị các tham số đầu vào cho các thuộc tính x, y của đối tượng.
 */
Diem::Diem(double hoanh, double tung)
{
    x = hoanh;
    y = tung;
}
/**
 * @brief Hàm hủy.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Giải phóng các tài nguyên.
 */
Diem::~Diem() {}
/**
 * @brief Nhập điểm.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Nhập tọa độ (x, y) của điểm
 */
void Diem::NhapDiem()
{
    cout << "Nhap x, y: ";
    cin >> x >> y;
}
/**
 * @brief Xuất điểm.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: xuất điểm với 2 giá trị thập phân
 */
void Diem::XuatDiem()
{
    cout << fixed << setprecision(2) << '(' << x << ", " << y << ')';
}
/**
 * @brief Cập nhật giá trị hoành độ cho điểm.
 * @param hoanh: Giá trị mới của hoành độ (kiểu double).
 * @return Không có.
 * @note Giải thuật: Gán trực tiếp giá trị tham số đầu vào cho thuộc tính x của đối tượng.
 */
void Diem::DatX(double hoanh)
{
    x = hoanh;
}
/**
 * @brief Cập nhật giá trị tung độ cho điểm.
 * @param tung: Giá trị mới của tung độ (kiểu double).
 * @return Không có.
 * @note Giải thuật: Gán trực tiếp giá trị tham số đầu vào cho thuộc tính y của đối tượng.
 */
void Diem::DatY(double tung)
{
    y = tung;
}
/**
 * @brief Lấy tọa độ x.
 * @param Không có.
 * @return trả về giá trị của tọa độ x
 * @note Giải thuật: Trả về tọa độ x
 */
double Diem::LayX()
{
    return x;
}
/**
 * @brief Lấy tọa độ y.
 * @param Không có.
 * @return trả về giá trị của tọa độ y
 * @note Giải thuật: Trả về tọa độ y
 */
double Diem::LayY()
{
    return y;
}
/**
 * @brief Tính khoảng cách từ điểm hiện tại đến một điểm khác.
 * @param dKhac: Đối tượng Diem cần tính khoảng cách tới.
 * @return Giá trị khoảng cách giữa hai điểm (kiểu double).
 * @note Giải thuật: Sử dụng công thức tính khoảng cách Euclide:
 *       1. Tính hiệu tọa độ hoành độ (dx) và tung độ (dy) giữa hai điểm.
 *       2. Khoảng cách = căn bậc hai của tổng bình phương dx và dy: sqrt(dx^2 + dy^2).
 */
double Diem::TinhKhoangCach(Diem dKhac)
{
    return sqrt(pow(dKhac.LayX() - x, 2) + pow(dKhac.LayY() - y, 2));
}
