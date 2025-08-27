#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int favoriteLevel; // Thêm thuộc tính mới: mức độ yêu thích (0-5 sao)

public:
    // Constructor
    Book(string bookTitle = "Unknown", string bookAuthor = "Unknown", int level = 3) {
        title = bookTitle;
        author = bookAuthor;
        setFavoriteLevel(level); // Sử dụng setter để kiểm tra tính hợp lệ
    }
    
    // Phương thức hiển thị thông tin sách (đã được cải tiến)
    void displayInfo() {
        cout << "\n=== THONG TIN SACH ===" << endl;
        cout << "Tieu de: " << title << endl;
        cout << "Tac gia: " << author << endl;
        cout << "Danh gia: ";
        displayStars(); // Hiển thị đánh giá bằng sao
    }
    
    // Getter và Setter cho title
    void setTitle(string bookTitle) {
        title = bookTitle;
    }
    
    string getTitle() {
        return title;
    }
    
    // Getter và Setter cho author
    void setAuthor(string bookAuthor) {
        author = bookAuthor;
    }
    
    string getAuthor() {
        return author;
    }
    
    // Getter và Setter cho favoriteLevel với kiểm tra hợp lệ
    void setFavoriteLevel(int level) {
        // Kiểm tra mức độ yêu thích hợp lệ (0-5)
        if (level >= 0 && level <= 5) {
            favoriteLevel = level;
        } else {
            cout << "Muc do yeu thich khong hop le! Dat muc mac dinh (3)." << endl;
            favoriteLevel = 3;
        }
    }
    
    int getFavoriteLevel() {
        return favoriteLevel;
    }
    
    // PHẦN BỔ SUNG: Hiển thị đánh giá bằng ngôi sao
    void displayStars() {
        for (int i = 0; i < favoriteLevel; i++) {
            cout << "★"; // In sao đầy
        }
        for (int i = favoriteLevel; i < 5; i++) {
            cout << "☆"; // In sao rỗng
        }
        cout << " (" << favoriteLevel << "/5)" << endl;
    }
};

int main() {
    cout << "=== HE THONG QUAN LY SACH ===" << endl;
    
    // Sách 1: Sách yêu thích của tôi
    Book book1("Dế Mèn Phiêu Lưu Ký", "Tô Hoài", 5);
    cout << "\nSach 1: Sach yeu thich cua toi" << endl;
    book1.displayInfo();
    
    // Sách 2: Sách học tập
    Book book2("Nhập môn Lập trình C++", "Nguyễn Văn A", 4);
    cout << "\nSach 2: Sach hoc tap" << endl;
    book2.displayInfo();
    
    // Sách 3: Thử đặt mức độ không hợp lệ
    Book book3("Truyện Kiều", "Nguyễn Du", 7); // Mức không hợp lệ
    cout << "\nSach 3: Thu muc do khong hop le" << endl;
    book3.displayInfo();
    
    // Cập nhật đánh giá cho sách
    cout << "\n=== CAP NHAT DANH GIA ===" << endl;
    book2.setFavoriteLevel(5);
    cout << "Sau khi doc ky, toi tang danh gia cho sach 2:" << endl;
    book2.displayInfo();
    
    return 0;
}