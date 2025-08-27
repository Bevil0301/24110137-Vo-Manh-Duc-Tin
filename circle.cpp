#include <iostream>
#include <cmath>
using namespace std;

class Circle {
private:
    double radius;
    string color;

public:
    // Constructor
    Circle(double r = 0, string c = "trắng") {
        setRadius(r); // Sử dụng setter để kiểm tra tính hợp lệ
        color = c;
    }
    
    // Phương thức kiểm tra bán kính hợp lệ
    bool isValidRadius() {
        return radius > 0;
    }
    
    // Setter cho radius với kiểm tra hợp lệ
    void setRadius(double r) {
        if (r > 0) {
            radius = r;
        } else {
            cout << "Bán kính không hợp lệ! Đặt giá trị mặc định là 1." << endl;
            radius = 1;
        }
    }
    
    double getRadius() {
        return radius;
    }
    
    // Phương thức tính chu vi
    double circumference() {
        if (!isValidRadius()) {
            cout << "Cảnh báo: Bán kính không hợp lệ!" << endl;
            return 0;
        }
        return 2 * M_PI * radius;
    }
    
    // Phương thức tính diện tích
    double area() {
        if (!isValidRadius()) {
            cout << "Cảnh báo: Bán kính không hợp lệ!" << endl;
            return 0;
        }
        return M_PI * radius * radius;
    }
    
    // Setter và Getter cho color
    void setColor(string c) {
        color = c;
    }
    
    string getColor() {
        return color;
    }
    
    // Phương thức hiển thị màu sắc
    void displayColor() {
        cout << "Màu sắc: " << color << endl;
    }
    
    // Phương thức hiển thị thông tin đầy đủ
    void displayInfo() {
        cout << "\n=== THÔNG TIN HÌNH TRÒN ===" << endl;
        displayColor();
        cout << "Bán kính: " << radius << endl;
        
        if (isValidRadius()) {
            cout << "Chu vi: " << circumference() << endl;
            cout << "Diện tích: " << area() << endl;
        } else {
            cout << "Hình tròn không hợp lệ!" << endl;
        }
    }
};

int main() {
    cout << "=== CHƯƠNG TRÌNH TÍNH HÌNH TRÒN ===" << endl;
    
    // Tạo hình tròn hợp lệ
    Circle circle1(5.0, "xanh dương");
    circle1.displayInfo();
    
    // Tạo hình tròn không hợp lệ (bán kính âm)
    Circle circle2(-2.5, "đỏ");
    circle2.displayInfo();
    
    // Tạo hình tròn và thay đổi thuộc tính
    Circle circle3;
    circle3.setRadius(3.0);
    circle3.setColor("vàng");
    
    cout << "\nSau khi thiết lập:" << endl;
    circle3.displayInfo();
    cout << "Màu sắc riêng: ";
    circle3.displayColor();
    
    return 0;
}