#include <iostream>
using namespace std;

int main(){
    //ввод данных
    cout << "This program cyclically shifts an array of length k by n positions to the left\n";
    int k, n;
    cout << "Enter k, n: ";
    while(!(cin >> k >> n) || k <= 0 || n <= 0){
        cout << "Incorrect output. Try again." << endl;
        cin.clear();
        cin.ignore(32767, '\n');
    }

    int a[100];
    cout << "Enter k array elements:\n";
    for(int i = 0; i < k; i++){
        while(!(cin >> a[i])){
            cout << "Incorrect output. Try again." << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            i = 0;
        }
    }

    //в случае если k < n будем сдвигать на остаток при деления k на n
    n = n % k;

    //сдвиг на n позиций

    //условно делем массив на подмассив один с длинной n и подмассив два с длинно k - n

    //"переворачиваем" первый подмассив
    for(int i = 0; i < n / 2; i++){
        swap(a[i], a[n - 1 - i]);
    }

    //"переворачиваем" второй модмассив
    for(int i = 0; i < (k - n) / 2; i ++){
        swap(a[n + i], a[k - 1 - i]);
    }

    //"переворчиваем" весь массив
    for(int i = 0; i < k / 2; i++){
        swap(a[i], a[k - 1 - i]);
    }

    //вывод
    cout << "\n";
    for(int i = 0; i < k; i++){
        cout << a[i] << " ";
    }

    return 0;
}