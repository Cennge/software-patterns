#include <iostream>
#include <string>

using namespace std;

class PC {
    string CPU;
    string RAM;
    string GPU;
    string SSD;
    string Motherboard;
public:
    void SetCPU(string cpu) { this->CPU = cpu; }
    string GetCPU() { return this->CPU; }

    void SetRAM(string ram) { this->RAM = ram; }
    string GetRAM() { return this->RAM; }

    void SetGPU(string gpu) { this->GPU = gpu; }
    string GetGPU() { return this->GPU; }

    void SetSSD(string ssd) { this->SSD = ssd; }
    string GetSSD() { return this->SSD; }

    void SetMotherboard(string motherboard) { this->Motherboard = motherboard; }
    string GetMotherboard() { return this->Motherboard; }

    void ShowPC()
    {
        cout << "PC Configuration: " << endl;
        cout << " CPU: " << CPU << endl;
        cout << " RAM: " << RAM << endl;
        cout << " GPU: " << GPU << endl;
        cout << " SSD: " << SSD << endl;
        cout << " Motherboard: " << Motherboard << endl;
    }
};

class PCBuilder {
protected:
    PC pc;
public:
    PC GetPC() { return pc; }
    virtual void BuildCPU() = 0;
    virtual void BuildRAM() = 0;
    virtual void BuildGPU() = 0;
    virtual void BuildSSD() = 0;
    virtual void BuildMotherboard() = 0;
};

class GamingPCBuilder : public PCBuilder {
public:
    void BuildCPU() override { pc.SetCPU("Ryzen 9 5900x"); }
    void BuildRAM() override { pc.SetRAM("32GB"); }
    void BuildGPU() override { pc.SetGPU("NVIDIA RTX 4090"); }
    void BuildSSD() override { pc.SetSSD("2TB NVMe"); }
    void BuildMotherboard() override { pc.SetMotherboard("ASUS ROG Maximus"); }
};

class OfficePCBuilder : public PCBuilder {
public:
    void BuildCPU() override { pc.SetCPU("Intel i5"); }
    void BuildRAM() override { pc.SetRAM("16GB"); }
    void BuildGPU() override { pc.SetGPU("Integrated Graphics"); }
    void BuildSSD() override { pc.SetSSD("512GB NVMe"); }
    void BuildMotherboard() override { pc.SetMotherboard("MSI B450M"); }
};

class PurePC {
    PCBuilder* pcBuilder;
public:
    void SetPCBuilder(PCBuilder* builder) { pcBuilder = builder; }
    PC GetPC() { return pcBuilder->GetPC(); }
    void ConstructPC()
    {
        pcBuilder->BuildCPU();
        pcBuilder->BuildRAM();
        pcBuilder->BuildGPU();
        pcBuilder->BuildSSD();
        pcBuilder->BuildMotherboard();
    }
};

void client(PCBuilder* builder) {
    PurePC assembler;
    assembler.SetPCBuilder(builder);
    assembler.ConstructPC();
    PC pc = assembler.GetPC();
    pc.ShowPC();
}

int main() {
    PCBuilder* builder = new GamingPCBuilder();
    client(builder);
    delete builder;

    builder = new OfficePCBuilder();
    client(builder);
    delete builder;

    system("pause");
    return 0;
}
