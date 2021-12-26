#include <iostream>
#include <string>
using namespace std;





string sum(string& num1, string& num2)
{
    string result;

    string ls1 = num1.size() < num2.size() ? num1 : num2; //little string
    string ls2 = num1.size() < num2.size() ? num2 : num1; //equalize strings

    if (num1.size() != num2.size()) {
        for (int i = ls1.size(); i < ls2.size(); i++){
            ls1 = '0' + ls1; // ?
        }
    }
    int a = 0, b = 0, r = 0;
    for (int i = ls1.size() - 1; i >= 0 ; i--) {
        if(ls1[i] >= 'A' && ls1[i] <= 'D'){
            a = 10 + ls1[i] - 'A';
        }
        else{
            a = ls1[i] - 48; //convert_to_three_numerical_system to digit
        }


        if(ls2[i] >= 'A' && ls2[i] <= 'D'){
            b = 10 + ls2[i] - 'A';
        }
        else{
            b = ls2[i] - 48;
        }


        int digitSum = (a + b + r) % 14;
        if(digitSum >= 10 && digitSum <= 13){
            result = char('A' + digitSum - 10) + result;
        }
        else{
            result = char(digitSum + '0') + result;
        }
        r = (a + b + r) / 14;
    }
    return result;
}

int main(){
    cout << "This program adds two numbers in fourteen digits system" << endl;

    string a;
    cout << "Enter first number:";
    cin >> a;

    string b;
    cout << "Enter second number:";
    cin >> b;

    cout << a << " + " << b << " = " <<  sum(a, b);
}