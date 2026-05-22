#include "CCongTy.h"
#include "CTienIch.h"
#include <iostream>
using namespace std;

/**
 * @brief Hàm khởi tạo mặc định cho lớp Công ty.
 * @param Không có.
 * @return Không có.
 */
CCongTy::CCongTy()
{
    DanhSachSX = nullptr;
    SoLuongSX = 0;
    DanhSachVP = nullptr;
    SoLuongVP = 0;
}

/**
 * @brief Hàm hủy đối tượng Công ty để giải phóng hệ thống bộ nhớ động lồng nhau.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Duyệt mảng DanhSachSX, giải phóng từng đối tượng nhân viên sản xuất được cấp phát độc lập bằng toán tử `delete`. Sau đó giải phóng mảng con trỏ gốc bằng `delete[]` hoặc `delete`.
 *       2. Thực hiện quy trình giải phóng tương tự cho mảng DanhSachVP của khối văn phòng để chống hoàn toàn rò rỉ bộ nhớ (Memory Leak).
 */
CCongTy::~CCongTy()
{
    if (DanhSachSX)
    {
        for (int i = 0; i < SoLuongSX; i++)
        {
            delete DanhSachSX[i];
        }
        delete DanhSachSX;
    }
    if (DanhSachVP)
    {
        for (int i = 0; i < SoLuongVP; i++)
        {
            delete DanhSachVP[i];
        }
        delete DanhSachVP;
    }
}

/**
 * @brief Cấp phát vùng nhớ và nhập danh sách toàn bộ nhân viên trong công ty.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Gọi hàm NhapSoNguyenAnToan() thu thập số lượng nhân viên sản xuất. Cấp phát mảng con trỏ chứa các thực thể CNhanVienSX. Chạy vòng lặp khởi tạo từng đối tượng con và gọi phương thức Nhap() nội tại.
 *       2. Thực hiện tuần tự quy trình tương tự để xây dựng cấu trúc dữ liệu cho danh sách khối nhân viên văn phòng.
 */
void CCongTy::NhapDanhSach()
{
    cout << "--Nhap danh sach nhan vien san xuat--\n";
    cout << "Nhap so luong nhan vien san xuat: ";
    SoLuongSX = NhapSoNguyenAnToan();
    DanhSachSX = new CNhanVienSX *[SoLuongSX];
    for (int i = 0; i < SoLuongSX; i++)
    {
        cout << "Nhan vien san xuat thu " << i + 1 << ":\n";
        DanhSachSX[i] = new CNhanVienSX();
        DanhSachSX[i]->Nhap();
    }

    cout << "\n--Nhap danh sach nhan vien van phong--\n";
    cout << "Nhap so luong nhan vien van phong: ";
    SoLuongVP = NhapSoNguyenAnToan();
    DanhSachVP = new CNhanVienVP *[SoLuongVP];
    for (int i = 0; i < SoLuongVP; i++)
    {
        cout << "Nhan vien van phong thu " << i + 1 << ":\n";
        DanhSachVP[i] = new CNhanVienVP();
        DanhSachVP[i]->Nhap();
    }
}

/**
 * @brief Xuất toàn bộ danh sách nhân viên phân tách theo khối bộ phận.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Sử dụng hai vòng lặp biệt lập tuần tự quét qua mảng `DanhSachSX` và `DanhSachVP`, kiểm tra số lượng để in thông báo nếu rỗng, ngược lại gọi phương thức Xuat() đồng bộ của từng nhân viên.
 */
void CCongTy::XuatDanhSach()
{
    cout << "\n-----Danh Sach nhan vien-----\n";
    cout << "---Danh sach nhan vien san xuat---\n";
    if (SoLuongSX == 0)
    {
        cout << "Danh sach trong\n";
    }
    for (int i = 0; i < SoLuongSX; i++)
    {
        DanhSachSX[i]->Xuat();
        if (i < SoLuongSX - 1)
        {
            cout << "---------------------------------------------\n";
        }
    }

    cout << "\n---Danh sach nhan vien van phong---\n";
    if (SoLuongVP == 0)
    {
        cout << "Danh sach trong\n";
    }
    for (int i = 0; i < SoLuongVP; i++)
    {
        DanhSachVP[i]->Xuat();
        if (i < SoLuongVP - 1)
        {
            cout << "---------------------------------------------\n";
        }
    }
}

/**
 * @brief Kích hoạt lệnh tính toán lương đồng loạt cho toàn thể nhân sự.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Duyệt qua toàn bộ các phần tử của cả hai mảng bộ phận và gọi phương thức TinhLuong() đặc thù cấu hình riêng cho từng khối đối tượng.
 */
void CCongTy::TinhLuong()
{
    for (int i = 0; i < SoLuongSX; i++)
    {
        DanhSachSX[i]->TinhLuong();
    }
    for (int i = 0; i < SoLuongVP; i++)
    {
        DanhSachVP[i]->TinhLuong();
    }
}

/**
 * @brief Tính tổng quỹ lương công ty cần chi trả cho toàn bộ nhân sự.
 * @param Không có.
 * @return Tổng số tiền lương tích lũy của hai khối phòng ban (double).
 * @note Giải thuật: Sử dụng biến tích lũy TongLuong, chạy qua hai danh sách để cộng dồn kết quả trả về từ phương thức truy xuất thông tin getLuong() của từng nhân viên.
 */
double CCongTy::TinhTongLuong()
{
    double TongLuong = 0;
    for (int i = 0; i < SoLuongSX; i++)
    {
        TongLuong += DanhSachSX[i]->getLuong();
    }
    for (int i = 0; i < SoLuongVP; i++)
    {
        TongLuong += DanhSachVP[i]->getLuong();
    }
    return TongLuong;
}

/**
 * @brief Tìm kiếm và hiển thị nhân viên thuộc khối sản xuất có mức lương thấp nhất.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Sử dụng kỹ thuật lính canh. Giả định nhân viên đầu tiên có mức lương tối thiểu, chạy vòng lặp so sánh từ phần tử kế tiếp qua phương thức getLuong() để cập nhật lại con trỏ đích nvMin nếu phát hiện mức lương thấp hơn.
 */
void CCongTy::TimNVSXLuongThapNhat()
{
    if (SoLuongSX == 0)
    {
        cout << "Khong co nhan vien san xuat\n";
        return;
    }
    CNhanVienSX *nvMin = DanhSachSX[0];
    for (int i = 1; i < SoLuongSX; i++)
    {
        if (DanhSachSX[i]->getLuong() < nvMin->getLuong())
        {
            nvMin = DanhSachSX[i];
        }
    }
    cout << "--Nhan vien san xuat co luong thap nhat la--\n";
    nvMin->Xuat();
}

/**
 * @brief Tìm kiếm và hiển thị nhân viên thuộc khối văn phòng có độ tuổi lớn nhất.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Áp dụng kỹ thuật lính canh dựa trên mốc lịch pháp: Người có tuổi lớn nhất sẽ có năm sinh nhỏ nhất trong hệ thống.
 *       2. Truy xuất năm sinh của nhân viên văn phòng đầu tiên thông qua lệnh liên kết dữ liệu chuỗi `GetNgaySinh().getNam()` để làm mốc chuẩn (namSinhMin).
 *       3. Duyệt mảng so sánh; nếu phát hiện nhân viên có năm sinh nhỏ hơn mốc chuẩn, cập nhật lại giá trị lính canh và trỏ biến nvGiaNhat về thực thể đó.
 */
void CCongTy::TimNVVPTuoiCaoNhat()
{
    if (SoLuongVP == 0)
    {
        cout << "Khong co nhan vien van phong\n";
        return;
    }

    CNhanVienVP *nvGiaNhat = DanhSachVP[0];
    int namSinhMin = DanhSachVP[0]->GetNgaySinh().getNam();

    for (int i = 1; i < SoLuongVP; i++)
    {
        int namSinhCur = DanhSachVP[i]->GetNgaySinh().getNam();
        if (namSinhCur < namSinhMin)
        {
            namSinhMin = namSinhCur;
            nvGiaNhat = DanhSachVP[i];
        }
    }

    cout << "\n--Nhan vien van phong co tuoi cao nhat la--\n";
    nvGiaNhat->Xuat();
}