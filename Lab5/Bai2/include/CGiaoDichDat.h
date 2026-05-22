#pragma once
#include "../include/CGiaoDich.h"
class CGiaoDichDat : public CGiaoDich
{
private:
    char LoaiDat;
public:
    void Nhap() override;
    void Xuat() override;
    void TinhThanhTien() override;
};