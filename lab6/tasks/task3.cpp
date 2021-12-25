#include <iostream>
using namespace std;

const int n = 4096;


void reverse_sub_str(char* str, int start, int end){
    for(int i = 0; i < ((end + 1) - start) / 2; ++i){
        swap(str[start + i], str[end - i]);
    }
}

int main(){
    char* str = new char[n];
    cin.getline(str, n);

    int index1 = 0;
    int index2 = 0;
    int index3 = 0;
    int numberOfSpaces = 0;
    for(int i = 0; i < n; ++i){
        if(str[i] == ' ' && numberOfSpaces == 0 ){
            ++numberOfSpaces;
            index2 = i;
        }
        else if((str[i] == ' ' || str[i] == '\0') && numberOfSpaces == 1){
            index3 = i;

            reverse_sub_str(str, index1, index3 - 1);
            reverse_sub_str(str, index1, index3 - index2 - 2 + index1);
            reverse_sub_str(str, index3 - index2 + index1, index3 - 1);

            index1 = index3 + 1;
            numberOfSpaces = 0;
        }

        if(str[i] == '\0'){
            break;
        }
    }

    cout << str;
}
