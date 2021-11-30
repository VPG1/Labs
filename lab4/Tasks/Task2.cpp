#include <iostream>
using namespace std;

int main(){
    cout << "This program counts the number of even elements on the main and secondary diagonal matrix n*n .\n";
    //ввод данных
    cout << "Enter n: ";
    int n;
    while(!(cin >> n) || n <= 0){
        cout << "Incorrect output. Try again." << endl;
        cin.clear();
        cin.ignore(32767, '\n');
    }
    
    cout << "Enter the matrix:\n";
    int a[100][100] = {0};
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            while(!(cin >> a[i][j])){
                cout << "Incorrect output. Try again." << endl;
                cin.clear();
                cin.ignore(32767, '\n');
                i = j = 0;
            }
        }
    }

    //определение количества четных элементов на главной и побочной диагонали
    int counter = 0;
    for(int i = 0; i < n; ++i){
        //проверка элемента на главной диагонали
        if(a[i][i] % 2 == 0){
            ++counter;
        }

        //проверка элемента на побочной диагонали
        if(a[i][n - 1 - i] % 2 == 0){
            ++counter;
        }
    }

    //вывод данных
    cout << counter;

    return 0;
}