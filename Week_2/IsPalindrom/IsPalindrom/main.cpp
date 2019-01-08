//
//  main.cpp
//  IsPalindrom
//
//  Created by Emin Tagiev on 27.09.17.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
bool IsPalindrom(string w){
    bool check = true;
    for (int i = 0; i < w.size()/2; i++) {
        if(w[i] != w[w.size() - 1 -i]){
        check = false;
        break;
        }
    }
    return check;
}

/*int main(){
//    string a;
//    bool check = false;
//    a = "gentleman";
  //  cout << a.size() << '\t' <<  a[4] << endl;
 /*   for (int i = 0; i < a.size(); i++) {
            if(a[i] == a[a.size() - 1 -i]) check = true;
            else check = false;
        }*/
//    cout << check << endl;
/*    cout << IsPalindrom("madam") << endl;
    cout << IsPalindrom("gentleman") << endl;
    cout << IsPalindrom("a") << endl;
    cout << IsPalindrom("54045") << endl;
    return 0;
}*/
