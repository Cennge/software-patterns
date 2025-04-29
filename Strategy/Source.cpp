#include <iostream>
#include <string>
using namespace std;

class ITransport
{
public:
    virtual void SetPrice(double price) = 0;
    virtual void SetTime(int minutes) = 0;
    virtual void TravelToAirport() = 0;
    virtual ~ITransport() {}
};

class Plane : public ITransport
{
private:
    double price;
    int time;
public:
    void SetPrice(double price) override
    {
        this->price = price;
    }

    void SetTime(int minutes) override
    {
        this->time = minutes;
    }

    void TravelToAirport() override
    {
        cout << "Flying to airport by plane!" << endl;
        cout << "Cost: $" << price << " (Most expensive)" << endl;
        cout << "Time: " << time << " minutes (Fastest)" << endl;
        cout << endl;
    }
};

class Bicycle : public ITransport
{
private:
    double price;
    int time;
public:
    void SetPrice(double price) override
    {
        this->price = price;
    }

    void SetTime(int minutes) override
    {
        this->time = minutes;
    }

    void TravelToAirport() override
    {
        cout << "Cycling to airport on bicycle!" << endl;
        cout << "Cost: $" << price << " (Free)" << endl;
        cout << "Time: " << time << " minutes (Slowest)" << endl;
        cout << endl;
    }
};

class Bus : public ITransport
{
private:
    double price;
    int time;
public:
    void SetPrice(double price) override
    {
        this->price = price;
    }

    void SetTime(int minutes) override
    {
        this->time = minutes;
    }

    void TravelToAirport() override
    {
        cout << "Taking the bus to airport!" << endl;
        cout << "Cost: $" << price << " (Inexpensive)" << endl;
        cout << "Time: " << time << " minutes (Moderate)" << endl;
        cout << endl;
    }
};

class Taxi : public ITransport
{
private:
    double price;
    int time;
public:
    void SetPrice(double price) override
    {
        this->price = price;
    }

    void SetTime(int minutes) override
    {
        this->time = minutes;
    }

    void TravelToAirport() override
    {
        cout << "Taking a taxi to airport!" << endl;
        cout << "Cost: $" << price << " (Expensive)" << endl;
        cout << "Time: " << time << " minutes (Fast)" << endl;
        cout << endl;
    }
};

class TravelPlanner
{
private:
    ITransport* transportStrategy;

public:
    TravelPlanner() : transportStrategy(nullptr) {}

    ~TravelPlanner()
    {

    }

    void SetTransportStrategy(ITransport* strategy)
    {
        this->transportStrategy = strategy;
    }

    void SetPrice(double price)
    {
        if (transportStrategy)
            transportStrategy->SetPrice(price);
    }

    void SetTime(int minutes)
    {
        if (transportStrategy)
            transportStrategy->SetTime(minutes);
    }

    void TravelToAirport()
    {
        if (transportStrategy)
            transportStrategy->TravelToAirport();
        else
            cout << "No transport strategy selected!" << endl;
    }
};

int main()
{
    TravelPlanner planner;

    Bicycle bicycle;
    Bus bus;
    Taxi taxi;
    Plane plane;

    planner.SetTransportStrategy(&bicycle);
    planner.SetPrice(0);
    planner.SetTime(120);
    cout << "Strategy 1: Bicycle (when money is limited)" << endl;
    planner.TravelToAirport();

    planner.SetTransportStrategy(&bus);
    planner.SetPrice(2);
    planner.SetTime(45);
    cout << "Strategy 2: Bus (when money is somewhat limited)" << endl;
    planner.TravelToAirport();

    planner.SetTransportStrategy(&taxi);
    planner.SetPrice(25);
    planner.SetTime(20);
    cout << "Strategy 3: Taxi (when time is limited)" << endl;
    planner.TravelToAirport();

    planner.SetTransportStrategy(&plane);
    planner.SetPrice(150);
    planner.SetTime(10);
    cout << "Strategy 4: Plane (when money is not an issue and time is critical)" << endl;
    planner.TravelToAirport();

    return 0;
}