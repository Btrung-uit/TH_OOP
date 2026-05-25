#pragma once
#include "CKhachHang.h"

class CCongTyXYZ
{
private:
    CKhachHang **DanhSach;
    int x, y, z;
    int TongSoLuong;
    void GiaiPhongBoNho();

public:
    CCongTyXYZ();
    ~CCongTyXYZ();
    void XuLyDuLieu();
};