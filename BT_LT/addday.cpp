#include <iostream>
using namespace std;
struct Date {
    int ngay, thang, nam;
};
bool namnhuan(int nam) {
    return (nam % 400 == 0) || ((nam % 4 == 0) && nam % 100 != 0); 
}
void addday(Date &hientai) {
    hientai.ngay += 7;
    int thang = hientai.thang;
    int ngay_max;
    if(thang == 2) {
        if(namnhuan(hientai.nam)) {
            ngay_max = 29;
        } else {
            ngay_max = 28;
        }
    } else if(thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12) {
        ngay_max = 31;
    } else {
        ngay_max = 30;
    }
    if(hientai.ngay > ngay_max) {
        hientai.ngay -= ngay_max;
        hientai.thang++;
        if(hientai.thang > 12) {
            hientai.thang = 1;
            hientai.nam++;
        }
    }
}
int main() {
    Date hientai;
    cin >> hientai.ngay >> hientai.thang >> hientai.nam;
    addday(hientai);
    cout << hientai.ngay << "/" << hientai.thang << "/" << hientai.nam;
}