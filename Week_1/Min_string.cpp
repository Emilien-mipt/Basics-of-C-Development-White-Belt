#include <iostream>
#include <string>
using namespace std;
/*int main(int argc, char const *argv[])
{
	string a, b, c;
	cin >> a >> b >> c;
	if(a < b && a < c) cout << a << endl;
		else 
			if(b < a && b < c) cout << b << endl; 
				else cout << c << endl;
	return 0;
}*/
int main(){
    string a, b, c;
    cin >> a >> b >> c;
    if((a < b && b < c) || (a < c && c < b)) cout << a << '\t';
        else 
    if((b < a && a < c) || (b < c && c < a)) cout << b << '\t';
        else cout << c << '\t'; 
    return 0;
}