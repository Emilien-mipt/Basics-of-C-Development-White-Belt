//
//  main.cpp
//  Even_numbers
//
//  Created by Emin Tagiev on 26.09.17.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int A, B;
    cin >> A >> B;
    for(int i=A; i<=B; i++){
        if (i%2==0) {
            cout << i << '\t';
        }
    }
    return 0;
}
