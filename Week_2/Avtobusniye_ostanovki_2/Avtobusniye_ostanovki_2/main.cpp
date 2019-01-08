//
//  main.cpp
//  Avtobusniye_ostanovki_2
//
//  Created by Emin Tagiev on 13.12.2017.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    map<vector<string>, unsigned long> m;
    unsigned long new_value = m.size();
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int N = 0;
        cin >> N;
        vector<string> stops(N);
        for(int j = 0; j < stops.size(); j++){ //Заполняем вектора с остановками
            string stop;
            cin >> stop;
            stops[j] = stop;
        }
        if(m.count(stops) == 0){
            new_value++;
            m[stops] = new_value;
            cout << "New bus " << new_value << endl;
        }
        else{
            cout << "Already exists for " << m[stops] << endl;
        }
    }
    return 0;
}
