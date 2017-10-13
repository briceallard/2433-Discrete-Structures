#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int recurrenceR(int k, int m, int a_, int n) {
	int total = 0;
	return total;
}

int recurrenceNR(int k, int m, int a_, int n) {
	int total = 0;
	return total;
}

int main() {
	ifstream infile;
	infile.open("recur.dat");
	ofstream outfile;
	outfile.open("allard_brice_recur.out");

	int k, m, a_, n;
	int count = 1;
	infile >> k >> m >> a_ >> n;

	while (!infile.eof()) {
		cout << "Equation #" << count << "\n\n";
		cout << "The " << n << " term found using the recursive solution is: "
			<< recurrenceR(k, m, a_, n) << '\n';
		cout << "The " << n << " term found using the recursive solution is: "
			<< recurrenceNR(k, m, a_, n) << "\n\n";

		infile >> k >> m >> a_ >> n;
		count++;
	}

	system("pause");
	return 0;
}
