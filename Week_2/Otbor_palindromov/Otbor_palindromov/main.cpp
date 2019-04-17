//
//  main.cpp
//  Otbor_palindromov
//
//  Created by Emin Tagiev on 27.09.17.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool IsPalindrom(string w){ //Checking whether the word is palindrom
    bool check = true;
    for (int i = 0; i < w.size()/2; i++) {
        if(w[i] != w[w.size() - 1 -i]){
            check = false;
            break;
        }
    }
    return check;
}

vector<string> PalindromFilter(vector<string> words, int minLength){
    vector<string> b;
    for (auto s : words) {
        // если требуеые условия выполняются, добавляем s к ответу
        if (s.size() >= minLength && IsPalindrom(s) == true) {
            b.push_back(s);
        }
    }
    return b;
}

int main(int argc, const char * argv[]) {
    vector<string> a = {"abacaba", "aba"};
    vector<string> d = {"weew", "bro", "code"};
    for(auto q: PalindromFilter(a, 2)){
        cout << q << endl;
    }
    for(auto q: PalindromFilter(d, 4)){
        cout << q << endl;
    }
    return 0;
}
