#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <input.h>
using namespace std;

struct student{
    int number;
    string name;
    string lastname;
    string patronymic;
    string address;
    vector<int> marks;

    double get_average(){
        double res = 0;
        for(int i = 0; i < marks.size(); ++i){
            res += marks[i];
        }
        return res / marks.size();
    }

    bool operator>(const student& man){
        for(int i = 0; i < min(this->lastname.max_size(), man.lastname.max_size()); ++i){
            if(this->lastname[i] != man.lastname[i]){
                return this->lastname[i] > man.lastname[i];
            }
        }
    }
};



vector<student> creation(){
    ifstream in;
    in.open("input.txt");
    vector<student> students;
    while(!in.eof()) {
        student tmpStudent;
        in >> tmpStudent.number;
        in >> tmpStudent.name;
        in >> tmpStudent.lastname;
        in >> tmpStudent.patronymic;
        in >> tmpStudent.address;
        string marks;


        students.push_back(tmpStudent);
    }
    students.pop_back();
    in.close();

    return students;
}



void add(vector<student>& students){
    ofstream out;
    out.open("input.txt", ofstream::app);
    while(true){

        student newStudent;
        cout << "Enter information about new student" << "\n";

        cout << "Enter number:";
        cin >> newStudent.number;
        out << newStudent.number << "\n";

        cout << "Enter name:";
        cin >> newStudent.name;
        out << newStudent.name << "\n";

        cout << "Enter lastname:";
        cin >> newStudent.lastname;
        out << newStudent.lastname << "\n";

        cout << "Enter patronymic:";
        cin >> newStudent.patronymic;
        out << newStudent.patronymic << "\n";

        cout << "Enter address:";
        cin >> newStudent.address;
        out << newStudent.address << "\n";

        cout << "Enter marks:";

        for(int& mark : newStudent.marks){
            cin >> mark;
            out << mark << " ";
        }

        students.push_back(newStudent);

        // переменная хранящая ответ на вопрос
        char b;
        cout << "\nWant to continue typing(y/n):";
        cin >> b;
        if(b == 'n'){
            break;
        }

        cout << "\n";
    }
    out.close();
}


void viewing(const string& path){
    ifstream in;
    in.open(path);
    string str;
    while(!in.eof()){
        str = "";
        getline(in, str);
        cout << str << "\n";
    }
    in.close();
}

void erase(vector<student>& students){
    viewing("input.txt");
    int i;
    cout << "Enter the number of the student you want to delete\n";
    cin >> i;
    students.erase(students.begin() + i - 1);
    ofstream out;
    out.open("input.txt");
    for(const auto& man : students){
        out << man.name << "\n";
        out << man.lastname << "\n";
        out << man.patronymic << "\n";
        out << man.address << "\n";
        for(auto mark : man.marks){
            out << mark << " ";
        }
    }
    out.close();
}

void correcting(vector<student>& students){
    viewing("input.txt");
    int i;
    cout << "Enter the number of the student you want to delete\n";
    cin >> i;
    students.erase(students.begin() + i - 1);
    ofstream out;
    out.open("input.txt");
    for(const auto& man : students){
        out << man.name << "\n";
        out << man.lastname << "\n";
        out << man.patronymic << "\n";
        out << man.address << "\n";
        for(auto mark : man.marks){
            out << mark << " ";
        }
    }
    out.close();
}

vector<string> foo(const vector<student>& students){
    vector<string> lastNames;
    for(auto man : students){
        if(man.get_average() >= 4.5 && man.address == "Minsk"){
            lastNames.push_back(man.lastname);
        }
    }
    return lastNames;
}

bool compare(const string& lastName1, const string& lastName2){
     for(int i = 0; i < min(lastName1.size(), lastName2.size()); ++i){
         if(lastName1.size() != lastName2.size()){
             return lastName1[i] > lastName2[i];
         }
     }
}

void sort(vector<string>& lastNames){
    for(int i = 0; i < lastNames.size() - 1; ++i){
         for(int j = 0; j < lastNames.size() - i - 1; ++j){
             if (compare(lastNames[j], lastNames[j + 1])){
                 swap(lastNames[j], lastNames[j + 1]);
             }
         }
    }
}




int main(){
    // проверка наличия фаила
    ifstream in;
    in.open("input.txt");
    if(!in.is_open()){
        cout << "File open error\n";
        return 0;
    }
    in.close();


    vector<struct student> students;
    bool t = true;
    while(t) {
        cout << "Enter the number of the function you want to apply:\n";
        cout << "1.Initialization\n";
        cout << "2.Add students\n";
        cout << "3.Remove student\n";
        cout << "4.Correcting\n";
        cout << "5.Viewing\n";
        cout << "6.Exit\n";
        int numberOfFunction;
        cin >> numberOfFunction;
        switch (numberOfFunction) {
            case 1:
                students = creation();
                break;
            case 2:
                add(students);
                break;
            case 3:
                erase(students);
                break;
            case 4:
                correcting(students);
                break;
            case 5:
                viewing("Input.txt");
                break;
            case 6:
                t = false;
                break;
        }
    }


    // создания и запись фаила с отсортировонными фамилиями
    vector<string> lastNames= foo(students);
    sort(lastNames);
    ofstream out;
    out.open("last_names.txt");
    for(auto lastName : lastNames){
        out << lastName << "\n";
    }
    out.close();

    return 0;
}
