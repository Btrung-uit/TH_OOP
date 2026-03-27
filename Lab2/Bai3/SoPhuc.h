#ifndef SOPHUC_H
#define SOPHUC_H

class SoPhuc {
private:
    double iThuc;
    double iAo;
public:
    void Nhap();
    void Xuat();
    
    SoPhuc TinhTong(SoPhuc a);
    SoPhuc TinhHieu(SoPhuc a);
    SoPhuc TinhTich(SoPhuc a);
    SoPhuc TinhThuong(SoPhuc a);
    //Hàm kiểm tra số 0
    bool LaSoKhong();
};
#endif