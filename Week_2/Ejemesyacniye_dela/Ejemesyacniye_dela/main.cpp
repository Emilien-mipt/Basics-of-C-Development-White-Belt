//
//  main.cpp
//  Ejemesyacniye_dela
//
//  Created by Emin Tagiev on 02.10.17.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
void ADD(const int& j,const string& s, vector<vector<string>>& tasks){
    tasks[j-1].push_back(s);
}

void DUMP(int n, vector<vector<string>>& tasks){
    cout << tasks[n-1].size() << ' ';
    for(auto c: tasks[n-1]) cout << c << ' ';
    cout << endl;
}

int main(int argc, const char * argv[]) {
    int Q;
    string command;
    cin >> Q; //Количество команд
    vector<int> size_of_months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//Длительности месяцев по дням
    vector<vector<string>> stuff_to_do(31);//То, что нужно сделать в каждом месяце
    int n_month = 0; // Мы в январе
    for (int j = 0; j < Q; j++) {
        cin >> command;
        if(command == "ADD"){
            int n = 0;
            cin >> n;
            string task;
            cin >> task;
 //           stuff_to_do[n].push_back(task);
            ADD(n, task, stuff_to_do);
        }
        if(command == "DUMP"){
            int number = 0;
            cin >> number;
            DUMP(number, stuff_to_do);
        }
        if(command == "NEXT"){
            ++n_month;
            if(n_month > 11) n_month = 0;
            if (size_of_months[n_month] > stuff_to_do.size()) {
                stuff_to_do.resize(size_of_months[n_month]);
            }
            else{
                for (int j = size_of_months[n_month]; j < stuff_to_do.size(); j++) {
                stuff_to_do[size_of_months[n_month]-1].insert(end(stuff_to_do[size_of_months[n_month]-1]), begin(stuff_to_do[j]), end(stuff_to_do[j]));
                }
                stuff_to_do.resize(size_of_months[n_month]);
            }
        }
    }
    return 0;
}



