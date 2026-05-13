#include <iostream>
using namespace std;
struct Enchant {
    string name;
    int level;
};
class Item {
    private:
        string name;
        int power;
        // các dòng phù phép
        Enchant EnchantList[5];
        int enchantcount;
    public:
        Item() {
            name = "Chua xac dinh";
            power = 0;
        }
        Item(string n, int p) {
            name = n;
            power = p;
        }
        void addEnchant(string eName, int eLevel) {
            if(enchantcount < 5) {
                EnchantList[enchantcount].name = eName;
                EnchantList[enchantcount].level = eLevel;
                enchantcount++;
                cout << "Da phu phep [" << eName << " " << eLevel << "] cho " << name << endl;
            } else {
                cout << "Vu khi da dat toi da 5 dong phu phep!" << endl;
            }
        }
        void showinfo() {
            cout << "Vat pham: " << name << " | Suc manh: " << power << endl;
            if(enchantcount > 0) {
                cout << "Cac dong phu phep: " <<endl;
                for(int i = 0; i < enchantcount; i++) {
                    cout << EnchantList[i].name << " " << EnchantList[i].level << endl;
                }
            }
            else {
                cout << "Vu khi chua co phu phep" << endl;
            }
        }
        string getName() {
            return name;
        }
};

int main() {
    string name;
    int power;
    cout << "Nhap ten vu khi: "; getline(cin, name);
    cout << "Nhap suc manh vu khi: "; cin >> power;
    Item vukhi(name, power);
    vukhi.showinfo();
    vukhi.addEnchant("Sat ben", 5);
    vukhi.addEnchant("Cham hong", 3);
    vukhi.addEnchant("Nhat do", 3);
    vukhi.showinfo();
    cout << vukhi.getName();
}