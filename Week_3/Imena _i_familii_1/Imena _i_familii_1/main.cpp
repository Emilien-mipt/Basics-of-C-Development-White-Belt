//
//  main.cpp
//  Imena _i_familii_1
//
//  Created by Emin Tagiev on 28.11.17.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

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
    
    map<int,string> name;
    map<int,string> surname;
};

int main(int argc, const char * argv[]) {
    Person person;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeFirstName(1965, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    
    return 0;
}
