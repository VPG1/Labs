#include <iostream>
#include <string>
#include <vector>
#include "input.h"
using namespace std;

struct worker{
    string name;
    string lastname;
    string patronymic;
    int id;
    int workedHours;
    int hourlyPayment;


    void get_info() const{
        cout << "name:" << this->name << "\t";
        cout << "lastname:" << this->lastname << "\t";
        cout << "patronymic:" << this->patronymic << "\t";
        cout << "id:" << this->id << "\t";
        cout << "worked hours:" << this->workedHours << "\t";
        cout << "hourly payment:" << this->hourlyPayment << "\n";
    }

    int get_salary () const{
        return workedHours * hourlyPayment;
    }

    bool operator>(const worker& man) const{
        return this->get_salary() > man.get_salary();
    }


};

// условие корректного ввод для выбора типа заполнеиня
bool condition1(int n){
    return n == 0 || n == 1;
}


bool condition2(char ch){
    return ch == 'y' || ch == 'n';
}

// условие корректного ввод для целочисленых полей структуры
bool condition3(int n){
    return n >= 0;
}

// условие корректного ввода для выбора поля
bool condition4(int n){
    return n >= 1 && n <= 6;
}

// условие корректного ввода для выбора функции
bool condition5(int n){
    return n >= 1 && n <= 7;
}

vector<worker> creation(){
    int type_of_input;
    cout << "Select input method\n";
    cout << "Enter 0 if you want to indicate the number of employees in advance\n";
    cout << "Enter 1 if you want to be able to stop typing\n";
    input(type_of_input, condition1);

    // переменная хранящая ответ на вопрос
    char a;
    bool hourlyPayById;
    cout << "Do you want to fill in the hourly pay with the last two digits of the tracking number?(y/n):";
    input(a, condition2);
    if(a == 'y'){
        hourlyPayById = true;
    }
    else{
        hourlyPayById = false;
    }
    cout << "\n";

    vector<worker> workers;

    if(type_of_input == 0){
        int n;
        cout << "Enter number of workers:";
        input(n, condition3);
        workers.resize(n);

        for (int i = 0; i < n; ++i){
            cout << "Enter information about worker number " << i + 1 << "\n";
            cout << "Enter name:";
            cin >> workers[i].name;
            cout << "Enter lastname:";
            cin >> workers[i].lastname;
            cout << "Enter patronymic:";
            cin >> workers[i].patronymic;
            cout << "Enter id:";
            input(workers[i].id, condition3);
            cout << "Enter the number of hours worked:";
            input(workers[i].workedHours, condition3);
            if(hourlyPayById){
                workers[i].hourlyPayment = workers[i].id % 100;
            }
            else{
                cout << "Enter hourly payment:";
                input(workers[i].hourlyPayment, condition3);
            }
            cout << "\n";
        }
    }
    else{
        int i = 1;
        while(true){
            worker man;
            cout << "Enter information about worker number " << i << "\n";
            cout << "Enter name:";
            cin >> man.name;
            cout << "Enter lastname:";
            cin >> man.lastname;
            cout << "Enter patronymic:";
            cin >> man.patronymic;
            cout << "Enter id:";
            input(man.id, condition3);
            cout << "Enter the number of hours worked:";
            input(man.workedHours, condition3);

            if(hourlyPayById){
                man.hourlyPayment = man.id % 100;
            }
            else{
                cout << "Enter hourly payment:";
                input(man.hourlyPayment, condition3);
            }
            workers.push_back(man);

            // переменная хранящая ответ на вопрос
            char b;
            cout << "\nWant to continue typing(y/n):";
            input(b, condition2);
            if(b == 'n'){
                break;
            }

            ++i;
            cout << "\n";
        }
    }
    cout << "\n";

    return workers;
}


void viewing(vector<worker> workers){
    cout << "Workers:\n";
    for(int i = 0; i < workers.size(); ++i){
        cout << "Worker number " << i + 1 << "\n";
        workers[i].get_info();
    }
    cout << "\n";
}

void add(vector<worker>& workers){
    // переменная хранящая ответ на вопрос
    char a;
    bool hourlyPayById;
    cout << "Do you want to fill in the hourly pay with the last two digits of the tracking number?(y/n):";
    input(a, condition2);
    if(a == 'y'){
        hourlyPayById = true;
    }
    else{
        hourlyPayById = false;
    }
    cout << "\n";

    while(true){
        worker newWorker;
        cout << "Enter information about new worker" << "\n";
        cout << "Enter name:";
        cin >> newWorker.name;
        cout << "Enter lastname:";
        cin >> newWorker.lastname;
        cout << "Enter patronymic:";
        cin >> newWorker.patronymic;
        cout << "Enter id:";
        input(newWorker.id, condition3);
        cout << "Enter the number of hours worked:";
        input(newWorker.workedHours, condition3);

        if(hourlyPayById){
            newWorker.hourlyPayment = newWorker.id % 100;
        }
        else{
            cout << "Enter hourly payment:";
            input(newWorker.hourlyPayment, condition3);
        }
        workers.push_back(newWorker);

        // переменная хранящая ответ на вопрос
        char b;
        cout << "\nWant to continue typing(y/n):";
        input(b, condition2);
        if(b == 'n'){
            break;
        }

        cout << "\n";
    }
    cout << "\n";
}




void search(const vector<worker>& workers){
    cout << "Enter number of characteristic by which you want to search for the worker\n";
    cout << "1.name\n";
    cout << "2.lastname\n";
    cout << "3.patronymic\n";
    cout << "4.id\n";
    cout << "5.number of hours worked\n";
    cout << "6.hourly payment\n";
    int numberOfCharacteristic;
    input(numberOfCharacteristic, condition4);

    if(numberOfCharacteristic == 1){
        string name;
        cout << "Enter name:";
        cin >> name;
        for(const auto& man : workers){
            if(man.name == name){
                cout << "Worker:\n";
                man.get_info();

            }
        }
        return;

    }
    if(numberOfCharacteristic == 2){
        string lastname;
        cout << "Enter lastname:";
        cin >> lastname;

        for(const auto& man : workers){
            if(man.lastname == lastname){
                cout << "Worker:\n";
                man.get_info();
            }
        }
        return;
    }
    if(numberOfCharacteristic == 3){
        string patronymic;
        cout << "Enter patronymic:";
        cin >> patronymic;
        for(const auto& man : workers){
            if(man.patronymic == patronymic){
                cout << "Worker:\n";
                man.get_info();
            }
        }
        return;
    }
    if(numberOfCharacteristic == 4){
        int id;
        cout << "Enter id:";
        input(id, condition3);
        for(const auto& man : workers){
            if(man.id == id){
                cout << "Worker:\n";
                man.get_info();
            }
        }
        return;
    }
    if(numberOfCharacteristic == 5){
        int workedHours;
        cout << "number of hours worked:";
        input(workedHours, condition3);
        for(const auto & worker : workers){
            if(worker.workedHours == workedHours){
                cout << "Worker:\n";
                worker.get_info();
            }
        }
        return;
    }
    if(numberOfCharacteristic == 6){
        int hourlyPayment;
        cout << "Enter hourly payment:";
        input(hourlyPayment, condition3);
        for(const auto & worker : workers){
            if(worker.hourlyPayment == hourlyPayment){
                cout << "Worker:\n";
                worker.get_info();
            }
        }
        return;
    }
}

void erase(vector<worker>& workers){
    viewing(workers);
    int i;
    cout << "Enter the number of the worker you want to delete\n";
    input(i, condition3);
    workers.erase(workers.begin() + i  - 1);
}

void change_el(vector<worker>& workers){
    viewing(workers);
    int i;
    cout << "Enter the worker number information about which you want to change\n";
    input(i, condition3);

    char a;
    cout << "Are you want change name?(y/n)\n";
    input(a, condition2);
    if(a == 'y'){
        cin >> workers[i - 1].name;
    }

    cout << "Are you want change lastname?(y/n)\n";
    input(a, condition2);
    if(a == 'y'){
        cin >> workers[i - 1].lastname;
    }

    cout << "Are you want change patronymic?(y/n)\n";
    input(a, condition2);
    if(a == 'y'){
        cin >> workers[i - 1].patronymic;
    }

    cout << "Are you want change id?(y/n)\n";
    input(a, condition2);
    if(a == 'y'){
        input(workers[i - 1].id, condition3);
    }

    cout << "Are you want change number of hours worked?(y/n)\n";
    input(a, condition2);
    if(a == 'y'){
        input(workers[i - 1].workedHours, condition3);
    }

    input(a, condition2);
    cout << "Are you want change hourly pay?(y/n)\n";
    if(a == 'y'){
        input(workers[i - 1].hourlyPayment, condition3);
    }
}


void sort(vector<worker>& workers){
    for(int i = 0; i < workers.size() - 1; ++i){
        for(int j = 0; j < workers.size() - i - 1; ++j){
            if(workers[j] > workers[j + 1]){
                swap(workers[j], workers[j + 1]);
            }
        }
    }
}

int main(){
    vector<worker> workers = creation();

    bool t = true;
    while(t) {
        cout << "Enter the number of the function you want to apply:\n";
        cout << "1.View content\n";
        cout << "2.Add workers\n";
        cout << "3.Search for the worker(by field)\n";
        cout << "4.Remove worker\n";
        cout << "5.Change information about worker\n";
        cout << "6.Sort worker by salary\n";
        cout << "7.Exit\n";
        int numberOfFunction;
        input(numberOfFunction, condition5);
        switch (numberOfFunction) {
            case 1:
                viewing(workers);
                break;
            case 2:
                add(workers);
                break;
            case 3:
                search(workers);
                break;
            case 4:
                erase(workers);
                break;
            case 5:
                change_el(workers);
                break;
            case 6:
                sort(workers);
                break;
            case 7:
                t = false;
                break;
        }
    }
    return 0;
}
