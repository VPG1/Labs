#include <iostream>
#include "input.h"
#include "star_line.h"
using namespace std;

// функция F
int F(const int n){
    if(n % 10 > 0){
        return n % 10;
    }
    else if(!n){
        return 0;
    }
    else{
        return F(n / 10);
    }
}

// функция S
int S(const int p, const int q){
    int sum = 0;
    for(int i = p; i <= q; ++i){
        sum += F(i);
    }
    return sum;
}

int main(){
    starLine();

    cout << "This program calculates S(p, q) = sum (F (i)) i from p to q" << endl;
    cout<< "       |n % 10, if (n % 10 > 0)" << endl;
    cout<< "F(n) = |0, if (n = 0)" << endl;
    cout<< "       |F(n / 10), otherwise" << endl;

    starLine();

    while(true){
        cout << "Enter pairs p and q (to exit enter -1 and -1): ";
        int p, q;
        input(p);
        input(q);

        if(p == -1 && q == -1) break;

        cout << "S(" << p << ", " << q <<  ") = " << S(p, q) << endl;
    }

    starLine();
}
