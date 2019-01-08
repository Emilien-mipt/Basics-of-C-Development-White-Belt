//
//  main.cpp
//  Test
//
//  Created by Emin Tagiev on 21.09.2018.
//  Copyright © 2018 Emin Tagiev. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int value = 33;
    char* pointer = reinterpret_cast<char*>(&value);
    *pointer = 66;
    cout << "value: " << value << "\n";
    return 0;
}
