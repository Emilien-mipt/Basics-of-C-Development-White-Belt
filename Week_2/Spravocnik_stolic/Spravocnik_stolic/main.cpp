//
//  main.cpp
//  Spravocnik_stolic
//
//  Created by Emin Tagiev on 05.12.2017.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

inline void about_size_0(string& string_1){
    cin >> string_1;
    cout << "Country " << string_1 << " doesn't exist" << endl;
}

void change_capital_size_0(string& string_1, string& string_2, map<string, string>& m){
    m[string_1] = string_2;
    cout << "Introduce new country " << string_1 << " with capital " << string_2 << endl;
}

inline void rename_size_0(string& string_1, string& string_2){
    cin >> string_1 >> string_2;
    cout << "Incorrect rename, skip" << endl;
}

inline void dump_size_0(){
    cout << "There are no countries in the world" << endl;
}

void about(string& string_1, map<string, string>& m){
    bool counter_country = 0;
    //for(auto counter : m){//Проверяем, есть ли такая страна
    counter_country = m.count(string_1);
    //}
    if(counter_country == false) cout << "Country " << string_1 << " doesn't exist" << endl; // Если такой страны не существует
    else{
        cout << "Country " << string_1 << " has capital " << m[string_1] << endl; //Если существует
    }
}

void change_capital(string& string_1, string& string_2, map<string, string>& m){
    bool counter_country = 0;
    //for(auto counter : m){
    counter_country = m.count(string_1);//Проверка того, что есть ли уже такая страна
    //}
    if(counter_country == false){ // Если нет
        cout << "Introduce new country " << string_1 << " with capital " << string_2 << endl;
        m[string_1] = string_2; //то добавляем новый элемент в словарь
    }
    else{ // А если есть
        if(m[string_1] == string_2){ //То проверяем, есть ли уже у этой страны такая столица
            cout << "Country " << string_1 << " hasn't changed its capital" << endl;
        }
        else{ //если столица новая
            cout << "Country " << string_1 << " has changed its capital from "<< m[string_1] << " to " << string_2 << endl;
            m[string_1] = string_2; //То обновляем столицу
        }
    }
}

void RENAME(string& string_1, string& string_2, map<string, string>& m){
    bool counter_old_country = 0; //Проверяем, действительно ли страна old_country_name не существует
    bool counter_new_country = 0;//или страна new_country_name уже существует
    //for(auto i: m){
    counter_old_country = m.count(string_1);
    counter_new_country = m.count(string_2);
    //}
    if(counter_old_country == false || counter_new_country == true || string_1 == string_2){ //Также проверяем новое название страны, совпадает ли со старым
        cout << "Incorrect rename, skip" << endl;
    }
    else{ //Если запрос корректен
        string capital;
        for(auto i: m){//Пробегаемся по словарю и ищем страну с соответствующим старым названием
            if(i.first == string_1){//Если нашли, то сохраняем столицу
                capital = i.second;
            }
        }
        m.erase(string_1);//Удаляем ключ со старым названием
        m[string_2] = capital;//Создаем ключ с новым названием
        cout << "Country " << string_1 << " with capital " << capital << " has been renamed to " << string_2 << endl;
    }
}

void dump(map<string, string> m){
    for(auto i : m){
        cout << i.first << "/" << i.second << " ";
    }
}









int main(int argc, const char * argv[]) {
    int Q = 0;
    cin >> Q;
    map<string, string> m; // <country, capital>
    string request, string_1, string_2; //CHANGE_CAPITAL: string_1 - country, string_2 - capital;
    // RENAME: old_country_name to new_country_name
    // ABOVE: country_name
    for (int j = 0; j < Q; j++){
        cin >> request;
        if(m.size() == 0){ //Перед первым запросом словарь пустой, поэтому рассматриваем этот случай отдельно
            if(request == "ABOUT") {
                about_size_0(string_1);
            }
            else{
            if (request == "CHANGE_CAPITAL"){
                cin >> string_1 >> string_2;
                change_capital_size_0(string_1, string_2, m);
            }
            if(request == "RENAME"){
                rename_size_0(string_1, string_2);
            }
            if(request == "DUMP"){
                dump_size_0();
                }
            } //else (not about)
         } // if m.size() == 0
        else{ //m.size() != 0
            if(request == "ABOUT"){
                cin >> string_1;
                about(string_1, m);
            }// if ABOUT
            else{
                if(request == "CHANGE_CAPITAL"){
                    cin >> string_1 >> string_2;
                    change_capital(string_1, string_2, m);
                } //if CHANGE_CAPITAL
                if(request == "RENAME"){
                    cin >> string_1 >> string_2;
                    RENAME(string_1, string_2, m);
                } //if RENAME
                if(request == "DUMP"){
                    dump(m);
                } //if DUMP
            }//else (not ABOUT)
        } //j!=0
    } //Loop for Q
    return 0;
}
