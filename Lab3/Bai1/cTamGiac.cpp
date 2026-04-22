#include <iostream>
#include <cmath>
#include "cTamGiac.h"
using namespace std;
#define PI 3.14159265358979323846
/**
 * @brief Kiểm tra ba điểm có thẳng hàng hay không.
 * @param a, b, c: Ba đối tượng Diem cần kiểm tra.
 * @return true nếu thẳng hàng, false nếu không thẳng hàng.
 * @note Giải thuật: Sử dụng tích có hướng của hai vectơ (b-a) và (c-a).
 *       Nếu giá trị tuyệt đối của tích này xấp xỉ bằng 0 (v < 1e-9),
 *       ba điểm đó thẳng hàng.
 */
bool KiemTraThangHang(Diem a, Diem b, Diem c)
{
    double v = (b.LayX() - a.LayX()) * (c.LayY() - a.LayY()) - (c.LayX() - a.LayX()) * (b.LayY() - a.LayY());
    v = v > 0 ? v : -v;
    if (v < 1e-9)
    {
        cout << "3 diem thang hang! Vui long nhap lai" << "\n";
        return true;
    }
    return false;
}
/**
 * @brief Hàm khởi tạo mặc định.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Khởi tạo một tam giác trống hoặc với các tọa độ mặc định (0,0).
 */
cTamGiac::cTamGiac() {}
/**
 * @brief Hàm khởi tạo có tham số.
 * @param d1, d2, d3: Tọa độ 3 đỉnh của tam giác.
 * @return Không có.
 * @note Giải thuật: Gán trực tiếp giá trị các tham số đầu vào cho các thuộc tính a, b, c của đối tượng.
 */
cTamGiac::cTamGiac(Diem d1, Diem d2, Diem d3)
{
    a = d1;
    b = d2;
    c = d3;
}
/**
 * @brief Hàm hủy.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Giải phóng các tài nguyên.
 */
cTamGiac::~cTamGiac() {}
/**
 * @brief Hàm nhập 3 điểm.
 * @param Không có.
 * @return void (Hàm không trả về giá trị).
 * @note Giải thuật: Sử dụng vòng lặp lần lượt nhập 3 điểm của tam giác.
 *       Nếu 3 điểm thẳng hàng thì nhập lại.
 */
void cTamGiac::Nhap()
{
    while (true)
    {
        cout << "Nhap diem thu nhat: ";
        a.NhapDiem();
        cout << "Nhap diem thu hai: ";
        b.NhapDiem();
        cout << "Nhap diem thu ba: ";
        c.NhapDiem();
        if (KiemTraThangHang(a, b, c))
        {
            continue;
        }
        return;
    }
}
/**
 * @brief Hàm xuất 3 điểm.
 * @param Không có.
 * @return void (Hàm không trả về giá trị).
 * @note Giải thuật: Lần lượt xuất tọa độ 3 điểm của tam giác.
 */
void cTamGiac::Xuat()
{
    cout << "Toa do 3 diem cua tam giac la: ";
    a.XuatDiem();
    cout << " ,";
    b.XuatDiem();
    cout << " ,";
    c.XuatDiem();
    cout << "\n";
}
/**
 * @brief Xác định và in ra màn hình loại của tam giác.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Tính độ dài 3 cạnh AB, AC, BC bằng công thức khoảng cách Euclide.
 *       2. Sử dụng sai số epsilon (1e-9) để so sánh các số thực (double), tránh lỗi làm tròn.
 *       3. Kiểm tra điều kiện tồn tại tam giác (Tổng 2 cạnh > cạnh còn lại + epsilon).
 *       4. Phân loại theo thứ tự ưu tiên:
 *          - Tam giác đều: Nếu trị tuyệt đối hiệu các cặp cạnh < epsilon.
 *          - Tam giác cân: Nếu có một cặp cạnh bằng nhau (xét theo epsilon).
 *            Tiếp tục kiểm tra định lý Pytago để phân biệt "Vuông cân" hay "Cân thường".
 *          - Tam giác vuông: Nếu thỏa mãn định lý Pytago (tổng bình phương 2 cạnh ≈ bình phương cạnh còn lại).
 *          - Tam giác thường: Các trường hợp còn lại.
 */
void cTamGiac::KiemTraLoaiTamGiac()
{
    cout << "Loai tam giac: ";
    double AB = a.TinhKhoangCach(b);
    double AC = a.TinhKhoangCach(c);
    double BC = b.TinhKhoangCach(c);

    double epsilon = 1e-9;

    // Kiểm tra tồn tại tam giác
    if (AB + AC > BC + epsilon && AB + BC > AC + epsilon && AC + BC > AB + epsilon)
    {
        // 1. Kiểm tra Đều
        if (abs(AB - AC) < epsilon && abs(AC - BC) < epsilon)
        {
            cout << "Tam giac deu";
        }
        // 2. Kiểm tra Cân
        else if (abs(AB - BC) < epsilon || abs(BC - AC) < epsilon || abs(AB - AC) < epsilon)
        {
            // Kiểm tra Vuông Cân
            if (abs(AB * AB + AC * AC - BC * BC) < epsilon ||
                abs(AB * AB + BC * BC - AC * AC) < epsilon ||
                abs(AC * AC + BC * BC - AB * AB) < epsilon)
            {
                cout << "Tam giac vuong can";
            }
            else
                cout << "Tam giac can";
        }
        // 3. Kiểm tra Vuông
        else if (abs(AB * AB + AC * AC - BC * BC) < epsilon ||
                 abs(AB * AB + BC * BC - AC * AC) < epsilon ||
                 abs(AC * AC + BC * BC - AB * AB) < epsilon)
        {
            cout << "Tam giac vuong";
        }
        else
            cout << "Tam giac thuong";
    }
    else
        cout << "Khong phai tam giac";
    cout << "\n";
}

/**
 * @brief Tính chu vi tam giác.
 * @param Không có.
 * @return void (Hàm không trả về giá trị).
 * @note Giải thuật:
 *          1. Tính độ dài 3 cạnh AB, AC, BC bằng hàm tính khoảng cách.
 *          2. Tính tổng 3 cạnh và xuất tổng 3 cạnh.
 */
void cTamGiac::TinhChuVi()
{
    cout << "Chu vi cua tam giac la:";
    double AB = a.TinhKhoangCach(b);
    double AC = a.TinhKhoangCach(c);
    double BC = b.TinhKhoangCach(c);
    cout << AB + AC + BC << "\n";
}
/**
 * @brief Tính diện tích tam giác.
 * @param Không có.
 * @return void (Hàm không trả về giá trị).
 * @note Giải thuật:
 *          1. Tính độ dài 3 cạnh AB, AC, BC bằng hàm tính khoảng cách.
 *          2. Tính diện tích tam giác theo công thức Heron.
 *          3. Xuất diện tích vừa tính được.
 */
void cTamGiac::TinhDienTich()
{
    cout << "Dien tich cua tam giac la: ";
    double AB = a.TinhKhoangCach(b);
    double AC = a.TinhKhoangCach(c);
    double BC = b.TinhKhoangCach(c);
    double p = (AB + AC + BC) / 2;
    cout << sqrt(p * (p - AB) * (p - AC) * (p - BC)) << "\n";
}
/**
 * @brief Tịnh tiến tam giác.
 * @param Không có.
 * @return void (Hàm không trả về giá trị).
 * @note Giải thuật:
 *          1. Nhập vector tịnh tiến.
 *          2. Lấy lần lượt tọa độ (x, y) của các điểm a, b, c cộng với
 *             tọa độ của vector tịnh tiến (dx, dy).
 */
void cTamGiac::TinhTien()
{
    cout << "Nhap vector tinh tien (x, y): ";
    double dx, dy;
    cin >> dx >> dy;
    a.DatX(a.LayX() + dx);
    a.DatY(a.LayY() + dy);
    b.DatX(b.LayX() + dx);
    b.DatY(b.LayY() + dy);
    c.DatX(c.LayX() + dx);
    c.DatY(c.LayY() + dy);
    cout << "Da tinh tien thanh cong!\n";
}
/**
 * @brief Quay toàn bộ tam giác quanh gốc tọa độ (0, 0).
 * @param Không có (Người dùng nhập góc quay trực tiếp từ bàn phím).
 * @return Không có.
 * @note Giải thuật:
 *       1. Nhận góc quay (độ) và đổi sang Radian: rad = độ * (PI / 180).
 *       2. Với mỗi đỉnh (a, b, c), tính tọa độ mới theo công thức:
 *          - x_mới = x*cos(rad) - y*sin(rad)
 *          - y_mới = x*sin(rad) + y*cos(rad)
 *       3. Sử dụng các biến tạm (xA_moi, yA_moi...) để lưu giá trị trước khi cập nhật,
 *          tránh việc dùng tọa độ mới tính cho bước sau.
 *       4. Cập nhật lại tọa độ các đỉnh của tam giác.
 */
void cTamGiac::Quay()
{
    cout << "Nhap goc quay (do): ";
    double goc;
    cin >> goc;
    double rad = goc * 3.1415926535 / 180.0;
    double xA_moi = a.LayX() * cos(rad) - a.LayY() * sin(rad);
    double yA_moi = a.LayX() * sin(rad) + a.LayY() * cos(rad);
    a.DatX(xA_moi);
    a.DatY(yA_moi);
    double xB_moi = b.LayX() * cos(rad) - b.LayY() * sin(rad);
    double yB_moi = b.LayX() * sin(rad) + b.LayY() * cos(rad);
    b.DatX(xB_moi);
    b.DatY(yB_moi);
    double xC_moi = c.LayX() * cos(rad) - c.LayY() * sin(rad);
    double yC_moi = c.LayX() * sin(rad) + c.LayY() * cos(rad);
    c.DatX(xC_moi);
    c.DatY(yC_moi);
    cout << "Da quay tam giac thanh cong!\n";
}
/**
 * @brief Phóng to tam giác.
 * @param Không có.
 * @return void (Hàm không trả về giá trị).
 * @note Giải thuật:
 *          1. Nhập hệ số phóng to.
 *          2. Nếu hệ số phóng to không lớn hơn 1 (k > 1) thì nhập lại
 *          3. Lần lượt lấy tọa độ (x, y) của các điểm a, b, c trong
 *             tam giác nhân với hệ số phóng to.
 *          4. Lưu các tọa độ vừa tính được vào các điểm a, b, c.
 */
void cTamGiac::PhongTo()
{
    cout << "Nhap he so phong to (k > 1): ";
    double k;
    while (cin >> k)
    {
        if (k > 1)
            break;
        cout << "He so khong hop le! Vui long nhap lai: ";
    }
    a.DatX(a.LayX() * k);
    a.DatY(a.LayY() * k);
    b.DatX(b.LayX() * k);
    b.DatY(b.LayY() * k);
    c.DatX(c.LayX() * k);
    c.DatY(c.LayY() * k);
    cout << "Da phong to thanh cong!\n";
}
/**
 * @brief Thu nhỏ tam giác.
 * @param Không có.
 * @return void (Hàm không trả về giá trị).
 * @note Giải thuật:
 *          1. Nhập hệ số thu nhỏ.
 *          2. Nếu hệ số thu nhỏ không không thuộc đoạn (0, 1) thì nhập lại
 *          3. Lần lượt lấy tọa độ (x, y) của các điểm a, b, c trong
 *             tam giác nhân với hệ số thu nhỏ.
 *          4. Lưu các tọa độ vừa tính được vào các điểm a, b, c.
 */
void cTamGiac::ThuNho()
{
    cout << "Nhap he so thu nho (0 < k < 1): ";
    double k;
    while (cin >> k)
    {
        if (k > 0 && k < 1)
            break;
        cout << "He so khong hop le! Vui long nhap lai: ";
    }
    a.DatX(a.LayX() * k);
    a.DatY(a.LayY() * k);
    b.DatX(b.LayX() * k);
    b.DatY(b.LayY() * k);
    c.DatX(c.LayX() * k);
    c.DatY(c.LayY() * k);
    cout << "Da thu nho thanh cong!\n";
}