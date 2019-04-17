//
//  main.cpp
//  Avtobusniye_ostanovki_1
//
//  Created by Emin Tagiev on 08.12.2017.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

//Функция для поиска автобусов, включающих нужную остановку
vector<string> Buses_with_stop(string& stop, map<string, vector<string>>& m){
    vector<string> buses_with_stop;
    for(auto j : m){
        for(string item : j.second){
            if(item == stop){
                //int long count_stop = 0;
                //count_stop++;
                buses_with_stop.push_back(j.first);//Список автобусов с остановкой stop
                //count_stop = count(begin(j.second), end(j.second), "stop");
            }
        }
    }
    return buses_with_stop;
}

vector<string> Buses_in_order(vector<string>& new_bus, vector<string>& buses_with_stop){
    vector<string> buses_in_order;
    for(string item_1 : new_bus){
        for(string item_2 : buses_with_stop){
            if(item_1 == item_2) buses_in_order.push_back(item_1);
        }
    }
    return buses_in_order;
}

void Print_vector(vector<string> buses, string& request){
    if(buses.size() == 0){ //Упорядочиваем список автобусов, включающих в себя остановку stop
        if(request == "BUSES_FOR_STOP"){
            cout << "No stop" << endl;
        }
        else{
            if(request == "STOPS_FOR_BUS"){
                cout << "no interchange" << endl;
            }
        }
    }
    else{
        for(string item : buses) cout << item << " ";
            cout << endl;
    }
}

void all_busses(map<string, vector<string>>& m){
    if(m.size() == 0){
        cout << "No buses" << endl;
    }
    else{
        for(auto j : m){
            cout << "Bus " << j.first << ": ";
            for(string item : j.second){
                cout << item << " ";
            }
            cout << endl;
        }
    }
}

//Функция, которая находит индекс нужного названия автобуса
int find_position(vector<string>& vector_with_buses, string& needed_bus){
    int p = 0;
    for(int k = 0; k < vector_with_buses.size(); k++){
        if(vector_with_buses[k] == needed_bus) p = k;
    }
    return p;
}

int main(int argc, const char * argv[]) {
    string request;
    int Q;
    cin >> Q;
    //vector<map<string, vector<string>>> raspisaniye;
    map<string, vector<string>> m;
    vector<string> new_bus; //заводим вектор, чтобы учесть последовательность объявления названия маршрутов
    for(int i=0; i<Q; i++){
        cin >> request;
        if(request == "NEW_BUS"){
            string bus_name;
            string route_name;
            int stop_count = 0; //Количество остановок в каждом маршруте
            cin >> bus_name >> stop_count;
            new_bus.push_back(bus_name); //Заполняем вектор с названиями автобусов в порядке заполнения
            vector<string> route(stop_count); //Вектор, для хранения становок
            for (int j = 0; j < route.size(); j++) { //Заполняем словарь
                cin >> route_name;
                route[j] = route_name;
            }
            m[bus_name] = route;
        }//if NEW_BUS
        if(request == "BUSES_FOR_STOP"){
            string stop;
            cin >> stop;
            vector<string> buses_with_stop; //Заводим вектор, чтобы хранить названия авторбусов, включающих в себя остановку stop
            buses_with_stop = Buses_with_stop(stop, m);
            vector<string> buses_in_order = Buses_in_order(new_bus, buses_with_stop);
            Print_vector(buses_in_order, request);
        }//If BUSES_FOR_STOP
        if(request == "ALL_BUSES"){
            all_busses(m);
        }//if ABOUT
        if(request == "STOPS_FOR_BUS"){
            string bus;
            cin >> bus;
            vector<string> buses_with_stop;
            if(m.count(bus) == 0){
                cout << "No bus" << endl;
            }
            else{
                for(string item : m[bus]){
                    buses_with_stop = Buses_with_stop(item, m);
                    int Position = find_position(buses_with_stop, bus);//Oпределили индекс bus
                    buses_with_stop.erase(buses_with_stop.begin() + Position);//Удалили элемент bus
                    //Вывод остановок с названиями маршрутов:
                        cout << "Stop "<< item << ": ";
                        vector<string> buses_in_order = Buses_in_order(new_bus, buses_with_stop);
                        Print_vector(buses_in_order, request);
                }
            }
        }//if STOPS_FOR_BUS
    }//Loop
    return 0;
}

