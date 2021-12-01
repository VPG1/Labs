#include <iostream>
#include <string>
using namespace std;

int main(){
    cout << "This program searches for the diagonal of the array with the greatest sum of elements\n";
    //ввод размера трехмерного массива
    int n;
    cout << "Enter size of array: ";
    while(!(cin >> n) || n <= 0){
        cout << "Incorrect input. Try again." << endl;
        cin.clear();
        cin.ignore(32767, '\n');
    }

    //выделение памяти
    int*** array = new int**[n];
    for(int i = 0; i < n; ++i){
        array[i] = new int*[n];
        for(int j = 0; j < n; ++j){
            array[i][j] = new int[n];
        }
    }




    // ввод трехмерного массива по слоям
    // например для n = 2
    /*
     1 2
     3 4

     5 6
     7 8
     */
    cout << "Enter three-dimensional array (by layers):\n";
    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                while(!(cin >> array[i][j][k])){
                    cout << "Incorrect input. Try again." << endl;
                    cin.clear();
                    cin.ignore(32767, '\n');
                    i = j = k = 0;
                }
            }
        }
    }

    //вычисление сумм диагоналей
    int sum1 = 0;
    for(int i = 0; i < n; ++i){
        sum1 += array[i][i][i];
    }

    int sum2 = 0;
    for(int i = 0; i < n; ++i){
        sum2 += array[i][i][n - i - 1];
    }
    
    int sum3 = 0;
    for(int i = 0; i < n; ++i){
        sum3 += array[n - 1 - i][i][i];
    }

    int sum4 = 0;
    for(int i = 0; i < n; ++i){
        sum4 += array[i][n - 1 - i][i];
    }

    // угловые элементы трехмерно массива обазначим:
    /* A = (0, 0, 0)
     * B = (n - 1, 0, 0)
     * C = (n - 1, n - 1, 0)
     * D = (0, n - 1, 0)
     * A' = (0, 0, n - 1)
     * B' = (n - 1, 0, n - 1)
     * C' = (n - 1, n - 1, n - 1)
     * D' = (0, n - 1, n - 1)
     */
    // диагональю будем обазначать первым и последним её элементом
    // таким образом есть 4 диагонали AD',A'D ,BC' и B'C

    // нахождение диагонали с максимальной суммой элементов
    int max_sum = sum1;
    int number_of_diagonal = 1;
    string diagonal = "AD'";
    if(sum2 > max_sum){
        max_sum = sum2;
        number_of_diagonal = 2;
        diagonal = "A'D";
    }
    if(sum3 > max_sum){
        max_sum = sum3;
        number_of_diagonal = 3;
        diagonal = "BC'";
    }
    if(sum4 > max_sum){
        max_sum = sum4;
        number_of_diagonal = 4;
        diagonal = "B'C";
    }

    // вывод
    cout << diagonal << endl;
    cout << "The diagonal with the greatest sum of elements has number " << number_of_diagonal;

    //очистка памяти
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete[] array;

    return 0;
}