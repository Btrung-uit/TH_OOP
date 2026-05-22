#pragma once
#include "CGiaoDich.h"
#include <string>

class CGiaoDichCanHo : public CGiaoDich
{
private:
    std::string MaCan;
    int ViTriTang;
public:
    void Nhap() override;
    void Xuat() override;
    void TinhThanhTien() override;
};