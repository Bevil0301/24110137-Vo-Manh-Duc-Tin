#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string accountNumber;
    string ownerName; // Thêm thuộc tính tên chủ tài khoản
    double balance;
    const double MIN_BALANCE = 100000; // Số dư tối thiểu 100,000 VND

public:
    // Constructor
    Account(string accNum = "Unknown", string owner = "Unknown", double bal = 0) {
        accountNumber = accNum;
        ownerName = owner;
        balance = bal;
    }
    
    // Phương thức nạp tiền
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Da nap: " << amount << " VND" << endl;
        } else {
            cout << "So tien nap khong hop le!" << endl;
        }
    }
    
    // Phương thức rút tiền với kiểm tra số dư tối thiểu
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "So tien rut khong hop le!" << endl;
            return;
        }
        
        if (amount > balance) {
            cout << "So du khong du!" << endl;
        } else if ((balance - amount) < MIN_BALANCE) {
            cout << "Khong the rut. Can giu lai it nhat " << MIN_BALANCE << " VND trong tai khoan." << endl;
        } else {
            balance -= amount;
            cout << "Da rut: " << amount << " VND" << endl;
        }
    }
    
    // Phương thức hiển thị số dư 
    void displayBalance() {
        cout << "\n=== THONG TIN TAI KHOAN ===" << endl;
        cout << "So tai khoan: " << accountNumber << endl;
        cout << "Chu tai khoan: " << ownerName << endl; // Hiển thị tên chủ tài khoản
        cout << "So du hien tai: " << balance << " VND" << endl;
        
        // Kiểm tra và cảnh báo nếu số dư dưới mức tối thiểu
        if (balance < MIN_BALANCE) {
            cout << "CANH BAO: So du duoi muc toi thieu (" << MIN_BALANCE << " VND)!" << endl;
        }
    }
    
    // Getter và Setter cho ownerName
    void setOwnerName(string owner) {
        ownerName = owner;
    }
    
    string getOwnerName() {
        return ownerName;
    }
};

int main() {
    cout << "=== HE THONG NGAN HANG ===" << endl;
    
    // Tạo tài khoản
    Account acc1("123456789", "Nguyen Van A", 500000);
    acc1.displayBalance();
    
    // Thực hiện giao dịch
    acc1.deposit(200000);
    acc1.displayBalance();
    
    acc1.withdraw(100000);
    acc1.displayBalance();
    
    // Thử rút số tiền khiến số dư dưới mức tối thiểu
    acc1.withdraw(550000); // Sẽ bị từ chối
    acc1.displayBalance();
    
    // Rút số tiền hợp lệ
    acc1.withdraw(500000);
    acc1.displayBalance();
    
    return 0;
}