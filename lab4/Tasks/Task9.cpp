#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    cout << "This program multiplies matrices A and B\n";
    // ввод размера матрицы A
    int n, m; // n кол-во строк матрицы A   m кол-во столбцов матрицы A
    cout << "Enter the number of rows and columns of matrix A: ";
    while(!(cin >> n >> m) || n <= 0 || m <= 0){
        cout << "Incorrect output. Try again." << endl;
        cin.clear();
        cin.ignore(32767, '\n');
    }

    // выделение памяти под под матрицу А и B
    int** A = (int**)malloc(n * sizeof(int));
    for(int i = 0; i < n; ++i){
        A[i] = (int*)malloc(m * sizeof(int));
    }


    // ввод элементов матирцы A
    cout << "Enter elements of matrix A:\n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            while(!(cin >> A[i][j])){
                cout << "Incorrect output. Try again." << endl;
                cin.clear();
                cin.ignore(32767, '\n');
                i = j = 0;
            }
        }
    }

    // ввод размера матрицы B
    int l, k; // l кол-во строк матрицы B   k кол-во столбцов матрицы B 
    cout << "Enter the number of rows and columns of matrix B: ";
    cin >> l >> k;

    int** B = (int**)malloc(l * sizeof(int*));
    for(int i = 0; i < l; ++i){
        B[i] = (int*)malloc(k * sizeof(int));
    }

    // ввод элементов матирцы B и выделение памяти под эту матрицы
    cout << "Enter elements of matrix B:\n";

    for(int i = 0; i < l; ++i){
        for(int j = 0; j < k; ++j){
            while(!(cin >> B[i][j])){
                cout << "Incorrect output. Try again." << endl;
                cin.clear();
                cin.ignore(32767, '\n');
                i = j = 0;
            }
        }
    }

    // проверка на совместимость A и B
    if(m != l){
        cout << "Matrices are not consistent";
        return 0;
    }

    // умножение матриц и выделение под новую матрицы памяти 
    int** C = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; ++i){
        C[i] = (int*)malloc(k * sizeof(int));

        for(int j = 0; j < k; ++j){
            int newElement = 0;
            for(int t = 0; t < m; ++t){
                newElement += A[i][t] * B[t][j];
            }
            C[i][j] = newElement;
        }
    }


    cout << "////////////////////////////////////////////////////////////////" << endl;

    //вывод
    cout << "The result of matrix multiplication is this matrix:\n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < k; ++j){
            cout << setw(4) << left <<  C[i][j] << " ";
        }
        cout << endl;
    }

    // очистка памяти
    for(int i = 0; i < n; ++i){
        free(A[i]);
        free(C[i]);
    }
    free(A);
    free(C);

    for(int i = 0; i < l; ++i){
        free(B[i]);
    }
    free(B);

    return 0;
}