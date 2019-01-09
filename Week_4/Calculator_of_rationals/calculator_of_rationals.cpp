#include <iostream>
#include <exception>
#include "rational_class.cpp"
using namespace std;

int main(int argc, char const *argv[])
{
	Rational R1, R2, R_result;
	char operation;
	//Ввод
try{
	cin >> R1;
	cin >> operation;
	cin >> R2;
		
	cout << R1.Numerator() << "/" << R1.Denominator() << operation << R2.Numerator() << "/" << R2.Denominator() << endl;
	
	try{
		if(operation == '+'){
			R_result = R1 + R2;
		}
		else if(operation == '-'){
			R_result = R1 - R2;
		}
		else if(operation == '*'){
			R_result = R1*R2;
		}
		else{
			R_result = R1/R2;
    	}
    	cout << R_result << endl;
	}
	catch(domain_error& err2) {
		cout << err2.what() << endl;
	}
}
catch(invalid_argument& err1){
	cout << err1.what() << endl;
}

	return 0;

}