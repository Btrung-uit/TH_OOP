#include "cSoPhuc.h"
#include <iostream>
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
    return cSoPhuc(thuc - khac.thuc, ao - khac.ao);
}
cSoPhuc cSoPhuc::operator/(const cSoPhuc &khac) const
{
    double mauSo = khac.thuc * khac.thuc + khac.ao * khac.ao;
    if (mauSo == 0)
        return cSoPhuc(0, 0);
    double thucMoi = (ao * khac.thuc + thuc * khac.ao) / mauSo;
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
istream &operator>>(istream &is, cSoPhuc &sp)
{
    cout << "Nhap phan tu thuc: ";
    cin >> sp.thuc;
    cout << "Nhap phan tu ao: ";
    cin >> sp.ao;
    return is;
}
ostream &operator<<(ostream &os, const cSoPhuc &sp)
{
    if (sp.thuc == 0 && sp.ao == 0)
    {
        cout << 0;
    }
    else if (sp.thuc == 0)
    {
        os << sp.ao << "i";
    }
    else if (sp.ao == 0)
    {
        os << sp.thuc;
    }
    else
    {
        os << sp.thuc;
        if (sp.ao > 0)
        {
            os << " + " << sp.ao << "i";
        }
        else
        {
            os << " - " << -sp.ao << "i";
        }
    }
    return os;
}
