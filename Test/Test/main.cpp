//
//  main.cpp
//  Test
//
//  Created by Emin Tagiev on 30.03.2018.
//  Copyright © 2018 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*string Print_history(const vector<string>& s){
    string result;
    string brakes;
    //bool flag = false;
    if(s.size() == 1){
        result = s[0];
    }
    else{
        if(s.size() == 2){
            result = s[1] + " (" + s[0] + ")";
        }
        else{
            result = s[s.size() - 1];
            brakes = s[s.size() - 2];
            for(long j = s.size() - 3; j >= 0 ; j--){
                brakes  += (", " + s[j]);
            }
            result += " (" + brakes + ")";
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<string> names = {"Emin", "Artyom", "Slava"};
    cout << Print_history(names) << endl;
    return 0;
}
*/


class Weather {
public:
    Weather(const string& new_state, int new_temperature) {
        state = new_state;
        temperature = new_temperature;
        cout << 'c';
    }
    ~Weather() {
        cout << 'd';
    }
private:
    string state;
    int temperature;
};

Weather GetMayWeather(int day) {
    if (day == 9) {
        cout << 'b';
        return {"clear", 10};
    } else {
        cout << 'b';
        return {"cloudy", 10};
    }
}

int main() {
    vector<int> days(2, 1);
    for (int day : days) {
        cout << 'a';
        Weather weather = GetMayWeather(day);
        cout << 'e';
    }
    cout << 'f';
    return 0;
}
