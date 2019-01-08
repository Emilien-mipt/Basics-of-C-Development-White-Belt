//
//  main.cpp
//  Division
//
//  Created by Emin Tagiev on 25.09.17.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    float A, B;
    int C;
    cin >> A >> B;
    if (B == 0) cout << "Impossible" << endl;
    else {
        C = static_cast<int>(A/B);
        cout << C << endl;
    }
    return 0;
}
