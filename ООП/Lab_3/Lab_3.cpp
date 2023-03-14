#include <iostream>
#include <Windows.h>

using namespace std;

class Unit {
protected:
	string name;
	int health;
	int damage;
public:
	Unit();
	Unit(string name, int health, int damage);

	string getName() { return name; }
	int getHealth() { return health; }
	int getDamage() { return damage; }

	void setName(string name) { this->name = name; }
	void setHealth(int health) { this->health = health; }
	void setDamage(int damage) { this->damage = damage; }

	void inputData();
	virtual void printInfo();

	virtual ~Unit(){
		cout << "Destructor Unit" << endl;
	}
};

Unit::Unit() {
	name = "";
	health = 100;
	damage = 10;
}

Unit::Unit(string name, int health, int damage) {
	this->name = name;
	this->health = health;
	this->damage = damage;
}

void Unit::inputData() {
	string nam;
	int heal, dam;
	cout << "Имя: ";
	cin >> nam;
	cout << "Кол-во жизни: ";
	cin >> heal;
	cout << "Урон: ";
	cin >> dam;
	setName(nam);
	setHealth(heal);
	setDamage(dam);
}

void Unit::printInfo() {
	cout << "Имя: " << getName() << endl;
	cout << "Кол-во жизни: " << getHealth() << endl;
	cout << "Урон: " << getDamage() << endl;
}

class Archer : public Unit {
	int range;
public:
	Archer();
	Archer(string name, int health, int damage, int range);

	int getRange() { return range; }
	void setRange(int range) { this->range = range; }

	void inputData();
	void printInfo() override;
	void survival();

	~Archer(){
		cout << "Destructor Archer" << endl;
	}
};

Archer::Archer() : Unit() {
	range = 20;
}

Archer::Archer(string name, int health, int damage, int range) : Unit(name, health, damage) {
	this->range = range;
}

void Archer::inputData() {
	Unit::inputData();
	int ran;
	cout << "Радиус атаки: ";
	cin >> ran;
	setRange(ran);
}

void Archer::printInfo(){
	Unit::printInfo();
	cout << "Радиус атаки: " << getRange() << endl;
}

void Archer::survival() {
	if (getHealth() <= 0)
		cout << "Лучник мертв";
	else
		cout << "Лучник жив";
}

class Swordsman : public Unit {
public:
	Swordsman() : Unit() {};
	Swordsman(string name, int health, int damage) : Unit(name, health, damage) {};

	~Swordsman() {
		cout << "Destructor Swordsman" << endl;
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Unit unit;
	Archer archer;
	Swordsman swordsman;
	cout << "Создание объекта класса - Юнит:" << endl;
	unit.inputData();
	cout << "Вывод информации об объекте:" << endl;
	unit.printInfo();
	cout << "\nСоздание объекта класса - Лучник:" << endl;
	archer.inputData();
	cout << "Вывод информации об объекте класса Лучник:" << endl;
	archer.printInfo();
	cout << "Проверка жив ли лучник: " << endl;
	archer.survival();
	cout << "\n\nСоздание объекта класса - Мечник:" << endl;
	swordsman.inputData();
	cout << "Вывод информации об объекте класса Мечник:" << endl;
	swordsman.printInfo();

	Unit* pointer = &archer;
	cout << "Вывод информации об объекте класса Лучник:" << endl;
	pointer->printInfo();
	cout << endl;
	Unit* pointer1 = &swordsman;
	cout << "Вывод информации об объекте класса Мечник:" << endl;
	pointer1->printInfo();
}