#include "../include/CQuanLyUIT.h"
#include "../include/CSV_CaoDang.h"
#include "../include/CSV_DaiHoc.h"
#include "../include/CTienIch.h"
#include <iostream>

using namespace std;

/**
 * @brief Hàm khởi tạo mặc định cho lớp Quản lý sinh viên UIT.
 * @param Không có.
 * @return Không có.
 */
CQuanLyUIT::CQuanLyUIT()
{
    DanhSachSV = nullptr;
    SoLuongSV = 0;
}

/**
 * @brief Hàm hủy đối tượng Quản lý để giải phóng hệ thống bộ nhớ động lồng nhau.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Kiểm tra sự tồn tại của mảng con trỏ DanhSachSV.
 *       2. Duyệt mảng và giải phóng độc lập từng thực thể sinh viên con (`CSV_CaoDang` hoặc `CSV_DaiHoc`) bằng toán tử `delete`.
 *       3. Giải phóng mảng con trỏ cấu trúc gốc bằng toán tử `delete[]`.
 */
CQuanLyUIT::~CQuanLyUIT()
{
    if (DanhSachSV != nullptr)
    {
        for (int i = 0; i < SoLuongSV; i++)
        {
            delete DanhSachSV[i];
        }
        delete[] DanhSachSV;
    }
}

/**
 * @brief Cấp phát vùng nhớ, lựa chọn hệ đào tạo và nhập danh sách toàn bộ sinh viên.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Nhận tổng số lượng sinh viên thông qua hàm tiện ích NhapSoNguyenAnToan().
 *       2. Cấp phát mảng động chứa các con trỏ lớp cha `CSinhVien*`.
 *       3. Quét vòng lặp duyệt mảng, ép người dùng chọn hệ đào tạo hợp lệ (1: Cao đẳng, 2: Đại học).
 *       4. Áp dụng tính chất Đa hình để liên kết động, khởi tạo đúng lớp con tương ứng và gọi phương thức Nhap() nội tại.
 */
void CQuanLyUIT::NhapDanhSach()
{
    cout << "Nhap tong so luong sinh vien can quan ly: ";
    SoLuongSV = NhapSoNguyenAnToan();

    DanhSachSV = new CSinhVien *[SoLuongSV];

    for (int i = 0; i < SoLuongSV; i++)
    {
        cout << "Nhap sinh vien thu " << i + 1 << "\n";
        cout << "Chon he dao tao:\n1: He Cao dang\n2: He Dai hoc\n";
        cout << "Vui long chon (1-2): ";

        int luaChon;
        while (true)
        {
            luaChon = NhapSoNguyenAnToan();
            if (luaChon == 1 || luaChon == 2)
                break;
            cout << "Lua chon khong hop le! Vui long nhap lai (1-2): ";
        }

        if (luaChon == 1)
        {
            DanhSachSV[i] = new CSV_CaoDang();
        }
        else
        {
            DanhSachSV[i] = new CSV_DaiHoc();
        }

        DanhSachSV[i]->Nhap();
    }
}

/**
 * @brief Xuất thông tin của tất cả sinh viên có trong danh sách quản lý.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Kiểm tra số lượng để in thông báo nếu rỗng, ngược lại dùng vòng lặp duyệt mảng gọi phương thức Xuat() đồng bộ thông qua cơ chế liên kết muộn của hàm ảo.
 */
void CQuanLyUIT::XuatDanhSach() const
{
    if (SoLuongSV == 0)
    {
        cout << "Danh sach sinh vien trong!\n";
        return;
    }
    cout << "\n---Danh sach tat ca sinh vien---\n";
    for (int i = 0; i < SoLuongSV; i++)
    {
        DanhSachSV[i]->Xuat();
    }
}

/**
 * @brief Lọc và hiển thị danh sách các sinh viên đạt điều kiện công nhận tốt nghiệp.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Duyệt mảng con trỏ lớp cha, gọi phương thức ảo KiemTraTotNghiep(). Nếu kết quả trả về là true thì tiến hành gọi hàm Xuat() hiển thị và bật biến cờ coSV để kiểm soát thông báo rỗng.
 */
void CQuanLyUIT::XuatDS_DuDieuKienTotNghiep() const
{
    cout << "\n---Danh sach sinh vien du dieu kien tot nghiep---\n";
    if (SoLuongSV == 0)
    {
        cout << "Danh sach sinh vien trong!\n";
        return;
    }
    bool coSV = false;
    for (int i = 0; i < SoLuongSV; i++)
    {
        if (DanhSachSV[i]->KiemTraTotNghiep() == true)
        {
            DanhSachSV[i]->Xuat();
            coSV = true;
        }
    }
    if (!coSV)
        cout << "Khong co sinh vien nao du dieu kien tot nghiep.\n";
}

/**
 * @brief Lọc và hiển thị danh sách các sinh viên chưa đạt điều kiện tốt nghiệp.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Quét toàn bộ danh sách, gọi phương thức ảo KiemTraTotNghiep(). Nếu trả về giá trị false thì thực hiện in thông tin sinh viên đó và cập nhật trạng thái biến cờ ghi nhận coSV.
 */
void CQuanLyUIT::XuatDS_KhongDuDieuKienTotNghiep() const
{
    cout << "\n---Danh sach sinh vien khong du dieu kien tot nghiep---\n";
    if (SoLuongSV == 0)
    {
        cout << "Danh sach sinh vien trong!\n";
        return;
    }
    bool coSV = false;
    for (int i = 0; i < SoLuongSV; i++)
    {
        if (DanhSachSV[i]->KiemTraTotNghiep() == false)
        {
            DanhSachSV[i]->Xuat();
            coSV = true;
        }
    }
    if (!coSV)
        cout << "Tat ca sinh vien deu da tot nghiep.\n";
}

/**
 * @brief Tìm kiếm và hiển thị danh sách sinh viên hệ Đại học có điểm trung bình cao nhất.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Quét danh sách lần một: Sử dụng toán tử `dynamic_cast` lọc ra các đối tượng thuộc hệ `CSV_DaiHoc`, ứng dụng kỹ thuật lính canh để tìm ra mức điểm trung bình lớn nhất (maxDiem).
 *       2. Kiểm tra nếu không có sinh viên Đại học nào thì in thông báo và kết thúc hàm.
 *       3. Quét danh sách lần hai: Sử dụng `dynamic_cast` đối chiếu kết hợp để hiển thị tất cả sinh viên Đại học có điểm số trùng khớp với giá trị maxDiem.
 */
void CQuanLyUIT::TimSVDaiHoc_DiemMax() const
{
    cout << "\n--- Sinh vien Dai hoc co Diem TB cao nhat ---\n";
    double maxDiem = -1.0;

    for (int i = 0; i < SoLuongSV; i++)
    {
        CSV_DaiHoc *svDH = dynamic_cast<CSV_DaiHoc *>(DanhSachSV[i]);
        if (svDH != nullptr)
        {
            if (svDH->getDiemTB() > maxDiem)
            {
                maxDiem = svDH->getDiemTB();
            }
        }
    }

    if (maxDiem == -1.0)
    {
        cout << "Khong co sinh vien Dai hoc nao trong danh sach.\n";
        return;
    }

    for (int i = 0; i < SoLuongSV; i++)
    {
        CSV_DaiHoc *svDH = dynamic_cast<CSV_DaiHoc *>(DanhSachSV[i]);
        if (svDH != nullptr && svDH->getDiemTB() == maxDiem)
        {
            svDH->Xuat();
        }
    }
}

/**
 * @brief Tìm kiếm và hiển thị danh sách sinh viên hệ Cao đẳng có điểm trung bình cao nhất.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Duyệt mảng danh sách lần một: Dùng toán tử `dynamic_cast` lọc riêng thực thể `CSV_CaoDang` để tìm giá trị cực đại của điểm trung bình qua kỹ thuật lính canh.
 *       2. Quét danh sách lần hai: Lọc trùng và in ra màn hình toàn bộ các sinh viên Cao đẳng có điểm số đạt đúng mức maxDiem vừa tìm được.
 */
void CQuanLyUIT::TimSVCaoDang_DiemMax() const
{
    cout << "\n--- Sinh vien Cao dang co Diem TB cao nhat ---\n";
    double maxDiem = -1.0;

    for (int i = 0; i < SoLuongSV; i++)
    {
        CSV_CaoDang *svCD = dynamic_cast<CSV_CaoDang *>(DanhSachSV[i]);
        if (svCD != nullptr)
        {
            if (svCD->getDiemTB() > maxDiem)
            {
                maxDiem = svCD->getDiemTB();
            }
        }
    }

    if (maxDiem == -1.0)
    {
        cout << "Khong co sinh vien Cao dang nao trong danh sach.\n";
        return;
    }

    for (int i = 0; i < SoLuongSV; i++)
    {
        CSV_CaoDang *svCD = dynamic_cast<CSV_CaoDang *>(DanhSachSV[i]);
        if (svCD != nullptr && svCD->getDiemTB() == maxDiem)
        {
            svCD->Xuat();
        }
    }
}

/**
 * @brief Thống kê số lượng sinh viên chưa đủ điều kiện tốt nghiệp phân tách chi tiết theo từng hệ đào tạo.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Khởi tạo hai biến đếm biệt lập demCD và demDH bằng 0.
 *       2. Duyệt qua mảng con trỏ lớp cha, lọc ra các sinh viên có hàm ảo KiemTraTotNghiep() trả về kết quả false.
 *       3. Ứng dụng RTTI với toán tử `dynamic_cast` để nhận diện phân loại hệ đào tạo, tiến hành tăng biến đếm tương ứng và in báo cáo.
 */
void CQuanLyUIT::ThongKeKhongTotNghiepTungHe() const
{
    int demCD = 0;
    int demDH = 0;

    for (int i = 0; i < SoLuongSV; i++)
    {

        if (DanhSachSV[i]->KiemTraTotNghiep() == false)
        {

            if (dynamic_cast<CSV_CaoDang *>(DanhSachSV[i]) != nullptr)
            {
                demCD++;
            }
            else if (dynamic_cast<CSV_DaiHoc *>(DanhSachSV[i]) != nullptr)
            {
                demDH++;
            }
        }
    }

    cout << "\n---Thong ke sinh vien khong tot nghiep---\n";
    cout << "+ He Cao dang: " << demCD << " sinh vien.\n";
    cout << "+ He Dai hoc : " << demDH << " sinh vien.\n";
}