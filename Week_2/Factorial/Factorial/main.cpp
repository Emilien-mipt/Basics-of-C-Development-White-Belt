//
//  main.cpp
//  Week_2
//
//  Created by Emin Tagiev on 27.09.17.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
using namespace std;
int Factorial(int n){
    if(n<=0) return 1;
    else{
        int fact = 1;
        for(int i=n; i>0; i--) fact *= i;
        return fact;
    }
}
