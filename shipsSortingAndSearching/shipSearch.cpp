#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

//This vector is made up of "ship" data types and is 
//needed to pass to the sorting functions.
vector<ship> ships;

//"ship" datatype that will be used to make 
//various ships from a file.
struct ship {
	string name;
	string type;
	string serviceNum;
	int size;
};

int main() {
	
	fstream readFile;
	readFile.open("ships.txt", ios::out);

	
}
