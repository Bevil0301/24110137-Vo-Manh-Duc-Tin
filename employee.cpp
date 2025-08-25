#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
private:
    string name;
    double salary;
    string employeeId;
    string department;
    int yearsOfService;

public:
    // Constructor mặc định
    Employee() : name("Unknown"), salary(0.0), employeeId("E0000"), department("Unassigned"), yearsOfService(0) {}
    
    // Constructor với tham số
    Employee(string empName, double empSalary, string id, string dept, int years = 0) 
        : name(empName), salary(empSalary), employeeId(id), department(dept), yearsOfService(years) {
        validateSalary(); // Kiểm tra lương hợp lệ khi khởi tạo
    }
    
    // Getter và Setter methods
    string getName() const { return name; }
    void setName(string empName) { name = empName; }
    
    double getSalary() const { return salary; }
    void setSalary(double empSalary) { 
        salary = empSalary; 
        validateSalary(); // Kiểm tra lương hợp lệ khi thiết lập
    }
    
    string getEmployeeId() const { return employeeId; }
    void setEmployeeId(string id) { employeeId = id; }
    
    string getDepartment() const { return department; }
    void setDepartment(string dept) { department = dept; }
    
    int getYearsOfService() const { return yearsOfService; }
    void setYearsOfService(int years) { 
        if (years >= 0) {
            yearsOfService = years; 
        }
    }
    
    // Hiển thị thông tin nhân viên
    void displayInfo() const {
        cout << "\nEmployee Information:" << endl;
        cout << "ID: " << employeeId << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: $" << salary << endl;
        cout << "Years of Service: " << yearsOfService << endl;
    }
    
    // Tính thưởng dựa trên số năm làm việc
    double calculateBonus() const {
        if (yearsOfService >= 10) return salary * 0.15;
        else if (yearsOfService >= 5) return salary * 0.10;
        else if (yearsOfService >= 3) return salary * 0.05;
        else return salary * 0.02;
    }
    
    // Tăng lương theo phần trăm
    void giveRaise(double percentage) {
        if (percentage > 0) {
            double increase = salary * (percentage / 100);
            salary += increase;
            cout << "Raise of " << percentage << "% applied. New salary: $" << salary << endl;
        } else {
            cout << "Invalid raise percentage. Must be positive." << endl;
        }
    }
    
    // Tăng số năm làm việc
    void addYearOfService() {
        yearsOfService++;
        cout << "Added one year of service. Total years: " << yearsOfService << endl;
    }

private:
    // Kiểm tra lương hợp lệ (không âm)
    void validateSalary() {
        if (salary < 0) {
            salary = 0;
        }
    }
};

int main() {
    // Tạo đối tượng Employee với constructor có tham số
    Employee employee1("Alice Johnson", 5000, "E1001", "Engineering", 3);
    employee1.displayInfo();
    
    // Tính và hiển thị thưởng
    cout << "Annual Bonus: $" << employee1.calculateBonus() << endl;
    
    // Tăng lương
    employee1.giveRaise(10);
    employee1.displayInfo();
    
    cout << "\n";
    
    // Tạo đối tượng Employee khác
    Employee employee2("Bob Smith", 6000, "E1002", "Marketing", 7);
    employee2.displayInfo();
    
    // Tính và hiển thị thưởng
    cout << "Annual Bonus: $" << employee2.calculateBonus() << endl;
    
    // Thêm năm làm việc
    employee2.addYearOfService();
    employee2.displayInfo();
    
    cout << "\n";
    
    // Test validation cho lương
    cout << "Testing salary validation:" << endl;
    Employee employee3("Test Employee", -2500, "E1003", "Test Dept"); // Lương không hợp lệ
    cout << "Salary after setting to -2500: $" << employee3.getSalary() << endl;
    
    employee3.setSalary(3000);
    cout << "Salary after setting to 3000: $" << employee3.getSalary() << endl;
    
    return 0;
}