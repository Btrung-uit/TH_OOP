#pragma once
#include <iostream>
#include "CVector.h" // Dùng để nhận diện CVector

class CMatrix
{
private:
    int m; // Số hàng
    int n; // Số cột
    double **phanTu;

public:
    CMatrix();
    CMatrix(int hang, int cot);
    ~CMatrix();
    CMatrix(const CMatrix &khac);

    CMatrix &operator=(const CMatrix &khac);

    // Phép toán với số thực
    CMatrix operator+(double k) const;
    CMatrix operator-(double k) const;
    CMatrix operator*(double k) const;
    CMatrix operator/(double k) const;

    // Phép toán với Ma trận
    CMatrix operator+(const CMatrix &khac) const;
    CMatrix operator-(const CMatrix &khac) const;
    CMatrix operator*(const CMatrix &khac) const;

    // Phép toán với Vector

    CVector operator*(const CVector &v) const;

    friend std::istream &operator>>(std::istream &is, CMatrix &mat);
    friend std::ostream &operator<<(std::ostream &os, const CMatrix &mat);
};