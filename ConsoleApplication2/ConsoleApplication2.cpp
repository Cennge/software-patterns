#include <iostream>
#include <string>

using namespace std;

class Device {
public:
    virtual string GetInfo() const = 0;
    virtual ~Device() {} 
};

class VideoCard : public Device {
public:
    string GetInfo() const override {
        return "Видеокарта: NVIDIA GeForce RTX 4060 Ti 16GB";
    }
};

class Processor : public Device {
public:
    string GetInfo() const override {
        return "Процессор: AMD Ryzen 9 5900X";
    }
};

class HardDrive : public Device {
public:
    string GetInfo() const override {
        return "Жесткий диск: SSD 512GB NVMe";
    }
};

class RAM : public Device {
public:
    string GetInfo() const override {
        return "Оперативная память: 32GB ADATA DDR4";
    }
};

class Report {
protected:
    Device* device;
public:
    Report(Device* dev) : device(dev) {}
    virtual void Show() const = 0;
    virtual ~Report() {}
};

class TextReport : public Report {
public:
    TextReport(Device* dev) : Report(dev) {}

    void Show() const override {
        cout << "----- ОТЧЕТ УСТРОЙСТВА -----" << endl;
        cout << device->GetInfo() << endl;
        cout << "-----------------------------" << endl;
    }
};

int main() {
    VideoCard videoCard;
    Processor processor;
    HardDrive hardDrive;
    RAM ram;

    TextReport report1(&videoCard);
    report1.Show();

    TextReport report2(&processor);
    report2.Show();

    TextReport report3(&hardDrive);
    report3.Show();

    TextReport report4(&ram);
    report4.Show();

    return 0;
}
