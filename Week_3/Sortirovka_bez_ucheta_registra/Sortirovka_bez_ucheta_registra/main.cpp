//
//  main.cpp
//  Sortirovka_bez_ucheta_registra
//
//  Created by Emin Tagiev on 12.10.17.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
//#include <stdio.h>
//#include <ctype.h>
#include <string>
//#include <locale>

using namespace std;

string lowered(const string& A){
    string L;
    for(auto c : A) {
        L += tolower(c);
    }
    return L;
}

bool comp(string a, string b){
    return lowered(a) < lowered(b);
}

void Print(const vector<string>& A){
    for(auto c : A) cout << c << ' ';
}

int main(int argc, const char * argv[]) {
    int N;
    string L = "aCb";
//    locale loc;
    cin >> N;
//    cout << tolower(L, loc);
    vector<string> A(N);
    for(auto& n : A) cin >> n;
//    cout << lowered(L);
    sort(begin(A), end(A), comp);
    Print(A);
    return 0;
}

