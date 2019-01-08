//
//  main.cpp
//  Stroka
//
//  Created by Emin Tagiev on 19.09.2018.
//  Copyright © 2018 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class ReversibleString{
    
    public:
    
    ReversibleString(){};
    
    ReversibleString(const string& word){
        line = word;
    }
    
    void Reverse(){
        for(int i=0; i<line.size()/2; i++) swap(line[i], line[line.size()-1-i]);
        //Можно еще reverse(begin(line), end(line));
    }
    
    string ToString() const{
        return line;
    }
    
    private:
    
    void swap(char& a, char& b){
        int tmp = 0;
        tmp = a;
        a = b;
        b = tmp;
    }

    string line;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;
    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;
    
    ReversibleString empty;
    //cout << '"' << empty.ToString() << '"' << endl;
    return 0;
}
