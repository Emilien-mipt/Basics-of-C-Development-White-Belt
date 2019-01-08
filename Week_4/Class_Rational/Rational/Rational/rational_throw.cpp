#include <iostream>
#include <exception>
using namespace std;

class Rational {
public:
    Rational() {
        // Реализуйте конструктор по умолчанию
        P = 0;
        Q = 1;
    }

    Rational(int numerator, int denominator) {
        // Реализуйте конструктор
        P = numerator/(nod(numerator, denominator));
        Q = denominator/(nod(numerator, denominator));
        signs(P, Q);
        if(Q == 0){
            throw invalid_argument("invalid_argument");
        }
    }

    int Numerator() const { //Числитель
        // Реализуйте этот метод
        return P;
    }

    int Denominator() const { //Знаменатель
        // Реализуйте этот метод
        return Q;
    }

private:
    void signs(int& a, int& b){
        if((a>0 && b<0) || (a<0 && b<0)){
            a=-a;
            b=-b;
        }
    }
    int nod(int a, int b) {
        return b == 0 ? a : nod(b, a % b);
    }
    // Добавьте поля
    int P;  //P - целое число (числитель)
    int Q; //Q - натуральное число (знаменатель)
};

// Вставьте сюда реализацию operator / для класса Rational
Rational operator/(const Rational& r_1, const Rational& r_2){
    int Numerator=0;
    int Denominator=0;
    if(r_2.Numerator()==0){
        throw domain_error("domain_error");
    }
    Denominator = r_1.Denominator()*r_2.Numerator();
    Numerator = r_1.Numerator()*r_2.Denominator();

    return Rational(Numerator, Denominator);
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    }
    catch (invalid_argument&) {
    }
 
    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    }
    catch (domain_error&) {
    }
 
    cout << "OK" << endl;
    return 0;
}
