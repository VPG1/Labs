#include <iostream>
using namespace std;

// максимальный кол-во символов вводимого текста
const int n = 4096;

void deletion_letter_from_str(char*& str, const char deletedLetter){
    char* tempStr = new char[n];
    int j = 0;
    for (int i = 0; i < n && str[i] != '\0'; ++i) {
        if (str[i] != deletedLetter) {
            tempStr[j] = str[i];
            ++j;
        }
    }
    tempStr[j] = '\0';
    delete[] str;
    str = tempStr;
}

int main() {
    // ввод текса
    char *str = new char[n];
    cout << "Enter text: " << endl;
    cin.getline(str, n);

    // ввод удаляемого символа
    char ch;
    cout << "Enter symbol which you want delete: ";
    cin >> ch;

    // удаление элементов из массива
    cout << "Text after character deletion:" << endl;
    deletion_letter_from_str(str, ch);

    // вывод
    for(int i = 0; i < n && str[i] != '\0'; ++i){
        cout << str[i];
    }
    delete[] str;
}