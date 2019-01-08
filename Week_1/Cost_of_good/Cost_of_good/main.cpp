//
//  main.cpp
//  Cost_of_good
//
//  Created by Emin Tagiev on 26.09.17.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    float N, A, B, X, Y, C = 0.0;
    cin >> N >> A >> B >> X >> Y;
    if(N <= A) cout << N << endl;
    else{
        if(N > A && N < B) {
            C = N - X*N/100;
            cout << C << endl;
        }
        if(N > B) {
            C = N - Y*N/100;
            cout << C << endl;
        }
    }
    
    return 0;
}
