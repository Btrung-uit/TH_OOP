#include "CMatrix.h"
#include <stdexcept>
#include <iomanip>

using namespace std;
// === QUẢN LÝ BỘ NHỚ ===

/**
 * @brief Hàm khởi tạo mặc định cho đối tượng ma trận.
 * @param Không có.
 * @return Không có.
 */
CMatrix::CMatrix() : m(0), n(0), phanTu(nullptr) {}

/**
 * @brief Hàm khởi tạo ma trận với số hàng và số cột xác định.
 * @param hang: Số lượng hàng của ma trận.
 * @param cot: Số lượng cột của ma trận.
 * @return Không có.
 */
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

/**
 * @brief Hàm hủy đối tượng ma trận để giải phóng bộ nhớ động.
 * @param Không có.
 * @return Không có.
 * @note Giải thuật:
 *       1. Duyệt qua từng hàng để giải phóng bộ nhớ của mảng một chiều (các cột).
 *       2. Giải phóng mảng con trỏ quản lý các hàng.
 */
CMatrix::~CMatrix()
{
    if (phanTu)
    {
        for (int i = 0; i < m; i++)
            delete[] phanTu[i];
        delete[] phanTu;
    }
}

/**
 * @brief Hàm khởi tạo sao chép (Copy Constructor) tạo bản sao độc lập từ ma trận
 *        khác.
 * @param khac: Đối tượng ma trận nguồn cần sao chép.
 * @return Không có.
 */
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

/**
 * @brief Nạp chồng toán tử gán để sao chép sâu dữ liệu giữa hai ma trận.
 * @param khac: Đối tượng ma trận nguồn.
 * @return CMatrix&: Tham chiếu đến đối tượng hiện tại sau khi gán.
 * @note Giải thuật:
 *       1. Kiểm tra tự gán (this != &khac).
 *       2. Giải phóng toàn bộ bộ nhớ cũ của ma trận hiện tại.
 *       3. Cấp phát vùng nhớ mới và sao chép từng phần tử từ ma trận nguồn sang.
 */
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

/**
 * @brief Cộng ma trận với một số thực k.
 * @param k: Số thực cần cộng vào từng phần tử.
 * @return CMatrix: Ma trận kết quả sau khi cộng.
 * @note Giải thuật: Duyệt qua từng phần tử tại vị trí [i][j] và thực hiện phép
 *       cộng với k.
 */
CMatrix CMatrix::operator+(double k) const
{
    CMatrix temp(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            temp.phanTu[i][j] = phanTu[i][j] + k;
    return temp;
}

/**
 * @brief Trừ ma trận cho một số thực k.
 * @param k: Số thực cần trừ đi từ từng phần tử.
 * @return CMatrix: Ma trận kết quả sau khi trừ.
 * @note Giải thuật: Duyệt qua từng phần tử tại vị trí [i][j] và thực hiện phép
 *       trừ cho k.
 */
CMatrix CMatrix::operator-(double k) const
{
    CMatrix temp(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            temp.phanTu[i][j] = phanTu[i][j] - k;
    return temp;
}

/**
 * @brief Nhân ma trận với một số thực k.
 * @param k: Hệ số tỉ lệ cần nhân.
 * @return CMatrix: Ma trận mới sau khi nhân hệ số.
 * @note Giải thuật: Duyệt qua từng phần tử tại vị trí [i][j] và nhân với k.
 */
CMatrix CMatrix::operator*(double k) const
{
    CMatrix temp(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            temp.phanTu[i][j] = phanTu[i][j] * k;
    return temp;
}

/**
 * @brief Chia từng phần tử của ma trận cho một số thực k.
 * @param k: Số thực thực hiện phép chia (k phải khác 0).
 * @return CMatrix: Ma trận mới sau khi chia.
 * @note Giải thuật:
 *       1. Kiểm tra k có bằng 0 hay không để ném ngoại lệ lỗi.
 *       2. Duyệt qua từng phần tử và thực hiện phép chia cho k.
 */
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

/**
 * @brief Cộng hai ma trận cùng kích thước.
 * @param khac: Ma trận thứ hai tham gia phép cộng.
 * @return CMatrix: Ma trận tổng.
 * @note Giải thuật:
 *       1. Kiểm tra điều kiện cùng số hàng và số cột.
 *       2. Cộng các phần tử tương ứng tại từng vị trí [i][j].
 */
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

/**
 * @brief Trừ hai ma trận cùng kích thước.
 * @param khac: Ma trận bị trừ.
 * @return CMatrix: Ma trận hiệu.
 * @note Giải thuật:
 *       1. Kiểm tra điều kiện tương thích kích thước.
 *       2. Trừ các phần tử tương ứng tại từng vị trí [i][j].
 */
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

/**
 * @brief Nạp chồng toán tử nhân hai ma trận (Matrix Multiplication).
 * @param khac: Đối tượng ma trận thứ hai tham gia phép nhân.
 * @return CMatrix: Ma trận tích có kích thước (hàng_1 x cột_2).
 * @note Giải thuật:
 *       1. Kiểm tra điều kiện nhân: Số cột ma trận 1 phải bằng số hàng ma trận 2.
 *       2. Sử dụng 3 vòng lặp lồng nhau:
 *          - Vòng lặp i, j để định vị phần tử tại hàng i, cột j của ma trận tích.
 *          - Vòng lặp k để tính tổng các tích của hàng i (ma trận 1) và cột j
 *            (ma trận 2).
 */
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

/**
 * @brief Nạp chồng toán tử nhân ma trận với một vector.
 * @param v: Đối tượng CVector tham gia phép nhân.
 * @return CVector: Một vector kết quả có số chiều bằng số hàng của ma trận.
 * @note Giải thuật:
 *       1. Kiểm tra điều kiện: Số cột của ma trận phải bằng số chiều của vector.
 *       2. Thực hiện nhân từng hàng của ma trận với vector để tạo ra từng thành phần
 *          tương ứng của vector kết quả.
 */
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

/**
 * @brief Nạp chồng toán tử nhập luồng để cấu hình kích thước và dữ liệu phần tử ma trận.
 * @param is: Tham chiếu đến đối tượng luồng nhập (istream).
 * @param mat: Tham chiếu đến đối tượng CMatrix cần lưu trữ dữ liệu.
 * @return istream&: Trả về tham chiếu của luồng nhập.
 * @note Giải thuật:
 *       1. Nhập số hàng m và số cột n thông qua hàm NhapHopLeSoNguyen().
 *       2. Giải phóng bộ nhớ động cũ của mảng hai chiều phanTu để chống rò rỉ.
 *       3. Cấp phát mảng con trỏ mới cho m hàng, sau đó cấp phát mảng một chiều cho
 *          từng n cột.
 *       4. Dùng vòng lặp lồng nhau kết hợp hàm KiemTraSoThuc() để điền giá trị cho
 *          từng ô [i][j].
 */
istream &operator>>(istream &is, CMatrix &mat)
{
    cout << "Nhap so hang m: ";
    mat.m = NhapHopLeSoNguyen(is);
    cout << "Nhap so cot n: ";
    mat.n = NhapHopLeSoNguyen(is);

    if (mat.phanTu)
    {
        for (int i = 0; i < mat.m; i++)
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

/**
 * @brief Nạp chồng toán tử xuất luồng để in ma trận ra màn hình dưới dạng bảng.
 * @param os: Tham chiếu đến đối tượng luồng xuất (ostream).
 * @param mat: Tham chiếu hằng đến đối tượng CMatrix cần hiển thị.
 * @return ostream&: Trả về tham chiếu của luồng xuất.
 * @note Giải thuật:
 *       1. Kiểm tra nếu ma trận rỗng thì thông báo "Ma tran rong".
 *       2. Sử dụng vòng lặp lồng nhau in các phần tử theo hàng và cột.
 *       3. Dùng `setw(8)` để căn chỉnh các con số thẳng hàng theo cột giúp dễ
 *          quan sát.
 */
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