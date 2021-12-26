#include <iostream>
using namespace std;

int add(int x, int y){
    int a, b;
    do {
        a = x & y;
        b = x ^ y;
        x = a << 1;
        y = b;
    }while(a);
    return b;
}

int main() {
    cout << "Program check your number for divisibility by 7, 23 and 197.\nEnter your number:";
    int a;
    cin >> a;
    int arr[] = {7, 23, 197};
    for (int i = 0; i < 3; i++) {
        int tmp = a;

        // вычитаем пока больше нуля и если tmp = 0, то число делиться без остатка
        while (tmp > 0) {
            // -a = ~a + 1
            tmp = add(tmp, add(~arr[i], 1));
        }

        if (tmp == 0){
            cout << "number divided by " << arr[i] << endl;
        }
        else{
            cout << "number not divided by " << arr[i] << endl;
        }
    }

    return 0;
}