#include <iostream>
#include <string>
using namespace std;

class Nguoi {
    public:
        string ten = "Trung";
        int namsinh;
};
class SV : public Nguoi {
    public:
    string ten = "SV";x
        string maSo;
};
int main() {
    SV sv1;
    cout << sv1.ten;
}