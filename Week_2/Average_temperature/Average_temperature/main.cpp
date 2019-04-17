//
//  main.cpp
//  Average_temperature
//
//  Created by Emin Tagiev on 29.09.17.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N; //number of days;
    vector<int> t(N);
    
    for(int& d : t) cin >> d; //Заполнили вектор
    //    cout << t.size() << endl;
    
    int s = 0; //Находим среднее
    for(int c : t) s += c;
//  cout << "s = " << s << endl;
    int average = 0;
    average = s/N;
//  cout << "average = " << average << endl;
    
    int K = 0; //Выводим количество дней
    for(int c : t){
        if(c > average) K++;
    }
    cout << K << endl;
    
    for(int j = 0; j < t.size(); j++){
        if(t[j] > average) cout << j << '\t';
    }
    return 0;
}
