#include <iostream>
#include "input.h"
using namespace std;

unsigned long long modExp(const long long k, const long long n, const int m){
    if(!n){
        return 1;
    }
    unsigned long long z = modExp(k, n / 2, m);
    if (n % 2) {
        return (k * z * z) % m;
    }
    return (z * z) % m;
}

bool condition_for_t(short n){
    return (n <= 100) && (n >= 1);
}
bool condition_for_L(short n){
    return (n <= 1000000000) && (n >= 1);
}
bool condition_for_m(short n){
    return (n <= 10000) && (n >= 1);
}

int main(){
    short t;
    cout << "Enter the number of cases:";
    input(t, condition_for_t);
    while(t--){
        cout << "Enter L, m, s1 and s2:" << endl;
        int L;
        input(L);

        int m;
        input(m);

        string s1, s2;
        cin >> s1 >> s2;
        cout << "Number of options: ";
        int temp = L - s1.size() - s2.size();
        if(temp > 0) {
            cout << 2 * modExp(26, temp, m) % m;
        }
        else if(temp == 0){
            cout << 2;
        }
        else if(temp >= -L){
            int number_of_options = 2;
            for(int i = L - s2.size(), j = 0; i < s1.size() - 1; ++i, ++j){
                if(s1[i] != s2[j]){
                    --number_of_options;
                    break;
                }
            }
            for(int i = L - s1.size(), j = 0; i < s2.size() - 1; ++i, ++j){
                if(s2[i] != s1[j]){
                    --number_of_options;
                    break;
                }
            }
            cout << number_of_options;
        }
        else{
            cout << 0;
        }
        cout << endl;
    }

    return 0;
}
