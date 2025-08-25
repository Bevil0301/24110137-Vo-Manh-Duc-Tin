#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    int publicationYear;
    string isbn;
    bool isAvailable;

public:
    // Constructor mặc định
    Book() : title("Unknown"), author("Unknown"), publicationYear(0), isbn("000-0000000000"), isAvailable(false) {}
    
    // Constructor với tham số
    Book(string bookTitle, string bookAuthor, int year, string bookIsbn, bool available = true) 
        : title(bookTitle), author(bookAuthor), publicationYear(year), isbn(bookIsbn), isAvailable(available) {
        validatePublicationYear(); // Kiểm tra năm xuất bản hợp lệ
    }
    
    // Getter và Setter methods
    string getTitle() const { return title; }
    void setTitle(string bookTitle) { title = bookTitle; }
    
    string getAuthor() const { return author; }
    void setAuthor(string bookAuthor) { author = bookAuthor; }
    
    int getPublicationYear() const { return publicationYear; }
    void setPublicationYear(int year) { 
        publicationYear = year; 
        validatePublicationYear(); // Kiểm tra năm xuất bản hợp lệ
    }
    
    string getIsbn() const { return isbn; }
    void setIsbn(string bookIsbn) { isbn = bookIsbn; }
    
    bool getIsAvailable() const { return isAvailable; }
    void setIsAvailable(bool available) { isAvailable = available; }
    
    // Hiển thị thông tin sách
    void displayInfo() const {
        cout << "\nBook Information:" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publication Year: " << publicationYear << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Status: " << (isAvailable ? "Available" : "Borrowed") << endl;
    }
    
    // Mượn sách
    bool borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Book '" << title << "' has been borrowed successfully." << endl;
            return true;
        } else {
            cout << "Book '" << title << "' is not available for borrowing." << endl;
            return false;
        }
    }
    
    // Trả sách
    void returnBook() {
        isAvailable = true;
        cout << "Book '" << title << "' has been returned." << endl;
    }
    
    // Kiểm tra sách có phải là cổ điển (xuất bản trước năm 1950)
    bool isClassic() const {
        return publicationYear < 1950;
    }

private:
    // Kiểm tra năm xuất bản hợp lệ (không vượt quá năm hiện tại)
    void validatePublicationYear() {
        // Giả sử năm hiện tại là 2024
        const int CURRENT_YEAR = 2024;
        if (publicationYear > CURRENT_YEAR) {
            publicationYear = CURRENT_YEAR;
        } else if (publicationYear < 0) {
            publicationYear = 0;
        }
    }
};

int main() {
    // Tạo đối tượng Book với constructor có tham số
    Book book1("C++ Programming", "Bjarne Stroustrup", 2013, "978-0321563842");
    book1.displayInfo();
    
    // Test tính năng mượn/trả sách
    cout << "\nTesting borrow/return functionality:" << endl;
    book1.borrowBook();
    book1.displayInfo();
    
    book1.returnBook();
    book1.displayInfo();
    
    cout << "\n";
    
    // Tạo đối tượng Book khác
    Book book2("The Great Gatsby", "F. Scott Fitzgerald", 1925, "978-0743273565");
    book2.displayInfo();
    
    // Kiểm tra có phải sách cổ điển không
    cout << "Is this a classic book? " << (book2.isClassic() ? "Yes" : "No") << endl;
    
    cout << "\n";
    
    // Test validation cho năm xuất bản
    cout << "Testing publication year validation:" << endl;
    Book book3("Test Book", "Test Author", 2030, "999-9999999999"); // Năm không hợp lệ
    cout << "Publication year after setting to 2030: " << book3.getPublicationYear() << endl;
    
    book3.setPublicationYear(-100); // Năm không hợp lệ
    cout << "Publication year after setting to -100: " << book3.getPublicationYear() << endl;
    
    return 0;
}