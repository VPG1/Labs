#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void deletion_all_substr(string& str, string substrToDelete){
    int i = str.find(substrToDelete);
    while(i != -1){
        str.erase(i, 1);
        i = str.find(substrToDelete, i);
    }
}
void replacing_all_substr_with_substr(string& str,const string& replaceableSubstr, const string& substrToReplace){
    int i = str.find(replaceableSubstr);
    while(i != -1){
        str.replace(i, replaceableSubstr.size(), substrToReplace);
        i = str.find(replaceableSubstr, i);
    }
}
void replacement_c(string& str){
    unsigned int i = str.find('c');
    while(i != -1){
        if(str[i + 1] == 'e' || str[i + 1] == 'i' || str[i + 1] == 'y'){
            str[i] = 's';
        }
        else{
            str[i] = 'k';
        }
        i = str.find('c', i);
    }
}

void deletion_double_consonants(string& str){
    for(int i = 0; i < str.size() - 1; ++i){
        bool vowelLetter = (str[i] == 'a') || (str[i] == 'e') || (str[i] == 'i') || (str[i] == 'o') || (str[i] == 'u') || (str[i] == 'y');
        if(!vowelLetter && str[i] == str[i + 1]){
            str.erase(i + 1, 1);
        }
    }
}


int main(){
    string inPath = "input.txt";
    string outPath = "output.txt";
    ifstream in(inPath);
    ofstream out(outPath);
    if(!in.is_open()){
        cout << "Error. Could not find read file." << endl;
        cout << "Check if the read file exists and if the path to it is correct." << endl;
        return 0;
    }

    while(!in.eof()){
        string str;
        getline(in, str);

        // удаляем C, Q, W, X
        deletion_all_substr(str, "C");
        deletion_all_substr(str, "Q");
        deletion_all_substr(str, "W");
        deletion_all_substr(str, "X");

        // замена c
        replacement_c(str);

        // замена qu на kv, q на k, x на ks, ph на f, you и oo на u, ee на i и th на z
        replacing_all_substr_with_substr(str, "qu", "kv");
        replacing_all_substr_with_substr(str, "Qu", "Kv");

        replacing_all_substr_with_substr(str, "q", "k");
        replacing_all_substr_with_substr(str, "Q", "K");

        replacing_all_substr_with_substr(str, "w", "v");
        // поскольку в задание нечетко сформулирован порядок замен и W выше удаляется это строка бесполезна
        replacing_all_substr_with_substr(str, "W", "V");

        replacing_all_substr_with_substr(str, "x", "ks");
        // то же самое, что и с W
        replacing_all_substr_with_substr(str, "X", "Ks");

        replacing_all_substr_with_substr(str, "ph", "f");
        replacing_all_substr_with_substr(str, "Ph", "F");

        replacing_all_substr_with_substr(str, "you", "u");
        replacing_all_substr_with_substr(str, "You", "U");

        replacing_all_substr_with_substr(str, "oo", "u");
        replacing_all_substr_with_substr(str, "ee", "i");

        replacing_all_substr_with_substr(str, "th", "z");
        replacing_all_substr_with_substr(str, "Th", "Z");

        //удаление двойных согласных
        deletion_double_consonants(str);


        out << str << endl;
    }

    cout << "program execution successfully";

    return 0;
}

