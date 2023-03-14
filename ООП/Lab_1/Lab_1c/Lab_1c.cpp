#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>

using namespace std;

class Train {
	string destination; //Пункт назначения
	int numTrain; //Номер поезда
	string timeDep; //Время отправления
public:
	Train();
	Train(string  destination, int numTrain, string timeDep);

	string getDestination() { return destination; }
	int getNumTrain() { return numTrain; }
	string getTimeDep() { return timeDep; }

	void setDestination(string destination) { this->destination = destination; }
	void setNumTrain(int numTrain) { this->numTrain = numTrain; }
	void setTimeDep(string timeDep) { this->timeDep = timeDep; }

	int menu();
	void addTrain();
	void putTrains(int i, Train trains[]);
	void processing(Train trains[]);
};

Train::Train() {
	destination = "";
	numTrain = NULL;
	timeDep = "";
}

Train::Train(string destination, int numTrain, string timeDep) {
	this->destination = destination;
	this->numTrain = numTrain;
	this->timeDep = timeDep;
}

int Train::menu() {
	int variant;
	string s;
	cout << "           Меню" << endl;
	cout << "1. Ввод данных" << endl;
	cout << "2. Вывод данных" << endl;
	cout << "3. Обработка данных" << endl;
	cout << "4. Выход" << endl;
	cin >> s;
	while (sscanf_s(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > 4) {
		cout << "Некорректный ввод. Повторите:" << endl;
		cin >> s;
	}
	return variant;
}

void Train::addTrain() {
	string des, time;
	int num;	
		cout << "Пунут назначения: ";
		cin >> des;
		setDestination(des);
		cout << "Номер поезда: ";
		cin >> num;
		setNumTrain(num);
		cout << "Время отправления: ";
		cin >> time;
		setTimeDep(time);
}

void Train::putTrains(int i, Train trains[]){
	cout << "+-------------------------------------------------------------------------------------------+" << endl;
	cout << "                                Расписание отправки поездов" << endl;
	for (int j = 0; j < i; j++) {
		cout << j + 1 << " Пункт назначения: " << setw(15) << trains[j].getDestination() << "   ";
		cout << "Номер поезда: " << setw(5) << trains[j].getNumTrain() << "   ";
		cout << "Время отправления: " << setw(8) << trains[j].getTimeDep() << "   " << endl;
	}
	cout << "+-------------------------------------------------------------------------------------------+" << endl;
}

void Train::processing(Train trains[]) {
	int sr1, sr2;
	cout << "Обработка данных" << endl;
	cout << "Введите первый номер для сравнения" << endl;
	cin >> sr1;
	cout << "Введите второй номер для сравнения" << endl;
	cin >> sr2;
	if (trains[sr1 - 1].getTimeDep() == trains[sr2 - 1].getTimeDep()) {
		cout << "Время отправления заданных поездов совпадает" << endl;
	}
	else {
		cout << "Время отправления заданных поездов несовпадает" << endl;
	}
}

int main() {
	SetConsoleCP(1251); //установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); //установка кодовой страницы win-cp 1251 в поток вывода

	const int quantity = 3;
	Train trains[quantity];
	int i = 0;
	int var = trains->menu();
	while (var != 4) {
		switch (var) {
		case 1:
			if (i < quantity) { trains[i].addTrain(); i++; }
			else
				cout << "Нет места в расписании отправки поездов\n" << endl;
			var = trains->menu();
			break;
		case 2:
			trains->putTrains(i, trains);
			var = trains->menu();
			break;
		case 3:
			trains->processing(trains);
			var = trains->menu();
			break;
		}
	}
}