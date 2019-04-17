//
//  main.cpp
//  MoveStrings
//
//  Created by Emin Tagiev on 28.09.17.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination){
    for(auto s : source) destination.push_back(s);
    source.clear();
}

int main(int argc, const char * argv[]) {
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);
    for(auto c : source) cout << c << '\t';
    for(auto d : destination) cout << d << '\t';
    return 0;
}
