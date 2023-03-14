#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;

class Matrix;

class Vector {
    int* vec;
    int columns;
public:
    Vector(int columns) { this->columns = columns; }

    void createVector();

    void display();

    friend void change(Matrix ob1, Vector ob2);
};

void Vector::createVector() {
    vec = new int[columns];
    for (int i = 0; i < columns; i++) {
        vec[i] = rand() % 100;
    }
}

void Vector::display() {
    for (int i = 0; i < columns; i++) {
        cout << setw(3) << vec[i] << " ";
    }
    cout << endl;
}

class Matrix {
    double** matr;
    int columns;
    int rows;
public:
    Matrix(int columns, int rows) {
        this->columns = columns;
        this->rows = rows;
    }

    void createMatrix();

    void display();

    friend void change(Matrix ob1, Vector ob2);
};

void Matrix::createMatrix() {
    matr = new double* [columns];
    for (int i = 0; i < columns; i++) {
        matr[i] = new double[rows];
        for (int j = 0; j < rows; j++) {
            matr[i][j] = rand() % 100;
        }
    }
}

void Matrix::display() {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            cout << setw(3) << matr[i][j] << " ";
        }
        cout << endl;
    }
}

void change(Matrix ob1, Vector ob2) {
    if ((ob1.columns == ob2.columns) && (ob1.rows == ob2.columns)) {
        for (int i = 0; i < ob1.columns; i++) {
            ob1.matr[i][i] = ob2.vec[i];
        }
    }
    else {
        cout << "Ошибка! Неверно задана размерность матрицы или вектора\n" << endl;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int columnsV, columnsM, rows;
    cout << "Введите размерность матрицы:" << endl;
    cout << "Количество столбцов = ";
    cin >> columnsM;
    cout << "Количество строк = ";
    cin >> rows;
    cout << "Введите размерность вектора:" << endl;
    cout << "Количество столбцов = ";
    cin >> columnsV;
    Matrix ob1(columnsM, rows);
    Vector ob2(columnsV);
    ob1.createMatrix();
    ob1.display();
    cout << endl;
    ob2.createVector();
    ob2.display();
    cout << endl;
    change(ob1, ob2);
    ob1.display();
    return 0;
}
