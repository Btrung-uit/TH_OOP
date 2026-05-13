#include <iostream>
using namespace std;
struct Rice {
    int numGrains; // so luong hat gao
    float volume;  //the tich
};
// mo phong nau com
Rice cook(Rice rawRice) {
    Rice cooked;
    cooked.numGrains = rawRice.numGrains; // so luong giu nguyen
    cooked.volume = rawRice.volume*1.5;  // the tich tang 50% (*1.5)
    return cooked;
}
// mo phong chien com
Rice fry(Rice cookedRice) {
    Rice fried;
    fried.numGrains = cookedRice.numGrains*0.9; // So hat gao giam 10% (*90%)
    fried.volume = cookedRice.volume*0.7; // the tich giam 30% (*70%)
    return fried;
}
int main() {
    Rice myRice;
    cout << "Nhap so hat gao: ";
    cin >>myRice.numGrains;
    cout << "Nhap the tich: ";
    cin >> myRice.volume;
    cout << "So hat: " << myRice.numGrains << ", The tich: " << myRice.volume << endl;
    Rice cookedRice = cook(myRice);
    Rice friedRice = fry(cookedRice);
    cout << "Thanh pham cuoi cung: ";
    cout << "So hat: " << friedRice.numGrains << ", the tich: " << friedRice.volume;
    return 0;
}