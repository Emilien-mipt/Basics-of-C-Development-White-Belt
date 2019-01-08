//
//  main.cpp
//  Imena_i_familii_3
//
//  Created by Emin Tagiev on 19.09.2018.
//  Copyright © 2018 Emin Tagiev. All rights reserved.
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
    
    Person(const string& first_name, const string& last_name, const int& year){
        name[year] = first_name;
        surname[year] = last_name;
        birth = year;
    }
    
    void ChangeFirstName(int year, const string& first_name){
        if(year >= birth)
            name[year] = first_name;
        // добавить факт изменения имени на first_name в год year
    }
    
    void ChangeLastName(int year, const string& last_name) {
        // добавить факт изменения фамилии на last_name в год year
        if(year >= birth)
            surname[year] = last_name;
    }
    
    string GetFullName(int year) const{
        // получить имя и фамилию по состоянию на конец года year
        string result;
        int needed_year_name = previous_year(year, name);
        int needed_year_surname = previous_year(year, surname);
        if(year < birth){
            result = "No person";
        }
        else{
            if(needed_year_name == 0 && needed_year_surname == 0)
                result = "Incognito";
            else{
                if(needed_year_name == 0){
                    result = surname.at(needed_year_surname) + " with unknown first name";
                }
                else{
                    if(needed_year_surname == 0){
                        result = name.at(needed_year_name) + " with unknown last name";
                    }
                    else{
                        result = name.at(needed_year_name) + " " + surname.at(needed_year_surname);
                    }
                }
            }
        }
        return result;
    }
    
    string GetFullNameWithHistory(int year) const{
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
        
        if(year < birth){
            result = "No person";
        }
        else{
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
        }
        return result;
    }
    
    
private:
    //Функция, определяющая ближайший к году year ключ словаря
    int previous_year(int year, const map<int, string>& m) const{
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
    vector<string> history(int year, const map<
                           int, string>& m) const{
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
    
    //Функция, осуществляющая вывод
    string Print_history(const vector<string>& s) const{
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
    int birth;
};


/*int main(int argc, const char * argv[]) {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    return 0;
}*/
