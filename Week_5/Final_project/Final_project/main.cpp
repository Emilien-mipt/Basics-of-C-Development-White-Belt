//
//  main.cpp
//  Final_project
//
//  Created by Emin Tagiev on 12/01/2019.
//  Copyright © 2019 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <exception>



using namespace std;
// Реализуйте функции и методы классов и при необходимости добавьте свои

class Date {
public:
    //Check if string is purely a number
    bool is_number(const string& s)
    {
        bool negative_check = false;
        string::const_iterator it = s.begin();
        if(*it == '-') negative_check = true;
        while ((it != s.end() && isdigit(*it)) || negative_check){
            ++it;
            negative_check = false;
        }
        return !s.empty() && it == s.end();
    }
    
    //Function to read dates from input data
    void Get_dates(string& date, string& command){
        if(command != "Print"){
            stringstream date_numbers(date);
            char c1, c2;
            string c3, Day;
            date_numbers >> year >> c1 >> month >> c2 >> Day >> c3;
            //Check date format. Introduce special string Day to check the case "1-1--1", where the last number is -1, so the format is not wrong.
            if(c1!='-' || c2!='-' || c3!="" || !is_number(Day)){
                throw runtime_error("Wrong date format: " + date);
            }
            stringstream Day_convert(Day);
            Day_convert >> day;
            //Check month
            if(month < 1 || month > 12){
                throw runtime_error("Month value is invalid: " + to_string(month));
            }
            
            //check day
            if((day < 1 || day > 31) && (month >= 1 || month > 12)){
                throw runtime_error("Day value is invalid: " + to_string(day));
            }
        }
    }
    
    int GetYear() const{
        return year;
    };
    int GetMonth() const{
        return month;
    };
    int GetDay() const{
        return day;
    };
private:
    int day;
    int month;
    int year;
};


//In fact, overloading only "<" is enough
bool operator < (const Date& lhs, const Date& rhs){
    bool result;
    if(lhs.GetYear() != rhs.GetYear()) result = lhs.GetYear() < rhs.GetYear();
    else{
        if(lhs.GetMonth() != rhs.GetMonth()) result = lhs.GetMonth() < rhs.GetMonth();
        else{
            result = lhs.GetDay() < rhs.GetDay();
        }
    }
    return result;
}

bool operator == (const Date& lhs, const Date& rhs){
    return lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay();
}

bool operator > (const Date& lhs, const Date& rhs){
    bool result;
    if(lhs.GetYear() != rhs.GetYear()) result = lhs.GetYear() > rhs.GetYear();
    else{
        if(lhs.GetMonth() != rhs.GetMonth()) result = lhs.GetMonth() > rhs.GetMonth();
        else{
            result = lhs.GetDay() > rhs.GetDay();
        }
    }
    return result;
}

//Need to overload output stream for Date class to make it easier to use cout << ...
ostream& operator<<(ostream& stream, const Date& date) {
    stream << setw(4) << setfill('0') << date.GetYear() <<
    "-" << setw(2) << setfill('0') << date.GetMonth() <<
    "-" << setw(2) << setfill('0') << date.GetDay();
    return stream;
}

class Database {
public:
    
    void AddEvent(const Date& date, const string& event){
        map_events[date].insert(event);
    }
    
    bool DeleteEvent(const Date& date, const string& event){
        bool del_success = false;
        if(map_events.count(date)){
            if(map_events[date].count(event)) {
                del_success = true;
                map_events[date].erase(event);
            }
        }
        return del_success;
    }
    
    int  DeleteDate(const Date& date){
        unsigned long n_events = map_events[date].size();
        map_events.erase(date);
        return n_events;
    }
    
    void Find(const Date& date) const {
        if(map_events.count(date))
            for(string s:map_events.at(date)){
                cout << s << endl;
            }
    }
    
    void Print() const{
        for(auto m:map_events){
            for(string s:m.second){
                if(m.first.GetYear()>=0)
                    cout << m.first << endl;
            }
        }
    }

private:
    map<Date, set<string>> map_events;
};

int main() {
    Database db;

    string command, COMMAND, DATE, EVENT;

        try{
        while (getline(cin, command)) {
            stringstream commands(command);
            commands >> COMMAND >> DATE >> EVENT;
            if (COMMAND == "" && DATE == "" && EVENT == "") continue;
            
            if(COMMAND != "Add" && COMMAND != "Del" && COMMAND != "Find" && COMMAND != "Print")
                throw runtime_error("Unknown command: " + COMMAND);
            
            Date date;

            date.Get_dates(DATE, COMMAND);
            

            //cout << date.GetYear() << "-" << date.GetMonth() << "-" << date.GetDay() << endl;
            
            if(COMMAND == "Add")
                db.AddEvent(date, EVENT);
            else if(COMMAND == "Del"){
                if(EVENT != "")
                    if(db.DeleteEvent(date, EVENT)) cout << "Deleted successfully" << endl;
                    else cout << "Event not found" << endl;
                else
                    cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
            }
            else if (COMMAND == "Find")
                db.Find(date);
            else if (COMMAND == "Print")
                db.Print();

            COMMAND = "";
            DATE = "";
            EVENT = "";
            }
        }
        catch (exception& ex) {
            cout << ex.what() << endl;
        }
    
    return 0;
}


