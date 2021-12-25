#include <iostream>
#include "input.h"
#include "star_line.h"
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


bool condition1(const long long num){
//    long long tenPowNineteen = 1;
//    for(int i = 0; i < 19; ++i){
//        tenPowNineteen *= 10;
//    }
    return (num >= 0);
}
bool condition2(const short num){
    return (num >= 0) && (num < 10);
}


int main(){
    starLine();

    cout << "This program calculates x = sum (f(i)) i from 0 to n * (k - 1)" << endl;
    cout<< "       |1, if (n = 0, r = 0)" << endl;
    cout<< "f(n) = |sum(f(n - 1,r - i)) i from 0 to k - 1, if ((n > 0) and (0 <= r < n * (k - 1) + 1))" << endl;
    cout<< "       |0, otherwise" << endl;

    starLine();

    int counter = 1;
    while(true){
        long long k, n;
        short t;
        cout << "Enter k, n and t (to exit enter 0, 0 and 0): " << endl;
        input(k, condition1);
        input(n, condition1);
        input(t, condition2);

        if(!k && !n && !t) break;

        int m = 1;
        for(int i = 0; i < t; ++i){
            m *= 10;
        }

        cout << "Case #" << counter << " " << modExp(k, n, m) % m << endl;

        ++counter;
    }

}

