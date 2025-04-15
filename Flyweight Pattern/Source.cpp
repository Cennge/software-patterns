#include <iostream>
#include <map>
#include <string>
using namespace std;

class MilitaryUnit
{
protected:
    int speed;
    int power;      
    string image;   

public:
    virtual void Show(double x, double y) = 0;

    int GetSpeed() const { return speed; }
    int GetPower() const { return power; }
    string GetImage() const { return image; }
};

class LightInfantry : public MilitaryUnit
{
public:
    LightInfantry()
    {
        speed = 20;
        power = 10;
        image = "light_infantry.png";
    }

    void Show(double x, double y) override
    {
        cout << "Light Infantry (Speed: " << speed << ", Power: " << power << ")" << endl;
        cout << "Position: X = " << x << ", Y = " << y << endl;
        cout << "Image: " << image << endl << endl;
    }
};

class Transport : public MilitaryUnit
{
public:
    Transport()
    {
        speed = 70;
        power = 0;
        image = "transport.png";
    }

    void Show(double x, double y) override
    {
        cout << "Transport Vehicle (Speed: " << speed << ", Power: " << power << ")" << endl;
        cout << "Position: X = " << x << ", Y = " << y << endl;
        cout << "Image: " << image << endl << endl;
    }
};

class HeavyCombat : public MilitaryUnit
{
public:
    HeavyCombat()
    {
        speed = 15;
        power = 150;
        image = "heavy_combat.png";
    }

    void Show(double x, double y) override
    {
        cout << "Heavy Combat Vehicle (Speed: " << speed << ", Power: " << power << ")" << endl;
        cout << "Position: X = " << x << ", Y = " << y << endl;
        cout << "Image: " << image << endl << endl;
    }
};

class LightCombat : public MilitaryUnit
{
public:
    LightCombat()
    {
        speed = 50;
        power = 30;
        image = "light_combat.png";
    }

    void Show(double x, double y) override
    {
        cout << "Light Combat Vehicle (Speed: " << speed << ", Power: " << power << ")" << endl;
        cout << "Position: X = " << x << ", Y = " << y << endl;
        cout << "Image: " << image << endl << endl;
    }
};

class Aircraft : public MilitaryUnit
{
public:
    Aircraft()
    {
        speed = 300;
        power = 100;
        image = "aircraft.png";
    }

    void Show(double x, double y) override
    {
        cout << "Aircraft (Speed: " << speed << ", Power: " << power << ")" << endl;
        cout << "Position: X = " << x << ", Y = " << y << endl;
        cout << "Image: " << image << endl << endl;
    }
};

class MilitaryUnitFactory
{
private:
    map<string, MilitaryUnit*> units;

public:
    MilitaryUnitFactory()
    {
        units["LightInfantry"] = new LightInfantry();
        units["Transport"] = new Transport();
        units["HeavyCombat"] = new HeavyCombat();
        units["LightCombat"] = new LightCombat();
        units["Aircraft"] = new Aircraft();
    }

    ~MilitaryUnitFactory()
    {
        for (auto& pair : units)
        {
            delete pair.second;
        }
        units.clear();
    }

    MilitaryUnit* GetUnit(string type)
    {
        if (units.find(type) != units.end())
        {
            return units[type];
        }
        return nullptr;
    }
};

int main()
{
    MilitaryUnitFactory* factory = new MilitaryUnitFactory();

    cout << "===== Deploying Light Infantry Squad =====" << endl;
    for (int i = 0; i < 5; i++)
    {
        MilitaryUnit* unit = factory->GetUnit("LightInfantry");
        if (unit)
        {
            unit->Show(10.0 + i * 2, 20.0 + i);
        }
    }

    cout << "===== Deploying Transport Column =====" << endl;
    for (int i = 0; i < 3; i++)
    {
        MilitaryUnit* unit = factory->GetUnit("Transport");
        if (unit)
        {
            unit->Show(50.0 + i * 5, 30.0);
        }
    }

    cout << "===== Deploying Heavy Combat Vehicles =====" << endl;
    for (int i = 0; i < 2; i++)
    {
        MilitaryUnit* unit = factory->GetUnit("HeavyCombat");
        if (unit)
        {
            unit->Show(100.0 + i * 10, 50.0);
        }
    }

    cout << "===== Deploying Light Combat Vehicles =====" << endl;
    for (int i = 0; i < 4; i++)
    {
        MilitaryUnit* unit = factory->GetUnit("LightCombat");
        if (unit)
        {
            unit->Show(80.0 + i * 3, 70.0 + i * 2);
        }
    }

    cout << "===== Deploying Aircraft =====" << endl;
    for (int i = 0; i < 3; i++)
    {
        MilitaryUnit* unit = factory->GetUnit("Aircraft");
        if (unit)
        {
            unit->Show(200.0 + i * 20, 200.0 + i * 10);
        }
    }

    delete factory;

    system("Pause");
    return 0;
}