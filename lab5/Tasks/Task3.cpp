#include <iostream>
#include "input.h"
#include "star_line.h"
using namespace std;

// улсовие
bool condition(const int number){
    return number > 0;
}

// функция создания нового массива из четных элементов главной диагонали матрицы
void creationAnArray(int** matrix, int*& array, int& size){
    for(int i = 0, k = 0; i < size; ++i){
        if(matrix[i][i] % 2 == 0){ //
            array[k] = matrix[i][i];
            ++k;
        }
        else{
            --size;
        }
    }

    int* new_array = new int[size];
    for(int i = 0; i < size; ++i){
        new_array[i] = array[i];
    }

    delete[] array;
    array = new_array;
}

// функция произведения элементов массива
int productElementsOfArray(int* array, const int size){
    int result = 1;
    for(int i = 0; i < size; ++i){
        result *= array[i];
    }

    return result;
}


int main() {
    starLine();

    cout << "This program creates a dynamic array from the even elements of the diagonal" << endl;

    starLine();

    // ввод размера матрицы A
    int n, k;
    cout << "Enter N(number of rows): ";
    input(n, condition);
    cout << "Enter K(number of columns): ";
    input(k, condition);

    starLine();

    // выделение памяти под матрицу
    int **A = new int *[n];
    for(int i = 0; i < n; ++i){
        A[i] = new int[k];
    }
    // ввод элементов матрицы A
    cout << "Enter matrix:\n";
    input(A, n, k);

    // создание массива для хранения элементов расположеных на главное диагонале матрицы имеет четное значение
    int size = n; // размерность массива 5*6 по условию и поэтому в size ложим n = 5 так как это максимальной значения size
    // в случае произвольной размерности ложим в size минимальное из n и k
    // size = n > k ? k : n;
    int* array = new int[size];
    creationAnArray(A, array, size);

    // вычисление произведенения элементов массива
    int result = productElementsOfArray(array, size);

    starLine();

    // вывод
    cout << "Array of even elements of the diagonal of the matrix:" << endl;
    for(int i = 0; i < size; ++i){
        cout << array[i] << " ";
    }
    cout << endl;

    starLine();

    cout << "The result of the elements of this array equal " << result << endl;

    starLine();

    for(int i = 0; i < n; ++i){
        delete[] A[i];
    }
    delete[] A;
}