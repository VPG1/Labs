#include <iostream>
using namespace std;

int main(){
    cout << "This program calculates the number of outlets obtained by the optimal connection of N extension cords (initially there is only one outlet)\n";
    // ввод количества удлинителей
    cout << "Enter N: ";
    int N;
    while(!(cin >> N) || N <= 0){
        cout << "Incorrect output. Try again." << endl;
        cin.clear();
        cin.ignore(32767, '\n');
    }

    // ввод массива с количества разеток у каждого удленителя
    int* array = new int[N];
    for(int i = 0; i < N; ++i){
        while(!(cin >> array[i])){
            cout << "Incorrect output. Try again." << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            i = 0;
        }
    }

    // подсчет количества разеток
    int number_of_input = -N + 1;
    for(int i = 0; i < N; ++i){
        number_of_input += array[i];
    }

    // вывод
    cout << number_of_input << endl;

    // очистка памяти
    delete[] array;

    return 0;
}