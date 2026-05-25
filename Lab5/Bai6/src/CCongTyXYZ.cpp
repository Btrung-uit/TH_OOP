#include "CCongTyXYZ.h"
#include "CKhachHangA.h"
#include "CKhachHangB.h"
#include "CKhachHangC.h"
#include "CTienIch.h"
#include <iostream>

using namespace std;

/**
 * @brief Hàm khởi tạo mặc định cho lớp Quản lý Công ty XYZ.
 * @param Không có.
 * @return Không có.
 */
CCongTyXYZ::CCongTyXYZ()
{
    DanhSach = nullptr;
    x = y = z = 0;
    TongSoLuong = 0;
}

/**
 * @brief Hàm hủy đối tượng Công ty XYZ để kích hoạt quy trình giải phóng tài nguyên.
 * @param Không có.
 * @return Không có.
 */
CCongTyXYZ::~CCongTyXYZ()
{
    GiaiPhongBoNho();
}

/**
 * @brief Thực hiện thu hồi bộ nhớ động đã cấp phát cho mảng cấu trúc con trỏ lồng nhau.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Kiểm tra sự tồn tại của mảng DanhSach độc lập với nullptr.
 *       2. Quét vòng lặp delete giải phóng từng thực thể khách hàng con tương ứng (`CKhachHangA`, `CKhachHangB`, `CKhachHangC`) và đưa con trỏ vùng nhớ đó về nullptr.
 *       3. Giải phóng mảng con trỏ nền tảng bằng toán tử `delete[]`.
 */
void CCongTyXYZ::GiaiPhongBoNho()
{
    if (DanhSach != nullptr)
    {
        for (int i = 0; i < TongSoLuong; i++)
        {
            if (DanhSach[i] != nullptr)
            {
                delete DanhSach[i];
                DanhSach[i] = nullptr;
            }
        }
        delete[] DanhSach;
        DanhSach = nullptr;
    }
}

/**
 * @brief Trực tiếp điều phối luồng đọc/ghi dữ liệu tệp tin và áp dụng Đa hình để quản lý danh sách khách hàng.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Mở luồng tệp tin đầu vào "XYZ.INP" và tệp tin đầu ra "XYZ.OUT". Kiểm tra trạng thái lỗi mở file.
 *       2. Sử dụng hàm tiện ích CTienIch::DocSoNguyen() trích xuất số lượng khách hàng từng nhóm x, y, z. Chặn biên kiểm tra điều kiện kích thước dữ liệu hợp lệ (0 < giá trị < 1000).
 *       3. Tính toán tổng số lượng, cấp phát mảng động con trỏ lớp cha `CKhachHang*`.
 *       4. Sử dụng 3 vòng lặp tuần tự tương ứng để khởi tạo đa hình vùng nhớ lớp con (`CKhachHangA`, `CKhachHangB`, `CKhachHangC`), kích hoạt nạp dữ liệu từ hàm DocFile() nội tại và bắt lỗi định dạng dòng tệp.
 *       5. Xuất số lượng nhóm ra file kết quả. Quét vòng lặp cuối cùng điều khiển hàm GhiFile() kết xuất thông tin riêng và tính toán tổng tiền tích lũy qua phương thức ảo TinhTien().
 */
void CCongTyXYZ::XuLyDuLieu()
{
    ifstream inFile("XYZ.INP");
    ofstream outFile("XYZ.OUT");

    if (!inFile)
    {
        outFile << "Loi: Khong the mo file XYZ.INP\n";
        return;
    }

    bool flag = true;

    x = CTienIch::DocSoNguyen(inFile, flag);
    y = CTienIch::DocSoNguyen(inFile, flag);
    z = CTienIch::DocSoNguyen(inFile, flag);

    if (flag == false)
    {
        outFile << "Loi dinh dang hoac chua so am o dong dau tien trong file XYZ.INP\n";
        return;
    }

    if (x <= 0 || x >= 1000 || y <= 0 || y >= 1000 || z <= 0 || z >= 1000)
    {
        outFile << "Loi: So luong khach hang x, y, z phai thoa man dieu kien 0 < gia tri < 1000\n";
        return;
    }

    TongSoLuong = x + y + z;
    DanhSach = new CKhachHang *[TongSoLuong];
    for (int i = 0; i < TongSoLuong; i++)
    {
        DanhSach[i] = nullptr;
    }

    int index = 0;

    for (int i = 0; i < x; i++)
    {
        DanhSach[index] = new CKhachHangA();
        DanhSach[index]->DocFile(inFile, flag);
        if (flag == false)
        {
            outFile << "Loi dinh dang du lieu tai Khach hang loai A thu " << i + 1 << "\n";
            GiaiPhongBoNho();
            return;
        }
        index++;
    }

    for (int i = 0; i < y; i++)
    {
        DanhSach[index] = new CKhachHangB();
        DanhSach[index]->DocFile(inFile, flag);
        if (flag == false)
        {
            outFile << "Loi dinh dang du lieu tai Khach hang loai B thu " << i + 1 << "\n";
            GiaiPhongBoNho();
            return;
        }
        index++;
    }

    for (int i = 0; i < z; i++)
    {
        DanhSach[index] = new CKhachHangC();
        DanhSach[index]->DocFile(inFile, flag);
        if (flag == false)
        {
            outFile << "Loi dinh dang du lieu tai Khach hang loai C thu " << i + 1 << "\n";
            GiaiPhongBoNho();
            return;
        }
        index++;
    }

    outFile << x << " " << y << " " << z << "\n";

    double tongSoTienCongTyThuDuoc = 0.0;
    for (int i = 0; i < TongSoLuong; i++)
    {
        DanhSach[i]->GhiFile(outFile);
        tongSoTienCongTyThuDuoc += DanhSach[i]->TinhTien();
    }

    outFile << CTienIch::DinhDangTien(tongSoTienCongTyThuDuoc);

    inFile.close();
    outFile.close();
}