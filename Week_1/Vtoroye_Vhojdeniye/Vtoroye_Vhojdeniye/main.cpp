//
//  main.cpp
//  Vtoroye_Vhojdeniye
//
//  Created by Emin Tagiev on 26.09.17.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    string a;
    cin >> a;
    int j = 0; //to count the number of "f"
    cout << a.size() << endl;
    for (int i=0; i<a.size(); i++) {
 //       cout << "i counter = " << i << endl;
        if (a[i] == 'f') {
            j++;
 //           cout << "j counter = " << j << endl;
            if (j == 2) {
                cout << i << endl;
                break;
            }
        }
    }
    if (j == 0) cout << "-2" << endl;
    if (j == 1) cout << "-1" << endl;
    return 0;
}
