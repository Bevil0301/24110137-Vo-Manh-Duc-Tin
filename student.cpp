#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
    string name;
    double grade;
    string studentId;
    vector<string> courses;

public:
    // Constructor mặc định
    Student() : name("Unknown"), grade(0.0), studentId("000000") {}
    
    // Constructor với tham số
    Student(string studentName, double studentGrade, string id) 
        : name(studentName), grade(studentGrade), studentId(id) {
        validateGrade(); // Kiểm tra điểm hợp lệ khi khởi tạo
    }
    
    // Getter và Setter methods
    string getName() const { return name; }
    void setName(string studentName) { name = studentName; }
    
    double getGrade() const { return grade; }
    void setGrade(double studentGrade) { 
        grade = studentGrade; 
        validateGrade(); // Kiểm tra điểm hợp lệ khi thiết lập
    }
    
    string getStudentId() const { return studentId; }
    void setStudentId(string id) { studentId = id; }
    
    vector<string> getCourses() const { return courses; }
    
    // Thêm môn học
    void addCourse(string course) {
        courses.push_back(course);
        cout << "Added course: " << course << endl;
    }
    
    // Hiển thị thông tin sinh viên
    void displayInfo() const {
        cout << "\nStudent Information:" << endl;
        cout << "ID: " << studentId << endl;
        cout << "Name: " << name << endl;
        cout << "Grade: " << grade << endl;
        
        if (!courses.empty()) {
            cout << "Courses enrolled: ";
            for (size_t i = 0; i < courses.size(); ++i) {
                cout << courses[i];
                if (i < courses.size() - 1) cout << ", ";
            }
            cout << endl;
        }
    }
    
    // Xác định học lực dựa trên điểm
    string getAcademicPerformance() const {
        if (grade >= 8.5) return "Excellent";
        else if (grade >= 7.0) return "Good";
        else if (grade >= 5.5) return "Average";
        else return "Below Average";
    }

private:
    // Kiểm tra điểm hợp lệ (0-10)
    void validateGrade() {
        if (grade < 0.0) grade = 0.0;
        else if (grade > 10.0) grade = 10.0;
    }
};

int main() {
    // Tạo đối tượng Student với constructor có tham số
    Student student1("John Doe", 8.5, "SV001");
    student1.displayInfo();
    
    // Thêm môn học
    student1.addCourse("Mathematics");
    student1.addCourse("Computer Science");
    student1.addCourse("Physics");
    
    // Hiển thị thông tin cập nhật
    student1.displayInfo();
    
    // Hiển thị học lực
    cout << "Academic Performance: " << student1.getAcademicPerformance() << endl;
    
    cout << "\n";
    
    // Tạo đối tượng Student khác
    Student student2("Jane Smith", 7.8, "SV002");
    student2.displayInfo();
    
    // Test validation cho điểm số
    cout << "\nTesting grade validation:" << endl;
    student2.setGrade(12.5); // Điểm không hợp lệ
    cout << "Grade after setting to 12.5: " << student2.getGrade() << endl;
    
    student2.setGrade(-3.0); // Điểm không hợp lệ
    cout << "Grade after setting to -3.0: " << student2.getGrade() << endl;
    
    return 0;
}