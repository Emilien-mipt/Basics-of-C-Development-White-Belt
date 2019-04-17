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
    
    ifstream input("input.txt");

    double a;

    cout « fixed « setprecision(3);

    while (input » a) {
        cout « a « endl;
    }

    return 0;
}
