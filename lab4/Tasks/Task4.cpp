#include <iostream>
using namespace std;

int main(){
    cout << "This program counts the number of local minima in the matrix\n";
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

    
    int count = 0;
    //подсчет количества локальных минимумов
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            double value = matrix[i][j];

            if(i > 0 && matrix[i - 1][j] <= value){
                continue;
            } 
            else if(i < n - 1 && matrix[i + 1][j] <= value){
                continue;
            }
            else if(j > 0 && matrix[i][j - 1] <= value){
                continue;
            }
            else if(j < m - 1 && matrix[i][j + 1] <= value){
                continue;
            }
            else if(i > 0 && j > 0 && matrix[i - 1][j - 1] <= value){
                continue;
            }
            else if(i > 0 && j < m - 1 && matrix[i - 1][j + 1] <= value){
                continue;
            }
            else if(i < n - 1 && j > 0 && matrix[i + 1][j - 1] <= value){
                continue;
            }
            else if(i < n - 1 && j < m - 1 && matrix[i + 1][j + 1] <= value){
                continue;
            }

            else{
                count++;
            }
        }
    }

    //вывод
    cout << "The number of local minima in the matrix equal " <<  count;

    //очистка памяти
    for(int i = 0; i < n; i++){
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
