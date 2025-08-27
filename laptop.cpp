#include <iostream>
#include <string>
using namespace std;

class Laptop {
private:
    string brand;
    string model;
    int ram;
    int storage;
    string gpu; // Thêm thuộc tính card đồ họa

public:
    // Constructor
    Laptop(string b = "Unknown", string m = "Unknown", int r = 4, int s = 256, string g = "Integrated") {
        brand = b;
        model = m;
        ram = r;
        storage = s;
        gpu = g;
    }
    
    // Phương thức hiển thị thông tin
    void displayInfo() {
        cout << "\n=== THONG TIN LAPTOP ===" << endl;
        cout << "Thuong hieu: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "RAM: " << ram << " GB" << endl;
        cout << "Luu tru: " << storage << " GB" << endl;
        cout << "Card do hoa: " << gpu << endl;
    }
    
    // Phương thức kiểm tra RAM
    void checkRAM(int requiredRAM) {
        if (ram >= requiredRAM) {
            cout << "May nay du RAM de chay phan mem." << endl;
        } else {
            cout << "May nay KHONG du RAM de chay phan mem." << endl;
            cout << "Thieu " << (requiredRAM - ram) << " GB RAM" << endl;
        }
    }
    
    // PHẦN MỞ RỘNG: Phương thức kiểm tra card đồ họa
    void checkGPU() {
        if (gpu.find("RTX") != string::npos || gpu.find("GTX") != string::npos) {
            cout << "Card do hoa manh, co the choi game nang." << endl;
        } else if (gpu.find("Integrated") != string::npos) {
            cout << "Card do hoa tich hop, phu hop cho van phong." << endl;
        } else {
            cout << "Card do hoa trung binh." << endl;
        }
    }
    
    // PHẦN MỞ RỘNG: Phương thức nâng cấp RAM
    void upgradeRAM(int additionalRAM) {
        if (additionalRAM > 0) {
            ram += additionalRAM;
            cout << "Da nang cap them " << additionalRAM << " GB RAM." << endl;
            cout << "Tong RAM hien tai: " << ram << " GB" << endl;
        } else {
            cout << "So RAM nang cap phai lon hon 0!" << endl;
        }
    }
    
    // Getter và Setter cho GPU
    void setGPU(string graphicCard) {
        gpu = graphicCard;
    }
    
    string getGPU() {
        return gpu;
    }
};

int main() {
    cout << "=== HE THONG QUAN LY LAPTOP ===" << endl;
    
    // Tạo laptop 1
    Laptop laptop1("Dell", "XPS 13", 8, 256, "Integrated");
    laptop1.displayInfo();
    laptop1.checkRAM(16);
    laptop1.checkGPU();
    
    // Tạo laptop 2
    Laptop laptop2("ASUS", "ROG Strix", 16, 512, "RTX 3060");
    laptop2.displayInfo();
    laptop2.checkRAM(16);
    laptop2.checkGPU();
    
    // Nâng cấp RAM cho laptop1
    cout << "\n=== NANG CAP RAM CHO LAPTOP1 ===" << endl;
    laptop1.upgradeRAM(8);
    laptop1.checkRAM(16);
    
    return 0;
}