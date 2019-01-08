//
//  main.cpp
//  Razvorot_posledovatelnosti
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
void Reverse(vector<int>& v){
    for(int i=0; i<v.size()/2; i++) swap(v[i], v[v.size()-1-i]);
}

/*int main(int argc, const char * argv[]) {
    vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    for(auto s : numbers) cout << s << " ";
    return 0;
}*/
