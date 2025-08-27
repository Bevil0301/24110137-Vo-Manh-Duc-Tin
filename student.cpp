#include <iostream>
#include <string>  // Thêm thư viện string để sử dụng kiểu string
using namespace std;

class Student {
private:  // Sử dụng encapsulation để bảo vệ dữ liệu
    string name;
    double grade;
    
public:
    // Constructor với tham số mặc định
    Student(string studentName = "Unknown", double studentGrade = 0.0) {
        name = studentName;
        grade = studentGrade;
    }
    
    // Phương thức hiển thị thông tin
    void displayInfo() {
        cout << "Student Information:" << endl;
        cout << "- Name: " << name << endl;
        cout << "- Grade: " << grade << endl;
        cout << "- Status: " << getStatus() << endl;  // Thêm thông tin về học lực
    }
    
    // Getter và Setter cho name
    void setName(string studentName) {
        name = studentName;
    }
    
    string getName() {
        return name;
    }
    
    // Getter và Setter cho grade
    void setGrade(double studentGrade) {
        // Kiểm tra tính hợp lệ của điểm
        if (studentGrade >= 0.0 && studentGrade <= 10.0) {
            grade = studentGrade;
        } else {
            cout << "Invalid grade! Grade must be between 0 and 10." << endl;
        }
    }
    
    double getGrade() {
        return grade;
    }
    
    // Phương thức bổ sung để xác định học lực
    string getStatus() {
        if (grade >= 8.5) return "Excellent";
        else if (grade >= 7.0) return "Good";
        else if (grade >= 5.5) return "Average";
        else return "Below Average";
    }
};

int main() {
    cout << "=== STUDENT MANAGEMENT PROGRAM ===" << endl;
    
    // Tạo đối tượng sinh viên thứ nhất sử dụng constructor
    Student student1("Nguyen Van A", 8.7);
    cout << "\nStudent 1:" << endl;
    student1.displayInfo();
    
    // Tạo đối tượng sinh viên thứ hai sử dụng setter
    Student student2;
    student2.setName("Tran Thi B");
    student2.setGrade(7.3);
    cout << "\nStudent 2:" << endl;
    student2.displayInfo();
    
    // Tạo đối tượng sinh viên thứ ba với điểm không hợp lệ
    Student student3("Le Van C");
    student3.setGrade(12.5);  // Điểm không hợp lệ
    cout << "\nStudent 3:" << endl;
    student3.displayInfo();
    
    // Thay đổi thông tin sinh viên
    cout << "\nAfter updating student 2's grade:" << endl;
    student2.setGrade(8.9);
    cout << "Student 2's new grade: " << student2.getGrade() << endl;
    student2.displayInfo();
    
    return 0;
}