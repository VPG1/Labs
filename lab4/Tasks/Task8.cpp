#include <iostream>
using namespace std;

int main(){
    cout << "This program will replace all elements between the largest and smallest elements in the array with zeros," << endl;
    cout << "and if the number of zeros is more than half, then it removes all zeros from the array." <<endl;
    //ввод размера массива
    int n;
    cout << "Enter size of array: ";
    while(!(cin >> n) || n <= 0){
        cout << "Incorrect input. Try again." << endl;
        cin.clear();
        cin.ignore(32767, '\n');
    }

    //ввод элементов массива
    int* array = new int[n];
    cout << "Enter elements of array:\n";
    for(int i = 0; i < n; ++i){
        while(!(cin >> array[i])){
            cout << "Incorrect input. Try again." << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            i = 0;
        }
    }

    // поиск индексов минимального и максимального элемента
    int index_of_min = 0;
    int index_of_max = 0;
    for(int i = 1; i < n; ++i){
        if(array[i] < array[index_of_min]){
            index_of_min = i;
        }
        else if(array[i] > array[index_of_max]){
            index_of_max = i;
        }
    }
    
    // сравниваем индексы минимального и максимального
    int greater_index = index_of_max;
    int lower_index = index_of_min;
    if(index_of_min > index_of_max){
        greater_index = index_of_min;
        lower_index = index_of_max;
    }

    // вычисление количества нулей в массиве
    int number_of_zeros = greater_index - lower_index - 1;
    // поиск нуля в исходном массиве 
    for(int i = 0; i <= lower_index; ++i){
        if(array[i] == 0){
            ++number_of_zeros;
            break;
        }
    }

    for(int i = greater_index; i < n; ++i){
        if(array[i] == 0){
            ++number_of_zeros;
            break;
        }
    }

    // замена всех элементов массива между наименьшим и наибольшим элементом на нули
    for(int i = lower_index + 1; i < greater_index; ++i){
        array[i] = 0;
    }
    
    // удаление нулей из массива
    if(number_of_zeros > n / 2){
        int* newArray = new int[n - number_of_zeros];

        for(int i = 0, j = 0; i < n; ++i){
            if(array[i] != 0){
                newArray[j] = array[i];
                ++j;
            }
        }

        n -= number_of_zeros;

        delete[] array;

        array = newArray;
    }

    //вывод
    cout << "Array after transformation: ";
    for(int i = 0; i < n; ++i){
        cout << array[i] << " ";
    }

    //очистка памяти
    delete[] array;

    return 0;
}