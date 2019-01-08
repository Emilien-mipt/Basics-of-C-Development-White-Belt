//
//  main.cpp
//  Vivod_s_tochnostyu
//
//  Created by Emin Tagiev on 09.10.2018.
//  Copyright © 2018 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    /*
    ifstream input("input.txt");
    double number = 0;
    vector<double> numbers;
    while(!input.eof()){
        input >> number;
        numbers.push_back(number);
    }
    numbers.pop_back();
    for(int i = 0; i < numbers.size(); i++){
        cout << fixed << setprecision(3) << numbers[i] << endl;*/
    
    ifstream input("input.txt");

    double a;

    cout « fixed « setprecision(3);

    while (input » a) {
        cout « a « endl;
    }
        

    /*ifstream input("input.txt");
    double line;
    cout << fixed << setprecision(3);
    while (input) {
        input >> line;
        cout << line << endl;
    }*/

    /*ifstream input("input.txt"); //входной поток из файла
    string line;
    while (getline(input, line)) { //пока не кончатся строки
        //тут я порылся в инете(с мыслью конвертировать строки в число), и нашел интересность ниже
        double dline = atof(line.c_str()); //любопытная штукенция для конвертации
        cout << fixed << setprecision(3); //как положено, 3 знака после точки
        cout << dline << "\n";
    }*/

    return 0;
}
