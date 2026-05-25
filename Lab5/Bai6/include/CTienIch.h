#pragma once
#include <string>
#include <fstream>

class CTienIch
{
public:
    static std::string DocChuoiAnToan(std::ifstream &in);
    static std::string ChuanHoaTen(std::string ten);
    static std::string DinhDangTien(double tien);

    static int DocSoNguyen(std::ifstream &in, bool &trangThaiHopLe);
    static double DocSoThuc(std::ifstream &in, bool &trangThaiHopLe);
};