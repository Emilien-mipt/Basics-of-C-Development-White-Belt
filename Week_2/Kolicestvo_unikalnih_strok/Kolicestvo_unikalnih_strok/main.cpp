//
//  main.cpp
//  Kolicestvo_unikalnih_strok
//
//  Created by Emin Tagiev on 14.12.2017.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int N = 0;
    cin >> N;
    set<string> words;
    for(int j = 0; j < N; j++){
        string word;
        cin >> word;
        words.insert(word);
    }
    cout << words.size() << endl;
    return 0;
}
