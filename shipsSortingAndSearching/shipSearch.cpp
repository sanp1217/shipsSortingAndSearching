#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

//"ship" datatype that will be used to make 
//various ships from a file.
struct ship {
	string name;
	string type;
	string serviceNum;
	int size;
};

//This vector is made up of "ship" data types 
//that will be added from a file and is 
// needed to pass to the sorting functions.
vector<ship> ships;

int main() {
	//First, all of the data for each ship will
	//be stored into a file and read from it to
	//be stored into a vector.
	fstream readFile;
	readFile.open("ships.txt", ios::in);

	if (readFile.is_open()) {
		//This while loop reads from the file until
		//the end of the file.
		while(readFile.good()) {
			//Local variables to be used to get the info 
			//of the various ships from the file one ship 
			//at a time.
			string shipName;
			string shipType;
			string shipServiceNum;
			string shipSize;
			//shipSize is a string for now because getline
			//only accepts a string as a parameter.

			getline(readFile, shipName);
			getline(readFile, shipType);
			getline(readFile, shipServiceNum);
			getline(readFile, shipSize);

			//Storing values from the file onto a
			//struct.
			ship ship;
			ship.name = shipName;
			ship.type = shipType;
			ship.serviceNum = shipServiceNum;
			ship.size = stoi(shipSize);
			//stoi() turns the string shipSize into an int.

			//struct is added to the vector of ships.
			ships.push_back(ship);
			
		}
		readFile.close();
	}
}
