#include <iostream>
#include <string>
using namespace std;

class Course {
private:
    string courseName;
    string courseCode;
    int credits;
    string instructorName; // Thêm thuộc tính tên giảng viên

public:
    // Constructor
    Course(string name = "Unknown", string code = "Unknown", int cred = 0, string instructor = "Unknown") {
        courseName = name;
        courseCode = code;
        credits = cred;
        instructorName = instructor;
    }
    
    // Phương thức hiển thị thông tin
    void displayInfo() {
        cout << "\n=== THONG TIN KHOA HOC ===" << endl;
        cout << "Ten khoa hoc: " << courseName << endl;
        cout << "Ma khoa hoc: " << courseCode << endl;
        cout << "So tin chi: " << credits << endl;
        cout << "Giang vien: " << instructorName << endl; // Hiển thị tên giảng viên
    }
    
    // Phương thức kiểm tra khóa học nhiều tín chỉ
    bool isHighCredit() {
        return credits > 3;
    }
    
    // PHẦN MỞ RỘNG: Phương thức kiểm tra yêu cầu phòng thí nghiệm
    bool isLabRequired() {
        return credits > 4; // Khóa học > 4 tín chỉ yêu cầu phòng thí nghiệm
    }
    
    // Getter và Setter cho instructorName
    void setInstructor(string instructor) {
        instructorName = instructor;
    }
    
    string getInstructor() {
        return instructorName;
    }
};

int main() {
    cout << "=== HE THONG QUAN LY KHOA HOC ===" << endl;
    
    // Tạo khóa học 1
    Course course1("Lap trinh Huong Doi tuong", "CS202", 4, "Vo Manh Duc Tin");
    course1.displayInfo();
    
    if (course1.isHighCredit()) {
        cout << "Day la khoa hoc nhieu tin chi." << endl;
    } else {
        cout << "Day khong phai khoa hoc nhieu tin chi." << endl;
    }
    
    if (course1.isLabRequired()) {
        cout << "Khoa hoc yeu cau phong thi nghiem." << endl;
    } else {
        cout << "Khoa hoc khong yeu cau phong thi nghiem." << endl;
    }
    
    // Tạo khóa học 2
    Course course2("Thuc hanh Vat ly", "PHY101", 5, "Truong Khac Nhat Phi");
    course2.displayInfo();
    
    if (course2.isHighCredit()) {
        cout << "Day la khoa hoc nhieu tin chi." << endl;
    } else {
        cout << "Day khong phai khoa hoc nhieu tin chi." << endl;
    }
    
    if (course2.isLabRequired()) {
        cout << "Khoa hoc yeu cau phong thi nghiem." << endl;
    } else {
        cout << "Khoa hoc khong yeu cau phong thi nghiem." << endl;
    }
    
    return 0;
}