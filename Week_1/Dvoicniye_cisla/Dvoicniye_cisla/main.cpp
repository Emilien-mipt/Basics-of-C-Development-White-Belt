//
//  main.cpp
//  Dvoicniye_cisla
//
//  Created by Emin Tagiev on 26.09.17.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> a;
    int b;
    cin >> b;
    if(b == 1) cout << b << endl;
    else{
    do{
 //       cout << "ostatok: " << b%2 << endl;
        a.push_back(b%2);
        b/=2;
 //       cout << "b: " << b << endl;
        }
        while(b >= 2);
    a.push_back(b);
    for(int i = a.size()-1; i>=0; i--) cout << a[i];
    }
    return 0;
}
