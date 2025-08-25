#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    string accountNumber;
    string ownerName;
    double balance;
    static const double MIN_BALANCE; // Số dư tối thiểu

public:
    // Constructor mặc định
    Account() : accountNumber("000000000"), ownerName("Unknown"), balance(0.0) {}
    
    // Constructor với tham số
    Account(string accNum, string owner, double initialBalance = 0.0) 
        : accountNumber(accNum), ownerName(owner), balance(initialBalance) {
        validateBalance(); // Kiểm tra số dư hợp lệ khi khởi tạo
    }
    
    // Getter và Setter methods
    string getAccountNumber() const { return accountNumber; }
    void setAccountNumber(string accNum) { accountNumber = accNum; }
    
    string getOwnerName() const { return ownerName; }
    void setOwnerName(string owner) { ownerName = owner; }
    
    double getBalance() const { return balance; }
    
    // Nạp tiền vào tài khoản
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << " VND" << endl;
            displayBalance();
        } else {
            cout << "Invalid deposit amount. Amount must be positive." << endl;
        }
    }
    
    // Rút tiền từ tài khoản
    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount. Amount must be positive." << endl;
            return false;
        }
        
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
            return false;
        }
        
        if (balance - amount < MIN_BALANCE) {
            cout << "Cannot withdraw. Minimum balance requirement (" << MIN_BALANCE 
                 << " VND) would be violated." << endl;
            return false;
        }
        
        balance -= amount;
        cout << "Withdrew: " << amount << " VND" << endl;
        displayBalance();
        return true;
    }
    
    // Hiển thị số dư tài khoản
    void displayBalance() const {
        cout << "\nAccount Information:" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Owner Name: " << ownerName << endl;
        cout << "Current Balance: " << balance << " VND" << endl;
        cout << "Minimum Required Balance: " << MIN_BALANCE << " VND" << endl;
    }
    
    // Chuyển tiền đến tài khoản khác
    bool transfer(Account& recipient, double amount) {
        if (withdraw(amount)) {
            recipient.deposit(amount);
            cout << "Transferred " << amount << " VND to account " 
                 << recipient.getAccountNumber() << endl;
            return true;
        }
        cout << "Transfer failed." << endl;
        return false;
    }
    
    // Tính lãi suất
    void calculateInterest(double rate, int years) {
        if (rate > 0 && years > 0) {
            double interest = balance * rate * years / 100;
            cout << "Interest after " << years << " years at " << rate 
                 << "%: " << interest << " VND" << endl;
            cout << "Total balance after interest: " << (balance + interest) << " VND" << endl;
        } else {
            cout << "Invalid interest rate or years." << endl;
        }
    }

private:
    // Kiểm tra số dư hợp lệ (không âm và đáp ứng yêu cầu tối thiểu)
    void validateBalance() {
        if (balance < 0) {
            balance = 0;
            cout << "Warning: Balance cannot be negative. Set to 0." << endl;
        } else if (balance < MIN_BALANCE) {
            cout << "Warning: Initial balance is below minimum requirement (" 
                 << MIN_BALANCE << " VND)." << endl;
        }
    }
};

// Khởi tạo hằng số số dư tối thiểu
const double Account::MIN_BALANCE = 100000.0; // 100,000 VND

int main() {
    // Tạo tài khoản với constructor có tham số
    Account acct1("123456789", "Nguyen Van A", 1000000.0);
    acct1.displayBalance();
    
    cout << "\n";
    
    // Test các giao dịch
    cout << "Testing transactions:" << endl;
    acct1.deposit(500000);
    acct1.withdraw(200000);
    
    cout << "\n";
    
    // Test rút tiền vượt quá số dư
    cout << "Testing withdrawal exceeding balance:" << endl;
    acct1.withdraw(2000000);
    
    cout << "\n";
    
    // Test rút tiền vi phạm số dư tối thiểu
    cout << "Testing withdrawal violating minimum balance:" << endl;
    acct1.withdraw(900000); // Sẽ khiến số dư dưới 100,000 VND
    
    cout << "\n";
    
    // Tạo tài khoản thứ hai để test chuyển tiền
    Account acct2("987654321", "Tran Thi B", 500000.0);
    acct2.displayBalance();
    
    cout << "\n";
    
    // Test chuyển tiền
    cout << "Testing transfer between accounts:" << endl;
    acct1.transfer(acct2, 300000);
    
    cout << "\n";
    
    // Hiển thị số dư sau chuyển tiền
    cout << "After transfer:" << endl;
    acct1.displayBalance();
    acct2.displayBalance();
    
    cout << "\n";
    
    // Test tính lãi suất
    cout << "Testing interest calculation:" << endl;
    acct1.calculateInterest(5.0, 3); // 5% lãi suất trong 3 năm
    
    return 0;
}