#include <iostream>
#include <fstream>
#include <string>
using namespace::std;

int fileRead() {
	ifstream sampleFile; //Text that comes after ifstream is related to everything for that file for that function.
	//For instance, if you want to load text from the foyer description, you could describe it as "foyerFile"

	sampleFile.open("test.txt", ios::out);//This opens the file, just replace test.txt with the file name
		 if (sampleFile.is_open()) //Checks if file is open
		{
			string tp;
			while (getline(sampleFile, tp)) { //Takes text from a file and turns it into a string
				cout << tp << endl; //Prints the string it made
			}
			sampleFile.close(); //Closes file
		}
 
		 system("pause");
	return 0;
}
