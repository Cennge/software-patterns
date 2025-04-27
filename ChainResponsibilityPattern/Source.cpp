#include <iostream>

using namespace std;

// Класс-получатель запроса
class Receiver
{
	// банковские переводы
	bool BankTransfer;
	// денежные переводы - WesternUnion, Unistream
	bool MoneyTransfer;
	// перевод через PayPal
	bool PayPalTransfer;
	// перевод криптовалютой
	bool CryptoTransfer;
	// оплата наличными
	bool CashTransfer;
public:
	Receiver(bool bt, bool mt, bool ppt, bool ct, bool cash)
	{
		BankTransfer = bt;
		MoneyTransfer = mt;
		PayPalTransfer = ppt;
		CryptoTransfer = ct;
		CashTransfer = cash;
	}
	bool GetBankTransfer() { return BankTransfer; }
	void SetBankTransfer(bool BankTransfer) { this->BankTransfer = BankTransfer; }

	bool GetMoneyTransfer() { return MoneyTransfer; }
	void SetMoneyTransfer(bool MoneyTransfer) { this->MoneyTransfer = MoneyTransfer; }

	bool GetPayPalTransfer() { return PayPalTransfer; }
	void SetPayPalTransfer(bool PayPalTransfer) { this->PayPalTransfer = PayPalTransfer; }

	bool GetCryptoTransfer() { return CryptoTransfer; }
	void SetCryptoTransfer(bool CryptoTransfer) { this->CryptoTransfer = CryptoTransfer; }

	bool GetCashTransfer() { return CashTransfer; }
	void SetCashTransfer(bool CashTransfer) { this->CashTransfer = CashTransfer; }
};

// Абстрактный класс обработчика
class PaymentHandler abstract
{
protected:
	PaymentHandler* Successor;
public:
	PaymentHandler* GetHandler()
	{
		return Successor;
	}
	void SetHandler(PaymentHandler* Successor)
	{
		this->Successor = Successor;
	}
	virtual void Handle(Receiver* receiver) abstract;
};

// Конкретные обработчики

class BankPaymentHandler : public PaymentHandler
{
public:
	void Handle(Receiver* receiver) override
	{
		if (receiver->GetBankTransfer())
			cout << "Bank transfer\n";
		else if (Successor != nullptr)
			Successor->Handle(receiver);
	}
};

class MoneyPaymentHandler : public PaymentHandler
{
public:
	void Handle(Receiver* receiver) override
	{
		if (receiver->GetMoneyTransfer())
			cout << "Transfer through money transfer systems\n";
		else if (Successor != nullptr)
			Successor->Handle(receiver);
	}
};

class PayPalPaymentHandler : public PaymentHandler
{
public:
	void Handle(Receiver* receiver) override
	{
		if (receiver->GetPayPalTransfer())
			cout << "Transfer via PayPal\n";
		else if (Successor != nullptr)
			Successor->Handle(receiver);
	}
};

// Новый обработчик: Криптовалюта
class CryptoPaymentHandler : public PaymentHandler
{
public:
	void Handle(Receiver* receiver) override
	{
		if (receiver->GetCryptoTransfer())
			cout << "Transfer via Cryptocurrency\n";
		else if (Successor != nullptr)
			Successor->Handle(receiver);
	}
};

// Новый обработчик: Наличные
class CashPaymentHandler : public PaymentHandler
{
public:
	void Handle(Receiver* receiver) override
	{
		if (receiver->GetCashTransfer())
			cout << "Payment in Cash\n";
		else if (Successor != nullptr)
			Successor->Handle(receiver);
	}
};

// Функция обработки запроса
void Request(PaymentHandler* h, Receiver* receiver)
{
	h->Handle(receiver);
}

// Главная функция
int main()
{
	PaymentHandler* bankPaymentHandler = new BankPaymentHandler();
	PaymentHandler* paypalPaymentHandler = new PayPalPaymentHandler();
	PaymentHandler* moneyPaymentHandler = new MoneyPaymentHandler();
	PaymentHandler* cryptoPaymentHandler = new CryptoPaymentHandler();
	PaymentHandler* cashPaymentHandler = new CashPaymentHandler();

	// Формируем цепочку обработчиков
	bankPaymentHandler->SetHandler(paypalPaymentHandler);
	paypalPaymentHandler->SetHandler(moneyPaymentHandler);
	moneyPaymentHandler->SetHandler(cryptoPaymentHandler);
	cryptoPaymentHandler->SetHandler(cashPaymentHandler);

	// Примеры разных получателей
	Receiver* receiver = new Receiver(false, false, true, false, false);
	Request(bankPaymentHandler, receiver);
	delete receiver;

	receiver = new Receiver(false, true, false, false, false);
	Request(bankPaymentHandler, receiver);
	delete receiver;

	receiver = new Receiver(true, false, false, false, false);
	Request(bankPaymentHandler, receiver);
	delete receiver;

	receiver = new Receiver(false, false, false, true, false);
	Request(bankPaymentHandler, receiver);
	delete receiver;

	receiver = new Receiver(false, false, false, false, true);
	Request(bankPaymentHandler, receiver);
	delete receiver;

	// Освобождаем память
	delete bankPaymentHandler;
	delete paypalPaymentHandler;
	delete moneyPaymentHandler;
	delete cryptoPaymentHandler;
	delete cashPaymentHandler;

	system("pause");
	return 0;
}
