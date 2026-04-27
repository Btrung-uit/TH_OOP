#include "cNhanVienSX.h"
#include <iostream>
#include <iomanip>

using namespace std;

cNhanVienSX::cNhanVienSX()
{
    maNV = "";
    hoTen = "";
    soSanPham = 0;
    donGia = 0.0;
}

string cNhanVienSX::getMaNV()
{
    return maNV;
}

void cNhanVienSX::setMaNV(string m)
{
    maNV = m;
}

string cNhanVienSX::getHoTen()
{
    return hoTen;
}

void cNhanVienSX::setHoTen(string ht)
{
    hoTen = ht;
}

int cNhanVienSX::getSoSanPham()
{
    return soSanPham;
}

void cNhanVienSX::setSoSanPham(int sp)
{
    soSanPham = sp;
}

double cNhanVienSX::getDonGia()
{
    return donGia;
}

void cNhanVienSX::setDonGia(double dg)
{
    donGia = dg;
}

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

double cNhanVienSX::TinhLuong()
{
    return soSanPham * donGia;
}

int cNhanVienSX::getTuoi(int namHienTai)
{
    return namHienTai - ngaySinh.getNam();
}