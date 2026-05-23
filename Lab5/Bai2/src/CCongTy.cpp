#include "../include/CCongTy.h"
#include "../include/CGiaoDich.h"
#include "../include/CGiaoDichDat.h"
#include "../include/CGiaoDichNhaPho.h"
#include "../include/CGiaoDichCanHo.h"
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
    DanhSachGD = nullptr;
    SoLuongGD = 0;
}

/**
 * @brief Hàm hủy đối tượng Công ty để giải phóng hệ thống bộ nhớ động.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Kiểm tra sự tồn tại của mảng con trỏ DanhSachGD.
 *       2. Duyệt qua từng phần tử để giải phóng bộ nhớ của các đối tượng giao dịch con bằng toán tử `delete`.
 *       3. Tiến hành giải phóng mảng con trỏ gốc bằng toán tử `delete[]`.
 */
CCongTy::~CCongTy()
{
    if (DanhSachGD)
    {
        for (int i = 0; i < SoLuongGD; i++)
        {
            delete DanhSachGD[i];
        }
        delete[] DanhSachGD;
    }
}

/**
 * @brief Cấp phát vùng nhớ, lựa chọn phân loại và nhập danh sách các giao dịch bất động sản.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Nhận số lượng giao dịch thông qua hàm tiện ích NhapSoNguyenAnToan().
 *       2. Khởi tạo mảng con trỏ lớp cha `CGiaoDich*`.
 *       3. Chạy vòng lặp duyệt mảng, ép luồng chọn phân loại (1: Đất, 2: Nhà phố, 3: Căn hộ).
 *       4. Áp dụng cơ chế Đa hình để cấp phát vùng nhớ cho lớp con tương ứng, sau đó gọi phương thức Nhap() và TinhThanhTien() đồng bộ.
 */
void CCongTy::NhapDanhSach()
{
    cout << "Nhap so luong giao dich: ";
    SoLuongGD = NhapSoNguyenAnToan();

    DanhSachGD = new CGiaoDich *[SoLuongGD];
    cout << "--Tien hanh giao dich---\n";
    cout << "Cac lua chon giao dich:\n1: Giao dich Dat\n2: Giao dich Nha pho\n3: Giao dich can ho chung cu\n";
    for (int i = 0; i < SoLuongGD; i++)
    {
        cout << "---Giao dich thu " << i + 1 << "---\n";
        cout << "Nhap lua chon: ";
        int choose;
        while (true)
        {
            choose = NhapSoNguyenAnToan();
            if (choose >= 1 && choose <= 3)
            {
                break;
            }
            cout << "Lua chon khong hop le!\nVui long nhap lai (1->3): ";
        }
        if (choose == 1)
        {
            DanhSachGD[i] = new CGiaoDichDat();
        }
        else if (choose == 2)
        {
            DanhSachGD[i] = new CGiaoDichNhaPho();
        }
        else
        {
            DanhSachGD[i] = new CGiaoDichCanHo();
        }
        DanhSachGD[i]->Nhap();
    }
    for (int i = 0; i < SoLuongGD; i++)
    {
        DanhSachGD[i]->TinhThanhTien();
    }
}

/**
 * @brief Lọc và xuất danh sách giao dịch phân tách theo từng loại bất động sản.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Kiểm tra nếu số lượng bằng 0 thì báo danh sách rỗng và kết thúc.
 *       2. Sử dụng kỹ thuật RTTI với toán tử `dynamic_cast` để nhận diện chính xác kiểu thực thể lớp con trong mảng con trỏ lớp cha.
 *       3. Thực hiện 3 vòng lặp tuần tự để xuất riêng nhóm Giao dịch đất, Giao dịch nhà phố và Giao dịch căn hộ.
 */
void CCongTy::XuatDanhSach()
{
    cout << "\n---Danh sach giao dich---\n";
    if (SoLuongGD == 0)
    {
        cout << "Danh sach rong!\n";
        return;
    }
    cout << "===Giao dich dat===\n";
    for (int i = 0; i < SoLuongGD; i++)
    {
        if (dynamic_cast<CGiaoDichDat *>(DanhSachGD[i]) != nullptr)
        {
            DanhSachGD[i]->Xuat();
        }
    }

    cout << "===Giao dich nha pho===\n";
    for (int i = 0; i < SoLuongGD; i++)
    {
        if (dynamic_cast<CGiaoDichNhaPho *>(DanhSachGD[i]) != nullptr)
        {
            DanhSachGD[i]->Xuat();
        }
    }

    cout << "===Giao dich can ho===\n";
    for (int i = 0; i < SoLuongGD; i++)
    {
        if (dynamic_cast<CGiaoDichCanHo *>(DanhSachGD[i]) != nullptr)
        {
            DanhSachGD[i]->Xuat();
        }
    }
}

/**
 * @brief Thống kê tổng số lượng giao dịch đã thực hiện theo từng loại biến thể.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Khởi tạo lại biến đếm, sử dụng `dynamic_cast` duyệt qua mảng danh sách để phân loại và cộng dồn số lượng thực thể của riêng từng lớp con (`CGiaoDichDat`, `CGiaoDichNhaPho`, `CGiaoDichCanHo`).
 */
void CCongTy::ThongKeSoLuongTungLoai()
{
    cout << "\n---Danh sach so luong giao dich---\n";
    if (SoLuongGD == 0)
    {
        cout << "Danh sach rong!\n";
        return;
    }
    cout << "So luong giao dich dat: ";
    int count = 0;
    for (int i = 0; i < SoLuongGD; i++)
    {
        if (dynamic_cast<CGiaoDichDat *>(DanhSachGD[i]) != nullptr)
        {
            count++;
        }
    }
    cout << count << "\n";
    cout << "So luong giao dich nha pho: ";
    count = 0;
    for (int i = 0; i < SoLuongGD; i++)
    {
        if (dynamic_cast<CGiaoDichNhaPho *>(DanhSachGD[i]) != nullptr)
        {
            count++;
        }
    }
    cout << count << "\n";
    cout << "So luong giao dich can ho: ";
    count = 0;
    for (int i = 0; i < SoLuongGD; i++)
    {
        if (dynamic_cast<CGiaoDichCanHo *>(DanhSachGD[i]) != nullptr)
        {
            count++;
        }
    }
    cout << count << "\n";
}

/**
 * @brief Tính giá trị thành tiền trung bình của tất cả giao dịch thuộc khối căn hộ chung cư.
 * @param Không có.
 * @return Giá trị trung bình thành tiền (double), hoặc trả về -1 nếu danh sách không có căn hộ nào.
 * @note Giải thuật:
 *       1. Duyệt mảng danh sách, dùng `dynamic_cast` lọc ra các đối tượng thuộc lớp `CGiaoDichCanHo`.
 *       2. Cộng dồn tiền qua hàm getThanhTien() vào biến sum và tăng biến đếm count.
 *       3. Trả về kết quả thương số của phép chia `sum / count` nếu tìm thấy căn hộ.
 */
double CCongTy::TinhTrungBinhThanhTienCuaCanHo()
{
    cout << "\n--Tinh trung binh thanh tien can ho---\n";
    double sum = 0;
    int count = 0;
    for (int i = 0; i < SoLuongGD; i++)
    {
        if (dynamic_cast<CGiaoDichCanHo *>(DanhSachGD[i]) != nullptr)
        {
            sum += DanhSachGD[i]->getThanhTien();
            count++;
        }
    }
    if (count == 0)
    {
        return -1;
    }
    else
    {
        return sum / count;
    }
}

/**
 * @brief Tìm kiếm và hiển thị danh sách các giao dịch nhà phố có giá trị thành tiền cao nhất.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Áp dụng kỹ thuật lính canh: Duyệt mảng tìm thực thể `CGiaoDichNhaPho` đầu tiên làm mốc giá trị cao nhất.
 *       2. Quét toàn bộ danh sách để cập nhật lại mốc giá trị cao nhất nếu phát hiện giao dịch nhà phố có thành tiền lớn hơn.
 *       3. Chạy vòng lặp cuối cùng để in toàn bộ các giao dịch nhà phố có giá trị bằng mốc cực đại (để tránh bỏ sót trường hợp đồng giải nhất).
 */
void CCongTy::NhaPhoGiaTriCaoNhat()
{
    cout << "\n---Giao dich nha pho co gia tri cao nhat---\n";
    if (SoLuongGD == 0)
    {
        cout << "Danh sach rong!\n\n";
        return;
    }
    CGiaoDich *temp = DanhSachGD[0];
    bool isFound = false;
    if (dynamic_cast<CGiaoDichNhaPho *>(temp) != nullptr)
    {
        isFound = true;
    }
    for (int i = 1; i < SoLuongGD; i++)
    {
        if (dynamic_cast<CGiaoDichNhaPho *>(DanhSachGD[i]) != nullptr)
        {
            if (DanhSachGD[i]->getThanhTien() > temp->getThanhTien())
            {
                isFound = true;
                temp = DanhSachGD[i];
            }
        }
    }
    if (isFound)
    {
        for (int i = 0; i < SoLuongGD; i++)
        {
            if (dynamic_cast<CGiaoDichNhaPho *>(DanhSachGD[i]) != nullptr)
            {
                if (DanhSachGD[i]->getThanhTien() == temp->getThanhTien())
                {
                    DanhSachGD[i]->Xuat();
                    cout << "\n";
                }
            }
        }
    }
    else
    {
        cout << "Khong co giao dich nha pho!\n\n";
    }
}

/**
 * @brief Lọc và in ra toàn bộ giao dịch diễn ra trong mốc thời gian cụ thể (Tháng 12 Năm 2024).
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Duyệt qua mảng con trỏ, liên kết chuỗi dữ liệu truy xuất qua hàm `getNgayGiaoDich().getNam()` và `getThang()` của lớp cha để đối chiếu điều kiện lọc số học, hiển thị thông tin nếu trùng khớp.
 */
void CCongTy::XuatDanhSachThang12Nam2024()
{
    cout << "---Danh sach giao dich Thang 12 Nam 2024---\n";
    if (SoLuongGD == 0)
    {
        cout << "Danh sach rong!\n";
        return;
    }
    bool isFound = false;
    for (int i = 0; i < SoLuongGD; i++)
    {
        if (DanhSachGD[i]->getNgayGiaoDich().getNam() == 2024 && DanhSachGD[i]->getNgayGiaoDich().getThang() == 12)
        {
            isFound = true;
            DanhSachGD[i]->Xuat();
            cout << "\n";
        }
    }
    if (!isFound)
    {
        cout << "Khong co giao dich nao o thang 12 nam 2024\n";
    }
}