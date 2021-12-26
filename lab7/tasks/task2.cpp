#include <iostream>
#include <string>
using namespace std;


int main(){
    string straightCode;
    cout << "Enter straight code:" << endl;
    cin >> straightCode;

    for(int i = 0; i < straightCode.size(); ++i){
        if(straightCode[i] != '1' && straightCode[i] != '0'){
            cout << "ERROR. Incorrect input." << endl;
            return 0;
        }
    }

    cout << "Reverse code:" << endl;
    if(straightCode[0] == '1'){
        cout << 1;

        for(int i = 1; i < straightCode.size(); ++i){
            if(straightCode[i] == '0'){
                cout << 1;
            }
            else{
                cout << 0;
            }
        }
    }
    else{
        for(int i = 0; i < straightCode.size(); ++i){
            cout << straightCode[i];
        }
    }
    return 0;
}