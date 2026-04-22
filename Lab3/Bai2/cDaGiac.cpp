#include <iostream>
#include <cmath>
#include "cDaGiac.h"
using namespace std;

/**
 * @brief Hàm khởi tạo mặc định. Khởi tạo một đa giác rỗng chưa có đỉnh.
 * @param Không có
 * @return Không có
 * @note Giải thuật: Khởi tạo số lượng đỉnh (n) bằng 0 và đặt con trỏ quản lý mảng điểm (dsDiem)
 *                   trỏ vào vùng nhớ rỗng (nullptr).
 */
cDaGiac::cDaGiac()
{
    n = 0;
    dsDiem = nullptr;
}

/**
 * @brief Hàm khởi tạo có tham số. Cấp phát mảng động để chứa các đỉnh của đa giác.
 * @param soDinh Số lượng đỉnh cần tạo cho đa giác (kiểu int).
 * @return Không có
 * @note Giải thuật: Gán số lượng đỉnh bằng tham số đầu vào, sau đó sử dụng toán tử new để cấp
 *                   phát một mảng động kiểu Diem với kích thước tương ứng.
 */
cDaGiac::cDaGiac(int soDinh)
{
    n = soDinh;
    dsDiem = new Diem[n];
}

/**
 * @brief Hàm hủy. Giải phóng vùng nhớ đã cấp phát cho mảng động dsDiem để tránh rò rỉ bộ nhớ.
 * @param Không có
 * @return Không có
 * @note Giải thuật: Kiểm tra con trỏ dsDiem có đang trỏ tới vùng nhớ nào không. Nếu có, sử
 *                   dụng toán tử delete[] để thu hồi toàn bộ mảng động đã cấp phát.
 */
cDaGiac::~cDaGiac()
{
    if (dsDiem)
    {
        delete[] dsDiem;
    }
}

/**
 * @brief Nhập số lượng đỉnh (yêu cầu n > 2) và tọa độ từng đỉnh của đa giác.
 * @param Không có
 * @return void (Hàm không trả về giá trị).
 * @note Giải thuật:
 *          1. Sử dụng vòng lặp kiểm tra để đảm bảo người dùng nhập số đỉnh n > 2.
 *          2. Kiểm tra và giải phóng mảng dsDiem cũ (nếu có) để tránh rò rỉ bộ nhớ trước khi cấp
 *             phát mới.
 *          3. Cấp phát mảng động mới bằng kích thước n.
 *          4. Sử dụng vòng lặp for duyệt qua từng phần tử và gọi hàm NhapDiem() để lấy tọa độ.
 */
void cDaGiac::Nhap()
{
    cout << "Nhap so dinh cua da giac (n > 2): ";
    while (cin >> n)
    {
        if (n > 2)
            break;
        cout << "So dinh khong hop le (n > 2)! Vui long nhap lai: ";
    }
    if (dsDiem)
        delete[] dsDiem;
    dsDiem = new Diem[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap diem thu " << i + 1 << ":\n";
        dsDiem[i].NhapDiem();
    }
}

/**
 * @brief Lần lượt xuất tọa độ tất cả các đỉnh của đa giác ra màn hình.
 * @param Không có
 * @return void (Hàm không trả về giá trị).
 * @note Giải thuật: Sử dụng vòng lặp for chạy từ 0 đến n-1, lần lượt gọi phương thức XuatDiem() của từng đối tượng Diem trong mảng động để in dữ liệu ra màn hình.
 */
void cDaGiac::Xuat()
{
    cout << "Toa do cac dinh cua da giac (" << n << " dinh):\n";
    for (int i = 0; i < n; i++)
    {
        dsDiem[i].XuatDiem();
        cout << "\n";
    }
}
/**
 * @brief Kiểm tra loại đa giác (trọng tâm là kiểm tra đa giác đều).
 * @param Không có.
 * @return Không có (In kết quả ra màn hình).
 * @note Giải thuật:
 *       1. Tính độ dài cạnh đầu tiên làm chuẩn.
 *       2. So sánh tất cả các cạnh còn lại với cạnh chuẩn. Nếu có cạnh khác -> Đa giác thường.
 *       3. Tính khoảng cách từ trọng tâm (trung bình cộng tọa độ các đỉnh) đến từng đỉnh.
 *       4. Nếu tất cả khoảng cách đến tâm bằng nhau -> Đa giác đều. Ngược lại là đa giác có các
 *          cạnh bằng nhau nhưng không đều (ví dụ hình thoi).
 */
void cDaGiac::KiemTraLoaiDaGiac()
{
    double epsilon = 1e-9;

    // 1. Kiểm tra các cạnh có bằng nhau không
    double canhChuan = dsDiem[0].TinhKhoangCach(dsDiem[1]);
    bool cacCanhBangNhau = true;
    for (int i = 1; i < n; i++)
    {
        double canhTiepTheo = dsDiem[i].TinhKhoangCach(dsDiem[(i + 1) % n]);
        if (abs(canhChuan - canhTiepTheo) > epsilon)
        {
            cacCanhBangNhau = false;
            break;
        }
    }

    if (!cacCanhBangNhau)
    {
        cout << "Day la da giac thuong.\n";
        return;
    }

    // 2. Kiểm tra các góc (bằng cách kiểm tra khoảng cách đến trọng tâm)
    double tongX = 0, tongY = 0;
    for (int i = 0; i < n; i++)
    {
        tongX += dsDiem[i].LayX();
        tongY += dsDiem[i].LayY();
    }
    Diem tam(tongX / n, tongY / n);

    double khoangCachChuan = dsDiem[0].TinhKhoangCach(tam);
    bool cachDeuTam = true;
    for (int i = 1; i < n; i++)
    {
        if (abs(khoangCachChuan - dsDiem[i].TinhKhoangCach(tam)) > epsilon)
        {
            cachDeuTam = false;
            break;
        }
    }

    if (cachDeuTam)
    {
        cout << "Day la da giac deu.\n";
    }
    else
    {
        cout << "Da giac co cac canh bang nhau nhung khong deu.\n";
    }
}
/**
 * @brief Tính chu vi của đa giác.
 * @param Không có.
 * @return Giá trị chu vi (double).
 * @note Giải thuật:
 *       1. Khởi tạo biến tongChuVi = 0.
 *       2. Duyệt qua n đỉnh của đa giác.
 *       3. Tại mỗi đỉnh i, tính khoảng cách đến đỉnh kế tiếp (i + 1).
 *          Sử dụng phép chia lấy dư (i + 1) % n để đỉnh cuối nối về đỉnh đầu.
 *       4. Cộng dồn các khoảng cách này vào tongChuVi.
 */
void cDaGiac::TinhChuVi()
{
    double tongChuVi = 0;
    for (int i = 0; i < n; i++)
    {
        // Lấy đỉnh kế tiếp, nếu là đỉnh cuối thì nối về đỉnh đầu (0)
        int j = (i + 1) % n;
        tongChuVi += dsDiem[i].TinhKhoangCach(dsDiem[j]);
    }
    cout << "Chu vi cua da giac la: " << tongChuVi << "\n";
}
/**
 * @brief Tính diện tích đa giác theo công thức Shoelace.
 * @param Không có.
 * @return Giá trị diện tích (double).
 * @note Giải thuật: Sử dụng công thức Shoelace (Tọa độ diện tích):
 *       S = 0.5 * | (x0*y1 - x1*y0) + (x1*y2 - x2*y1) + ... + (xn-1*y0 - x0*yn-1) |
 */
void cDaGiac::TinhDienTich()
{
    double dienTich = 0;
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n; // Đỉnh kế tiếp (đỉnh cuối nối về đỉnh đầu)
        dienTich += (dsDiem[i].LayX() * dsDiem[j].LayY());
        dienTich -= (dsDiem[j].LayX() * dsDiem[i].LayY());
    }
    cout << "Dien tich cua da giac la: " << abs(dienTich) / 2.0 << "\n";
}
/**
 * @brief Tịnh tiến đa giác theo vector (dx, dy).
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Duyệt qua tất cả các đỉnh trong mảng dsDiem,
 *       cộng dx vào hoành độ và dy vào tung độ của từng điểm.
 */
void cDaGiac::TinhTien()
{
    double dx, dy;
    cout << "Nhap vector tinh tien (dx, dy): ";
    cin >> dx >> dy;
    for (int i = 0; i < n; i++)
    {
        dsDiem[i].DatX(dsDiem[i].LayX() + dx);
        dsDiem[i].DatY(dsDiem[i].LayY() + dy);
    }
    cout << "Tinh tien thanh cong!\n";
}
/**
 * @brief Quay đa giác quanh gốc tọa độ (0,0).
 * @param Không có.
 * @note Giải thuật:
 *       1. Đổi góc sang Radian.
 *       2. Áp dụng công thức quay (x', y') cho từng phần tử trong mảng dsDiem.
 */
void cDaGiac::Quay()
{
    double goc;
    cout << "Nhap goc (do): ";
    cin >> goc;
    double rad = goc * 3.1415926535 / 180.0;
    for (int i = 0; i < n; i++)
    {
        double x_cu = dsDiem[i].LayX();
        double y_cu = dsDiem[i].LayY();

        // 1. Tính toán tọa độ mới
        double x_moi = x_cu * cos(rad) - y_cu * sin(rad);
        double y_moi = x_cu * sin(rad) + y_cu * cos(rad);

        // 2. Chuẩn hóa sai số (Nếu quá gần 0 thì gán thẳng bằng 0)
        if (abs(x_moi) < 1e-9)
            x_moi = 0.0;
        if (abs(y_moi) < 1e-9)
            y_moi = 0.0;

        // 3. Cập nhật tọa độ
        dsDiem[i].DatX(x_moi);
        dsDiem[i].DatY(y_moi);
    }
    cout << "Quay thanh cong!\n";
}
/**
 * @brief Phóng to đa giác theo hệ số k > 1.
 * @param Không có.
 * @return void.
 * @note Giải thuật:
 *       1. Nhập hệ số phóng to k. Kiểm tra điều kiện k > 1.
 *       2. Sử dụng vòng lặp duyệt qua tất cả n đỉnh của đa giác trong mảng dsDiem.
 *       3. Tại mỗi đỉnh, nhân tọa độ x và y với hệ số k.
 *       4. Cập nhật lại tọa độ mới cho các đỉnh thông qua phương thức DatX, DatY.
 */
void cDaGiac::PhongTo()
{
    double k;
    cout << "Nhap he so phong to (k > 1): ";
    while (cin >> k)
    {
        if (k > 1)
            break;
        cout << "He so khong hop le (k > 1)! Vui long nhap lai: ";
    }

    for (int i = 0; i < n; i++)
    {
        dsDiem[i].DatX(dsDiem[i].LayX() * k);
        dsDiem[i].DatY(dsDiem[i].LayY() * k);
    }
    cout << "Da phong to thanh cong!\n";
}
/**
 * @brief Thu nhỏ đa giác theo hệ số 0 < k < 1.
 * @param Không có.
 * @return void.
 * @note Giải thuật:
 *       1. Nhập hệ số thu nhỏ k. Kiểm tra điều kiện 0 < k < 1.
 *       2. Sử dụng vòng lặp duyệt qua toàn bộ danh sách đỉnh dsDiem.
 *       3. Thực hiện nhân tọa độ hiện tại của mỗi đỉnh với hệ số k.
 *       4. Cập nhật tọa độ mới cho đa giác.
 */
void cDaGiac::ThuNho()
{
    double k;
    cout << "Nhap he so thu nho (0 < k < 1): ";
    while (cin >> k)
    {
        if (k > 0 && k < 1)
            break;
        cout << "He so khong hop le (0 < k < 1)! Vui long nhap lai: ";
    }

    for (int i = 0; i < n; i++)
    {
        dsDiem[i].DatX(dsDiem[i].LayX() * k);
        dsDiem[i].DatY(dsDiem[i].LayY() * k);
    }
    cout << "Da thu nho đa giac thanh cong!\n";
}
