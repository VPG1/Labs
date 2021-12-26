#include <iostream>
#include <string>
using namespace std;

string convert_to_three_numerical_system(int a){
    string result;
    if(a < 3){
        return to_string(a);
    }
    return convert_to_three_numerical_system(a / 3) + to_string(a % 3);
}

string convert_to_sasha_numerical_system(const string &num) {
    string result = num;
    int counter = 0;
    for (int i = 1; i < result.size(); i++) {
        if (result[i] == '0') {
            result[i - 1] = char(result[i - 1] - 1);
            result[i] = '3';
        }
    }
    for (int i = 0; i < result.size(); i++) {
        if (result[i] == '0') {
            result.erase(i, 1);
        }
    }
    return result;
}

int main(){
    int num;
    cout << "Enter number:";
    cin >> num;

    cout << "Number in Sasha's numerical system: ";
    cout << convert_to_sasha_numerical_system(convert_to_three_numerical_system(num));
}
