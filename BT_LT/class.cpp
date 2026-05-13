#include <bits/stdc++.h>
using namespace std;
/*
    class: lớp
    thuộc tính: attribute
    phương thức: method, behavior
    object: đối tượng (Thực thể của 1 cái class đấy) có thể là 1 cái người cu thể nào đó
    ----
    Tính chất đầu tiên là Đóng gói: Encapsulation:
    Khi xây dựng lớp các thuộc tính của lớp đấy thường được để private
    Các phương thức thường để là public
    protected liên quan đến kế thừa

    Access modifier: mô tả phạm vi của 1 cái thuộc tính nào đó ở trong lớp, gồm 3 phần:
    1. Private
    2. Public
    3. Protected

    Constructor: hàm khởi tạo: 
        +hàm sẽ khởi tạo mỗi khi khai báo 1 class mới
        +có cùng tên với class và không có kiểu trả về
    Destructor: Ngược với hàm tạo thì nó sẽ hủy đi 1 đối tượng:
        +không thể ghi đè
        +không có kiểu trả về
        +có tên trùng với tên class và có dấu '~' ở đằng trước vd: ~SinhVien();


*/

//khai báo
class TenClass {
    // Các thuộc tính và phương thức bạn sẽ định nghĩa ở trong này
};
class SinhVien {
    private: // để đám bảo tính chất encapsulation: đóng gói
        // cấm truy cập trực tiếp từ bên ngoài
        string id, ten, ngaysinh;
        double gpa;
    public:
        SinhVien(); //Constructor
        SinhVien(string, string, string, double); //constructor: khởi tạo
        void input();
        void output();
        ~SinhVien(); // destructor
        // đây là các phương thức

};
SinhVien a;
class BaoTrung:public SinhVien {
    private:
        int namsinh;
    public:
        void input();
        void output();
};
void BaoTrung::input() {
    SinhVien::input();
    cout << "Nhap nam sinh: ";
    cin >> namsinh;
}
void BaoTrung::output() {
    SinhVien::output();
    cout << "Nam sinh: " << namsinh << endl;
}
SinhVien::SinhVien() { 
    // hàm constructor không có tham số
    // phải luôn tạo nếu gọi SinhVien ở hàm main không có tham số thì sẽ bị báo lỗi
    //cout << "Ham khoi tao duoc goi\n";
    //cout << "Doi tuong mac dinh duoc tao tai day! \n";
    id = ten = ngaysinh = "";
    gpa = 0;
}
SinhVien::~SinhVien() {
    cout << "Doi tuong duoc huy tai day!\n";
}
SinhVien::SinhVien(string ma, string name, string birth, double diem) { 
    // hàm constructor có tham số
    cout << "Ham khoi tao co tham so duoc goi! \n";
    id = ma;
    ten = name;
    ngaysinh = birth;
    gpa = diem;
}
void SinhVien::input() {
    cout << "Nhap id: ";
    cin >> id;
    cin.ignore();
    cout << "Nhap ten: ";
    getline(cin, ten);
    cout << "Nhap ngay sinh: ";
    cin >> ngaysinh;
    cout << "Nhap diem: ";
    cin >> gpa;
}
void SinhVien::output() {
    cout << "id: " << id << " ten: "<< ten << " ngay sinh: " << ngaysinh << " gpa: " << fixed << setprecision(2) << gpa << endl;
}
/*
void SinhVien::xinchao() {
    cout << "Chao";
}
void SinhVien::dihoc() {
    cout << "\nDi hoc";
}
*/
// ví dụ class sinh vien
int main() {
    /*
    cout << "Xin Chao!\n";
    if(1) {
        SinhVien x;
    }
    */
    //SinhVien x("123", "Nguyen Van A", "23/12/2003", 3.14);
    //x.xinchao();
    //x.dihoc();
    SinhVien x;
    int x;
    cin >> x;
    x.input();
    x.output();
    BaoTrung b;
    b.input();
    b.output();
    return 0;
}