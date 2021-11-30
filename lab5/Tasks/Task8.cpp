#include <iostream>
#include "input.h"
#include "star_line.h"
using namespace std;

// f(k) - наибольший нечёнтый делитель k
// очевидно, что если k нечётное, то f(k) = k
// для чётных k верно следуешее равенство f(k) = f(k / 2)
// действительно, если чётное число x делиться на y, то очевидно, что x делиться на (x / y)
// минимальный нетривильный делитель четного числа x(т.е. не единица и не оно само) это 2
// следовательно максимальный нетривиальный делитель числа x это (x / 2)

// пусть g(n) = f(1) + f(2) + ... + f(n)
// кол-во слагаемых с чётным аргументом l = n / 2 c округлением вниз
// кол-во слагаемых с нечётным аргументом k =  n / 2 с окргуглением вверх
// g(n) = f(2) + f(4) + ... + f(2 * l) + f(1) + f(3) + ... + f(2 * k + 1)
// g(n) = f(1) + f(2) + ... + f(l) + 1 + 3 + ... + 2 * k + 1
// g(n) = g(l) + ((1 + 2 * k - 1) / 2) * k
// g(n) = g(l) + k ^ 2

unsigned long long g(const int n){
    int k = (n + 1) / 2;
    if(!n) return 0;
    return g(n / 2) + k * k;
}

bool condition(const int n){
    return (n > 0) && (n < 1000000000);
}

int main(){
    starLine();

    cout << "This program calculate sum f(1) + f(2) + ... + f(n)" << endl;
    cout << "where f (n) is the greatest odd divisor of n" << endl;

    starLine();

    int n;
    cout << "Enter n(0 < n <= 10^9): ";
    input(n, condition);
    cout << "This sum for " << n << " equal " << g(n);
}
