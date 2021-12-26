#include <iostream>
#include <string>
using namespace std;

string ConvToBin(const string& number)
{
    long long tmp = stoi(number);
    string result;
    while (tmp != 0) {
        result = char(tmp % 2 + '0') + result;
        tmp /= 2;
    }
    return result;
}
string BinCounter(int end)  //counter of binary numbers, but we consider them like decimal
{
    string result = "0";
    int counter = 0;
    int i = 0;
    string tmp;
    while (i < end) {   //until we find need number
        if (result[result.size() - 1] == '0') result[result.size() - 1] = '1';
        else {
            counter = 0;
            while (counter < result.size()) {
                if (result[result.size() - 1 - counter] == '0') {
                    result[result.size() - 1 - counter] = '1';
                    for (int k = result.size() - counter; k < result.size(); k++){
                        result[k] = '0';
                    }
                    break;
                }
                counter++;
            }
            if (counter == result.size()){
                for(int j = 0; j < result.size(); j++){
                    result[j] = '0';
                }
                result = '1' + result;
            }
        }

        tmp = ConvToBin(result);
        tmp = tmp.substr(tmp.size() - result.size(), tmp.size());
        if (result == tmp) {
            i++;
        }
    }
    return result;
}

int main()
{
    cout << "Program find bindecimal number.\nEnter serial number:";
    int test;
    cin >> test;
    cout << BinCounter(test);
    return 0;
}
