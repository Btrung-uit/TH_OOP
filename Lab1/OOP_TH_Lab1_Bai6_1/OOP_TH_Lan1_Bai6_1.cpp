#include <iostream>
#include <limits>
using namespace std;

/*
 * Hàm KiemTraNguyenDuong: Kiểm tra và nhập một số nguyên dương từ người dùng.
 * Đầu vào: Không có tham số đầu vào. Hàm sẽ yêu cầu người dùng nhập từ bàn phím.
 * Đầu ra: Trả về một số nguyên dương hợp lệ.
 */
int KiemTraNguyenDuong() { // hàm kiểm tra điều kiện đầu vào có phải là số nguyên dương không, nếu không phải là số nguyên thì nhập lại
    int n;
    while(true) {
        if(cin >> n) {
            if(n > 0) {
                // nếu đúng là số nguyên dương thì thoát vòng lặp
                break;
            }
            else {
                cout << "Dau vao khong hop le! Vui long nhap lai so nguyen duong: ";
                continue;
            }
        }
        else {
            // nếu là chữ hoặc kí tự đặc biệt
            cout << "Dau vao khong hop le! Vui long nhap lai so nguyen duong: ";
            cin.clear(); // xóa trạng thái lỗi của đối tượng cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // bỏ qua toàn bộ kí tự rác trong bộ nhớ đệm
        }
    }
    // trả về số nguyên dương hợp lệ
    return n;
}

/*
 * Hàm KiemTraSoNguyen: Kiểm tra và nhập một số nguyên từ người dùng.
 * Đầu vào: Không có tham số đầu vào. Hàm sẽ yêu cầu người dùng nhập từ bàn phím.
 * Đầu ra: Trả về một số nguyên hợp lệ.
 */
int KiemTraSoNguyen() { // hàm kiểm tra điều kiện đầu vào có phải là số nguyên không, nếu không phải là số nguyên thì nhập lại
    int n;
    while(true) {
        if(cin >> n) {
            // nếu đúng là số nguyên thì thoát vòng lặp
            break;
        }
        else {
            // nếu là chữ hoặc kí tự đặc biệt
            cout << "Dau vao khong hop le! Vui long nhap lai so nguyen: ";
            cin.clear(); // xóa trạng thái lỗi của đối tượng cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // bỏ qua toàn bộ kí tự rác trong bộ nhớ đệm
        }
    }
    // trả về số nguyên hợp lệ
    return n;
}

/*
 * Hàm inputNum: Nhập số phần tử của mảng A và B.
 * Đầu vào: Tham chiếu đến a và b (được truyền bằng tham chiếu để thay đổi giá trị).
 * Đầu ra: Không trả về giá trị, nhưng thay đổi giá trị của a và b.
 */
void inputNum(int &a, int &b) { // hàm nhập số phần tử của mảng A và B
    cout << "=====Nhap so phan tu cua mang====" << endl;
    cout << "Nhap so phan tu cua mang A: ";
    a = KiemTraNguyenDuong(); // kiểm tra xem số có hợp lệ không
    cout << "Nhap so phan tu cua mang B: ";
    b = KiemTraNguyenDuong();  // kiểm tra xem số có hợp lệ không
}

/*
 * Hàm inputArray: Nhập các phần tử của mảng A và B.
 * Đầu vào: Số phần tử a và b, con trỏ đến mảng arrA và arrB.
 * Đầu ra: Không trả về giá trị, nhưng thay đổi nội dung của arrA và arrB.
 */
void inputArray(int a, int b, int *arrA, int *arrB) { // hàm nhập mảng A và B
    cout << "===========Nhap mang A===========" << endl;
    for(int i = 0; i < a; i++) {
        cout << "Nhap phan tu thu " << i+1 << " cua mang A: ";
        arrA[i] = KiemTraSoNguyen();  // kiểm tra xem số có hợp lệ không
    }
    cout << "===========Nhap mang B===========" << endl;
    for(int i = 0; i < b; i++) {
        cout << "Nhap phan tu thu " << i+1 << " cua mang B: ";
        arrB[i] = KiemTraSoNguyen();  // kiểm tra xem số có hợp lệ không
    }
}

/*
 * Hàm find: Tìm số lần mảng A xuất hiện như một dãy con trong mảng B và các vị trí xuất hiện.
 * Đầu vào: Số phần tử a và b, con trỏ đến mảng arrA và arrB.
 * Đầu ra: Không trả về giá trị, nhưng in ra số lần xuất hiện và các chỉ số vị trí.
 */
void find(int a, int b, int *arrA, int *arrB) { // hàm tìm kiếm số lần xuất hiện của A trong B
    cout << "============Tim kiem=============" << endl;
    cout << "So lan mang A xuat hien trong mang B: ";
    if(a > b) { // nếu mảng A lớn hơn B thì in ra 0 lần và kết thúc
        cout << "0 lan.";
        return;
    }
    int *temp = new int[b - a + 1](); // khởi tạo mảng để lưu chỉ số của vị trí A xuất hiện trong B
    int count = 0;
    for(int i = 0; i <= b - a; i++) { // vòng lặp tìm kiếm A trong B, chỉ duyệt đến (b - a) để tránh Out of Bounds
        bool match = true;
        // vòng lặp trong: Tịnh tiến j từ 0 đến a - 1
        for(int j = 0; j < a; j++) {
            // So sánh arrA[j] với phần tử tương ứng của arrB tính từ vị trí i
            if(arrB[i + j] != arrA[j]) {
                match = false;
                break; // dừng ngay khi có phần tử lệch
            }
        }
        if(match) { // nếu khớp toàn bộ thì lưu chỉ số i vào mảng temp
            temp[count] = i;
            count++;
        }
    }
    if(count > 0) { 
        cout << count << " lan." << endl;
        cout << "Mang A xuat hien tai cac chi so: ";
        for(int i = 0; i < count; i++) {
            cout << temp[i] << (i < count - 1 ? ", " : ".");
        }
        cout << endl;
    } else {
        // xử lý khi count == 0
        cout << "0 lan." << endl; 
    }
    delete[] temp;
}

/*
 * Hàm main: Hàm chính của chương trình, nhập mảng A và B, tìm số lần A xuất hiện trong B.
 * Đầu vào: Không có tham số.
 * Đầu ra: Trả về 0 khi chương trình kết thúc thành công.
 */
int main() {
    int a,b;
    inputNum(a ,b);
    int *arrA = new int[a];
    int *arrB = new int[b];
    inputArray(a, b, arrA, arrB);
    find(a, b, arrA, arrB);
    delete[] arrA;
    delete[] arrB;
    return 0;
}
