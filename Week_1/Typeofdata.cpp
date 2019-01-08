#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
struct Worker
{
	string name;
	string surname;
	int age;
};
int main(int argc, char const *argv[])
{
	//vectors and operations with vectors
	vector<int> numbers = {1, 2, 3, 4, 5};
	cout << numbers.size() << '\n';
	vector<Worker> worker;
	worker.push_back({"Emin", "Tagiev", 24});
	worker.push_back({"Farhad", "Tagiev", 20});
	cout << worker[0].name << '\t' << worker[0].surname << '\t' << worker[0].age << '\n';
	//strings
	string hw = "Hello, world!";
	cout << hw << '\n';
	//maps
	map<string, int> map_1;
	map_1["one"] = 1;
	map_1["two"] = 2;
	cout << "two is "<< map_1["two"] << '\n';
	return 0;
}