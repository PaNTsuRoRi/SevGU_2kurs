#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class Car {
	string brand;
	int power, speed;
public:
	Car();
	Car(string brand, int power, int speed);
	~Car() { cout << "Destructor Car" << endl; }

	string getBrand() { return brand; }
	int getPower() { return power; }
	int getSpeed() { return speed; }

	void setBrand(string brand) { this->brand = brand; }
	void setPower(int power) { this->power = power; }
	void setSpeed(int speed) { this->speed = speed; }

	void show() {
		cout << "Car" << endl;
		cout << "Марка: " << getBrand() << endl;
		cout << "Мощность: " << getPower() << endl;
		cout << "Скорость: " << getSpeed() << endl;
	}

	void powerAboveX(int X) {
		if (power > X)
			cout << "Мощность больше заданной" << endl;
		else cout << "Мощность меньше заданной" << endl;
	}
};

class Transport {
	double tonnage;
	string type;
public:
	Transport();
	Transport(double tonnage, string type);
	~Transport() { cout << "Destructor Transport" << endl; };

	double getTonnage() { return tonnage; }
	string getType() { return type; }

	void setTonnage(double tonnage) { this->tonnage = tonnage; }
	void setType(string type) { this->type = type; }

	void show() {
		cout << "Transport" << endl;
		cout << "Тоннаж: " << getTonnage() << endl;
		cout << "Тип: " << getType() << endl;
	}
	
	void tonnageBelowX(double X) {
		if (tonnage < X)
			cout << "Груз слишком большой" << endl;
		else cout << "Транспорт подходит" << endl;
	}
};

class Truck : public Car, public Transport{
	string color;
public:
	Truck(string brand, int power, int speed, double tonnage, string type, string color) : 
		Car(brand, power, speed), Transport(tonnage, type) { this->color = color; };
	~Truck() { cout << "Destructor Truck" << endl; }

	string getColor() { return color; }
	void setColor(string color) { this->color = color; }

	void show() {
		cout << "Truck" << endl;
		cout << "Марка: " << getBrand() << endl;
		cout << "Мощность: " << getPower() << endl;
		cout << "Скорость: " << getSpeed() << endl;
		cout << "Тоннаж: " << getTonnage() << endl;
		cout << "Тип: " << getType() << endl;
		cout << "Цвет: " << getColor() << endl;
	}

	void tonnageNeedRemove(double X) {
		if (Transport::getTonnage() < X) {
			X = X - Transport::getTonnage();
			cout << "Груз слишком большой нужно убрать " << X << " тон" << endl;
		}
		else cout << "Тоннаж соответсвует грузу" << endl;
	}
};

Car::Car() {
	brand = "";
	power = 0;
	speed = 0;
}

Car::Car(string brand, int power, int speed) {
	this->brand = brand;
	this->power = power;
	this->speed = speed;
}

Transport::Transport() {
	tonnage = 0.0;
	type = "";
}

Transport::Transport(double tonnage, string type) {
	this->tonnage = tonnage;
	this->type = type;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Car* car;
	car = new Car("BMW", 530, 200);
	car->show();
	car->powerAboveX(240);
	cout << endl;

	Transport* transport;
	transport = new Transport(2, "Седан");
	transport->show();
	transport->tonnageBelowX(4);
	cout << endl;

	Truck* truck;
	truck = new Truck("Vovlo", 500, 120, 45, "Автовоз", "Серый");
	truck->show();
	truck->tonnageNeedRemove(60);
}