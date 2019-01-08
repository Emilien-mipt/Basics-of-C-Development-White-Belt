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

/*int average_temperature(const vector<int>& temp){ //N - number of days; vector temp - vector with temperatures for these days
    int s = 0;
    for(int c : temp) {
       // cout << s;
        s += c;
    }
    return s/temp.size();
}*/

/*int amount_of_days(const vector<int>& temp){ //Print out number of days
    int K = 0;
    for(int c : temp){
        if(c > average_temperature(temp)) K++;
    }
    return K;
}

void number_of_days(const vector<int>& temp){
    for(int j = 0; j < temp.size(); j++){
        if(temp[j] > average_temperature(temp)){
            cout << j << '\t';
        }
    }
}*/

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
    
    // cout << s;
//   average_temperature(t);
//    cout << "srednyaa temp: "<<average_temperature(t) << endl;
//    cout << amount_of_days(t) << endl;
//    number_of_days(t);
    return 0;
}
