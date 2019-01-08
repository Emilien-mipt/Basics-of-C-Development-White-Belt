//
//  main.cpp
//  Ensure_Equal
//
//  Created by Emin Tagiev on 22.10.2018.
//  Copyright © 2018 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void EnsureEqual(const string& left, const string& right){
    if(left != right){
        stringstream s;
        s << left << " " << "!= " << right;
        throw runtime_error(s.str());
    }
}

int main(int argc, const char * argv[]) {
    try {
        EnsureEqual("C++ White", "C++ White");
        EnsureEqual("C++ White", "C++ Yellow");
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }
    return 0;
}
