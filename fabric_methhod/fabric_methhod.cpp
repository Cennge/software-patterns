#include <iostream>

using namespace std;

class Transport {
public:
    virtual ~Transport() {}
    virtual std::string Deliver() const = 0;
};

class Truck : public Transport {
public:
    std::string Deliver() const override {
        return "Truck deliver!";
    }
};

class Ship : public Transport {
public:
    std::string Deliver() const override {
        return "Ship deliver!";
    }
};

class Logistic {
public:
    virtual ~Logistic() {};
    virtual Transport* FactoryMethod() const = 0;
    std::string SomeOperation() const {
        Transport* transport = this->FactoryMethod();
        std::string result = "Logistic: created " + transport->Deliver();
        delete transport;
        return result;
    }
};

class CreateTruck : public Logistic {
public:
    Transport* FactoryMethod() const override {
        return new Truck();
    }
};

class CreateShip: public Logistic {
public:
    Transport* FactoryMethod() const override {
        return new Ship();
    }
};

int main() {
    
}