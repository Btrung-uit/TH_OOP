#include "cQuanLyNVSX.h"
#include <iostream>

using namespace std;

/**
 * @brief Hàm khởi tạo mặc định cho lớp Quản lý nhân viên.
 * @note Giải thuật: Thiết lập số lượng nhân viên ban đầu n = 0 và con trỏ danh sách bằng nullptr.
 */
cQuanLyNVSX::cQuanLyNVSX()
{
    n = 0;
    dsNV = nullptr;
}

/**
 * @brief Hàm hủy đối tượng Quản lý.
 * @note Giải thuật: Kiểm tra và giải phóng mảng động dsNV để tránh rò rỉ bộ nhớ khi đối tượng bị hủy.
 */
cQuanLyNVSX::~cQuanLyNVSX()
{
    if (dsNV != nullptr)
    {
        delete[] dsNV;
    }
}

/**
 * @brief Nhập danh sách nhân viên sản xuất từ bàn phím.
 * @note Giải thuật:
 *       1. Nhập số lượng nhân viên n (phải > 0).
 *       2. Cấp phát mảng động dsNV có n phần tử.
 *       3. Với mỗi nhân viên, thực hiện nhập thông tin và kiểm tra trùng mã:
 *          - Duyệt các nhân viên đã nhập trước đó để so sánh mã số (getMaNV).
 *          - Nếu trùng, yêu cầu người dùng nhập lại mã mới cho đến khi là duy nhất.
 */
void cQuanLyNVSX::NhapDanhSach()
{
    cout << "Nhap so luong nhan vien: ";
    while (true)
    {
        if (cin >> n && n > 0)
        {
            break;
        }
        cout << "So luong khong hop le!\nVui long nhap lai: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    if (dsNV != nullptr)
    {
        delete[] dsNV;
    }
    dsNV = new cNhanVienSX[n];

    for (int i = 0; i < n; i++)
    {
        cout << "--- Nhap thong tin nhan vien thu " << i + 1 << " ---\n";
        dsNV[i].Nhap();
        bool trungMa;
        do
        {
            trungMa = false;
            for (int j = 0; j < i; j++)
            {
                if (dsNV[j].getMaNV() == dsNV[i].getMaNV())
                {
                    trungMa = true;
                    break;
                }
            }
            if (trungMa)
            {
                cout << "Ma nhan vien nay da ton tai!\nVui long nhap lai: ";
                string maMoi;
                while (true)
                {
                    cin >> maMoi;
                    if (maMoi.length() <= 8)
                        break;
                    cout << "Ma nhan vien khong hop le!\nVui long nhap lai: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                dsNV[i].setMaNV(maMoi);
            }
        } while (trungMa);
    }
}

/**
 * @brief Xuất toàn bộ danh sách nhân viên hiện có.
 * @note Giải thuật: Sử dụng vòng lặp duyệt qua mảng và gọi phương thức Xuat() của từng đối tượng nhân viên.
 */
void cQuanLyNVSX::XuatDanhSach()
{
    cout << "\nDANH SACH NHAN VIEN SAN XUAT:\n";
    cout << "----------------------------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        dsNV[i].Xuat();
    }
    cout << "----------------------------------------------------------------------------------------\n";
}

/**
 * @brief Tìm và in ra các nhân viên có mức lương thấp nhất.
 * @note Giải thuật:
 *       1. Sử dụng kỹ thuật lính canh: giả định nhân viên đầu tiên có lương thấp nhất.
 *       2. Duyệt danh sách để tìm giá trị lương thấp nhất (minLuong).
 *       3. Duyệt lại lần hai để in ra tất cả nhân viên có mức lương bằng minLuong (để tránh bỏ sót nếu có nhiều người cùng lương).
 */
void cQuanLyNVSX::TimNVLuongThapNhat()
{
    if (n == 0)
        return;

    double minLuong = dsNV[0].TinhLuong();
    for (int i = 1; i < n; i++)
    {
        if (dsNV[i].TinhLuong() < minLuong)
        {
            minLuong = dsNV[i].TinhLuong();
        }
    }

    cout << "\nNHAN VIEN CO LUONG THAP NHAT:\n";
    cout << "----------------------------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        if (dsNV[i].TinhLuong() == minLuong)
        {
            dsNV[i].Xuat();
        }
    }
    cout << "----------------------------------------------------------------------------------------\n";
}

/**
 * @brief Tính tổng lương của tất cả nhân viên trong danh sách.
 * @return Tổng số tiền lương (double).
 * @note Giải thuật: Duyệt qua mảng và cộng dồn kết quả từ hàm TinhLuong() của từng nhân viên vào biến tổng.
 */
double cQuanLyNVSX::TinhTongLuong()
{
    double tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong += dsNV[i].TinhLuong();
    }
    return tong;
}

/**
 * @brief Tìm và in ra các nhân viên có tuổi cao nhất.
 * @param namHienTai: Năm thực tế để tính tuổi.
 * @note Giải thuật:
 *       1. Tìm giá trị tuổi lớn nhất (maxTuoi) bằng phương pháp lính canh.
 *       2. Duyệt lại danh sách để in tất cả nhân viên có tuổi bằng maxTuoi.
 */
void cQuanLyNVSX::TimNVTuoiCaoNhat(int namHienTai)
{
    if (n == 0)
        return;

    int maxTuoi = dsNV[0].getTuoi(namHienTai);
    for (int i = 1; i < n; i++)
    {
        if (dsNV[i].getTuoi(namHienTai) > maxTuoi)
        {
            maxTuoi = dsNV[i].getTuoi(namHienTai);
        }
    }

    cout << "\nNHAN VIEN CO TUOI CAO NHAT (" << maxTuoi << " TUOI):\n";
    cout << "----------------------------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        if (dsNV[i].getTuoi(namHienTai) == maxTuoi)
        {
            dsNV[i].Xuat();
        }
    }
    cout << "----------------------------------------------------------------------------------------\n";
}

/**
 * @brief Sắp xếp danh sách nhân viên tăng dần theo mức lương.
 * @note Giải thuật: Sử dụng thuật toán Interchange Sort (Đổi chỗ trực tiếp):
 *       - So sánh TinhLuong() của cặp phần tử i và j.
 *       - Nếu lương của i > lương của j thì thực hiện hoán vị (swap) hai đối tượng nhân viên.
 */
void cQuanLyNVSX::SapXepTangDanTheoLuong()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (dsNV[i].TinhLuong() > dsNV[j].TinhLuong())
            {
                cNhanVienSX temp = dsNV[i];
                dsNV[i] = dsNV[j];
                dsNV[j] = temp;
            }
        }
    }
    cout << "\nDa sap xep danh sach tang dan theo luong.\n";
}