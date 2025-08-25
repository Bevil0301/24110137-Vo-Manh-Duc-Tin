#include <iostream>
#include <cmath>

using namespace std;

class Rectangle {
private:
    double width;
    double height;

public:
    // Constructor mặc định
    Rectangle() : width(1.0), height(1.0) {}
    
    // Constructor với tham số
    Rectangle(double w, double h) : width(w), height(h) {
        validateDimensions(); // Kiểm tra kích thước hợp lệ khi khởi tạo
    }
    
    // Getter và Setter methods
    double getWidth() const { return width; }
    void setWidth(double w) { 
        width = w; 
        validateDimensions(); // Kiểm tra kích thước hợp lệ khi thiết lập
    }
    
    double getHeight() const { return height; }
    void setHeight(double h) { 
        height = h; 
        validateDimensions(); // Kiểm tra kích thước hợp lệ khi thiết lập
    }
    
    // Tính diện tích
    double calculateArea() const {
        return width * height;
    }
    
    // Tính chu vi
    double calculatePerimeter() const {
        return 2 * (width + height);
    }
    
    // Tính đường chéo
    double calculateDiagonal() const {
        return sqrt(width * width + height * height);
    }
    
    // Kiểm tra có phải là hình vuông
    bool isSquare() const {
        return width == height;
    }
    
    // Hiển thị thông tin hình chữ nhật
    void displayInfo() const {
        cout << "\nRectangle Information:" << endl;
        cout << "Width: " << width << endl;
        cout << "Height: " << height << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Perimeter: " << calculatePerimeter() << endl;
        cout << "Diagonal: " << calculateDiagonal() << endl;
        cout << "Is square: " << (isSquare() ? "Yes" : "No") << endl;
    }
    
    // Scale hình chữ nhật theo tỷ lệ
    void scale(double factor) {
        if (factor > 0) {
            width *= factor;
            height *= factor;
            cout << "Scaled by factor " << factor << ". New dimensions: " 
                 << width << " x " << height << endl;
        } else {
            cout << "Invalid scale factor. Must be positive." << endl;
        }
    }

private:
    // Kiểm tra kích thước hợp lệ (dương)
    void validateDimensions() {
        if (width <= 0) {
            width = 1.0;
            cout << "Warning: Width must be positive. Set to default value 1.0" << endl;
        }
        if (height <= 0) {
            height = 1.0;
            cout << "Warning: Height must be positive. Set to default value 1.0" << endl;
        }
    }
};

int main() {
    // Tạo đối tượng Rectangle với constructor có tham số
    Rectangle rect1(5.0, 10.0);
    rect1.displayInfo();
    
    cout << "\n";
    
    // Tạo đối tượng Rectangle khác
    Rectangle rect2(7.5, 7.5);
    rect2.displayInfo();
    
    // Test phương thức scale
    cout << "\nTesting scale functionality:" << endl;
    rect2.scale(2.0);
    rect2.displayInfo();
    
    cout << "\n";
    
    // Test validation cho kích thước
    cout << "Testing dimension validation:" << endl;
    Rectangle rect3(-5.0, 8.0); // Chiều rộng không hợp lệ
    rect3.displayInfo();
    
    rect3.setHeight(-3.0); // Chiều cao không hợp lệ
    rect3.displayInfo();
    
    cout << "\n";
    
    // Sử dụng constructor mặc định
    Rectangle rect4;
    cout << "Default rectangle:" << endl;
    rect4.displayInfo();
    
    // Thay đổi kích thước
    rect4.setWidth(3.0);
    rect4.setHeight(4.0);
    cout << "\nAfter setting new dimensions:" << endl;
    rect4.displayInfo();
    
    return 0;
}