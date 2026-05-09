#include "cSoPhuc.h"
#include <iostream>
#include <cmath>
using namespace std;

cSoPhuc::cSoPhuc(double t, double a)
{
    thuc = t;
    ao = a;
}

// toán tử toán học
cSoPhuc cSoPhuc::operator+(const cSoPhuc &khac) const
{
    return cSoPhuc(thuc + khac.thuc, ao + khac.ao);
}
cSoPhuc cSoPhuc::operator-(const cSoPhuc &khac) const
{
    return cSoPhuc(thuc - khac.thuc, ao - khac.ao);
}
cSoPhuc cSoPhuc::operator*(const cSoPhuc &khac) const
{
    double thucMoi = thuc * khac.thuc - ao * khac.ao;
    double aoMoi = thuc * khac.ao + ao * khac.thuc;
    return cSoPhuc(thucMoi, aoMoi);
}
cSoPhuc cSoPhuc::operator/(const cSoPhuc &khac) const
{
    double mauSo = khac.thuc * khac.thuc + khac.ao * khac.ao;
    if (mauSo == 0)
        return cSoPhuc(0, 0);
    double thucMoi = (thuc * khac.thuc + ao * khac.ao) / mauSo;
    double aoMoi = (ao * khac.thuc - thuc * khac.ao) / mauSo;
    return cSoPhuc(thucMoi, aoMoi);
}

// toán thử so sánh
bool cSoPhuc::operator==(const cSoPhuc &khac) const
{
    return (thuc == khac.thuc && ao == khac.ao);
}
bool cSoPhuc::operator!=(const cSoPhuc &khac) const
{
    return !(*this == khac);
}
double NhapHopLe(istream &is)
{
    double so;
    while (true)
    {
        if (is >> so)
            return so;
        cout << "Gia tri khong hop le!\nVui long nhap so thuc!\nNhap lai: ";
        is.clear();
        is.ignore(10000, '\n');
    }
}
istream &operator>>(istream &is, cSoPhuc &sp)
{
    cout << "Nhap phan tu thuc: ";
    sp.thuc = NhapHopLe(is);
    cout << "Nhap phan tu ao: ";
    sp.ao = NhapHopLe(is);
    return is;
}
ostream &operator<<(ostream &os, const cSoPhuc &sp)
{
    if (sp.thuc == 0 && sp.ao == 0)
    {
        os << 0;
        return os;
    }
    if (sp.thuc != 0)
    {
        os << sp.thuc;
    }
    if (sp.ao != 0)
    {
        if (sp.ao > 0 && sp.thuc != 0)
        {
            os << " + ";
        }
        else if (sp.ao < 0 && sp.thuc != 0)
        {
            os << " - ";
        }
        else if (sp.ao < 0 && sp.thuc == 0)
        {
            os << "-";
        }
        if (abs(sp.ao) != 1)
        {
            os << abs(sp.ao);
        }
        os << "i";
    }
    return os;
}
