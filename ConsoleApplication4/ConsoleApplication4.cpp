#include <iostream>
using namespace std;

class PowerSupply {
public:
    void supplyPower() {
        cout << "PowerSupply: Power supplied" << endl;
    }

    void shutdown() {
        cout << "PowerSupply: Shutdown" << endl;
    }
};

class Sensors {
public:
    bool checkVoltage() {
        cout << "Sensors: Voltage check passed" << endl;
        return true;
    }

    bool checkTemperature() {
        cout << "Sensors: Temperature check passed" << endl;
        return true;
    }

    void checkAllTemperatures() {
        cout << "Sensors: All systems temperature checked" << endl;
    }
};

class VideoCard {
public:
    void start() {
        cout << "VideoCard: Started" << endl;
    }

    void displayInfo() {
        cout << "VideoCard: Displaying info" << endl;
    }
};

class RAM {
public:
    void start() {
        cout << "RAM: Started" << endl;
    }

    void clear() {
        cout << "RAM: Cleared" << endl;
    }

    void analyze() {
        cout << "RAM: Memory analyzed" << endl;
    }
};

class HardDrive {
public:
    void start() {
        cout << "HardDrive: Started" << endl;
    }

    void stop() {
        cout << "HardDrive: Stopped" << endl;
    }

    void checkBootSector() {
        cout << "HardDrive: Boot sector checked" << endl;
    }
};

class OpticalDrive {
public:
    void start() {
        cout << "OpticalDrive: Started" << endl;
    }

    void checkDisk() {
        cout << "OpticalDrive: Disk check performed" << endl;
    }

    void reset() {
        cout << "OpticalDrive: Returned to initial position" << endl;
    }
};

class ComputerFacade {
private:
    PowerSupply ps;
    Sensors sensors;
    VideoCard vc;
    RAM ram;
    HardDrive hdd;
    OpticalDrive od;

public:
    void turnOn() {
        cout << "----- Starting Computer -----" << endl;
        ps.supplyPower();

        sensors.checkVoltage();
        sensors.checkTemperature();
        sensors.checkTemperature();

        ps.supplyPower();
        vc.start();
        vc.displayInfo();

        sensors.checkTemperature();

        ps.supplyPower();
        ram.start();
        ram.analyze();
        vc.displayInfo();

        ps.supplyPower();
        od.start();
        od.checkDisk();
        vc.displayInfo();

        ps.supplyPower();
        hdd.start();
        hdd.checkBootSector();
        vc.displayInfo();

        sensors.checkAllTemperatures();
        cout << "----- Computer Started Successfully -----\n" << endl;
    }

    void turnOff() {
        cout << "----- Shutting Down Computer -----" << endl;
        hdd.stop();
        ram.clear();
        ram.analyze();
        vc.displayInfo();
        od.reset();

        ps.supplyPower();
        sensors.checkVoltage();
        ps.shutdown();
        cout << "----- Computer Shut Down Successfully -----" << endl;
    }
};

int main() {
    srand(time(0));
    ComputerFacade computer;
    computer.turnOn();
    computer.turnOff();
    return 0;
}
