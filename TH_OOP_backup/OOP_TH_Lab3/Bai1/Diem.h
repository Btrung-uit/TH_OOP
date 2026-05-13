#pragma once
class Diem
{
private:
    double x, y;

public:
    Diem();
    Diem(double, double);
    ~Diem(void);
    void NhapDiem();
    void XuatDiem();
    void DatX(double);
    void DatY(double);
    double LayX();
    double LayY();
    double TinhKhoangCach(Diem);
};