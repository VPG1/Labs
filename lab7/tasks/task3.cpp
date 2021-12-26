#include <iostream>
#include <string>
using namespace std;


void translation_in_additional_code(string &s) {
    if (s[0] == '1') {
        for (int i = 1; i < static_cast<int>(s.size()); i++) {
            if (s[i] == '0') {
                s[i] = '1';
            } else {
                s[i] = '0';
            }
        }
        bool f = false;
        for (int i = s.size() - 1; i > 0; i--) {
            if (s[i] == '0') {
                s[i] = '1';
                f = true;
                break;
            }
        }
        if (!f) {
            for (int i = 1; i < static_cast<int>(s.size()); i++) {
                s[i] = '0';
            }
        }
    }
}

string sum(string &a, string &b) {
    while (max(a.size(), b.size()) - a.size()) {
        a.insert(1, "0");
    }
    while (max(a.size(), b.size()) - b.size()) {
        b.insert(1, "0");
    }

    string result(a.size(), 0);
    for (int i = result.size() - 1; i > 0; i--) {
        result[i] += a[i] + b[i] - '0';
        if (result[i] > '1') {
            result[i] -= 2;
            result[i - 1]++;
        }
    }
    result[0] = a[0] + b[0] - '0';
    if (result[0] > '1') {
        result[0] -= 2;
    }
    return result;
}

int main(){
    cout << "Enter the number in binary:";
    string num1;
    cin >> num1;
    for(int i = 0; i < num1.size(); ++i){
        if(num1[i] != '1' && num1[i] != '0'){
            cout << "ERROR. Incorrect input." << endl;
            return 0;
        }
    }

    string num2;
    cin >> num2;
    for(int i = 0; i < num2.size(); ++i){
        if(num2[i] != '1' && num2[i] != '0'){
            cout << "ERROR. Incorrect input." << endl;
            return 0;
        }
    }

    translation_in_additional_code(num1);
    translation_in_additional_code(num2);

    cout << num1 << " + " << num2 <<  sum(num1, num2);
}

