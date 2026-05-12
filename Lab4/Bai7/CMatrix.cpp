#include "CMatrix.h"
#include <stdexcept>
#include <iomanip>

using namespace std;
// === QUẢN LÝ BỘ NHỚ ===
CMatrix::CMatrix() : m(0), n(0), phanTu(nullptr) {}

CMatrix::CMatrix(int hang, int cot) : m(hang), n(cot)
{
    if (m == 0 || n == 0)
    {
        phanTu = nullptr;
        return;
    }
    phanTu = new double *[m];
    for (int i = 0; i < m; i++)
    {
        phanTu[i] = new double[n];
        for (int j = 0; j < n; j++)
            phanTu[i][j] = 0;
    }
}

CMatrix::~CMatrix()
{
    if (phanTu)
    {
        for (int i = 0; i < m; i++)
            delete[] phanTu[i];
        delete[] phanTu;
    }
}

CMatrix::CMatrix(const CMatrix &khac) : m(khac.m), n(khac.n)
{
    if (m == 0 || n == 0)
    {
        phanTu = nullptr;
        return;
    }
    phanTu = new double *[m];
    for (int i = 0; i < m; i++)
    {
        phanTu[i] = new double[n];
        for (int j = 0; j < n; j++)
            phanTu[i][j] = khac.phanTu[i][j];
    }
}

CMatrix &CMatrix::operator=(const CMatrix &khac)
{
    if (this != &khac)
    {
        if (phanTu)
        {
            for (int i = 0; i < m; i++)
                delete[] phanTu[i];
            delete[] phanTu;
        }
        m = khac.m;
        n = khac.n;
        if (m == 0 || n == 0)
        {
            phanTu = nullptr;
            return *this;
        }
        phanTu = new double *[m];
        for (int i = 0; i < m; i++)
        {
            phanTu[i] = new double[n];
            for (int j = 0; j < n; j++)
                phanTu[i][j] = khac.phanTu[i][j];
        }
    }
    return *this;
}

// === PHÉP TOÁN VỚI SỐ THỰC ===
CMatrix CMatrix::operator+(double k) const
{
    CMatrix temp(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            temp.phanTu[i][j] = phanTu[i][j] + k;
    return temp;
}

CMatrix CMatrix::operator-(double k) const
{
    CMatrix temp(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            temp.phanTu[i][j] = phanTu[i][j] - k;
    return temp;
}

CMatrix CMatrix::operator*(double k) const
{
    CMatrix temp(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            temp.phanTu[i][j] = phanTu[i][j] * k;
    return temp;
}

CMatrix CMatrix::operator/(double k) const
{
    if (k == 0)
        throw invalid_argument("Loi! Khong the chia cho 0!");

    CMatrix temp(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            temp.phanTu[i][j] = phanTu[i][j] / k;
    return temp;
}

// === PHÉP TOÁN VỚI MA TRẬN ===
CMatrix CMatrix::operator+(const CMatrix &khac) const
{
    if (this->m != khac.m || this->n != khac.n)
        throw invalid_argument("Loi! 2 ma tran khong cung kich thuoc!");

    CMatrix temp(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            temp.phanTu[i][j] = phanTu[i][j] + khac.phanTu[i][j];
    return temp;
}

CMatrix CMatrix::operator-(const CMatrix &khac) const
{
    if (this->m != khac.m || this->n != khac.n)
        throw invalid_argument("Loi! 2 ma tran khong cung kich thuoc!");

    CMatrix temp(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            temp.phanTu[i][j] = phanTu[i][j] - khac.phanTu[i][j];
    return temp;
}

CMatrix CMatrix::operator*(const CMatrix &khac) const
{
    if (this->n != khac.m)
        throw invalid_argument("Loi! So cot cua ma tran 1 khong bang so hang cua ma tran 2!");

    CMatrix temp(this->m, khac.n);
    for (int i = 0; i < this->m; i++)
    {
        for (int j = 0; j < khac.n; j++)
        {
            double sum = 0;
            for (int k = 0; k < this->n; k++)
            {
                sum += this->phanTu[i][k] * khac.phanTu[k][j];
            }
            temp.phanTu[i][j] = sum;
        }
    }
    return temp;
}

// === PHÉP TOÁN VỚI VECTOR ===
CVector CMatrix::operator*(const CVector &v) const
{
    // CMatrix cần là friend của CVector để truy cập v.n và v.thanhPhan
    if (this->n != v.n)
        throw invalid_argument("Loi! So cot cua ma tran khong bang so hang cua vector!");

    // Kết quả của Ma trận (m x n) nhân Vector (n x 1) là Vector (m x 1)
    CVector temp(this->m);
    for (int i = 0; i < this->m; i++)
    {
        double sum = 0;
        for (int j = 0; j < this->n; j++)
        {
            sum += this->phanTu[i][j] * v.thanhPhan[j];
        }
        temp.thanhPhan[i] = sum;
    }
    return temp;
}

/**
 * @brief Nhập và ép luồng dữ liệu số nguyên lớn hơn hoặc bằng 0,
 *        chặn các ký tự rác đi kèm.
 * @param is: Tham chiếu đến đối tượng luồng nhập (istream).
 * @return Giá trị số nguyên hợp lệ duy nhất trích xuất được
 *         từ dòng nhập.
 * @note Giải thuật:
 *       1. Sử dụng vòng lặp vô hạn để ép nhập đúng kiểu dữ liệu.
 *       2. Dùng hàm is.peek() để quét kiểm tra toàn bộ các ký tự
 *          còn lại trên dòng sau số nguyên.
 *       3. Nếu phát hiện ký tự rác (không phải khoảng trắng, tab
 *          hay xuống dòng), đánh dấu chuỗi không hợp lệ và ép
 *          nhập lại.
 *       4. Dọn sạch cờ lỗi và bộ nhớ đệm luồng nếu dữ liệu sai
 *          quy chuẩn.
 */
int NhapHopLeSoNguyen(istream &is)
{
    int bac;
    while (true)
    {
        if (is >> bac && bac >= 0)
        {
            bool chuoiHopLe = true;
            char c;
            while (true)
            {
                c = is.peek();
                if (c == '\n' || c == EOF)
                    break;
                if (c != ' ' && c != '\t')
                    chuoiHopLe = false;
                is.get();
            }
            if (chuoiHopLe)
            {
                if (is.peek() == '\n')
                    is.get();
                return bac;
            }
        }
        cout << "Loi! So luong khong hop le!\nNhap lai: ";
        is.clear();
        is.ignore(10000, '\n');
    }
}

/**
 * @brief Nhập và ép luồng dữ liệu số thực, loại bỏ hoàn
 *        toàn các ký tự rác đi kèm.
 * @param is: Đối tượng luồng nhập (istream).
 * @return giaTri: double.
 * @note Giải thuật:
 *       1. Sử dụng vòng lặp vô hạn và đọc dữ liệu thông qua toán
 *          tử is >> giaTri.
 *       2. Sử dụng is.get(c) để quét từng ký tự còn lại trên
 *          cùng một dòng cho đến khi gặp ký tự xuống dòng (\n).
 *       3. Nếu phát hiện bất kỳ ký tự nào không phải khoảng trắng
 *          (' ') hoặc tab ('\t'), gán cờ chuoiHopLe = false để
 *          đánh dấu dòng nhập chứa ký tự rác
 *          (Ví dụ: nhập "3.14abc").
 *       4. Nếu chuỗi hợp lệ, thoát hàm để lưu giá trị. Ngược lại,
 *          tiến hành xóa cờ lỗi của stream, dọn sạch bộ nhớ đệm
 *          và yêu cầu người dùng nhập lại.
 */
double KiemTraSoThuc(istream &is)
{
    double giaTri;
    while (true)
    {
        if (is >> giaTri)
        {
            bool chuoiHopLe = true;
            char c;
            while (is.get(c) && c != '\n')
            {
                if (c != ' ' && c != '\t')
                {
                    chuoiHopLe = false;
                }
            }

            if (chuoiHopLe)
            {
                return giaTri;
            }
            cout << "Gia tri khong hop le!\nVui long nhap so thuc!\nNhap lai: ";
            continue;
        }
        cout << "Gia tri khong hop le!\nVui long nhap so thuc!\nNhap lai: ";
        is.clear();
        is.ignore(10000, '\n');
    }
}
// === NHẬP / XUẤT ===
istream &operator>>(istream &is, CMatrix &mat)
{
    cout << "Nhap so hang m: ";
    mat.m = NhapHopLeSoNguyen(is);
    cout << "Nhap so cot n: ";
    mat.n = NhapHopLeSoNguyen(is);

    if (mat.phanTu)
    {
        for (int i = 0; i < mat.m; i++) // Có nguy cơ rác nếu mat.m cũ khác mới, nhưng ta giả định khởi tạo sạch
            delete[] mat.phanTu[i];
        delete[] mat.phanTu;
    }

    if (mat.m == 0 || mat.n == 0)
    {
        mat.phanTu = nullptr;
        return is;
    }

    mat.phanTu = new double *[mat.m];
    for (int i = 0; i < mat.m; i++)
    {
        mat.phanTu[i] = new double[mat.n];
        for (int j = 0; j < mat.n; j++)
        {
            cout << "Nhap phan tu [" << i << "][" << j << "]: ";
            mat.phanTu[i][j] = KiemTraSoThuc(is);
        }
    }
    return is;
}

ostream &operator<<(ostream &os, const CMatrix &mat)
{
    if (mat.m == 0 || mat.n == 0)
    {
        os << "[Ma tran rong]";
        return os;
    }

    for (int i = 0; i < mat.m; i++)
    {
        os << "[ ";
        for (int j = 0; j < mat.n; j++)
        {
            os << setw(8) << mat.phanTu[i][j] << " ";
        }
        os << "]\n";
    }
    return os;
}