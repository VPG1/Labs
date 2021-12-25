#include <iostream>
#include <string>
using namespace std;

// докажим, что если в палиндроме есть хотя бы две различные буквы,
// то максимальн длинна подстроки не являющейся палиндромом на еденицу меньше длинны палиндрома
// предположим обратное
// существует такой палиндром x1x2...x(n-1)x(n)x(n-1)...x2x1(где среди x1, x2 ... x(n) есть хотя бы два различных символа),
// что x1x2...x(n-1)x(n)x(n - 1)..x3x2 то же палиндром.
// Но тогда x1 = x2, x2 = x3, ..., x(n - 1) = x(n)
// пришли к противоречию
// те же самые рассуждения работают если длинна изначального палиндрома четна

bool isPalindrome(const string& word){
    for(int i = 0; i < word.size() / 2; ++i){
        if(word[i] != word[word.size() - i - 1]){
            return false;
        }
    }
    return true;
}
bool areCharactersEqual(const string& word){
    for(int i = 1; i < word.size(); ++i){
        if(word[0] != word[i]){
            return false;
        }
    }
    return true;
}

int main(){
    string word;
    cout << "Enter word:" << endl;
    unsigned short length;
    while(true){
        cin >> word;
        length = word.size();
        if(length <= 105 && length >= 1){
            break;
        }
        cout << "Incorrect input(word length greater than 100)" << endl;
    }

    // вывод
    cout << "Max length of non palindrome substring is: " << endl;
    if(areCharactersEqual(word)){
        cout << -1;
    }
    else if(isPalindrome(word)){
        cout << length - 1;
    }
    else{
        cout << length;
    }
}