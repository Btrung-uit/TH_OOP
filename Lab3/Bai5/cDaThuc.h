#pragma once

class cDaThuc
{
private:
    int n;
    double *heSo;

public:
    cDaThuc();
    cDaThuc(int);
    ~cDaThuc();
    void Nhap();
    void Xuat();
    double TinhGiaTri(double);
    cDaThuc Cong(cDaThuc &);
    cDaThuc Tru(cDaThuc &);
    cDaThuc(const cDaThuc &);
    cDaThuc &operator=(const cDaThuc &);
};