#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	string a, b, c;
	cin >> a >> b >> c;
	string min = a;
	if(min > b) min = b;
	if(min > c) min = c;
	cout << min << endl;
	return 0;
}