/*
Brice Allard
10/23/2017
Recurrence Relations - Program 2
	// Show understanding of concepts of solving recurrence
	// relations, and comparing recursive and non-recursive
	// solutions
*/

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Recurrence function
int recurrenceR(int k, int m, int a_, int n, int count) {
	int answer = a_;	// stores answer of each relation

	// Checks if we've reached the 'n'th relation
	if (count == n)
		return answer;	// if so, returns answer
	else {
		a_ = (k * a_) + m;	// if not, solves relation
	}

	count++;
	recurrenceR(k, m, a_, n, count);	// recurrence here
}

// Non-Recurrence function
int recurrenceNR(int k, int m, int a_, int n) {
	// implement array to store values from each relation
	int* arr = NULL;
	arr = new int[n];
	arr[0] = a_;

	for (int i = 1; i <= n; i++) {
		arr[i] = (k * arr[i - 1]) + m;	// solves relation
	}

	return arr[n];
}

int main() {
	// create infile/outfile
	ifstream infile;
	infile.open("recur.dat");
	ofstream outfile;
	outfile.open("allard_brice_recur.out");

	// set member variables
	int k, m, a_, n;
	int equation = 1;
	int count = 0;

	// read in from infile and store in variables
	infile >> k >> m >> a_ >> n;

	cout << "Brice Allard" << "\n\n";
	outfile << "Brice Allard" << "\n\n";

	// do till end of file
	while (!infile.eof()) {
		cout << "Equation #" << equation << "\n\n";
		outfile << "Equation #" << equation << "\n\n";
		cout << "The " << n << " term found using the recursive solution is: "
			<< recurrenceR(k, m, a_, n, count) << '\n';
		outfile << "The " << n << " term found using the recursive solution is: "
			<< recurrenceR(k, m, a_, n, count) << '\n';
		cout << "The " << n << " term found using the non-recursive solution is: "
			<< recurrenceNR(k, m, a_, n) << "\n\n";
		outfile << "The " << n << " term found using the non-recursive solution is: "
			<< recurrenceNR(k, m, a_, n) << "\n\n";

		infile >> k >> m >> a_ >> n;	// update variables
		equation++;
	}

	system("pause");
	return 0;
}
