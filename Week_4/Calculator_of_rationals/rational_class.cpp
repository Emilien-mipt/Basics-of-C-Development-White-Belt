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
            throw invalid_argument("Invalid argument");
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

// Вставьте сюда реализацию operator / и * для класса Rational
Rational operator/(const Rational& r_1, const Rational& r_2){
    int Numerator=0;
    int Denominator=0;
    if(r_2.Numerator()==0){
        throw domain_error("Division by zero");
    }
    Denominator = r_1.Denominator()*r_2.Numerator();
    Numerator = r_1.Numerator()*r_2.Denominator();

    return Rational(Numerator, Denominator);
}

Rational operator*(const Rational& r_1, const Rational& r_2){
    int Numerator=0;
    int Denominator=0;
    Denominator = r_1.Denominator()*r_2.Denominator();
    Numerator = r_1.Numerator()*r_2.Numerator();
    return Rational(Numerator, Denominator);
}

// Реализуйте для класса Rational операторы << и >>
ostream& operator << (ostream& stream, const Rational& r){
    stream << r.Numerator() << "/" << r.Denominator();
    return stream;
}

istream& operator >> (istream& stream, Rational& r){
    char delenie;
    int a, b;
    stream >> a >> delenie >> b;
    if (stream && delenie == '/') {
        r = Rational(a, b);
    }
    return stream;
}

// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а
bool operator > (Rational a, Rational b) {
    return (a.Numerator() / (double)a.Denominator()) > double(b.Numerator() / (double)b.Denominator());
}
bool operator < (Rational a, Rational b) { //обязательно нужно это дело перегрузить, для использования в map и set
    return (a.Numerator() / (double)a.Denominator()) < (b.Numerator() / (double)b.Denominator());
}

