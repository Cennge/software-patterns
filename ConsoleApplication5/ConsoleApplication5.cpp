#include <iostream>
#include <string>
using namespace std;

class Payment {
public:
    virtual void pay(double amount) = 0;
    virtual ~Payment() {}
};

class CreditCard : public Payment {
public:
    void pay(double amount) override {
        cout << "Оплата " << amount << " с помощью кредитной карты.\n";
    }
};

class Cash : public Payment {
public:
    void pay(double amount) override {
        cout << "Оплата " << amount << " наличными.\n";
    }
};

void processPayment(Payment* paymentMethod, double amount) {
    paymentMethod->pay(amount);
}

int main() {
    Payment* payment1 = new CreditCard();
    Payment* payment2 = new Cash();

    processPayment(payment1, 1500.50);
    processPayment(payment2, 780.20);

    delete payment1;
    delete payment2;

    return 0;
}
