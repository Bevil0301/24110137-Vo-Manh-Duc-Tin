#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    int year;
    string model;
    double mileage;

public:
    // Constructor mặc định
    Car() : brand("Unknown"), year(0), model("Unknown"), mileage(0.0) {}
    
    // Constructor với tham số
    Car(string carBrand, int carYear, string carModel, double carMileage = 0.0) 
        : brand(carBrand), year(carYear), model(carModel), mileage(carMileage) {}
    
    // Getter và Setter methods
    string getBrand() const { return brand; }
    void setBrand(string carBrand) { brand = carBrand; }
    
    int getYear() const { return year; }
    void setYear(int carYear) { 
        if (carYear > 1886) { // Kiểm tra năm hợp lệ (năm sản xuất ô tô đầu tiên)
            year = carYear; 
        }
    }
    
    string getModel() const { return model; }
    void setModel(string carModel) { model = carModel; }
    
    double getMileage() const { return mileage; }
    void setMileage(double carMileage) { 
        if (carMileage >= 0) {
            mileage = carMileage; 
        }
    }
    
    // Phương thức hiển thị thông tin
    void displayInfo() const {
        cout << "Car Information:" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Mileage: " << mileage << " km" << endl;
    }
    
    // Phương thức mô phỏng lái xe
    void drive(double distance) {
        if (distance > 0) {
            mileage += distance;
            cout << "Drove " << distance << " km. Total mileage: " << mileage << " km" << endl;
        }
    }
};

int main() {
    // Tạo đối tượng Car sử dụng constructor có tham số
    Car car1("Toyota", 2020, "Camry", 15000.5);
    car1.displayInfo();
    
    cout << "\n";
    
    // Tạo đối tượng Car khác
    Car car2("Honda", 2022, "Civic");
    car2.displayInfo();
    
    cout << "\n";
    
    // Mô phỏng lái xe
    car2.drive(250.7);
    car2.drive(150.3);
    
    cout << "\n";
    
    // Hiển thị thông tin cập nhật
    cout << "Updated information for " << car2.getBrand() << " " << car2.getModel() << ":" << endl;
    cout << "Current mileage: " << car2.getMileage() << " km" << endl;
    
    return 0;
}