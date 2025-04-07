#include <iostream>
using namespace std;

class ITransport abstract {
public:
	virtual void Drive() abstract;
};

class Auto : public ITransport {
public:
	void Drive() override {
		cout << "The car drives on the road.\n";
	}
};

class Driver {
public:
	void Travel(ITransport* transport) {
		transport->Drive();
	}
};

class IAnimal abstract {
public:
	virtual void Move() abstract;
};

class Camel : public IAnimal {
public:
	void Move() override {
		cout << "Camel rides on the sands of the desert.\n";
	}
};

class CamelToTransportAdapter : public ITransport {
	Camel camel;
public:
	CamelToTransportAdapter(Camel animal) {
		camel = animal;
	}
	void Drive() override {
		camel.Move();
	}
};

class Elephant : public IAnimal {
public:
	void Move() override {
		cout << "Elephant slowly walks through the jungle.\n";
	}
};

class ElephantToTransportAdapter : public ITransport {
	Elephant elephant;
public:
	ElephantToTransportAdapter(Elephant animal) {
		elephant = animal;
	}
	void Drive() override {
		elephant.Move();
	}
};

class Deer : public IAnimal {
public:
	void Move() override {
		cout << "Deer gracefully runs through the snow forest.\n";
	}
};

class DeerToTransportAdapter : public ITransport {
	Deer deer;
public:
	DeerToTransportAdapter(Deer animal) {
		deer = animal;
	}
	void Drive() override {
		deer.Move();
	}
};

class Horse : public IAnimal {
public:
	void Move() override {
		cout << "Horse gallops across the field.\n";
	}
};

class HorseToTransportAdapter : public ITransport {
	Horse horse;
public:
	HorseToTransportAdapter(Horse animal) {
		horse = animal;
	}
	void Drive() override {
		horse.Move();
	}
};


int main() {
	Driver driver;

	// Автомобиль
	Auto car;
	ITransport* transport = &car;
	driver.Travel(transport);

	// Верблюд
	Camel camel;
	CamelToTransportAdapter camelAdapter(camel);
	transport = &camelAdapter;
	driver.Travel(transport);

	// Слон
	Elephant elephant;
	ElephantToTransportAdapter elephantAdapter(elephant);
	transport = &elephantAdapter;
	driver.Travel(transport);

	// Олень
	Deer deer;
	DeerToTransportAdapter deerAdapter(deer);
	transport = &deerAdapter;
	driver.Travel(transport);

	// Лошадь
	Horse horse;
	HorseToTransportAdapter horseAdapter(horse);
	transport = &horseAdapter;
	driver.Travel(transport);

	return 0;
}
