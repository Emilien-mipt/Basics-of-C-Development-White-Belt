//
//  main.cpp
//  Sortirovka_po_modulu
//
//  Created by Emin Tagiev on 12.10.17.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool comp(int A, int B){
    if(abs(A) < abs(B)) return true;
    else return false;
}

void Print(vector<int>& A){
    for(auto c : A) cout << c << ' ';
}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int& n : A) cin >> n;
    sort(begin(A), end(A), comp);
    Print(A);
    return 0;
}
