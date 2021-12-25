#include <iostream>
using namespace std;

const int MAX_SIZE = 80;

bool isDigit(char sm){
    return (sm <= '9' && sm >= '0');
}

int main(){
    char str[MAX_SIZE];
    cout << "Enter the string: ";
    cin >> str; // ???

    // переменная принимающая значени true если в строке встретилась цифра
    bool b = false;

    cout << "Substring: ";
    for(int i = 0; i < MAX_SIZE; ++i){
        if(isDigit(str[i])){
            cout << str[i];
            b = true;
        }
        else if(b){
            break;
        }
    }
}