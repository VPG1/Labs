#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter n: ";
    while(!(cin >> n) || n <= 0){
        cout << "Incorrect input. Try again." << endl;
        cin.clear();
        cin.ignore(32767, '\n');
    }

    int** array = new int*[n];
    for(int i = 0; i < n; ++i){
        array[i] = new int[n];
    }

    int value = 1;
    int m = 1;
    while(m <= n){
        int i = 0, j = m - 1;
        while(i < m - 1){
            array[i][j] = value;
            ++i;
            ++value;
        }
        
        while(j >= 0){
            array[i][j] = value;
            --j;
            ++value;
        }

        ++m;
    }

    cout << "Matrix:\n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }

    int number;
    cout << "Enter the number of coordinates you want to know: ";
    cin >> number;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(array[i][j] == number){
                cout << "row " << i + 1 << "\tcolumn " << j + 1 << endl;
                break;    
            }
        }
    }

    for(int i = 0; i < n; ++i){
        delete[] array[i];
    }
    delete[] array;
}