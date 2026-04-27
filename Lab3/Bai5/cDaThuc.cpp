#include <iostream>
#include <cmath>
#include "cDaThuc.h"
using namespace std;
/**
 * @brief Hàm khởi tạo mặc định.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Khởi tạo đa thức bậc 0 với hệ số bằng 0.
 */
cDaThuc::cDaThuc()
{
    n = 0;
    heSo = new double[1];
    heSo[0] = 0;
}
/**
 * @brief Hàm khởi tạo đa thức với bậc cho trước.
 * @param bac: Bậc của đa thức.
 * @return Không có.
 * @note Giải thuật: Cấp phát mảng động heSo kích thước (bac + 1) và gán tất cả bằng 0.
 */
cDaThuc::cDaThuc(int bac)
{
    n = bac;
    heSo = new double[n + 1];
    for (int i = 0; i <= n; i++)
    {
        heSo[i] = 0;
    }
}
/**
 * @brief Hàm hủy đối tượng.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Giải phóng bộ nhớ mảng động heSo để tránh rò rỉ.
 */
cDaThuc::~cDaThuc()
{
    if (heSo)
        delete[] heSo;
}
/**
 * @brief Nhập dữ liệu đa thức từ bàn phím.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Nhập và kiểm tra tính hợp lệ của bậc đa thức n (n >= 0).
 *       2. Giải phóng bộ nhớ cũ và cấp phát lại mảng heSo mới.
 *       3. Lần lượt nhập các hệ số từ bậc cao nhất (x^n) đến bậc 0.
 */
void cDaThuc::Nhap()
{
    cout << "Nhap bac cua da thuc: ";
    while (true)
    {
        if (cin >> n && n >= 0)
            break;
        cout << "Bac cua da thuc khong hop le!\nVui long nhap lai: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    if (heSo)
        delete[] heSo;
    heSo = new double[n + 1];
    for (int i = 0; i <= n; i++)
    {
        cout << "Nhap he so cua x^" << n - i << ": ";
        while (true)
        {
            if (cin >> heSo[i])
                break;
            cout << "He so khong hop le!\nVui long nhap lai: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}
/**
 * @brief Xuất đa thức ra màn hình dưới dạng chuẩn toán học.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Duyệt qua mảng hệ số, bỏ qua các phần tử bằng 0.
 *       2. Xử lý dấu (+/-), ẩn hệ số 1, ẩn biến x ở bậc 0 và xử lý số mũ (x^k).
 *       3. Sử dụng biến cờ DaInPhanTuDau để định dạng các dấu nối giữa các số hạng.
 */
void cDaThuc::Xuat()
{
    bool DaInPhanTuDau = false;
    for (int i = 0; i <= n; i++)
    {
        if (heSo[i] == 0)
            continue;
        int bac = n - i;
        if (heSo[i] > 0 && DaInPhanTuDau)
            cout << " + ";
        if (heSo[i] < 0)
        {
            if (DaInPhanTuDau)
                cout << " - ";
            else
                cout << '-';
        }
        double triTuyetDoi = abs(heSo[i]);
        if (triTuyetDoi != 1 || bac == 0)
        {
            cout << triTuyetDoi;
        }
        if (bac > 0)
        {
            cout << "x";
            if (bac > 1)
                cout << "^" << bac;
        }
        DaInPhanTuDau = true;
    }
    if (!DaInPhanTuDau)
        cout << "0";
    cout << "\n";
}
/**
 * @brief Tính giá trị của đa thức tại x bằng sơ đồ Horner.
 * @param x: Giá trị của biến x cần tính.
 * @return Giá trị của đa thức (double).
 * @note Giải thuật: Sử dụng lược đồ Horner để tối ưu số phép nhân:
 *       P(x) = (...((a_n*x + a_n-1)*x + a_n-2)*x + ... + a_0).
 */
double cDaThuc::TinhGiaTri(double x)
{
    double sum = heSo[0];
    for (int i = 1; i <= n; i++)
    {
        sum = sum * x + heSo[i];
    }
    return sum;
}
/**
 * @brief Cộng hai đa thức.
 * @param p: Đa thức cần cộng thêm.
 * @return Một đối tượng cDaThuc mới là tổng của hai đa thức.
 * @note Giải thuật:
 *       1. Xác định bậc cao nhất giữa hai đa thức.
 *       2. Cộng các hệ số có cùng bậc (truy xuất từ cuối mảng lên để khớp bậc).
 *       3. Lưu kết quả vào đa thức mới và trả về.
 */
cDaThuc cDaThuc::Cong(cDaThuc &p)
{
    int bacMax = (n > p.n) ? n : p.n;
    cDaThuc Tong(bacMax);
    for (int i = 0; i <= bacMax; i++)
    {
        double heSo1 = (i <= n) ? heSo[n - i] : 0;
        double heSo2 = (i <= p.n) ? p.heSo[p.n - i] : 0;
        Tong.heSo[Tong.n - i] = heSo1 + heSo2;
    }
    return Tong;
}
/**
 * @brief Trừ hai đa thức.
 * @param p: Đa thức bị trừ.
 * @return Một đối tượng cDaThuc mới là hiệu của hai đa thức.
 * @note Giải thuật: Tương tự phép cộng, nhưng thực hiện trừ các hệ số tương ứng giữa hai đa thức.
 */
cDaThuc cDaThuc::Tru(cDaThuc &p)
{
    int bacMax = (n > p.n) ? n : p.n;
    cDaThuc Hieu(bacMax);
    for (int i = 0; i <= bacMax; i++)
    {
        double heSo1 = (i <= n) ? heSo[n - i] : 0;
        double heSo2 = (i <= p.n) ? p.heSo[p.n - i] : 0;
        Hieu.heSo[Hieu.n - i] = heSo1 - heSo2;
    }
    return Hieu;
}
/**
 * @brief Hàm khởi tạo sao chép (Copy Constructor).
 * @param khac: Đối tượng đa thức nguồn cần sao chép.
 * @return Không có.
 * @note Giải thuật: Tạo một vùng nhớ mới và sao chép toàn bộ bậc và hệ số từ đối tượng "khac".
 */
cDaThuc::cDaThuc(const cDaThuc &khac)
{
    n = khac.n;
    heSo = new double[n + 1];
    for (int i = 0; i <= n; i++)
    {
        heSo[i] = khac.heSo[i];
    }
}
/**
 * @brief Toán tử gán (Assignment Operator).
 * @param khac: Đối tượng đa thức nguồn cần gán.
 * @return Tham chiếu đến đối tượng hiện tại sau khi gán.
 * @note Giải thuật:
 *       1. Kiểm tra tự gán (this == &khac).
 *       2. Giải phóng vùng nhớ cũ, cấp phát vùng nhớ mới và sao chép dữ liệu.
 */
cDaThuc &cDaThuc::operator=(const cDaThuc &khac)
{
    if (this != &khac)
    {
        if (heSo)
        {
            delete[] heSo;
        }
        n = khac.n;
        heSo = new double[n + 1];
        for (int i = 0; i <= n; i++)
        {
            heSo[i] = khac.heSo[i];
        }
    }
    return *this;
}