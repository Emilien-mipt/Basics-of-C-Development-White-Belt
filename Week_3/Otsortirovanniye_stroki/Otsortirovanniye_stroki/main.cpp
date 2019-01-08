//
//  main.cpp
//  Otsortirovanniye_stroki
//
//  Created by Emin Tagiev on 06.11.17.
//  Copyright © 2017 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        list_of_strings.push_back(s);       // добавить строку s в набор
    }
    vector<string> GetSortedStrings() {
        sort(begin(list_of_strings), end(list_of_strings));
        // получить набор из всех добавленных строк в отсортированном порядке
        return list_of_strings;
    }
private:
    vector<string> list_of_strings;
    // приватные поля
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    SortedStrings strings;
    
    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);
    
    strings.AddString("second");
    PrintSortedStrings(strings);
    
    return 0;
}
