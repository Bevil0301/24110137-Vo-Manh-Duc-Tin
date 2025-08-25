#include <iostream>
#include <string>

using namespace std;

class Laptop {
private:
    string brand;
    string model;
    int ram; // Dung lượng RAM tính bằng GB
    int storage; // Dung lượng ổ cứng tính bằng GB
    string gpu; // Card đồ họa

public:
    // Constructor mặc định
    Laptop() : brand("Unknown"), model("Unknown"), ram(4), storage(256), gpu("Integrated") {}
    
    // Constructor với tham số
    Laptop(string b, string m, int r, int s, string g = "Integrated") 
        : brand(b), model(m), ram(r), storage(s), gpu(g) {
        validateSpecs(); // Kiểm tra thông số kỹ thuật hợp lệ khi khởi tạo
    }
    
    // Getter và Setter methods
    string getBrand() const { return brand; }
    void setBrand(string b) { brand = b; }
    
    string getModel() const { return model; }
    void setModel(string m) { model = m; }
    
    int getRam() const { return ram; }
    void setRam(int r) { 
        ram = r; 
        validateSpecs(); // Kiểm tra thông số kỹ thuật hợp lệ khi thiết lập
    }
    
    int getStorage() const { return storage; }
    void setStorage(int s) { 
        storage = s; 
        validateSpecs(); // Kiểm tra thông số kỹ thuật hợp lệ khi thiết lập
    }
    
    string getGpu() const { return gpu; }
    void setGpu(string g) { gpu = g; }
    
    // Hiển thị thông tin laptop
    void displayInfo() const {
        cout << "\nLaptop Information:" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "RAM: " << ram << " GB" << endl;
        cout << "Storage: " << storage << " GB" << endl;
        cout << "GPU: " << gpu << endl;
    }
    
    // Kiểm tra xem laptop có đủ RAM để chạy phần mềm không
    void checkRAM(int requiredRAM) const {
        if (ram >= requiredRAM) {
            cout << "This laptop has enough RAM (" << ram << "GB) to run the software requiring " 
                 << requiredRAM << "GB." << endl;
        } else {
            cout << "This laptop does not have enough RAM (" << ram << "GB) to run the software requiring " 
                 << requiredRAM << "GB." << endl;
        }
    }
    
    // Kiểm tra card đồ họa có đủ mạnh để chơi game không
    void checkGPU(const string& requiredGPU = "Dedicated") const {
        if (gpu == "Dedicated" || gpu.find("RTX") != string::npos || gpu.find("GTX") != string::npos) {
            cout << "This laptop has a dedicated GPU (" << gpu << ") suitable for gaming." << endl;
        } else if (requiredGPU == "Integrated" && gpu == "Integrated") {
            cout << "This laptop has an integrated GPU, which is basic but functional." << endl;
        } else {
            cout << "This laptop's GPU (" << gpu << ") may not be sufficient for demanding games." << endl;
        }
    }
    
    // Nâng cấp RAM
    void upgradeRAM(int additionalRAM) {
        if (additionalRAM > 0) {
            ram += additionalRAM;
            cout << "Upgraded RAM by " << additionalRAM << "GB. New RAM: " << ram << "GB" << endl;
        } else {
            cout << "Invalid RAM upgrade amount. Must be positive." << endl;
        }
    }
    
    // Nâng cấp ổ cứng
    void upgradeStorage(int additionalStorage) {
        if (additionalStorage > 0) {
            storage += additionalStorage;
            cout << "Upgraded storage by " << additionalStorage << "GB. New storage: " << storage << "GB" << endl;
        } else {
            cout << "Invalid storage upgrade amount. Must be positive." << endl;
        }
    }
    
    // Kiểm tra xem laptop có đáp ứng yêu cầu hệ thống tối thiểu không
    bool meetsMinimumRequirements(int minRAM, int minStorage, const string& minGPU = "Integrated") const {
        bool hasEnoughRAM = ram >= minRAM;
        bool hasEnoughStorage = storage >= minStorage;
        bool hasGoodGPU = (minGPU == "Integrated") ? true : (gpu != "Integrated");
        
        return hasEnoughRAM && hasEnoughStorage && hasGoodGPU;
    }

private:
    // Kiểm tra thông số kỹ thuật hợp lệ
    void validateSpecs() {
        if (ram < 1) {
            ram = 4;
            cout << "Warning: RAM must be at least 1GB. Set to default 4GB." << endl;
        }
        if (storage < 1) {
            storage = 256;
            cout << "Warning: Storage must be at least 1GB. Set to default 256GB." << endl;
        }
    }
};

int main() {
    // Tạo đối tượng Laptop với constructor có tham số
    Laptop laptop1("Dell", "XPS 13", 8, 256, "Intel Iris Xe");
    laptop1.displayInfo();
    
    // Kiểm tra RAM cho phần mềm yêu cầu 16GB
    laptop1.checkRAM(16);
    
    // Kiểm tra card đồ họa cho chơi game
    laptop1.checkGPU("Dedicated");
    
    cout << "\n";
    
    // Test nâng cấp RAM
    cout << "Testing RAM upgrade:" << endl;
    laptop1.upgradeRAM(8);
    laptop1.displayInfo();
    laptop1.checkRAM(16); // Kiểm tra lại sau khi nâng cấp
    
    cout << "\n";
    
    // Tạo laptop gaming
    Laptop laptop2("ASUS", "ROG Zephyrus", 16, 1000, "NVIDIA RTX 4070");
    laptop2.displayInfo();
    laptop2.checkGPU("Dedicated");
    
    // Kiểm tra yêu cầu hệ thống
    cout << "\nTesting system requirements check:" << endl;
    bool meetsReq = laptop2.meetsMinimumRequirements(8, 512, "Dedicated");
    cout << "Meets minimum gaming requirements: " << (meetsReq ? "Yes" : "No") << endl;
    
    cout << "\n";
    
    // Test validation cho thông số kỹ thuật
    cout << "Testing specs validation:" << endl;
    Laptop laptop3("Test", "Test Model", -2, -100, "Test GPU"); // Thông số không hợp lệ
    laptop3.displayInfo();
    
    return 0;
}