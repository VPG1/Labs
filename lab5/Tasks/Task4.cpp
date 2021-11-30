#include <iostream>
#include "input.h"
#include "star_line.h"
using namespace std;

bool condition(const int number){
    return number > 0;
}


// функция подсчёта кол-ва элементов
void counting_zeros(double** matrix, const int n, const int m, int& number_of_zeros){
    number_of_zeros = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(matrix[i][j] == 0){
                ++number_of_zeros;
            }
        }
    }
}

// функция поиска индексов нулевых элементов
void search_indices_of_zeros(double** matrix, const int n, const int m, int** indices){
    int k = 0; // индекс строки массива индексов
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!matrix[i][j]){
                indices[k][0] = i;
                indices[k][1] = j;
                ++k;
            }
        }
    }
}

// функция перестановки элементов  массива в обратном порядке
void reverse_matrix(double** matrix, const int n, const int m){
    // "переворачиваем" массив относительно "вертикальной оси"
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m / 2; ++j){
            swap(matrix[i][j], matrix[i][m - 1 - j]);
        }
    }

    // "переворачиваем" массив относительно "горизонатльной оси"
    for(int i = 0; i < n / 2; ++i){
        for(int j = 0; j < m; ++j){
            swap(matrix[i][j], matrix[n - 1 - i][j]);
        }
    }
}

int main(){
    starLine();

    cout << "This program counts the number of zeros and their indices in the matrix, and also represents the elements of the matrix in reverse order" << endl;

    starLine();

    // ввод размера матрицы
    int n, m;
    cout << "Enter N(number of rows): ";
    input(n, condition);
    cout << "Enter M(number of columns): ";
    input(m, condition);

    starLine();

    // выделение памяти под матрицу
    double** matrix = new double*[n];
    for(int i = 0; i < n; ++i){
        matrix[i] = new double[m];
    }

    // ввод элемнетов матрицы
    cout << "Enter elements of matrix:" << endl;
    input(matrix, n, m);

    // подсчёт кол-ва нулевых элементов
    int number_of_zeros;
    counting_zeros(matrix, n, m, number_of_zeros);


    // поиск индексов нулевых элементов
    int** indices = new int*[number_of_zeros]; // массив для хранения индексов нулевых элементов в первом столбце все i, а во втором столбце все j
    if(number_of_zeros){ // провека на наличие нулевых элементов в матрице
        for(int i = 0; i < number_of_zeros; ++i){
            indices[i] = new int[2];
        }
        search_indices_of_zeros(matrix, n, m, indices);
    }

    // представления элементов массива в обратном порядке
    reverse_matrix(matrix, n, m);

    // вывод количества нулевых элемнтов матрицы и их индексов
    if(number_of_zeros){ // провека на наличие нулевых элементов в матрице
        starLine();

        cout << "Number of zeros in matrix: " << number_of_zeros << endl;

        starLine();

        cout << "Indices of zeros(indexing start at zero):" << endl;
        for(int i = 0; i < number_of_zeros; ++i){
            cout << indices[i][0] << " " << indices[i][1] << endl;
        }
    }

    starLine();

    // вывод
    cout << "Reversed matrix:" << endl;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    starLine();

    for(int i = 0; i < n; ++i){
        delete[] matrix[i];
    }
    delete[] matrix;

    for(int i = 0; i < number_of_zeros; ++i){
        delete[] indices[i];
    }
    delete[] indices;
}
