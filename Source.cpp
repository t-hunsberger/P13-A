#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>

using namespace std;

void pressEnterToContinue() {
	char c;
	cout << "Press Enter to continue...";
	cin.ignore(1024, '\n');
	do { cin.get(c); } while (c != '\n' && c != EOF);
}

int main() {
	string filename; 
	cout << "Enter filename: ";
	cin >> filename;

	ifstream file(filename);
	if (!file.is_open()) {
		cout << "Error opening file!" << endl;
		return 1;
	}

	map<char, int> letterCount;
	for (char letter = 'A'; letter <= 'Z'; ++letter) {
		letterCount[letter] = 0;
	}
	char c;
	int totalCount = 0;

	while (file >> noskipws >> c) {
		if (isalpha(c)) {
			c = toupper(c);
			letterCount[c]++;
			totalCount++;
		}
	}

	file.close();

	cout << "Total number of letters: " << totalCount << endl;
	cout << "Frequency:" << endl;

	cout << fixed << setprecision(3);
	for (const auto& pair : letterCount) {
		char letter = pair.first;
		int count = pair.second;
		double frequency = (static_cast<double>(count) / totalCount) * 100.0;
		cout << "'" << letter << "': " << frequency << endl;
	}

	pressEnterToContinue();
	return 0;
}