#include "../include/CCongTy.h"
#include "../include/CLapTrinhVien.h"
#include "../include/CKiemChungVien.h"
#include "../include/CTienIch.h"
#include <iostream>

using namespace std;

/**
 * @brief Hàm khởi tạo mặc định cho lớp Công ty.
 * @param Không có.
 * @return Không có.
 */
CCongTy::CCongTy()
{
    DanhSach = nullptr;
    SoLuong = 0;
}

/**
 * @brief Hàm hủy đối tượng Công ty để giải phóng hệ thống bộ nhớ động lồng nhau.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Kiểm tra tính hợp lệ của mảng con trỏ DanhSach.
 *       2. Duyệt qua từng phần tử để giải phóng độc lập các thực thể nhân viên con (`CLapTrinhVien` hoặc `CKiemChungVien`) bằng toán tử `delete`.
 *       3. Thực hiện giải phóng mảng con trỏ cấu trúc nền bằng toán tử `delete[]`.
 */
CCongTy::~CCongTy()
{
    if (DanhSach != nullptr)
    {
        for (int i = 0; i < SoLuong; i++)
        {
            delete DanhSach[i];
        }
        delete[] DanhSach;
    }
}

// === Hàm hỗ trợ nội bộ ===
/**
 * @brief Tính giá trị lương trung bình của toàn thể nhân viên trong công ty.
 * @param Không có.
 * @return Giá trị lương trung bình (double).
 * @note Giải thuật: Kiểm tra điều kiện số lượng để chống lỗi chia cho 0. Quét vòng lặp qua mảng danh sách, gọi hàm TinhLuong() đồng bộ tích lũy vào biến tổng, sau đó trả về thương số của phép chia cho số lượng nhân viên.
 */
double CCongTy::TinhLuongTrungBinh() const
{
    if (SoLuong == 0)
        return 0.0; // Chống lỗi chia cho 0

    double tongLuong = 0.0;
    for (int i = 0; i < SoLuong; i++)
    {
        tongLuong += DanhSach[i]->TinhLuong();
    }
    return tongLuong / SoLuong;
}

// === a. Nhập danh sách nhân viên ===
/**
 * @brief Cấp phát vùng nhớ, phân loại vị trí và nhập danh sách toàn bộ nhân viên.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Thu thập tổng số lượng nhân viên qua hàm tiện ích NhapSoNguyenAnToan().
 *       2. Khởi tạo mảng động chứa các con trỏ lớp cha `CNhanVien*`.
 *       3. Chạy vòng lặp duyệt mảng, bắt luồng chọn chức vụ hợp lệ (1: Lập trình viên, 2: Kiểm chứng viên).
 *       4. Áp dụng tính chất Đa hình để cấp phát đúng vùng nhớ cho lớp con và gọi phương thức Nhap() tương ứng.
 */
void CCongTy::NhapDanhSach()
{
    cout << "Nhap tong so luong nhan vien: ";
    SoLuong = NhapSoNguyenAnToan();

    if (SoLuong == 0)
        return;

    DanhSach = new CNhanVien *[SoLuong];

    cout << "\nNhap danh sach nhan vien\n";
    for (int i = 0; i < SoLuong; i++)
    {
        cout << "Nhap nhan vien thu " << i + 1 << "\n";
        cout << "1. Lap trinh vien\n2. Kiem chung vien\n";
        cout << "Chon loai nhan vien (1-2): ";

        int loai;
        while (true)
        {
            loai = NhapSoNguyenAnToan();
            if (loai == 1 || loai == 2)
                break;
            cout << "Lua chon khong hop le! Vui long nhap lai (1-2): ";
        }

        if (loai == 1)
        {
            DanhSach[i] = new CLapTrinhVien();
        }
        else
        {
            DanhSach[i] = new CKiemChungVien();
        }

        DanhSach[i]->Nhap();
    }
}

// === b. Xuất danh sách nhân viên ===
/**
 * @brief Lọc và xuất thông tin danh sách nhân viên phân tách theo từng vị trí chức vụ.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Kiểm tra tính hợp lệ của mảng dữ liệu để chặn trường hợp danh sách rỗng.
 *       2. Sử dụng toán tử `dynamic_cast` duyệt mảng để nhận diện phân loại thực thể lớp con.
 *       3. Thực hiện in riêng biệt nhóm Lập trình viên và nhóm Kiểm chứng viên kèm cờ kiểm soát thông báo rỗng.
 */
void CCongTy::XuatDanhSach() const
{
    if (SoLuong == 0 || DanhSach == nullptr)
    {
        cout << "\nDanh sach rong!\n";
        return;
    }
    cout << "\n---Danh sach nhan vien Cty Hoan cau---\n";
    cout <<"===Danh sach Lap trinh vien===\n";
    bool isDev = false;
    for (int i = 0; i < SoLuong; i++)
    {
        CLapTrinhVien *dev = dynamic_cast<CLapTrinhVien *>(DanhSach[i]);
        if (dev != nullptr)
        {
            isDev = true;
            dev->Xuat();
        }
    }
    if(!isDev)
    {
        cout << "Khong co Lap trinh vien nao trong cong ty.\n";
    }
    cout <<"===Danh sach Kiem chung vien===\n";
    bool isTester = false;
    for (int i = 0; i < SoLuong; i++)
    {
        CKiemChungVien *tester = dynamic_cast<CKiemChungVien *>(DanhSach[i]);
        if (tester != nullptr)
        {
            isTester = true;
            tester->Xuat();
        }
    }
    if(!isTester)
    {
        cout << "Khong co Kiem chung vien nao trong cong ty.\n";
    }
}
// === c. Xuất nhân viên có lương < Trung bình ===
/**
 * @brief Lọc và hiển thị các nhân viên có mức lương thực nhận dưới mức trung bình của công ty.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Gọi hàm TinhLuongTrungBinh() để lấy giá trị mốc chuẩn (luongTB). Duyệt qua mảng danh sách, đối chiếu kết quả trả về từ phương thức ảo TinhLuong() của từng nhân viên; nếu nhỏ hơn mốc chuẩn thì gọi hàm Xuat() hiển thị.
 */
void CCongTy::XuatNhanVien_LuongDuoiTrungBinh() const
{
    cout << "\n---Danh sach nhan vien co luong duoi trung binh---\n";
    if (SoLuong == 0 || DanhSach == nullptr)
    {
        cout << "Danh sach rong!\n";
        return;
    }

    double luongTB = TinhLuongTrungBinh();
    cout << "Muc luong trung binh: "
         << DinhDangTien(luongTB) << " VND\n";

    bool coNhanVien = false;
    for (int i = 0; i < SoLuong; i++)
    {
        if (DanhSach[i]->TinhLuong() < luongTB)
        {
            DanhSach[i]->Xuat();
            coNhanVien = true;
        }
    }
    if (!coNhanVien)
        cout << "Khong co ai nhan luong thap hon muc trung binh.\n";
}

// === d. Xuất thông tin nhân viên có lương cao nhất ===
/**
 * @brief Tìm kiếm và hiển thị toàn bộ nhân viên có mức lương thực nhận cao nhất công ty.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Áp dụng kỹ thuật lính canh: Giả định phần tử đầu tiên đạt giá trị lớn nhất (maxLuong), quét mảng so sánh để tìm ra giá trị lương cực đại thực tế.
 *       2. Chạy vòng lặp lần hai để đối chiếu kết hợp, thực hiện in toàn bộ nhân viên có mức lương bằng đúng giá trị maxLuong để chống bỏ sót.
 */
void CCongTy::XuatNhanVien_LuongMax() const
{
    cout << "\n---Nhan vien co luong cao nhat---\n";
    if (SoLuong == 0 || DanhSach == nullptr)
    {
        cout << "Danh sach rong!\n";
        return;
    }

    double maxLuong = DanhSach[0]->TinhLuong();

    for (int i = 1; i < SoLuong; i++)
    {
        if (DanhSach[i]->TinhLuong() > maxLuong)
        {
            maxLuong = DanhSach[i]->TinhLuong();
        }
    }

    for (int i = 0; i < SoLuong; i++)
    {
        if (DanhSach[i]->TinhLuong() == maxLuong)
            DanhSach[i]->Xuat();
    }
}

// === e. Xuất thông tin nhân viên có lương thấp nhất ===
/**
 * @brief Tìm kiếm và hiển thị toàn bộ nhân viên có mức lương thực nhận thấp nhất công ty.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Áp dụng phương pháp lính canh tìm ra giá trị lương cực tiểu (minLuong) của toàn công ty ở lượt quét thứ nhất, sau đó chạy lượt quét thứ hai để hiển thị tất cả nhân viên có mức thu nhập bằng đúng giá trị minLuong.
 */
void CCongTy::XuatNhanVien_LuongMin() const
{
    cout << "\n---Nhan vien co luong thap nhat---\n";
    if (SoLuong == 0 || DanhSach == nullptr)
    {
        cout << "Danh sach rong!\n";
        return;
    }

    double minLuong = DanhSach[0]->TinhLuong();

    for (int i = 1; i < SoLuong; i++)
    {
        if (DanhSach[i]->TinhLuong() < minLuong)
        {
            minLuong = DanhSach[i]->TinhLuong();
        }
    }

    for (int i = 0; i < SoLuong; i++)
    {
        if (DanhSach[i]->TinhLuong() == minLuong)
            DanhSach[i]->Xuat();
    }
}

// === f. Xuất thông tin Lập trình viên có lương cao nhất ===
/**
 * @brief Tìm kiếm và hiển thị danh sách các Lập trình viên có mức lương cao nhất.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Quét danh sách lần một: Sử dụng `dynamic_cast` lọc riêng thực thể `CLapTrinhVien`, ứng dụng kỹ thuật lính canh khởi tạo từ -1.0 để tìm mức lương lớn nhất (maxLuong).
 *       2. Quét danh sách lần hai: Lọc trùng kết hợp so sánh điều kiện để in toàn bộ Lập trình viên có mức lương bằng giá trị maxLuong.
 */
void CCongTy::XuatLapTrinhVien_LuongMax() const
{
    cout << "\n---Lap trinh vien co luong cao nhat---\n";
    if (SoLuong == 0 || DanhSach == nullptr)
    {
        cout << "Danh sach rong!\n";
        return;
    }

    double maxLuong = -1.0;

    for (int i = 0; i < SoLuong; i++)
    {
        CLapTrinhVien *dev = dynamic_cast<CLapTrinhVien *>(DanhSach[i]);
        if (dev != nullptr)
        {
            if (dev->TinhLuong() > maxLuong)
            {
                maxLuong = dev->TinhLuong();
            }
        }
    }

    if (maxLuong == -1.0)
    {
        cout << "Khong co Lap trinh vien nao trong cong ty.\n";
        return;
    }

    for (int i = 0; i < SoLuong; i++)
    {
        CLapTrinhVien *dev = dynamic_cast<CLapTrinhVien *>(DanhSach[i]);
        if (dev != nullptr && dev->TinhLuong() == maxLuong)
            dev->Xuat();
    }
}

// === g. Xuất thông tin Kiểm chứng viên có lương thấp nhất ===
/**
 * @brief Tìm kiếm và hiển thị danh sách các Kiểm chứng viên có mức lương thấp nhất.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Duyệt mảng lần một: Sử dụng `dynamic_cast` lọc riêng thực thể `CKiemChungVien`. Khởi tạo lính canh từ -1.0, thực hiện cấu trúc điều kiện hoặc (`||`) để tìm ra mức lương cực tiểu (minLuong) của khối kiểm thử.
 *       2. Duyệt mảng lần hai: Đối chiếu lọc trùng để in ra màn hình toàn bộ các Kiểm chứng viên có mức lương bằng đúng giá trị minLuong vừa xác định.
 */
void CCongTy::XuatKiemChungVien_LuongMin() const
{
    cout << "\n---Kiem chung vien co luong thap nhat---\n";
    if (SoLuong == 0 || DanhSach == nullptr)
    {
        cout << "Danh sach rong!\n";
        return;
    }

    double minLuong = -1.0;

    for (int i = 0; i < SoLuong; i++)
    {
        CKiemChungVien *tester = dynamic_cast<CKiemChungVien *>(DanhSach[i]);
        if (tester != nullptr)
        {
            // Nếu là Tester đầu tiên tìm thấy HOẶC tìm được Tester có lương nhỏ hơn
            if (minLuong == -1.0 || tester->TinhLuong() < minLuong)
            {
                minLuong = tester->TinhLuong();
            }
        }
    }

    if (minLuong == -1.0)
    {
        cout << "Khong co Kiem chung vien nao trong cong ty.\n";
        return;
    }

    for (int i = 0; i < SoLuong; i++)
    {
        CKiemChungVien *tester = dynamic_cast<CKiemChungVien *>(DanhSach[i]);
        if (tester != nullptr && tester->TinhLuong() == minLuong)
            tester->Xuat();
    }
}