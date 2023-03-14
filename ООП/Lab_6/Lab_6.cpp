#include <iostream>
#include <Windows.h>

using namespace std;

class rectangle {
	int a, b;
public:
	rectangle() { a = 0; b = 0; }
	rectangle(int a, int b) {
		this->a = a;
		this->b = b;
	}
	~rectangle() { cout << "Деструктор" << endl; }

	rectangle& operator !() {
		if (a == b) cout << "Квадрат" << endl;
		else cout << "Не квадрат" << endl;
		return *this;
	}
	friend int operator -(rectangle& R);
	bool operator ==(const rectangle& R) {
		if (a * b == R.a * R.b) return true;
		return false;
	}
	friend int operator +(rectangle& R1, rectangle& R2);
	friend ostream& operator <<(ostream& out, const rectangle& R);
	friend istream& operator >>(istream& in, rectangle& R);
};

int operator -(rectangle &R) {
	return abs(R.a - R.b);
}
int operator +(rectangle& R1, rectangle& R2) {
	return R1.a * R1.b + R2.a * R2.b;
}
ostream& operator <<(ostream& out, const rectangle& R) {
	out << "a=" << R.a << "; b=" << R.b << endl;
	return out;
}
istream& operator >>(istream& in, rectangle& R) {
	cout << "a=";
	in >> R.a;
	cout << "b=";
	in >> R.b;
	return in;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	rectangle rec1, rec2, r1;
	bool r2;
	int r3;
	cout << "Введите стороны 1 прямоугольника:" << endl;
	cin >> rec1;
	cout << "Введите стороны 2 прямоугольника:" << endl;
	cin >> rec2;
	cout << "\nСтороны 1 прямоугольника : ";
	cout << rec1;
	cout << "Стороны 2 прямоугольника : ";
	cout << rec2;
	cout << "\n1 прямоугольник - ";
	r1 = !rec1;
	cout << r1 << endl;
	cout << "Разница между сторонами 2 прямоугольника: ";
	r2 = -rec2;
	cout << r2 << endl;
	cout << "\nРавна ли площадь прямоугольников: ";
	r2 = rec1 == rec2;
	cout << r2 << endl;
	cout << "\nСумма площадей 2-х прямоугольников: ";
	r3 = rec1 + rec2;
	cout << r3 << "\n\n";
}