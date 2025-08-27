#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    double salary;
    int years; // Thêm thuộc tính mới: số năm kinh nghiệm

public:
    // Constructor
    Employee(string empName = "Unknown", double empSalary = 0, int empYears = 0) {
        name = empName;
        salary = empSalary;
        years = empYears;
    }
    
    // Phương thức hiển thị thông tin
    void displayInfo() {
        cout << "\nThong tin nhan vien:" << endl;
        cout << "Ten: " << name << endl;
        cout << "Luong: " << salary << " VND" << endl;
        cout << "Kinh nghiem: " << years << " nam" << endl; // Hiển thị thêm kinh nghiệm
    }
    
    // Getter và Setter cho years
    void setYears(int empYears) {
        years = empYears;
    }
    
    int getYears() {
        return years;
    }
};

int main() {
    // Tạo nhân viên
    Employee emp1("Nguyen Van A", 15000000, 3);
    emp1.displayInfo();
    
    Employee emp2("Tran Thi B", 12000000, 1);
    emp2.displayInfo();
    
    return 0;
}