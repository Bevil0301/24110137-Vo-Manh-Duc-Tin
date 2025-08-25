#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Circle {
private:
    double radius;
    string color;

public:
    // Hằng số PI
    static const double PI;

    // Constructor mặc định
    Circle() : radius(1.0), color("Red") {}
    
    // Constructor với tham số
    Circle(double r, string c = "Red") : radius(r), color(c) {
        validateRadius(); // Kiểm tra bán kính hợp lệ khi khởi tạo
    }
    
    // Getter và Setter methods
    double getRadius() const { return radius; }
    void setRadius(double r) { 
        radius = r; 
        validateRadius(); // Kiểm tra bán kính hợp lệ khi thiết lập
    }
    
    string getColor() const { return color; }
    void setColor(string c) { color = c; }
    
    // Tính chu vi hình tròn
    double circumference() const {
        return 2 * PI * radius;
    }
    
    // Tính diện tích hình tròn
    double area() const {
        return PI * radius * radius;
    }
    
    // Tính đường kính hình tròn
    double diameter() const {
        return 2 * radius;
    }
    
    // Kiểm tra bán kính hợp lệ
    bool isValid() const {
        return radius > 0;
    }
    
    // Hiển thị thông tin hình tròn
    void displayInfo() const {
        cout << "\nCircle Information:" << endl;
        cout << "Radius: " << radius << endl;
        cout << "Color: " << color << endl;
        cout << "Diameter: " << diameter() << endl;
        cout << "Circumference: " << circumference() << " units" << endl;
        cout << "Area: " << area() << " square units" << endl;
        cout << "Is valid: " << (isValid() ? "Yes" : "No") << endl;
    }
    
    // So sánh với hình tròn khác
    bool isLargerThan(const Circle& other) const {
        return this->area() > other.area();
    }
    
    // Tạo hình tròn mới với tỷ lệ scale
    Circle createScaledCircle(double factor) const {
        if (factor > 0) {
            return Circle(radius * factor, color);
        }
        return *this; // Trả về bản sao nếu factor không hợp lệ
    }

private:
    // Kiểm tra bán kính hợp lệ (dương)
    void validateRadius() {
        if (radius <= 0) {
            radius = 1.0;
            cout << "Warning: Radius must be positive. Set to default value 1.0" << endl;
        }
    }
};

// Khởi tạo hằng số PI
const double Circle::PI = 3.14159265358979323846;

int main() {
    // Nhập bán kính từ người dùng
    double r;
    string c;
    
    cout << "Enter circle radius: ";
    cin >> r;
    
    cout << "Enter circle color: ";
    cin.ignore(); // Bỏ qua ký tự newline còn lại
    getline(cin, c);
    
    // Tạo đối tượng Circle với constructor có tham số
    Circle circle1(r, c);
    circle1.displayInfo();
    
    cout << "\n";
    
    // Test các phương thức khác
    cout << "Testing additional methods:" << endl;
    cout << "Diameter: " << circle1.diameter() << " units" << endl;
    
    // Tạo hình tròn thứ hai để so sánh
    Circle circle2(2.5, "Blue");
    cout << "Is circle1 larger than circle2? " << (circle1.isLargerThan(circle2) ? "Yes" : "No") << endl;
    
    // Tạo hình tròn scaled
    Circle circle3 = circle1.createScaledCircle(1.5);
    cout << "\nScaled circle (1.5x):" << endl;
    circle3.displayInfo();
    
    cout << "\n";
    
    // Test validation cho bán kính
    cout << "Testing radius validation:" << endl;
    Circle circle4(-3.0, "Green"); // Bán kính không hợp lệ
    circle4.displayInfo();
    
    circle4.setRadius(4.0); // Thiết lập bán kính hợp lệ
    circle4.displayInfo();
    
    return 0;
}