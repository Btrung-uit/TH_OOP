#pragma once
#include "CSinhVien.h"

class CQuanLyUIT
{
private:
    CSinhVien **DanhSachSV; 
    int SoLuongSV;          

public:
    CQuanLyUIT();
    ~CQuanLyUIT();

    void NhapDanhSach();                          
    void XuatDanhSach() const;                    
    void XuatDS_DuDieuKienTotNghiep() const;      
    void XuatDS_KhongDuDieuKienTotNghiep() const; 
    void TimSVDaiHoc_DiemMax() const;             
    void TimSVCaoDang_DiemMax() const;            
    void ThongKeKhongTotNghiepTungHe() const;     
};