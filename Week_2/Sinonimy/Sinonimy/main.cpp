//
//  main.cpp
//  Sinonimy
//
//  Created by Emin Tagiev on 14.12.2017.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    map<string, set<string>> sinonimy;
    int Q = 0;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        string request;
        cin >> request;
        if(request == "ADD"){
            string word1, word2;
            cin >> word1 >> word2;
            sinonimy[word1].insert(word2);
            sinonimy[word2].insert(word1);
        }//ADD
        if(request == "COUNT"){
            string word;
            cin >> word;
           cout << sinonimy[word].size() << endl;
        }//COUNT
        if(request == "CHECK"){
            string word1, word2;
            cin >> word1 >> word2;
            if(sinonimy[word1].count(word2) != 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }//CHECK
    }
    return 0;
}
