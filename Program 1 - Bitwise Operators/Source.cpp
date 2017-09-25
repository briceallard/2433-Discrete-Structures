#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void processLine() {
	ifstream infile;
	infile.open("on_off.dat");
	ofstream outfile;
	outfile.open("allard_brice_bits.out");

	outfile << "Brice Allard" << endl << endl;

	int count = 0;
	string on_off;
	infile >> on_off;

	while (!infile.eof()) {
		unsigned int flag = 0;
		for (int i = 32768; i > 0; i/=2) {			
			if (on_off == "on") {
				flag = flag | i;
			}
			infile >> on_off;
		}
		count++;
		outfile << "ASSIGNMENT #" << count << " FLAG IS " << flag << endl;;
	}
}

int main() {
	processLine();

	return 0;
}