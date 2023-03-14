#include <iostream>
#include <Windows.h>

using namespace std;

template <class M1>
void Swap(M1* m, int i, int j, int length) {
	M1 temp;
	i--; j--;
	for (int n = 0; n < length; n++) {
		temp[n] = m[i][n];
		m[i][n] = m[j][n];
		m[j][n] = temp[n];
	}
}

template <class M2>
void Print(M2* matr, int length) {
	for (int n = 0; n < length; n++) {
		for (int m = 0; m < length; m++)
			cout << matr[n][m] << " ";
		cout << endl;
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int i = 1, j = 2;
	static const int length = 3;
	int matr1[length][length] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	char matr2[length][length] = {
		{'v','g','r'},
		{':','p','A'},
		{'n','T','+'},
	};
	double matr3[length][length] = {
		{2.6, 6.1, 9.8},
		{7.1, 5.7, 3.6},
		{6.3, 0.8, 2.6}
	};
	cout << "Матрица типа int:" << endl;
	Print(matr1, length);
	Swap(matr1, i, j, length);
	cout << "Матрица после перестановки " << i << " строки и " << j << endl;
	Print(matr1, length);
	cout << "\nМатрица типа char:" << endl;
	Print(matr2, length);
	Swap(matr2, i, j, length);
	cout << "Матрица после перестановки " << i << " строки и " << j << endl;
	Print(matr2, length);
	cout << "\nМатрица типа double:" << endl;
	Print(matr3, length);
	Swap(matr3, i, j, length);
	cout << "Матрица после перестановки " << i << " строки и " << j << endl;
	Print(matr3, length);
}