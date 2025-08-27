#include <iostream>
using namespace std;

class Rectangle {
private:
    int width;
    int height;
    string color; // Thêm thuộc tính mới: màu sắc

public:
    // Constructor
    Rectangle(int w = 0, int h = 0, string c = "trang") {
        width = w;
        height = h;
        color = c;
    }
    
    // Phương thức tính diện tích
    int calculateArea() {
        return width * height;
    }
    
    // Phương thức hiển thị thông tin
    void displayInfo() {
        cout << "Hinh chu nhat " << color << endl;
        cout << "Chieu rong: " << width << endl;
        cout << "Chieu cao: " << height << endl;
        cout << "Dien tich: " << calculateArea() << endl;
    }
    
    // Getter và Setter cho color
    void setColor(string c) {
        color = c;
    }
    
    string getColor() {
        return color;
    }
};

int main() {
    // Tạo hình chữ nhật
    Rectangle rect1(5, 10, "xanh");
    rect1.displayInfo();
    
    Rectangle rect2(3, 7, "do");
    rect2.displayInfo();
    
    return 0;
}