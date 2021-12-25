#include <iostream>
#include <string>
#include "input.h"
using namespace std;

int main(){
    int numberOfCases;
    cout << "Enter number of cases:";
    input(numberOfCases);
    while(numberOfCases--){
        string s;
        string t;
        cout << "Enter s:" << endl;
        cin >> s;
        cout << "Enter t:" << endl;
        cin >> t;
        int j = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == t[0]){
                ++j;
                for(int l = i + 1; l < s.size(); ++l){
                    if(s[l] != t[j]){
                        for(int k = l - 2; k >= 0; --k){
                            if(s[k] != t[j]){
                                break;
                            }
                            else {
                                ++j;
                            }
                        }
                        break;
                    }
                    else{
                        ++j;
                    }
                }
                break;

            }
        }

        if(j == t.size()){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
