#include <iostream>
using namespace std;

// функция удаления дупликатов 
void delete_all_duplicates(int*& array, int& size){ // указатель на массив передаяем по ссылке чтобы этому указателю присвоить адресс нового массива в памяти
    for(int i = 0; i < size - 1; ++i){
        for(int j = i + 1; j < size; ++j){
            if(array[i] == array[j]){
                for(int k = j; k < size - 1; ++k){
                    array[k] = array[k + 1];
                }
                --size;
                --j;
            }
        }
    }

    // создаем новый массив
    int* newArray = new int[size];
    for(int i = 0; i < size; ++i){
        newArray[i] = array[i];
    }

    delete[] array;

    array = newArray;
}

int main(){
    cout << "This program delete all duplicates in array\n";
    // ввод размера массива
    int n;
    cout << "Enter size of array: ";
    while(!(cin >> n) || n <= 0){
        cout << "Incorrect input. Try again." << endl;
        cin.clear();
        cin.ignore(32767, '\n');
    }

    // ввод элементов массива и выделение памяти
    int* array = new int[n];
    cout << "Enter array:\n";
    for(int i = 0; i < n; ++i){
        while(!(cin >> array[i])){
            cout << "Incorrect input. Try again." << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            i = 0;
        }
    }

    // удаляем дубликаты
    delete_all_duplicates(array, n);
    
    // вывод
    cout << "Array without duplicates:\n";
    for(int i = 0; i < n; ++i){
        cout << array[i] << " ";
    }

    delete[] array;

    return 0;
}