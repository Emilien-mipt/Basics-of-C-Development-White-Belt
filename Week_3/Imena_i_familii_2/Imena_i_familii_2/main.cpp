//
//  main.cpp
//  Imena _i_familii_2
//
//  Created by Emin Tagiev on 19.12.17.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
//#include <cctype>

using namespace std;

class Person{
public:
    
    void ChangeFirstName(int year, const string& first_name) {
        name[year] = first_name;
        // добавить факт изменения имени на first_name в год year
    }
    
    void ChangeLastName(int year, const string& last_name) {
        // добавить факт изменения фамилии на last_name в год year
        surname[year] = last_name;
    }
    
    string GetFullName(int year) {
        // получить имя и фамилию по состоянию на конец года year
        string result;
        int needed_year_name = previous_year(year, name);
        int needed_year_surname = previous_year(year, surname);
        if(needed_year_name == 0 && needed_year_surname == 0)
            result = "Incognito";
        else{
            if(needed_year_name == 0){
                result = surname[needed_year_surname] + " with unknown first name";
            }
            else{
                if(needed_year_surname == 0){
                    result = name[needed_year_name] + " with unknown last name";
                }
                else{
                    result = name[needed_year_name] + " " + surname[needed_year_surname];
                }
            }
        }
        return result;
    }
    
    string GetFullNameWithHistory(int year) {
        // получить имя и фамилию по состоянию на конец года year
        string result;
        int needed_year_name = previous_year(year, name);
        int needed_year_surname = previous_year(year, surname);
        
        //Создаем вектора с историей имен
        vector<string> history_of_names = history(needed_year_name, name);
        vector<string> history_of_surnames = history(needed_year_surname, surname);
        
        auto last_name = unique(history_of_names.begin(), history_of_names.end());
        history_of_names.erase(last_name, history_of_names.end());
        
        auto last_surname = unique(history_of_surnames.begin(), history_of_surnames.end());
        history_of_surnames.erase(last_surname, history_of_surnames.end());
        
        if(needed_year_name == 0 && needed_year_surname == 0)
            result = "Incognito";
        else{
            if(needed_year_name == 0){
                result = Print_history(history_of_surnames) + " with unknown first name";
            }
            else{
                if(needed_year_surname == 0){
                    result = Print_history(history_of_names) + " with unknown last name";
                }
                else{
                    result = Print_history(history_of_names) + " " + Print_history(history_of_surnames);
                }
            }
        }
        return result;
    }
    
    
private:
    //Функция, определяющая ближайший к году year ключ словаря
    int previous_year(int year, const map<int, string>& m){
        int i = 0;
        for(auto item : m){
            if(item.first <= year){
                i = item.first;
            }
            else{
                break;
            }
        }
        return i;
    }
    
    //Функция, заполняющая вектор с историй имен или фамилий до года year
    vector<string> history(int year, map<int, string>& m){
        vector<string> v;
        for(auto item : m){
            if(item.first <= year){
                v.push_back(item.second);
            }
            else{
                break;
            }
        }
        return v;
    }
    

    /*vector<string> history_without_rep(const set<string>& s){
        vector<string> result;
        for(string item : s){
            result.push_back(item);
        }
        return result;
    }*/
    
    //Функция, осуществляющая вывод
    string Print_history(const vector<string>& s){
            string result;
            string brakes;
            //bool flag = false;
            if(s.size() == 1){
                result = s[0];
            }
            else{
                if(s.size() == 2){
                    result = s[1] + " (" + s[0] + ")";
                }
                else{
                    result = s[s.size() - 1];
                    brakes = s[s.size() - 2];
                    for(long j = s.size() - 3; j >= 0 ; j--){
                            brakes  += (", " + s[j]);
                    }
                    result += " (" + brakes + ")";
                }
            }
            return result;
    }
    
    map<int,string> name;
    map<int,string> surname;
};


int main(int argc, const char * argv[]) {
    Person person;

    ////First Test////////////
   /* person.ChangeFirstName(1900, "Eugene");
    person.ChangeLastName(1900, "Sokolov");
    person.ChangeLastName(1910, "Sokolov");
    person.ChangeFirstName(1920, "Evgeny");
    person.ChangeLastName(1930, "Sokolov");
    cout << person.GetFullNameWithHistory(1940) << endl;
    */
    ////Second Test////////////
    
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;
    
    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;
    
    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;
    return 0;
}

