#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
private:
    string name;
    int age;
    string address;
    string phoneNumber;
    string email;

public:
    // Constructor mặc định
    Person() : name("Unknown"), age(0), address("Unknown"), phoneNumber("N/A"), email("N/A") {}
    
    // Constructor với tham số
    Person(string n, int a, string addr, string phone = "N/A", string em = "N/A") 
        : name(n), age(a), address(addr), phoneNumber(phone), email(em) {
        validateAge(); // Kiểm tra tuổi hợp lệ khi khởi tạo
    }
    
    // Getter và Setter methods
    string getName() const { return name; }
    void setName(string n) { name = n; }
    
    int getAge() const { return age; }
    void setAge(int a) { 
        age = a; 
        validateAge(); // Kiểm tra tuổi hợp lệ khi thiết lập
    }
    
    string getAddress() const { return address; }
    void setAddress(string addr) { address = addr; }
    
    string getPhoneNumber() const { return phoneNumber; }
    void setPhoneNumber(string phone) { phoneNumber = phone; }
    
    string getEmail() const { return email; }
    void setEmail(string em) { email = em; }
    
    // Hiển thị thông tin cá nhân
    void displayInfo() const {
        cout << "\nPersonal Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
        cout << "Status: " << (isAdult() ? "Adult" : "Minor") << endl;
        cout << "Life Stage: " << getLifeStage() << endl;
    }
    
    // Kiểm tra xem người đó có phải là người trưởng thành không
    bool isAdult() const {
        return age >= 18;
    }
    
    // Xác định giai đoạn cuộc đời
    string getLifeStage() const {
        if (age < 1) return "Infant";
        else if (age < 3) return "Toddler";
        else if (age < 13) return "Child";
        else if (age < 18) return "Teenager";
        else if (age < 30) return "Young Adult";
        else if (age < 60) return "Adult";
        else return "Senior";
    }
    
    // Cập nhật địa chỉ mới
    void move(string newAddress) {
        string oldAddress = address;
        address = newAddress;
        cout << name << " has moved from " << oldAddress << " to " << newAddress << endl;
    }
    
    // In lời chào
    void greet() const {
        cout << "Hello, my name is " << name << ". ";
        if (age > 0) {
            cout << "I am " << age << " years old. ";
        }
        if (address != "Unknown") {
            cout << "I live in " << address << ". ";
        }
        cout << "Nice to meet you!" << endl;
    }
    
    // Kiểm tra xem có số điện thoại không
    bool hasPhone() const {
        return phoneNumber != "N/A" && !phoneNumber.empty();
    }
    
    // Kiểm tra xem có email không
    bool hasEmail() const {
        return email != "N/A" && !email.empty();
    }
    
    // Kỷ niệm sinh nhật (tăng tuổi)
    void celebrateBirthday() {
        age++;
        cout << "Happy Birthday, " << name << "! You are now " << age << " years old." << endl;
    }
    
    // So sánh tuổi với người khác
    bool isOlderThan(const Person& other) const {
        return this->age > other.age;
    }

private:
    // Kiểm tra tuổi hợp lệ (0-120)
    void validateAge() {
        if (age < 0) {
            age = 0;
            cout << "Warning: Age cannot be negative. Set to 0." << endl;
        } else if (age > 120) {
            age = 120;
            cout << "Warning: Age cannot exceed 120. Set to 120." << endl;
        }
    }
};

int main() {
    // Tạo đối tượng Person với constructor có tham số
    Person person1("John Doe", 20, "123 Main St", "555-1234", "john.doe@email.com");
    person1.displayInfo();
    
    // Kiểm tra người trưởng thành
    cout << "\nIs adult: " << (person1.isAdult() ? "Yes" : "No") << endl;
    
    // Test lời chào
    cout << "\nGreeting:" << endl;
    person1.greet();
    
    cout << "\n";
    
    // Test di chuyển địa chỉ
    cout << "Testing move functionality:" << endl;
    person1.move("456 Oak Ave");
    person1.displayInfo();
    
    cout << "\n";
    
    // Test sinh nhật
    cout << "Testing birthday celebration:" << endl;
    person1.celebrateBirthday();
    person1.displayInfo();
    
    cout << "\n";
    
    // Tạo người thứ hai
    Person person2("Jane Smith", 16, "789 Pine Rd", "555-5678");
    person2.displayInfo();
    
    // So sánh tuổi
    cout << "\nAge comparison:" << endl;
    cout << person1.getName() << " is older than " << person2.getName() << ": " 
         << (person1.isOlderThan(person2) ? "Yes" : "No") << endl;
    
    cout << "\n";
    
    // Test validation cho tuổi
    cout << "Testing age validation:" << endl;
    Person person3("Test Person", -5, "Test Address"); // Tuổi không hợp lệ
    cout << "Age after setting to -5: " << person3.getAge() << endl;
    
    person3.setAge(150); // Tuổi không hợp lệ
    cout << "Age after setting to 150: " << person3.getAge() << endl;
    
    return 0;
}