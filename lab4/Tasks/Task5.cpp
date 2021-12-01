#include <iostream>
using namespace std;

int main(){
    cout << "This program smooths matrix(each element of the matrix is obtained as the arithmetic mean of its neighbors).\n";
    //ввод размерности матрицы
    cout << "Enter the number of rows and columns: ";
    int n, m;
    while(!(cin >> n >> m) || n <= 0 || m <= 0){
        cout << "Incorrect input. Try again." << endl;
        cin.clear();
        cin.ignore(32767, '\n');
    }

    // выделение памяти под матрицу
    double** matrix = new double*[n];
    for(int i = 0; i < n; ++i){
        matrix[i] = new double[m];
    }

    //ввод элементов матрицы
    cout << "Enter the matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            while(!(cin >> matrix[i][j])){
                cout << "Incorrect input. Try again." << endl;
                cin.clear();
                cin.ignore(32767, '\n');
                i = j = 0;
            }
        }
    }

    //создание сглаженой матрицы
    double** smoothed_matrix = new double*[n];
    for(int i = 0; i < n; i++){
        smoothed_matrix[i] = new double[m];

        for(int j = 0; j < m; j++){
            //переменные для хранения суммы соседних элементов и их количества
            double sum = 0;
            int number = 0;

            //нахождение суммы всех соседних элементов
            if(i > 0){
                sum += matrix[i - 1][j];
                number++;
            }
            if(i < n - 1){
                sum += matrix[i + 1][j];
                number++;
            }
            if(j > 0){
                sum += matrix[i][j - 1];
                number++;
            }
            if(j < n - 1){
                sum += matrix[i][j + 1];
                number++;
            }

            if(i > 0 && j > 0){
                sum += matrix[i - 1][j - 1];
                number++;
            }
            if(i > 0 && j < m - 1){
                sum += matrix[i - 1][j + 1];
                number++;
            }
            if(i < n - 1 && j > 0){
                sum += matrix[i + 1][j - 1];
                number++;
            }
            if(i < n - 1 && j < m - 1){
                sum += matrix[i + 1][j + 1];
                number++;
            }

            //находим элемент сглаженой матрицы
            smoothed_matrix[i][j] = sum / number;
        }
    }

    //вывод
    cout << "Smoothed matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << smoothed_matrix[i][j] << " ";
        }
        cout << "\n";
    }
    

    //очистка памяти
    for(int i = 0; i < n; i++){
        delete[] matrix[i];
    }
    delete[] matrix;

    for(int i = 0; i < n; i++){
        delete[] smoothed_matrix[i];
    }
    delete[] smoothed_matrix;

    return 0;
}