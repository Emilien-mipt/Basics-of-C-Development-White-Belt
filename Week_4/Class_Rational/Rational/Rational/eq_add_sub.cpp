#include <iostream>
using namespace std;

class Rational {
    // Вставьте сюда реализацию класса Rational из первой части
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
    signed Q; //Q - натуральное число (знаменатель)
};

// Реализуйте для класса Rational операторы ==, + и -
bool operator==(const Rational& r_1, const Rational& r_2){
    if((r_1.Numerator() == r_2.Numerator()) && (r_1.Denominator() == r_2.Denominator())) return true;
    else return false;
}

Rational operator+(const Rational& r_1, const Rational& r_2){
    int Numerator=0;
    int Denominator=0;
    Denominator = r_1.Denominator()*r_2.Denominator();
    Numerator = r_1.Numerator()*r_2.Denominator() + r_2.Numerator()*r_1.Denominator();
    return Rational(Numerator, Denominator);
}

Rational operator-(const Rational& r_1, const Rational& r_2){
    int Numerator=0;
    int Denominator=0;
    Denominator = r_1.Denominator()*r_2.Denominator();
    Numerator = r_1.Numerator()*r_2.Denominator() - r_2.Numerator()*r_1.Denominator();
    return Rational(Numerator, Denominator);
}

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
