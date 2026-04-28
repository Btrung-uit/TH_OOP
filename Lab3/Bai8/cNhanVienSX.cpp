#include "cNhanVienSX.h"
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * @brief Hàm khởi tạo mặc định cho lớp Nhân viên sản xuất.
 * @note Giải thuật: Thiết lập các chuỗi rỗng cho mã số, họ tên và gán giá trị 0 cho các chỉ số số lượng, đơn giá.
 */
cNhanVienSX::cNhanVienSX()
{
    maNV = "";
    hoTen = "";
    soSanPham = 0;
    donGia = 0.0;
}

// --- Nhóm các hàm Getter và Setter ---
/**
 * @brief Lấy mã nhân viên.
 * @return Chuỗi mã nhân viên (string).
 */
string cNhanVienSX::getMaNV()
{
    return maNV;
}

/**
 * @brief Cập nhật mã nhân viên.
 * @param m: Chuỗi mã mới.
 */
void cNhanVienSX::setMaNV(string m)
{
    maNV = m;
}

/**
 * @brief Lấy chuỗi họ và tên.
 * @return Chuỗi họ và tên (string).
 */
string cNhanVienSX::getHoTen()
{
    return hoTen;
}

/**
 * @brief Cập nhật họ và tên.
 * @param ht: Chuỗi họ và tên mới.
 */
void cNhanVienSX::setHoTen(string ht)
{
    hoTen = ht;
}

/**
 * @brief Lấy số sản phẩm.
 * @return số sản phẩm (int).
 */
int cNhanVienSX::getSoSanPham()
{
    return soSanPham;
}

/**
 * @brief Cập nhật số sản phẩm.
 * @param sp: Số sản phẩm mới.
 */
void cNhanVienSX::setSoSanPham(int sp)
{
    soSanPham = sp;
}

/**
 * @brief Lấy đơn giá.
 * @return Đơn giá (double).
 */
double cNhanVienSX::getDonGia()
{
    return donGia;
}

/**
 * @brief Cập nhật đơn giá.
 * @param dg: Đơn giá mới.
 */
void cNhanVienSX::setDonGia(double dg)
{
    donGia = dg;
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
{ // Kiểm tra tính hợp lệ của tên
    int lenght = ten.length();
    if (lenght > 26 || lenght == 0)
        return false; // Kiểm tra độ dài
    if (ten[0] == ' ' || ten[lenght - 1] == ' ')
        return false; // kiểm tra đầu chuỗi có dấu cách hay cuối chuỗi có dấu cách không
    for (int i = 0; ten[i] != '\0'; i++)
    {
        if (ten[i] == ' ')
        {
            if (i + 1 < lenght && ten[i + 1] == ' ')
                return false; // Kiểm tra có nhiều dấu cách trong tên hay không
            continue;
        }
        if ((ten[i] < 'A' || ten[i] > 'Z') && (ten[i] < 'a' || ten[i] > 'z'))
            return false;                            // kiểm tra xem có kí tự đặc biệt hay số không
        bool chuDau = (i == 0 || ten[i - 1] == ' '); // đặt cờ cho chữ đầu
        if (chuDau)
        { // nếu là chữ đầu kiểm tra xem có viết hoa không
            if (ten[i] < 'A' || ten[i] > 'Z')
                return false;
        }
        else
        {
            if (ten[i] < 'a' || ten[i] > 'z')
                return false; // nếu chữ bình thường kiểm tra xem có viết thường không
        }
    }
    return true;
}

/**
 * @brief Nhập thông tin chi tiết của nhân viên sản xuất từ bàn phím.
 * @note Giải thuật:
 *       1. Nhập và bắt lỗi độ dài Mã NV (<= 8 ký tự).
 *       2. Nhập Họ tên và sử dụng hàm KiemTraTen để bắt lỗi định dạng.
 *       3. Gọi phương thức Nhap() của thuộc tính ngaySinh (đối tượng lớp cNgay).
 *       4. Nhập và kiểm tra tính hợp lệ (số dương) cho Số sản phẩm và Đơn giá.
 */
void cNhanVienSX::Nhap()
{
    cout << "Nhap Ma nhan vien (Toi da 8 ki tu): ";
    while (true)
    {
        cin >> maNV;

        // Giới hạn độ dài cho mã nhân viên là 8
        if (maNV.length() <= 8)
        {
            break; // Hop le thi thoat vong lap
        }

        cout << "Ma NV khong hop le!\nVui long nhap lai: ";
        // Xoa rác bộ đệm nếu người dùng nhập dư
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Nhap Ho ten (toi da 26 ki tu): ";
    cin.ignore(10000, '\n');
    while (true)
    {
        getline(cin, hoTen);
        if (KiemTraTen(hoTen))
            break;
        cout << "Ho ten khong hop le!\nVui long nhap lai: ";
    }

    cout << "--- Nhap ngay sinh ---\n";
    ngaySinh.Nhap();

    cout << "Nhap so san pham: ";
    while (true)
    {
        if (cin >> soSanPham && soSanPham >= 0)
        {
            break;
        }
        cout << "So san pham khong hop le! Nhap lai: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Nhap don gia: ";
    while (true)
    {
        if (cin >> donGia && donGia >= 0)
        {
            break;
        }
        cout << "Don gia khong hop le! Nhap lai: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

/**
 * @brief Xuất thông tin nhân viên theo định dạng bảng.
 * @note Giải thuật: Sử dụng các hàm setw(), left để căn lề đều các cột thông tin.
 *       Kết quả bao gồm cả tiền lương được tính tự động.
 */
void cNhanVienSX::Xuat()
{
    cout << setw(10) << left << maNV
         << " | " << setw(20) << left << hoTen
         << " | ";
    ngaySinh.Xuat();
    cout << " | SP: " << setw(5) << left << soSanPham
         << " | Gia: " << setw(10) << left << donGia
         << " | Luong: " << TinhLuong() << "\n";
}

/**
 * @brief Tính lương của nhân viên sản xuất.
 * @return Giá trị lương (double).
 * @note Giải thuật: Lương được tính bằng công thức: Số sản phẩm * Đơn giá.
 */
double cNhanVienSX::TinhLuong()
{
    return soSanPham * donGia;
}

/**
 * @brief Tính tuổi của nhân viên dựa trên năm hiện tại.
 * @param namHienTai: Năm thực tế dùng để đối chiếu.
 * @return Tuổi của nhân viên (int).
 * @note Giải thuật: Lấy năm hiện tại trừ đi giá trị năm sinh nhận được từ đối tượng ngaySinh.
 */
int cNhanVienSX::getTuoi(int namHienTai)
{
    return namHienTai - ngaySinh.getNam();
}