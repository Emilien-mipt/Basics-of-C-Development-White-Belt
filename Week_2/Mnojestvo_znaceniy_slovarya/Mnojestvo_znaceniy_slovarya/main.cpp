//
//  main.cpp
//  Mnojestvo_znaceniy_slovarya
//
//  Created by Emin Tagiev on 14.12.2017.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    vector<string> words;
    for(auto item : m){
        words.push_back(item.second);
    }
    set<string> values(begin(words), end(words));
    return values;
}

/int main(int argc, const char * argv[]) {
    set<string> values = BuildMapValuesSet({
        {1, "odd"},
        {2, "even"},
        {3, "odd"},
        {4, "even"},
        {5, "odd"}
    });
    
    for (const string& value : values) {
        cout << value << endl;
    }
    return 0;
}
