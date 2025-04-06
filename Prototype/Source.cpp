#include <iostream>
#include <string>
using namespace std;

// Абстрактный прототип
class AbstractComponent {
protected:
    string producer;
public:
    virtual ~AbstractComponent() {}
    void SetProducer(const string& p) { producer = p; }
    string GetProducer() const { return producer; }
    virtual AbstractComponent* Clone() const = 0;
};

class Frame : public AbstractComponent {
    string material;
public:
    void SetMaterial(const string& m) { material = m; }
    string GetMaterial() const { return material; }
    AbstractComponent* Clone() const override {
        Frame* f = new Frame(*this);
        return f;
    }
};

class ControlSystem : public AbstractComponent {
    string type;
public:
    void SetType(const string& t) { type = t; }
    string GetType() const { return type; }
    AbstractComponent* Clone() const override {
        return new ControlSystem(*this);
    }
};

class Engine : public AbstractComponent {
    int horsepower;
public:
    void SetHorsePower(int hp) { horsepower = hp; }
    int GetHorsePower() const { return horsepower; }
    AbstractComponent* Clone() const override {
        return new Engine(*this);
    }
};

class Transmission : public AbstractComponent {
    string transmissionType;
public:
    void SetTransmissionType(const string& t) { transmissionType = t; }
    string GetTransmissionType() const { return transmissionType; }
    AbstractComponent* Clone() const override {
        return new Transmission(*this);
    }
};

class Chassis : public AbstractComponent {
    string suspensionType;
public:
    void SetSuspensionType(const string& t) { suspensionType = t; }
    string GetSuspensionType() const { return suspensionType; }
    AbstractComponent* Clone() const override {
        return new Chassis(*this);
    }
};

class ElectricalSystem : public AbstractComponent {
    int voltage;
public:
    void SetVoltage(int v) { voltage = v; }
    int GetVoltage() const { return voltage; }
    AbstractComponent* Clone() const override {
        return new ElectricalSystem(*this);
    }
};

class Car {
    Frame* frame;
    ControlSystem* controlSystem;
    Engine* engine;
    Transmission* transmission;
    Chassis* chassis;
    ElectricalSystem* electricalSystem;
public:
    Car() : frame(nullptr), controlSystem(nullptr), engine(nullptr),
            transmission(nullptr), chassis(nullptr), electricalSystem(nullptr) {}

    ~Car() {
        delete frame;
        delete controlSystem;
        delete engine;
        delete transmission;
        delete chassis;
        delete electricalSystem;
    }

    void SetFrame(Frame* f) { frame = f; }
    void SetControlSystem(ControlSystem* cs) { controlSystem = cs; }
    void SetEngine(Engine* e) { engine = e; }
    void SetTransmission(Transmission* t) { transmission = t; }
    void SetChassis(Chassis* c) { chassis = c; }
    void SetElectricalSystem(ElectricalSystem* es) { electricalSystem = es; }

    Car* Clone() const {
        Car* clone = new Car();
        if (frame) clone->SetFrame(static_cast<Frame*>(frame->Clone()));
        if (controlSystem) clone->SetControlSystem(static_cast<ControlSystem*>(controlSystem->Clone()));
        if (engine) clone->SetEngine(static_cast<Engine*>(engine->Clone()));
        if (transmission) clone->SetTransmission(static_cast<Transmission*>(transmission->Clone()));
        if (chassis) clone->SetChassis(static_cast<Chassis*>(chassis->Clone()));
        if (electricalSystem) clone->SetElectricalSystem(static_cast<ElectricalSystem*>(electricalSystem->Clone()));
        return clone;
    }

    void Print() const {
        cout << "Car configuration:\n";
        if (frame) cout << "Frame: " << frame->GetProducer() << ", Material: " << frame->GetMaterial() << endl;
        if (controlSystem) cout << "ControlSystem: " << controlSystem->GetProducer() << ", Type: " << controlSystem->GetType() << endl;
        if (engine) cout << "Engine: " << engine->GetProducer() << ", Horsepower: " << engine->GetHorsePower() << endl;
        if (transmission) cout << "Transmission: " << transmission->GetProducer() << ", Type: " << transmission->GetTransmissionType() << endl;
        if (chassis) cout << "Chassis: " << chassis->GetProducer() << ", Suspension: " << chassis->GetSuspensionType() << endl;
        if (electricalSystem) cout << "ElectricalSystem: " << electricalSystem->GetProducer() << ", Voltage: " << electricalSystem->GetVoltage() << "V" << endl;
    }
};

Car* CreateSportCar() {
    Car* car = new Car();

    Frame* frame = new Frame();
    frame->SetProducer("CarbonTech");
    frame->SetMaterial("Carbon Fiber");
    car->SetFrame(frame);

    ControlSystem* cs = new ControlSystem();
    cs->SetProducer("Bosch");
    cs->SetType("Sport");
    car->SetControlSystem(cs);

    Engine* engine = new Engine();
    engine->SetProducer("Ferrari");
    engine->SetHorsePower(600);
    car->SetEngine(engine);

    Transmission* tr = new Transmission();
    tr->SetProducer("ZF");
    tr->SetTransmissionType("Automatic Dual-Clutch");
    car->SetTransmission(tr);

    Chassis* chassis = new Chassis();
    chassis->SetProducer("Bilstein");
    chassis->SetSuspensionType("Sport");
    car->SetChassis(chassis);

    ElectricalSystem* es = new ElectricalSystem();
    es->SetProducer("Delphi");
    es->SetVoltage(12);
    car->SetElectricalSystem(es);

    return car;
}

int main() {
    Car* sportCar = CreateSportCar();
    sportCar->Print();

    cout << "\n--- Cloning the car ---\n";
    Car* cloneCar = sportCar->Clone();
    cloneCar->Print();

    delete sportCar;
    delete cloneCar;

    return 0;
}
