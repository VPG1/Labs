#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    const int n = 5; // размер магического квадрата

    // выделение памяти
    int** matrix = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; ++i){
        matrix[i] = (int*)malloc(n * sizeof(int*));
    }

    // вычисление магического квадрата
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            matrix[i - 1][j - 1] = 1 + ((i + j - 1 + (n - 1) / 2) % n) * n + ((i + 2 * j + 2) % n);
        }
    }

    // вывод
    cout << "Magic square 5 * 5:\n\n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << setw(4) << left << matrix[i][j];
        }
        cout << endl;
    }

    // очистка памяти
    for(int i = 0; i < n; ++i){
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}