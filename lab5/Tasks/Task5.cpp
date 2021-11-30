#include <iostream>
#include "input.h"
#include "star_line.h"
using namespace std;

// условие
bool condition(const int number){
    return number > 0;
}


// функция создания нового массива из нечётных элементов матрцы расположеных в чётных столбцах
void creationAnArray(int** matrix, const int n, const int m, int*& array, int& size_of_array){
    for(int j = 1, k = 0; j < m; j += 2){
        for(int i = 0; i < n; ++i){
            if(matrix[i][j] % 2) {
                array[k] = matrix[i][j];
                ++k;
            }
            else{
                --size_of_array;
            }
        }
    }

    int* new_array = new int[size_of_array];

    for(int i = 0; i < size_of_array; ++i){
        new_array[i] = array[i];
    }

    delete[] array;

    array = new_array;

}

// функция вычисления среднего арифметического
double calculatingAverage(const int* array, const int size){
    double sum = 0;
    for(int i = 0; i < size; ++i){
        sum += array[i];
    }
    return sum / size;
}

int main(){
    starLine();

    cout << "This program creates an array of odd elements of even columns of the matrix" << endl;

    starLine();

    // ввод размера матрицы
    int n, m;
    cout << "Enter N(number of rows): ";
    input(n, condition);
    cout << "Enter M(number of columns): ";
    input(m, condition);

    starLine();

    // ввод элемнетов матрицы
    int** matrix = new int*[n];
    for(int i = 0; i < n; ++i){
        matrix[i] = new int[m];
    }
    cout << "Enter elements of matrix:" << endl;
    input(matrix, n, m);

    starLine();

    // создание массива из нечётных элементов матрицы расположеных в четных столбцах
    int size = (m / 2) * n; // максимальный размер массива
    int* array = new int[size];
    creationAnArray(matrix, n, m, array, size);


    // вывод
    if(size){ // если в массиве нет элементов то ничего не выводим
        cout << "Array of elements of even columns of the matrix:";
        for(int i = 0; i < size; ++i){
            cout << array[i] << " ";
        }
         cout << endl;

        starLine();

        cout << "The average of the elements of this array equal " << calculatingAverage(array, size) << endl;

        starLine();
    }

    for(int i = 0; i < n; ++i){
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] array;

    return 0;
}
