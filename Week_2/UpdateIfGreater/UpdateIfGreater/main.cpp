//
//  main.cpp
//  UpdateIfGreater
//
//  Created by Emin Tagiev on 28.09.17.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
using namespace std;
void UpdateIfGreater(int first, int& second){
    if(first>second) second = first;
}

int main(int argc, const char * argv[]) {
    int a = 5;
    int b = 4;
    UpdateIfGreater(a, b);
    cout << b << endl;
    return 0;
}
