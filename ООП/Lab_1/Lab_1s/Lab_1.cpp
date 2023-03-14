#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>

using namespace std;

struct train {
	char destination[15];
	int numTrain;
	char timeDep[6];
};

int menu();

int main() {
	SetConsoleCP(1251); //установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); //установка кодовой страницы win-cp 1251 в поток вывода

	const int quantity = 3;
	train trains[quantity] = {};
	int var = menu();
	int i = 0;
	while (var != 4) {
		switch (var) {
		case 1:
			if (i < quantity) {
				cout << "Пунут назначения: ";
				cin >> trains[i].destination;
				cout << "Номер поезда: ";
				cin >> trains[i].numTrain;
				cout << "Время отправления: ";
				cin >> trains[i].timeDep;
				i++;
			}
			else
				cout << "Нет места в расписании отправки поездов\n" << endl;
			var = menu();
			break;
		case 2:
			cout << "+-------------------------------------------------------------------------------------------+" << endl;
			cout << "                                Расписание отправки поездов" << endl;
			for (int j = 0; j < i; j++) {
				cout << j + 1 << " Пункт назначения: " << setw(15) << trains[j].destination << "   ";
				cout << "Номер поезда: " << setw(5) << trains[j].numTrain << "   ";
				cout << "Время отправления: " << setw(8) << trains[j].timeDep << "   " << endl;
			}
			cout << "+-------------------------------------------------------------------------------------------+" << endl;
			var = menu();
			break;
		case 3:
			int sr1, sr2;
			cout << "Обработка данных" << endl;
			cout << "Введите первый номер для сравнения" << endl;
			cin >> sr1;
			cout << "Введите второй номер для сравнения" << endl;
			cin >> sr2;
			if ((strcmp(trains[sr1-1].timeDep, trains[sr2-1].timeDep)) == 0) {
				cout << "Время отправления заданных поездов совпадает" << endl;
			}
			else {
				cout << "Время отправления заданных поездов несовпадает" << endl;
			}
			var = menu();
			break;
		}
	}
}

int menu() {
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