#include <iostream>
#include <string>
#include <vector>

using namespace std;

class AirTrafficControl {
public:
    virtual void sendMessage(const string& message, class Aircraft* sender) = 0;
    virtual void registerAircraft(class Aircraft* aircraft) = 0;
    virtual ~AirTrafficControl() = default;
};

class Aircraft {
protected:
    AirTrafficControl* mediator;
    string name;

public:
    Aircraft(const string& name, AirTrafficControl* mediator)
        : name(name), mediator(mediator) {
        mediator->registerAircraft(this);
    }

    void send(const string& message) {
        mediator->sendMessage(message, this);
    }

    virtual void receive(const string& message) {
        cout << name << " received: " << message << endl;
    }

    string getName() const { return name; }
};

class ControlTower : public AirTrafficControl {
private:
    vector<Aircraft*> aircrafts;

public:
    void registerAircraft(Aircraft* aircraft) override {
        aircrafts.push_back(aircraft);
    }

    void sendMessage(const string& message, Aircraft* sender) override {
        for (Aircraft* aircraft : aircrafts) {
            if (aircraft != sender) {
                aircraft->receive(message);
            }
        }
    }
};

int main() {
    ControlTower tower;

    Aircraft plane1("Flight 101", &tower);
    Aircraft plane2("Flight 202", &tower);
    Aircraft plane3("Flight 303", &tower);

    plane1.send("Requesting landing clearance");
    plane2.send("Holding pattern established");

    return 0;
}
