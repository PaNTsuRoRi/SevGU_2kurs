#include <iostream>
#include <Windows.h>
#include <math.h>

using namespace std;

void res(double X) {
    double y;
    y = 10 * X + 2.2;
    if ((y < -1) || (y > 1)) {
        throw X;
    }
    y = 10*asin(10*X+2.2);
    cout << "Ответ: " << y;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double X;
    cout << "X = ";
    while (!(cin >> X)) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Неправильный ввод! Повторите!\nX = ";
    }
    try {
        res(X);
    }
    catch (const double ex) {
        cerr << "X должен быть в диапазоне [-0.32, -0.12)";
    }
}