#pragma once
#include <iostream>
using namespace std;

class CVector
{
private:
    int n;
    double *thanhPhan;

public:
    CVector();
    CVector(int);
    ~CVector();
    CVector(const CVector &);

    CVector &operator=(const CVector &);
    CVector operator+(const CVector &) const;
    CVector operator-(const CVector &) const;
    double operator*(const CVector &) const;
    CVector operator*(double) const;

    friend istream &operator>>(istream &is, CVector &p);
    friend ostream &operator<<(ostream &os, const CVector &p);
};