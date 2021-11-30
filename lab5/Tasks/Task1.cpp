#include <iostream>
#include "input.h"
#include "for_vector.h"
#include "star_line.h"
using namespace std;

// функция для дополнительного условия ввода
bool condition(const int number){
    return number > 0;
}

int main(){
    starLine();

    cout << "This program calculates the product of vectors X and Y" << endl;
    cout << "The elements of the vector Y are calculated by the formula 0.1 * tg (0.1 * i) i from 1 to n (size of the vector)" << endl;

    starLine();

    // ввод размера массива
    int size;
    cout << "Enter size of vectors X and Y: ";
    input(size, condition);

    starLine();

    //ввод вектора X
    double* X = new double[size];
    cout << "Enter vector X: " << endl;
    input(X, size);

    // заполнения вектора Y
    double* Y = new double[size];
    fillVector(Y, size);

    // произведение векторв X и Y
    int result = multiply(X, Y, size);

    starLine();

    //вывод вектора Y
    cout << "Vector Y:" << endl;
    for(int i = 0; i < size; ++i){
        cout << Y[i] << endl;
    }

    starLine();

    cout << "Product of vectors X and Y equal " << result << endl;

    starLine();

    delete[] X;
    delete[] Y;

    return 0;
}

