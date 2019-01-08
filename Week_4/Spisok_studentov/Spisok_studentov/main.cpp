//
//  main.cpp
//  Spisok_studentov
//
//  Created by Emin Tagiev on 10.10.2018.
//  Copyright © 2018 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student{
    string name;
    string surname;
    int day;
    int month;
    int year;
};

int main(int argc, const char * argv[]) {
    vector<Student> List_of_students;
    int N=0; //Количество студентов
    int M=0; //Количество запросов
    string command;
    int K=0;
    
    cin >> N;
    for(int i=0; i<N; i++){
        Student student;
        cin >> student.name >> student.surname
        >> student.day >> student.month >> student.year;
        List_of_students.push_back(student);
    }
    
    cin >> M;
    for(int j=0; j<M; j++){
        cin >> command >> K;
        //--K;
        if(command == "name" && K>=1 && K<N){
            cout << List_of_students[K-1].name << " " << List_of_students[K-1].surname << endl;
        }
        else if(command == "date" && K>=1 && K<N){
                cout << List_of_students[K-1].day << "." <<
                List_of_students[K-1].month << "." << List_of_students[K-1].year << endl;
            }
            else{
                cout << "bad request" << endl;
            }
        
    }

    return 0;
}
