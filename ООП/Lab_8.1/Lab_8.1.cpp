#include <iostream>
#include <Windows.h>
#include <fstream>
#include <iomanip>

using namespace std;

double transformС(double C) {
    double F = 32 + (C * 1.8);
    return F;
}

double transformF(double F) {
    double C = (F - 32) / 1.8;
    return C;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double degreeC, degreeF;
    bool correct = true;
    cout << "Введите температуру по Цельсию: ";
    while (!(cin >> degreeC)) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Неправильный ввод! Повторите: ";
    }
    cout << "Введите температуру по Фаренгейту: ";
    while (!(cin >> degreeF)) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Неправильный ввод! Повторите: ";
    }
    double Far = transformС(degreeC);
    double Cel = transformF(degreeF);
    ofstream fOut;
    fOut.open("res.txt");
    if (!fOut) {
        cout << "Невозможно открыть файл" << endl;
        exit(1);
    }
    fOut.fill('/');
    fOut << fixed << setprecision(4) << setw(13) << Far << "/" << setw(13) << Cel << endl;
    fOut.close();
}