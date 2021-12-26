#include <iostream>
using namespace std;




int main(){
    int t;
    cout << "Enter number of cases:";
    cin >> t;
    while(t--){
        int n;
        cout << "Enter n:";
        cin >> n;

        // интересными являются все числа с 9 на конце
        int answer = (n + 1) / 10;
        cout << "The number of interesting numbers is at most " << n << " equal " << answer << endl;

    }
}