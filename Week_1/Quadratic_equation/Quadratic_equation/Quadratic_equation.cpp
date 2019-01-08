//
//  main.cpp
//  Quadratic_equation
//
//  Created by Emin Tagiev on 25.09.17.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    /* Test:
     1) 0 0 C
     2) 0 B X
     3) A X X
     где X - любое число, включая ноль, а A, B и C - числа, не равные нулю.
     
     */
    double A, B, C, D, X_1, X_2;
    cin >> A >> B >> C;
    D = B*B - 4*A*C;
   
    if(A==0) {
        if(B!=0){
            X_1 = -C/B;
            cout << X_1 << endl;
            }
    }
    else{
        if(D == 0){
            X_1 = (-B)/(2*A);
            cout << X_1 << endl;
        }
        if(D > 0 && B != 0){
            X_1 = (-B + sqrt(D))/(2*A);
            X_2 = (-B - sqrt(D))/(2*A);
            cout << X_1 << '\t' << X_2 << endl;
        }
        if(D > 0 && B == 0 && C < 0){
            X_1 = sqrt(-C/A);
            X_2 = -sqrt(-C/A);
            cout << X_1 << '\t' << X_2 << endl;
        }
    }
    return 0;
}
