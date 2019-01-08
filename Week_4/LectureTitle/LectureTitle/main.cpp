//
//  main.cpp
//  LectureTitle
//
//  Created by Emin Tagiev on 25.09.2018.
//  Copyright © 2018 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

struct Specialization{
    string value;
    explicit Specialization(const string& new_value){
        value = new_value;
    }
};

struct Course{
    string value;
    explicit Course(const string& new_value){
        value = new_value;
    }
};

struct Week{
    string value;
    explicit Week(const string& new_value){
        value = new_value;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;
    LectureTitle(const Specialization& new_specialisation, const  Course& new_course, const Week& new_week){
        specialization = new_specialisation.value;
        course = new_course.value;
        week = new_week.value;
    }
};



int main(int argc, const char * argv[]) {
    LectureTitle title(
        Specialization("C++"),
        Course("White belt"),
        Week("4th")
                       );
    return 0;
}
