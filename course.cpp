#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Course {
private:
    string courseName;
    string courseCode;
    int credits;
    string instructorName;
    vector<string> prerequisites;
    bool hasLabSession;

public:
    // Constructor mặc định
    Course() : courseName("Unknown"), courseCode("XXX000"), credits(0), instructorName("TBA"), hasLabSession(false) {}
    
    // Constructor với tham số
    Course(string name, string code, int cred, string instructor = "TBA", bool lab = false) 
        : courseName(name), courseCode(code), credits(cred), instructorName(instructor), hasLabSession(lab) {
        validateCredits(); // Kiểm tra số tín chỉ hợp lệ khi khởi tạo
    }
    
    // Getter và Setter methods
    string getCourseName() const { return courseName; }
    void setCourseName(string name) { courseName = name; }
    
    string getCourseCode() const { return courseCode; }
    void setCourseCode(string code) { courseCode = code; }
    
    int getCredits() const { return credits; }
    void setCredits(int cred) { 
        credits = cred; 
        validateCredits(); // Kiểm tra số tín chỉ hợp lệ khi thiết lập
    }
    
    string getInstructorName() const { return instructorName; }
    void setInstructorName(string instructor) { instructorName = instructor; }
    
    bool getHasLabSession() const { return hasLabSession; }
    void setHasLabSession(bool lab) { hasLabSession = lab; }
    
    vector<string> getPrerequisites() const { return prerequisites; }
    void addPrerequisite(string prereq) {
        prerequisites.push_back(prereq);
        cout << "Added prerequisite: " << prereq << endl;
    }
    
    // Hiển thị thông tin khóa học
    void displayInfo() const {
        cout << "\nCourse Information:" << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Course Code: " << courseCode << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructorName << endl;
        cout << "Lab Session Required: " << (hasLabSession ? "Yes" : "No") << endl;
        
        if (!prerequisites.empty()) {
            cout << "Prerequisites: ";
            for (size_t i = 0; i < prerequisites.size(); ++i) {
                cout << prerequisites[i];
                if (i < prerequisites.size() - 1) cout << ", ";
            }
            cout << endl;
        }
        
        cout << "Course Level: " << getCourseLevel() << endl;
    }
    
    // Kiểm tra xem khóa học có nhiều tín chỉ không (hơn 3 tín chỉ)
    bool isHighCredit() const {
        return credits > 3;
    }
    
    // Kiểm tra xem khóa học có yêu cầu phòng thí nghiệm không
    bool isLabRequired() const {
        return credits > 4 || hasLabSession;
    }
    
    // Xác định cấp độ khóa học dựa trên mã khóa học
    string getCourseLevel() const {
        if (courseCode.find("100") != string::npos || courseCode.find("1") == 0) return "Introductory";
        if (courseCode.find("200") != string::npos || courseCode.find("2") == 0) return "Intermediate";
        if (courseCode.find("300") != string::npos || courseCode.find("3") == 0) return "Advanced";
        if (courseCode.find("400") != string::npos || courseCode.find("4") == 0) return "Senior Level";
        return "Unknown Level";
    }
    
    // Tính tổng thời gian học ước tính (giả sử 1 tín chỉ = 15 giờ học)
    int getEstimatedStudyHours() const {
        return credits * 15;
    }
    
    // Kiểm tra xem sinh viên có đủ điều kiện học khóa học này không
    bool canEnroll(const vector<string>& completedCourses) const {
        if (prerequisites.empty()) return true;
        
        for (const auto& prereq : prerequisites) {
            bool found = false;
            for (const auto& completed : completedCourses) {
                if (completed == prereq) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Missing prerequisite: " << prereq << endl;
                return false;
            }
        }
        return true;
    }

private:
    // Kiểm tra số tín chỉ hợp lệ (1-6)
    void validateCredits() {
        if (credits < 1) {
            credits = 1;
            cout << "Warning: Credits must be at least 1. Set to default 1." << endl;
        } else if (credits > 6) {
            credits = 6;
            cout << "Warning: Credits cannot exceed 6. Set to maximum 6." << endl;
        }
    }
};

int main() {
    // Tạo đối tượng Course với constructor có tham số
    Course course1("Object Oriented Programming", "CS202", 4, "Dr. Smith", true);
    course1.displayInfo();
    
    // Kiểm tra khóa học nhiều tín chỉ
    cout << "\nHigh credit course: " << (course1.isHighCredit() ? "Yes" : "No") << endl;
    
    // Kiểm tra yêu cầu phòng thí nghiệm
    cout << "Lab required: " << (course1.isLabRequired() ? "Yes" : "No") << endl;
    
    // Thêm điều kiện tiên quyết
    cout << "\nAdding prerequisites:" << endl;
    course1.addPrerequisite("CS101");
    course1.addPrerequisite("MATH101");
    
    // Kiểm tra điều kiện đăng ký
    cout << "\nTesting enrollment eligibility:" << endl;
    vector<string> completedCourses = {"CS101", "MATH101", "ENG101"};
    bool canEnroll = course1.canEnroll(completedCourses);
    cout << "Can enroll: " << (canEnroll ? "Yes" : "No") << endl;
    
    cout << "\n";
    
    // Tạo khóa học khác
    Course course2("Data Structures", "CS301", 3, "Dr. Johnson");
    course2.displayInfo();
    
    // Kiểm tra các tính năng
    cout << "High credit course: " << (course2.isHighCredit() ? "Yes" : "No") << endl;
    cout << "Lab required: " << (course2.isLabRequired() ? "Yes" : "No") << endl;
    cout << "Estimated study hours: " << course2.getEstimatedStudyHours() << " hours" << endl;
    
    cout << "\n";
    
    // Test validation cho số tín chỉ
    cout << "Testing credits validation:" << endl;
    Course course3("Test Course", "TEST001", -2, "Test Instructor"); // Số tín chỉ không hợp lệ
    cout << "Credits after setting to -2: " << course3.getCredits() << endl;
    
    course3.setCredits(7); // Số tín chỉ không hợp lệ
    cout << "Credits after setting to 7: " << course3.getCredits() << endl;
    
    return 0;
}