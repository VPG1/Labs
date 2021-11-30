#include <iostream>
using namespace std;

int main(){
    cout << "This is a program for a given matrix of dimension n * m builds a new matrix according to the following principle:\n";
    cout << "The element of the new matrix is the largest of the elements of the original matrix located\nabove or to the left of the position (i, j) including this position.\n\n";
    //ввод размерности матрицы
    cout << "Enter the number of rows and columns: ";
    int n, m;
    while(!(cin >> n >> m) || n <= 0 || m <= 0){
        cout << "Incorrect output. Try again." << endl;
        cin.clear();
        cin.ignore(32767, '\n');
    }

    //создание массива матрицы и ввод её значений 
    cout << "Enter the matrix:\n";
    double** matrix = new double*[n];
    for(int i = 0; i < n; i++){
        matrix[i] = new double[m];
        
        for(int j = 0; j < m; j++){
            while(!(cin >> matrix[i][j])){
                cout << "Incorrect output. Try again." << endl;
                cin.clear();
                cin.ignore(32767, '\n');
                i = j = 0;
            }
        }
    } 

    //создание новой матрицы
    double** new_matrix = new double*[n];
    for(int i = 0; i < n; i++){
        new_matrix[i] = new double[m];
        for(int j = 0; j < m; j++){
            double new_value = matrix[i][j];

            if(i > 0 && matrix[i - 1][j] > new_value){
                new_value = matrix[i - 1][j];
            }
            if(j > 0 && matrix[i][j - 1] > new_value){
                new_value = matrix[i][j - 1];
            }
            if(i > 0 && j > 0 && matrix[i - 1][j - 1] > new_value){
                new_value = matrix[i - 1][j - 1];
            }

            new_matrix[i][j] = new_value;
        }
    }

    //вывод
    cout << "New matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << new_matrix[i][j] << " ";
        }
        cout << "\n";
    }

    //очистка памяти
    for(int i = 0; i < n; i++){
        delete[] matrix[i];
    }
    delete[] matrix;

    for(int i = 0; i < n; i++){
        delete[] new_matrix[i];
    }
    delete[] new_matrix;

    return 0;
}