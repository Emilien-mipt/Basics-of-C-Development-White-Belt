//
//  main.cpp
//  Time server
//
//  Created by Emin Tagiev on 08/01/2019.
//  Copyright © 2019 Emin Tagiev. All rights reserved.
//

#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
    /* Для тестирования повставляйте сюда код, реализующий различное поведение этой функии:
     * нормальный возврат строкового значения
     * выброс исключения system_error
     * выброс другого исключения с сообщением.
     */
}

class TimeServer {
public:
    string GetCurrentTime() {
        /* Реализуйте этот метод:
         * если AskTimeServer() вернула значение, запишите его в LastFetchedTime и верните
         * если AskTimeServer() бросила исключение system_error, верните текущее значение
         поля LastFetchedTime
         * если AskTimeServer() бросила другое исключение, пробросьте его дальше.
         */
    }
    
private:
    string LastFetchedTime = "00:00:00";
};

int main() {
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
