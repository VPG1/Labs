#include <iostream>
#include <string>
using namespace std;

// формула для подсчета кол-ва анаграмм
//  t = n! / (m1! * m2! * ... * ml! * ... * mk!)
// n - длинна слова, k - кол-во различных букв, ml - кол-во вхождений буквы под номером l в слов

long long fact(const int n){
   if(!n){
       return 1;
   }
    return  n * fact(n - 1);
}

int main(){
    string word;
    cout << "Enter word:" << endl;
    unsigned short length;
    while(true){
        cin >> word;
        length = word.size();
        if(length <= 14){
            break;
        }
        cout << "Incorrect input(word length greater than 14)" << endl;
    }

    // используем long long т.к максимальное значение answer равно 14! = 87178291200 > 1e10
    long long answer = fact(length);

    for(int i = 0, tempLength = length; i < tempLength; ++i){
        int n = 1;
        for(int j = i + 1; j < tempLength; ++j){
            if(word[i] == word[j]){
                word.erase(j, 1);
                --j;
                --tempLength;
                ++n;
            }
        }
        answer /= fact(n);
    }
    cout << "Number of anagrams:" << answer << endl;

    return 0;
}
