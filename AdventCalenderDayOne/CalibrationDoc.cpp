// Arica N. Bryant
// Advent Calendar 2023: Day One
// 12/15/2023

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	// Declarations
	ifstream docfile;
	string currLine;
	int currNum = 0;
	string firstNum;
	string secondNum;
	int total = 0;

	// Opens the calibration document
	docfile.open("calibration_document.txt");

	// Reads through the file
	if (docfile.is_open()) {
		while (docfile) {
			getline(docfile, currLine);
			int count = 0;
			for (int i = 0; i < currLine.size(); i++) {
				if (isdigit(currLine[i])) {
					if (count == 0) {
						firstNum = currLine[i]; // Convert char to string
						count += 1;
					}
					else if (count >= 1) {
						secondNum = currLine[i];
						count += 1;
					}
				}
			}

			if (count == 1) { // If there is only one number on the line
				// Concatenate strings
				string temp = firstNum + firstNum;

				// Convert back to integer
				currNum = stoi(temp);
			}
			else if (count >= 1) { // if there is 2 numbers on the line
				// Concatenate strings
				string temp = firstNum + secondNum;

				// Convert back to integer
				currNum = stoi(temp);
			}
			total += currNum;
		}
		total -= currNum; // Removes extra calculation at end of file
	}
	cout << "The sum of all the calibration values is: " << total << endl;
}