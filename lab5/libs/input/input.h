#ifndef LAB5_INPUT_H
#define LAB5_INPUT_H

#include <iostream>
using namespace std;

template<typename T>
bool _true(const T number) {
    return true;
}

template<typename T>
void input(T& number, bool(*condition)(const T _number) = _true){
    while(!(cin >> number) || !(condition(number))){
        cout << "Incorrect output. Try again." << endl;
        cin.clear();
        cin.ignore(32767, '\n');
    }
}


template<typename T>
void input(T* number, const int n, bool(*condition)(const T _number) = _true){
    for(int i = 0; i < n; ++i) {
        while (!(cin >> number[i]) || !(condition(number[i]))) {
            cout << "Incorrect output. Try again." << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            i = 0;
        }
    }
}

template<typename T>
void input(T** number, const int n, const int m, bool(*condition)(const T _number) = _true){
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            while (!(cin >> number[i][j]) || !(condition(number[i][j]))) {
                cout << "Incorrect output. Try again." << endl;
                cin.clear();
                cin.ignore(32767, '\n');
                i = j = 0;
            }
        }
    }
}

#endif // LAB5_INPUT_H
