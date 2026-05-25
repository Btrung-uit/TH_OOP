#pragma once
#include "CKhachHang.h"

class CKhachHangB : public CKhachHang
{
private:
    int SoNamThanThiet;

public:
    CKhachHangB();

    void DocFile(std::ifstream &in, bool &flag) override;
    double TinhTien() override;
};