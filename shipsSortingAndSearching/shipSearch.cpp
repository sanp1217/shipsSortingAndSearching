#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//"ship" datatype that will be used to make various ships 
//from a file.
struct ship {
	string name;
	string type;
	string serviceNum;
	string size;
};

//const for number of ships in file.
const int NUM_OF_SHIPS = 10;
//array of ships
ship ships[NUM_OF_SHIPS];

//function prototypes
void showShips(ship[], int);


int main() {
	//all data from each ship will be read from a file.
	fstream readFile;
	readFile.open("ships.txt", ios::in);

	if (readFile.is_open()) {
		//This for loop reads from the file until
		//the end of the file.
		for (int i = 0; i < NUM_OF_SHIPS; i++) {
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

			ships[i].name = shipName;
			ships[i].type = shipType;
			ships[i].serviceNum = shipServiceNum;
			ships[i].size = shipSize;

		}
		readFile.close();
	}
}


void showShips(ship array[], int num) {
	cout << left << setw(20) << "Ship Name" << setw(20) << "Type" << setw(20) << "Service Number" << setw(20) << "Size" << endl;
	cout << string(70, '*') << endl;
	for (int x = 0; x < num; x++) {
		cout << left << setfill(' ')
		<< setw(20) << array[x].name << setw(20) << array[x].type << setw(20) << array[x].serviceNum << setw(20) << array[x].size << endl;
	}
	cout << endl;
}

