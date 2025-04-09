#include <iostream>
#include <string>
using namespace std;

class Character {
public:
    virtual int getAttack() = 0;
    virtual int getSpeed() = 0;
    virtual int getHealth() = 0;
    virtual int getDefense() = 0;
    virtual void move() = 0;
    virtual string getDescription() = 0;
    virtual ~Character() {}
};

class BaseCharacter : public Character {
public:
    int getAttack() override { return 0; }
    int getSpeed() override { return 0; }
    int getHealth() override { return 0; }
    int getDefense() override { return 0; }
    void move() override {
        cout << "Перемещение со скоростью: " << getSpeed() << endl;
    }
    string getDescription() override {
        return "Базовый персонаж";
    }
};

class ProfessionDecorator : public Character {
protected:
    Character* character;

public:
    ProfessionDecorator(Character* character) : character(character) {}

    virtual ~ProfessionDecorator() {
    }

    int getAttack() override {
        return character->getAttack();
    }

    int getSpeed() override {
        return character->getSpeed();
    }

    int getHealth() override {
        return character->getHealth();
    }

    int getDefense() override {
        return character->getDefense();
    }

    void move() override {
        character->move();
    }

    string getDescription() override {
        return character->getDescription();
    }
};

class Human : public ProfessionDecorator {
public:
    Human(Character* character) : ProfessionDecorator(character) {}

    int getAttack() override {
        return character->getAttack() + 20;
    }

    int getSpeed() override {
        return character->getSpeed() + 20;
    }

    int getHealth() override {
        return character->getHealth() + 150;
    }

    string getDescription() override {
        return character->getDescription() + " + Человек";
    }
};

class HumanWarrior : public ProfessionDecorator {
public:
    HumanWarrior(Character* character) : ProfessionDecorator(character) {}

    int getAttack() override {
        return character->getAttack() + 20;
    }

    int getSpeed() override {
        return character->getSpeed() + 10;
    }

    int getHealth() override {
        return character->getHealth() + 50;
    }

    int getDefense() override {
        return character->getDefense() + 20;
    }

    string getDescription() override {
        return character->getDescription() + " + Человек воин";
    }
};

class Swordsman : public ProfessionDecorator {
public:
    Swordsman(Character* character) : ProfessionDecorator(character) {}

    int getAttack() override {
        return character->getAttack() + 40;
    }

    int getSpeed() override {
        return character->getSpeed() - 10;
    }

    int getHealth() override {
        return character->getHealth() + 50;
    }

    int getDefense() override {
        return character->getDefense() + 40;
    }

    string getDescription() override {
        return character->getDescription() + " + Меченосец";
    }
};

class Archer : public ProfessionDecorator {
public:
    Archer(Character* character) : ProfessionDecorator(character) {}

    int getAttack() override {
        return character->getAttack() + 20;
    }

    int getSpeed() override {
        return character->getSpeed() + 20;
    }

    int getHealth() override {
        return character->getHealth() + 50;
    }

    int getDefense() override {
        return character->getDefense() + 10;
    }

    string getDescription() override {
        return character->getDescription() + " + Лучник";
    }
};

class Horseman : public ProfessionDecorator {
public:
    Horseman(Character* character) : ProfessionDecorator(character) {}

    int getAttack() override {
        return character->getAttack() - 10;
    }

    int getSpeed() override {
        return character->getSpeed() + 40;
    }

    int getHealth() override {
        return character->getHealth() + 200;
    }

    int getDefense() override {
        return character->getDefense() + 100;
    }

    string getDescription() override {
        return character->getDescription() + " + Всадник";
    }
};

class Elf : public ProfessionDecorator {
public:
    Elf(Character* character) : ProfessionDecorator(character) {}

    int getAttack() override {
        return character->getAttack() + 15;
    }

    int getSpeed() override {
        return character->getSpeed() + 30;
    }

    int getHealth() override {
        return character->getHealth() + 100;
    }


    string getDescription() override {
        return character->getDescription() + " + Эльф";
    }
};

class ElfWarrior : public ProfessionDecorator {
public:
    ElfWarrior(Character* character) : ProfessionDecorator(character) {}

    int getAttack() override {
        return character->getAttack() + 20;
    }

    int getSpeed() override {
        return character->getSpeed() - 10;
    }

    int getHealth() override {
        return character->getHealth() + 100;
    }

    int getDefense() override {
        return character->getDefense() + 20;
    }

    string getDescription() override {
        return character->getDescription() + " + Эльф воин";
    }
};

class ElfMage : public ProfessionDecorator {
public:
    ElfMage(Character* character) : ProfessionDecorator(character) {}

    int getAttack() override {
        return character->getAttack() + 10;
    }

    int getSpeed() override {
        return character->getSpeed() + 10;
    }

    int getHealth() override {
        return character->getHealth() - 50;
    }

    int getDefense() override {
        return character->getDefense() + 10;
    }

    string getDescription() override {
        return character->getDescription() + " + Эльф маг";
    }
};

class Crossbowman : public ProfessionDecorator {
public:
    Crossbowman(Character* character) : ProfessionDecorator(character) {}

    int getAttack() override {
        return character->getAttack() + 20;
    }

    int getSpeed() override {
        return character->getSpeed() + 10;
    }

    int getHealth() override {
        return character->getHealth() + 50;
    }

    int getDefense() override {
        return character->getDefense() - 10;
    }

    string getDescription() override {
        return character->getDescription() + " + Арбалетчик";
    }
};

class EvilMage : public ProfessionDecorator {
public:
    EvilMage(Character* character) : ProfessionDecorator(character) {}

    int getAttack() override {
        return character->getAttack() + 70;
    }

    int getSpeed() override {
        return character->getSpeed() + 20;
    }

    string getDescription() override {
        return character->getDescription() + " + Злой маг";
    }
};

class GoodMage : public ProfessionDecorator {
public:
    GoodMage(Character* character) : ProfessionDecorator(character) {}

    int getAttack() override {
        return character->getAttack() + 50;
    }

    int getSpeed() override {
        return character->getSpeed() + 30;
    }

    int getHealth() override {
        return character->getHealth() + 100;
    }

    int getDefense() override {
        return character->getDefense() + 30;
    }

    string getDescription() override {
        return character->getDescription() + " + Добрый маг";
    }
};

void displayCharacterStats(Character* character) {
    cout << "Описание: " << character->getDescription() << endl;
    cout << "Атака: " << character->getAttack() << endl;
    cout << "Скорость: " << character->getSpeed() << endl;
    cout << "Здоровье: " << character->getHealth() << endl;
    cout << "Защита: " << character->getDefense() << endl;
    character->move();
    cout << "------------------------" << endl;
}

int main() {
    setlocale(LC_ALL, "");
    Character* baseChar = new BaseCharacter();

    cout << "Пример 1: Человек -> Воин -> Меченосец -> Всадник" << endl;
    Character* human1 = new Human(baseChar);
    Character* warrior1 = new HumanWarrior(human1);
    Character* swordsman = new Swordsman(warrior1);
    Character* horseman = new Horseman(swordsman);
    displayCharacterStats(horseman);

    cout << "Пример 2: Человек -> Воин -> Лучник" << endl;
    Character* human2 = new Human(baseChar);
    Character* warrior2 = new HumanWarrior(human2);
    Character* archer = new Archer(warrior2);
    displayCharacterStats(archer);

    cout << "Пример 3: Эльф -> Маг -> Злой маг" << endl;
    Character* elf1 = new Elf(baseChar);
    Character* elfMage1 = new ElfMage(elf1);
    Character* evilMage = new EvilMage(elfMage1);
    displayCharacterStats(evilMage);

    cout << "Пример 4: Эльф -> Маг -> Добрый маг" << endl;
    Character* elf2 = new Elf(baseChar);
    Character* elfMage2 = new ElfMage(elf2);
    Character* goodMage = new GoodMage(elfMage2);
    displayCharacterStats(goodMage);

    cout << "Пример 5: Эльф -> Воин -> Арбалетчик" << endl;
    Character* elf3 = new Elf(baseChar);
    Character* elfWarrior = new ElfWarrior(elf3);
    Character* crossbowman = new Crossbowman(elfWarrior);
    displayCharacterStats(crossbowman);

    delete crossbowman;
    delete goodMage;
    delete evilMage;
    delete archer;
    delete horseman;
    delete baseChar;

    return 0;
}