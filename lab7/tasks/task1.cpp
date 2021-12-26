#include <iostream>
using namespace std;

void translation_from_base_5_to_10(int& num){
    int result = 0;
    int degree_of_five = 1;
    for(int i = 0; num; ++i){
        result += (num % 10) * degree_of_five;
        degree_of_five *= 5;
        num /= 10;
    }
    num = result;
}

char digit_in_base_14(int digit){
    if(digit >= 0 && digit <= 9){
        return digit + '0';
    }
    if(digit >= 10 && digit <= 13){
        return 'A' + digit - 10;
    }
}

void translation_from_base_10_to_14(int num){
    if(num < 14){
        cout << digit_in_base_14(num);
        return;
    }

    translation_from_base_10_to_14(num / 14);

    cout << digit_in_base_14(num % 14);
}


int main() {
    int num;
    cin >> num;
    translation_from_base_5_to_10(num);
    translation_from_base_10_to_14(num);
    return 0;
}
