//
//  main.cpp
//  NOD
//
//  Created by Emin Tagiev on 26.09.17.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
//#include <stdlib.h>
using namespace std;
    int nod(int a, int b) {
        return b == 0 ? a : nod(b, a % b);
    }
    int main(){
        int a, b;
        cin >> a >> b;
        cout << nod(a, b) << endl;
        return 0;
    }

