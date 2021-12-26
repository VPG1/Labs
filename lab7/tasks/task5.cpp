#include <iostream>
#include <string>
using namespace std;

string convert_to_roman_numerals(int num){
    string romanNumerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int arabicNumerals[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string result;
    for(int i = 0; i <= 12; ++i){
        while(num - arabicNumerals[i] >= 0){
            result += romanNumerals[i];
            num -=arabicNumerals[i];
        }
    }
    return result;
}



int main(){
    int num;
    cin >> num;
    cout << convert_to_roman_numerals(num) << endl;
}