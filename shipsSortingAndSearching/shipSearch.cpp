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
void sortByType(ship[], int);
void displayAll(ship[], int);
void displaySingle(ship[], int);
int searchByNameOrType(ship[], int, string);
int menu();


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

	displayAll(ships, NUM_OF_SHIPS);
}

//Displays information for all ships. Pauses when it reaches
//the fifth element and continues after user input.
void displayAll(ship array[], int numOfShips) {
	cout << left << setw(20) << "Ship Name" << setw(20) << "Type" << setw(20) << "Service Number" << setw(20) << "Size" << endl;
	cout << string(70, '*') << endl;
	for (int x = 0; x < numOfShips; x++) {
		//waits for user input
		if (x == 5) {
			system("pause");
		}
		cout << left << setw(20) << array[x].name << setw(20) << array[x].type << setw(20) << array[x].serviceNum << setw(20) << array[x].size << endl;
	}
	cout << endl;
}

//Displays ship info for a single ship.
void displaySingle(ship array[], int elementToOutput) {
	cout << array[elementToOutput].name << "  " << array[elementToOutput].type << "  " << array[elementToOutput].serviceNum << "  " << array[elementToOutput].size;
}

//sorts ships by type, alphabetically using selection sort.
void sortByType(ship array[], int numOfShips) {
	int startScan, minIndex;
	ship minValue;
	for (startScan = 0; startScan < (numOfShips - 1); startScan++) {
		minIndex = startScan;
		minValue = array[startScan];
		for (int index = startScan + 1; index < numOfShips; index++) {
			if (array[index].type < minValue.type) {
				minValue = array[index];
				minIndex = index;
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}
}

int searchByNameOrType(ship ships[], int elements, string toFind) {
	int index = 0;
	int position = -1;
	bool found = false;

	while (index < elements && !found) {
		if (ships[index].name == toFind || ships[index].type == toFind) {
			found = true;
			position = index;
		}
		index++;
	}
	return position;
}

int menu() {
	int choice = 0;
	cout << "Choose one of the following(enter a number): " << endl;
	cout << string(30, '*') << endl;
	cout << "1. Display ships.\n"
		<< "2. Sort ships by type.\n"
		<< "3. Search ships by name or type.\n"
		<< "4. Quit program\n";
	cin >> choice;
	while (choice > 4 || choice < 1) {
		cout << "Invalid choice. Try again.\n";
		cin >> choice;
	}
	return choice;
}
