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
	void printInfo();
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
	void printInfo();
	void survival();
};

Archer::Archer() {
	name = "";
	health = 100;
	damage = 10;
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

void Archer::printInfo() {
	Unit::printInfo();
	cout << "Радиус атаки: " << getRange() << endl;
}

void Archer::survival() {
	if (getHealth() <= 0)
		cout << "Лучник мертв";
	else
		cout << "Лучник жив";
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Unit unit1;
	Archer archer1, archer2;
	cout << "Создание объекта класса - Юнит:" << endl;
	unit1.inputData();
	cout << "Вывод информации об объекте:" << endl;
	unit1.printInfo();
	cout << "\nСоздание 1 объекта класса - Лучник:" << endl;
	archer1.inputData();
	cout << "Вывод информации об объекте 1:" << endl;
	archer1.printInfo();
	cout << "\nСоздание 2 объекта класса - Лучник:" << endl;
	archer2.inputData();
	cout << "Вывод информации об объекте 2:" << endl;
	archer2.printInfo();
	cout << "\nПроверка жив ли лучник: " << endl;
	cout << "1 объект: ";
	archer1.survival();
	cout << "\n2 объект: ";
	archer2.survival();
	cout << endl;
}