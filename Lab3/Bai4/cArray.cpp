#include <iostream>
#include <iomanip>
#include <cstdlib> // Chứa hàm rand(), srand()
#include <ctime>   // Chứa hàm time()
#include <cmath>
#include "cArray.h"
using namespace std;
/**
 * @brief Kiểm tra một số có phải là số nguyên tố hay không.
 * @param x: Số nguyên cần kiểm tra.
 * @return true nếu là số nguyên tố, false nếu không phải.
 * @note Giải thuật:
 *       1. Nếu x < 2, kết luận không phải số nguyên tố.
 *       2. Duyệt từ 2 đến căn bậc hai của x.
 *       3. Nếu x chia hết cho bất kỳ số nào trong khoảng đó, trả về false.
 */
bool cArray::KiemTraSoNguyenTo(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
/**
 * @brief Hàm khởi tạo mặc định.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Thiết lập kích thước mảng n = 0 và gán con trỏ array về nullptr.
 */
cArray::cArray()
{
    n = 0;
    array = nullptr;
}
/**
 * @brief Hàm khởi tạo với số lượng phần tử xác định.
 * @param soLuong: Số phần tử của mảng.
 * @return Không có.
 * @note Giải thuật: Gán n = soLuong và cấp phát mảng động tương ứng bằng toán tử new.
 */
cArray::cArray(int soLuong)
{
    n = soLuong;
    array = new int[n];
}
/**
 * @brief Hàm hủy đối tượng.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Kiểm tra nếu mảng đã được cấp phát thì dùng delete[] để giải phóng bộ nhớ.
 */
cArray::~cArray()
{
    if (array)
        delete[] array;
}
/**
 * @brief Tạo giá trị ngẫu nhiên cho các phần tử trong mảng.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Sử dụng srand(time(0)) để tạo hạt giống ngẫu nhiên theo thời gian.
 *       2. Duyệt qua mảng và dùng hàm rand() để gán giá trị trong đoạn [-99, 99].
 */
void cArray::TaoMangNgauNhien()
{
    cout << "Nhap so luong phan tu trong mang: ";
    while (cin >> n)
    {
        if (n > 0)
            break;
        cout << "So luong phan tu khong hop le!\nVui long nhap lai: ";
    }
    if (array)
        delete[] array;
    array = new int[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        array[i] = -99 + rand() % (99 - (-99) + 1);
    }
    cout << "Da khoi tao mang thanh cong!\n";
}
/**
 * @brief Xuất các phần tử của mảng ra màn hình.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Sử dụng vòng lặp for duyệt từ đầu đến cuối mảng và in từng giá trị.
 */
void cArray::XuatMang()
{
    cout << "Mang: ";
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && i % 7 == 0)
        {
            cout << "\n      ";
        }
        cout << setw(4) << array[i] << " ";
    }
    cout << "\n";
}
/**
 * @brief Đếm số lần xuất hiện của một giá trị x trong mảng.
 * @param x: Giá trị cần đếm.
 * @return Số lần xuất hiện (int).
 * @note Giải thuật: Sử dụng biến đếm count, duyệt qua mảng, mỗi lần gặp giá trị
 *                   bằng x thì tăng count lên 1.
 */
int cArray::DemSoLanXuatHien(int x)
{
    if (!array)
        return 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] == x)
            count++;
    }
    return count;
}
/**
 * @brief Kiểm tra xem các phần tử trong mảng có tăng dần hay không.
 * @param Không có.
 * @return true nếu mảng tăng dần, false nếu có bất kỳ phần tử nào vi phạm.
 * @note Giải thuật: Duyệt mảng từ phần tử đầu đến kế cuối, nếu thấy phần tử hiện
 *                   tại lớn hơn phần tử đứng sau thì trả về false ngay lập tức.
 */
bool cArray::KiemTraTangDan()
{
    for (int i = 0; i < n - 1; i++)
    {
        if (array[i] > array[i + 1])
            return false;
    }
    return true;
}
/**
 * @brief Tìm số lẻ nhỏ nhất trong mảng.
 * @param Không có.
 * @return Giá trị số lẻ nhỏ nhất, hoặc 0 nếu không tìm thấy số lẻ nào.
 * @note Giải thuật:
 *       1. Duyệt mảng tìm số lẻ đầu tiên để làm giá trị lính canh (minOdd).
 *       2. Tiếp tục duyệt các phần tử còn lại, nếu gặp số lẻ nhỏ hơn minOdd thì cập nhật lại.
 */
int cArray::TimLeNhoNhat()
{
    int minOdd;
    bool isFound = false;
    for (int i = 0; i < n; i++)
    {
        if (abs(array[i]) % 2 != 0)
        {
            if (!isFound)
            {
                minOdd = array[i];
                isFound = true;
            }
            else if (array[i] < minOdd)
            {
                minOdd = array[i];
            }
        }
    }
    return isFound ? minOdd : 0;
}
/**
 * @brief Tìm số nguyên tố lớn nhất trong mảng.
 * @param Không có.
 * @return Số nguyên tố lớn nhất tìm được, hoặc -1 nếu không có số nguyên tố nào.
 * @note Giải thuật: Duyệt qua mảng, gọi hàm KiemTraSoNguyenTo cho từng phần tử.
 *                   Nếu là số nguyên tố và lớn hơn giá trị maxPrime hiện tại thì cập nhật.
 */
int cArray::TimSoNguyenToLonNhat()
{
    int maxPrime = -1;
    for (int i = 0; i < n; i++)
    {
        if (KiemTraSoNguyenTo(array[i]))
        {
            if (maxPrime == -1 || maxPrime < array[i])
                maxPrime = array[i];
        }
    }
    return maxPrime;
}
/**
 * @brief Sắp xếp các phần tử trong mảng theo thứ tự tăng dần.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Sử dụng thuật toán Interchange Sort (Đổi chỗ trực tiếp) với 2 vòng
 *                   lặp lồng nhau để so sánh và hoán vị các cặp phần tử.
 */
void cArray::SapXepTangDan()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[i] > array[j])
                swap(array[i], array[j]);
        }
    }
    cout << "Da sap xep theo thu tu tang dan!\n";
}
/**
 * @brief Sắp xếp các phần tử trong mảng theo thứ tự giảm dần.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật: Sử dụng thuật toán Interchange Sort với điều kiện so sánh ngược lại
 *                   để đẩy các giá trị lớn lên đầu mảng.
 */
void cArray::SapXepGiamDan()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[i] < array[j])
                swap(array[i], array[j]);
        }
    }
    cout << "Da sap xep theo thu tu giam dan!\n";
}