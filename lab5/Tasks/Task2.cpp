#include <iostream>
#include <cmath>
#include "input.h"
#include "star_line.h"
using namespace std;

// функция условия
bool condition(const int number){
    return number > 0;
}

// функция нахождения суммы
double sum(const int start, const int end, double* array) {
    if (!(end - start)) {
        return sin(2 * array[start]) / 2; // sin(x) * cos(x) = sin(2 * x) / 2
    }

    return sum(start, (end + start) / 2, array) + sum((end + start) / 2 + 1, end, array);
}


int main(){
    starLine();

    cout << "This program calculate the sum(sin(Bi) * cos(Bi)) i from 1 to N" << endl;

    starLine();

    // ввод N
    int N;
    cout << "Enter N(size of array): ";
    input(N, condition);

    starLine();

    // ввод элементов массива B
    double* B = new double[N];
    cout << "Enter array B:" << endl;
    input(B, N);

    starLine();

    // вывод
    cout << "sum = "<< sum(0, N - 1, B) << endl;

    starLine();

    delete[] B;

    return 0;
}

