//
//  main.cpp
//  Cteniye_i_vivod_tablici
//
//  Created by Emin Tagiev on 10.10.2018.
//  Copyright © 2018 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream input("input.txt");
    int N = 0; //N строк
    int M = 0; //M столбцов
    int number = 0;
    if(input){
        input >> N >> M;
        //cout << "Test for N and M: " << N << " " << M << endl;
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            input >> number;
            input.ignore(1);
            if(j == M-1)
                cout << setw(10) << number;
            else
                cout << setw(10) << number << " ";
        }
        cout << endl;
    }
    return 0;
}
