//
//  main.cpp
//  Anagrammi
//
//  Created by Emin Tagiev on 05.12.2017.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;
map<char, int> BuildCharCounters(const string& s){
    map<char, int> m;
    for(auto item: s) ++m[item];
    return m;
}

void PrintMap(const map<char, int>& p){
    for(const auto& i: p) cout << i.first << ": " << i.second << endl;
    cout << "end of the word" <<  endl;
}

int main(int argc, const char * argv[]) {
    int N;
    map<char, int> m_1, m_2;
    string word_1, word_2;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> word_1 >> word_2;
        m_1 = BuildCharCounters(word_1);
        //PrintMap(m_1);
        m_2 = BuildCharCounters(word_2);
        //PrintMap(m_2);
        if(m_1 == m_2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
