#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Component {
protected:
    string name;
    double price;

public:
    Component(string name, double price) : name(name), price(price) {}
    virtual void Add(Component* c) = 0;
    virtual void Remove(Component* c) = 0;
    virtual void Display(int depth) = 0;
    virtual double GetTotalPrice() = 0;
};

class Composite : public Component {
    vector<Component*> components;

public:
    Composite(string name, double price = 0) : Component(name, price) {}

    void Add(Component* component) override {
        components.push_back(component);
    }

    void Remove(Component* component) override {
        auto iter = find(components.begin(), components.end(), component);
        if (iter != components.end())
            components.erase(iter);
    }

    void Display(int depth) override {
        string s(depth, '-');
        cout << s << name << " (Цена: " << price << ")\n";
        for (Component* component : components) {
            component->Display(depth + 2);
        }
    }

    double GetTotalPrice() override {
        double total = price;
        for (Component* component : components) {
            total += component->GetTotalPrice();
        }
        return total;
    }
};

class Leaf : public Component {
public:
    Leaf(string name, double price) : Component(name, price) {}

    void Add(Component* c) override {
        cout << "Нельзя добавить элемент к: " << name << endl;
    }

    void Remove(Component* c) override {
        cout << "Нельзя удалить элемент из: " << name << endl;
    }

    void Display(int depth) override {
        string s(depth, '-');
        cout << s << name << " (Цена: " << price << ")\n";
    }

    double GetTotalPrice() override {
        return price;
    }
};

int main() {
    setlocale(LC_ALL, "");
    Component* office = new Composite("Офис");

    Component* reception = new Composite("Приемная");
    reception->Add(new Leaf("Журнальный столик", 200));
    reception->Add(new Leaf("Мягкий диван", 500));
    Component* secretaryDesk = new Composite("Стол секретаря");
    secretaryDesk->Add(new Leaf("Компьютер", 800));
    secretaryDesk->Add(new Leaf("Офисный инструментарий", 150));
    reception->Add(secretaryDesk);
    reception->Add(new Leaf("Кулер с водой", 300));
    office->Add(reception);

    Component* classroom1 = new Composite("Аудитория 1");
    classroom1->Add(new Leaf("10 столов", 1000));
    classroom1->Add(new Leaf("Доска", 150));
    Component* teacherDesk = new Composite("Стол учителя");
    teacherDesk->Add(new Leaf("Компьютер", 800));
    classroom1->Add(teacherDesk);
    classroom1->Add(new Leaf("Плакаты великих математиков", 50));
    office->Add(classroom1);

    Component* cafeteria = new Composite("Столовая");
    cafeteria->Add(new Leaf("Кофейный автомат", 1000));
    cafeteria->Add(new Leaf("Стол с 4 стульями", 300));
    cafeteria->Add(new Leaf("Холодильник", 700));
    cafeteria->Add(new Leaf("Умывальник", 250));
    office->Add(cafeteria);

    office->Display(1);
    cout << "\nИтоговая стоимость обустройства офиса: " << office->GetTotalPrice() << " $\n";

    system("pause");
    return 0;
}
