#pragma once

class cArray
{
private:
    int n;
    int *array;
    bool KiemTraSoNguyenTo(int);

public:
    cArray();
    cArray(int);
    ~cArray();
    void TaoMangNgauNhien();
    void XuatMang();
    int DemSoLanXuatHien(int);
    bool KiemTraTangDan();
    int TimLeNhoNhat();
    int TimSoNguyenToLonNhat();
    void SapXepTangDan();
    void SapXepGiamDan();
};