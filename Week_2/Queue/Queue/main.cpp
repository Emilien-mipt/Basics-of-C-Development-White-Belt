//
//  main.cpp
//  Queue
//
//  Created by Emin Tagiev on 01.10.17.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<bool> queue;
    string command;
    int N = 0;
    int Q = 0;
    cin >> Q;
    for (int j = 0; j < Q; j++) {
        cin >> command;
        if(command == "WORRY_COUNT"){
            int n = 0;
            for(auto s : queue){
                if(s == true) n++;
            }
            cout << n << endl;
        }
        else{
        cin >> N;
        if(command == "COME" && N > 0){
            for(int p = 0; p < N; p++){
                queue.push_back(false);
            }
        }
        if(command == "COME" && N < 0) queue.resize(queue.size()+N);
        if(command == "WORRY") queue[N] = true;
        if(command == "QUIET") queue[N] = false;
        }
    }
    return 0;
}
