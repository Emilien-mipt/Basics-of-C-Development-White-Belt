//
//  main.cpp
//  Razvorot_2
//
//  Created by Emin Tagiev on 28.09.17.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b){
    int tmp = 0;
    tmp = a;
    a = b;
    b = tmp;
}
vector<int> Reversed(const vector<int>& v){
    vector<int> c = v;
    for(int i=0; i<c.size()/2; i++) swap(c[i], c[c.size()-1-i]);
    return c;
}

/*int main(int argc, const char * argv[]) {
 vector<int> numbers = {1, 5, 3, 4, 2};
 Reverse(numbers);
 for(auto s : Reverse(numbers)) cout << s << " ";
 return 0;
 }*/
