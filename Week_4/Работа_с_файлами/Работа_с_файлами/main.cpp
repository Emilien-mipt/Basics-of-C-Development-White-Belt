//
//  main.cpp
//  Работа_с_файлами
//
//  Created by Emin Tagiev on 09.10.2018.
//  Copyright © 2018 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
 
int main() {
    ifstream input("input.txt");
    string line;
    ofstream output("output.txt");
    while (getline(input, line)) {
    //cout << line << "\n"; //закомментируем эту строку, для 2 части
        output << line << "\n"; //закомментируем эту строку, для 1 части
    }
    return 0;
}

