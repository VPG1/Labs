#include <iostream>
#include <string>
using namespace std;

bool is_digit(char sm){
    return (sm <= '9' && sm >= '0');
}

int str_sum(const string& str){
    int sum = 0;
    bool thereAreNum = false;
    for(int i = 0; i < str.size(); ++i){
        string tmpSubStr;
        if(is_digit(str[i])) {
            while (is_digit(str[i])) {
                tmpSubStr.push_back(str[i]);
                ++i;
            }
            sum += stoi(tmpSubStr);
            thereAreNum = true;
        }
    }
    if(thereAreNum){
        return sum;
    }
    return -1;
}

int main(){
    string s;
    cout << "Enter string:" << endl;
    cin >> s;

    int result = str_sum(s);
    if(result == -1){
        cout << "No numbers in string" << endl;
    }
    else{
        cout << "Sum of numbers in string equal " << result << endl;
    }
}
