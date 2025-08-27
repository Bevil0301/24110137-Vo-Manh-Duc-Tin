#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;
    string address;
    string phoneNumber; // Thêm thuộc tính số điện thoại

public:
    // Constructor
    Person(string n = "Unknown", int a = 0, string addr = "Unknown", string phone = "Unknown") {
        name = n;
        age = a;
        address = addr;
        phoneNumber = phone;
    }
    
    // Phương thức hiển thị thông tin
    void displayInfo() {
        cout << "\n=== THONG TIN CA NHAN ===" << endl;
        cout << "Ho ten: " << name << endl;
        cout << "Tuoi: " << age << endl;
        cout << "Dia chi: " << address << endl;
        cout << "So dien thoai: " << phoneNumber << endl; // Hiển thị số điện thoại
    }
    
    // Phương thức kiểm tra trưởng thành
    bool isAdult() {
        return age >= 18;
    }
    
    // PHẦN MỞ RỘNG: Phương thức cập nhật địa chỉ mới
    void move(string newAddress) {
        address = newAddress;
        cout << "Da cap nhat dia chi moi: " << address << endl;
    }
    
    // PHẦN MỞ RỘNG: Phương thức chào hỏi
    void greet() {
        cout << "Xin chao, toi ten la " << name << endl;
    }
    
    // Getter và Setter cho phoneNumber
    void setPhoneNumber(string phone) {
        phoneNumber = phone;
    }
    
    string getPhoneNumber() {
        return phoneNumber;
    }
};

int main() {
    cout << "=== HE THONG QUAN LY NGUOI ===" << endl;
    
    // Tạo người 1
    Person person1("Nguyen Van A", 20, "36 Nguyen Trai", "0912345678");
    person1.displayInfo();
    person1.greet();
    
    if (person1.isAdult()) {
        cout << "Nguoi nay da truong thanh." << endl;
    } else {
        cout << "Nguoi nay chua truong thanh." << endl;
    }
    
    // Tạo người 2
    Person person2("Tran Thi B", 16, "18 Le Loi", "0987654321");
    person2.displayInfo();
    person2.greet();
    
    if (person2.isAdult()) {
        cout << "Nguoi nay da truong thanh." << endl;
    } else {
        cout << "Nguoi nay chua truong thanh." << endl;
    }
    
    // Cập nhật địa chỉ mới
    cout << "\n=== CAP NHAT DIA CHI ===" << endl;
    person1.move("109 Cao Dat");
    person1.displayInfo();
    
    return 0;
}