#include <iostream>
#include <string>  // Thêm thư viện string để sử dụng kiểu string
using namespace std;

// Lớp Car đại diện cho một chiếc xe hơi
class Car {
private:  // Sử dụng encapsulation để bảo vệ dữ liệu
    string brand;
    int year;

public:
    // Constructor mặc định
    Car() {
        brand = "Unknown";
        year = 0;
        cout << "A new car object has been created with default values." << endl;
    }
    
    // Constructor với tham số để khởi tạo giá trị
    Car(string b, int y) {
        brand = b;
        year = y;
        cout << "A new car object has been created: " << b << " (" << y << ")" << endl;
    }
    
    // Phương thức hiển thị thông tin xe
    void displayInfo() {
        cout << "Car Information:" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
        cout << "------------------------" << endl;
    }
    
    // Getter và Setter cho thuộc tính brand (thể hiện encapsulation)
    void setBrand(string b) {
        brand = b;
    }
    
    string getBrand() {
        return brand;
    }
    
    // Getter và Setter cho thuộc tính year
    void setYear(int y) {
        if (y > 1886) {  // Kiểm tra tính hợp lệ (năm sản xuất xe hơi đầu tiên)
            year = y;
        } else {
            cout << "Invalid year! The first car was invented in 1886." << endl;
        }
    }
    
    int getYear() {
        return year;
    }
};

int main() {
    cout << "=== CAR INFORMATION SYSTEM ===" << endl;
    
    // Tạo đối tượng car1 sử dụng constructor mặc định
    Car car1;
    car1.setBrand("Toyota");
    car1.setYear(2020);
    car1.displayInfo();
    
    // Tạo đối tượng car2 sử dụng constructor có tham số
    Car car2("Honda", 2018);
    car2.displayInfo();
    
    // Tạo đối tượng car3 và thử nghiệm với năm không hợp lệ
    Car car3;
    car3.setBrand("Ford");
    car3.setYear(1800);  // Năm không hợp lệ
    car3.setYear(2022);  // Năm hợp lệ
    car3.displayInfo();
    
    // Truy cập thông tin thông qua getter
    cout << "Car 1 brand: " << car1.getBrand() << endl;
    cout << "Car 2 year: " << car2.getYear() << endl;
    
    cout << "=== END OF PROGRAM ===" << endl;
    return 0;
}