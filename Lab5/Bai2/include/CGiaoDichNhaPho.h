#pragma once
#include "CGiaoDich.h"
#include <string>

class CGiaoDichNhaPho : public CGiaoDich
{
private:
    std::string LoaiNha;
    std::string DiaChi;
public:
    void Nhap() override;
    void TinhThanhTien() override;
    void Xuat() override;
};