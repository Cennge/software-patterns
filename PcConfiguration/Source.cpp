#include <iostream>
#include <string>
using namespace std;

class Box abstract {
public:
	virtual string GetName() abstract;
};

class Hdd abstract {
public:
	virtual string GetName() abstract;
};

class MainBoard abstract {
public:
	virtual string GetName() abstract;
};

class Processor abstract {
public:
	virtual string GetName() abstract;
};

class Memory abstract {
public:
	virtual string GetName() abstract;
};

class Gpu abstract {
public:
	virtual string GetName() abstract;
};

class SilverBox : public Box {
public:
	string GetName() override { return "SilverBox"; }
};

class BlackBox : public Box {
public:
	string GetName() override { return "BlackBox"; }
};

class SamsungHDD : public Hdd {
public:
	string GetName() override { return "Samsung HDD"; }
};

class LGHDD : public Hdd {
public:
	string GetName() override { return "LG HDD"; }
};

class MSIMainBord : public MainBoard {
public:
	string GetName() override { return "MSI MainBoard"; }
};

class AsusMainBord : public MainBoard {
public:
	string GetName() override { return "Asus MainBoard"; }
};

class IntelProcessor : public Processor {
public:
	string GetName() override { return "Intel Processor"; }
};

class AmdProcessor : public Processor {
public:
	string GetName() override { return "AMD Processor"; }
};

class Ddr3Memory : public Memory {
public:
	string GetName() override { return "DDR3 Memory"; }
};

class Ddr2Memory : public Memory {
public:
	string GetName() override { return "DDR2 Memory"; }
};

class IntegratedGpu : public Gpu {
public:
	string GetName() override { return "Integrated GPU"; }
};

class NvidiaGpu : public Gpu {
public:
	string GetName() override { return "Nvidia GPU"; }
};

class Pc {
	Box* box;
	Processor* processor;
	MainBoard* mainboard;
	Hdd* hdd;
	Memory* memory;
	Gpu* gpu;

public:
	void SetBox(Box* box) { this->box = box; }
	void SetProcessor(Processor* processor) { this->processor = processor; }
	void SetMainBoard(MainBoard* mainboard) { this->mainboard = mainboard; }
	void SetHdd(Hdd* hdd) { this->hdd = hdd; }
	void SetMemory(Memory* memory) { this->memory = memory; }
	void SetGpu(Gpu* gpu) { this->gpu = gpu; }

	Box* GetBox() { return box; }
	Processor* GetProcessor() { return processor; }
	MainBoard* GetMainBoard() { return mainboard; }
	Hdd* GetHdd() { return hdd; }
	Memory* GetMemory() { return memory; }
	Gpu* GetGpu() { return gpu; }
};

class IPcFactory abstract {
public:
	virtual Box* CreateBox() abstract;
	virtual Processor* CreateProcessor() abstract;
	virtual MainBoard* CreateMainBoard() abstract;
	virtual Hdd* CreateHdd() abstract;
	virtual Memory* CreateMemory() abstract;
	virtual Gpu* CreateGpu() abstract;
};

class HomePcFactory : public IPcFactory {
public:
	Box* CreateBox() override { return new SilverBox(); }
	Processor* CreateProcessor() override { return new IntelProcessor(); }
	MainBoard* CreateMainBoard() override { return new MSIMainBord(); }
	Hdd* CreateHdd() override { return new SamsungHDD(); }
	Memory* CreateMemory() override { return new Ddr3Memory(); }
	Gpu* CreateGpu() override { return new IntegratedGpu(); }
};

class OfficePcFactory : public IPcFactory {
public:
	Box* CreateBox() override { return new BlackBox(); }
	Processor* CreateProcessor() override { return new AmdProcessor(); }
	MainBoard* CreateMainBoard() override { return new AsusMainBord(); }
	Hdd* CreateHdd() override { return new LGHDD(); }
	Memory* CreateMemory() override { return new Ddr2Memory(); }
	Gpu* CreateGpu() override { return new IntegratedGpu(); }
};

class GamingPcFactory : public IPcFactory {
public:
	Box* CreateBox() override { return new BlackBox(); }
	Processor* CreateProcessor() override { return new IntelProcessor(); }
	MainBoard* CreateMainBoard() override { return new MSIMainBord(); }
	Hdd* CreateHdd() override { return new SamsungHDD(); }
	Memory* CreateMemory() override { return new Ddr3Memory(); }
	Gpu* CreateGpu() override { return new NvidiaGpu(); }
};

class PcConfigurator {
	IPcFactory* PcFactory;

public:
	void SetFactory(IPcFactory* pFactory) { PcFactory = pFactory; }

	void Configure(Pc& pc)
	{
		pc.SetBox(PcFactory->CreateBox());
		pc.SetMainBoard(PcFactory->CreateMainBoard());
		pc.SetHdd(PcFactory->CreateHdd());
		pc.SetMemory(PcFactory->CreateMemory());
		pc.SetProcessor(PcFactory->CreateProcessor());
		pc.SetGpu(PcFactory->CreateGpu());
	}
};

void PrintPcConfiguration(string configName, IPcFactory* PcFactory) {
	Pc pc;
	PcConfigurator configurator;
	configurator.SetFactory(PcFactory);
	configurator.Configure(pc);
	cout << "======== " + configName + " ========\n";
	cout << "Box: " + pc.GetBox()->GetName() + "\n";
	cout << "MainBoard: " + pc.GetMainBoard()->GetName() + "\n";
	cout << "Processor: " + pc.GetProcessor()->GetName() + "\n";
	cout << "HDD: " + pc.GetHdd()->GetName() + "\n";
	cout << "Memory: " + pc.GetMemory()->GetName() + "\n";
	cout << "GPU: " + pc.GetGpu()->GetName() + "\n";
}

int main() {
	IPcFactory* PcFactory = new HomePcFactory();
	PrintPcConfiguration("Home configuration", PcFactory);
	delete PcFactory;

	PcFactory = new OfficePcFactory();
	PrintPcConfiguration("Office configuration", PcFactory);
	delete PcFactory;

	PcFactory = new GamingPcFactory();
	PrintPcConfiguration("Gaming configuration", PcFactory);
	delete PcFactory;

	system("pause");
	return 0;
}
