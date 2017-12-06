/*
Brice Allard
Program 4 - Adjacency Matrices
Dr. Wulthrich
12/15/2017

This program gathers matrices to represent a simple and undirected
graph from input and determines if they are VALID or NOT VALID.
If they are valid the given vertex is displayed with the associated
number of degrees it has as well as displays the total number of
edges the graph has.

**Note**
Requirements for valid simple, undirected graph are as follows:
1. Must be symmetric
2. Must only contain a 0 or a 1
3. Must contain all 0's on the diagonal
*/

#include <iostream>
#include <fstream>

using namespace std;

// Fills 2D array with vertices from the infile.
int **fillMatrix(int, ifstream&);

// Counts number of degree each vertex of the adjacency matrix has
void findDegree(int **, int, ifstream&, ofstream&);

// Counts number of edges the adjacency matrix has
void findEdges(int **, int, ifstream&, ofstream&);

// Re-allocates memory and deletes 2D matrix
void deleteMatrix(int **, int);

// Checks that the matrix is symmetric
bool isSymmetric(int **, int);

// Checks that the matrix contains all 0 or 1
bool isValNum(int **, int);

// Checks that the matrix contains all 0 on diagonal axis
bool isValDiag(int **, int);

// Performs all previously declared validity checks
bool isValid(int **, int);

// converts a passed in integer to alpha character
char intToAlpha(int);

int main() {
	// Initiate and open I/O
	ofstream outfile;
	ifstream infile;
	infile.open("adj.dat");
	outfile.open("allard_brice_adj.txt");

	outfile << "Brice Allard\n\n";
	cout << "Adjacency Matrices\nCoded By: Brice Allard\n\n";
	
	int loop, size;
	int scenario = 1;

	infile >> loop;		// Gather total amount of matrices

	// Run for all matrices found in input.
	while (loop != 0) {
		infile >> size;

		cout << "Matrix #" << scenario << endl;
		outfile << "Matrix #" << scenario << endl;

		// Initiates and fills 2D array with matrices
		int** matrix = fillMatrix(size, infile);
		
		// Perform validity check to ensure simple graph
		if (isValid(matrix, size)) {
			findDegree(matrix, size, infile, outfile);
			findEdges(matrix, size, infile, outfile);
		}
		else {
			cout << "INVALID\n\n";
			outfile << "INVALID\n\n";
		}

		// Re-allocate that memory
		deleteMatrix(matrix, size);

		++scenario;	// increment each scenario
		--loop;		// Detriment the counter
	}

	system("pause");
	return 0;
}

/*
	fillMatrix -
		Fills 2D array with vertices from the infile.
	@ param - size of the matrix to create, I/O files
	@ return - int ** of the 2D array 'matrix'
*/
int **fillMatrix(int size, ifstream& infile) {
	int vertice;
	
	// Create a 2D array of pointers to store matrix
	int** matrix = new int*[size];	// rows
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];	// cols
	}

	// Fill the 2D array with vertices
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			infile >> vertice;
			matrix[i][j] = vertice;
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	
	return matrix;
}

/*
	findDegree -
		Counts number of degree each vertex of the adjacency matrix has.
	@ param - matrix to count edges, size of the matrix, I/O files
	@ return - None
*/
void findDegree(int **matrix, int size, ifstream& infile, ofstream& outfile) {
	int degree;
	cout << "Degree of:\n";
	outfile << "Degree of:\n";

	for (int i = 0; i < size; i++) {
		degree = 0;
		char alpha = intToAlpha(i);
		for (int j = 0; j < size; j++) {
			if (matrix[i][j] == 1)
				degree++;
		}
		outfile << "Vertex " << alpha << ": " << degree << endl;
		cout << "Vertex " << alpha << ": " << degree << endl;
	}
}

/*
	findEdges -
		Counts number of edges the adjacency matrix has.
	@ param - matrix to count edges, size of the matrix, I/O files
	@ return - None
*/
void findEdges(int **matrix, int size, ifstream& infile, ofstream& outfile) {
	int edges = 0;
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (matrix[i][j] == 1 && matrix[j][i] == 1)
				edges++;
		}
	}
	outfile << "Number of Edges: " << edges/2 << endl << endl;
	cout << "Number of Edges: " << edges/2 << endl << endl;
}

/*
	deleteMatrix -
		Re-allocates memory and deletes 2D matrix used for
		matrix representation so it can be reused
	@ param - matrix to delete and size of the matrix
	@ return - none
*/
void deleteMatrix(int **matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			matrix[i][j] = NULL;
	}
	delete[] matrix;	// Delete 2D array
	matrix = NULL;

	cout << "Matrix Deleted and Memory Re-Allocated ... \n\n";
}

/*
	isSymmetric -
		Checks that the matrix is symmetric given the rules
		of a undirected simple graph
	@ param - matrix to verify and size of the matrix
	@ return - bool t/f if tests are passed/failed
*/
bool isSymmetric(int **matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (matrix[i][j] != matrix[j][i])
				return false;
		}
	}
	return true;
}

/*
	isValNum -
		Checks that the matrix contains all 0 or 1 given
		the rules of a undirected simple graph
	@ param - matrix to verify and size of the matrix
	@ return - bool t/f if tests are passed/failed
*/
bool isValNum(int **matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (matrix[i][j] > 1 || matrix[i][j] < 0)
				return false;
		}
	}
	return true;
}

/*
	isValDiag -
		Checks that the matrix contains all 0 on diagonal axis
	@ param - matrix to verify and size of the matrix
	@ return - bool t/f if tests are passed/failed
*/
bool isValDiag(int **matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (matrix[i][i] != 0)
				return false;
		}
	}
	return true;
}

/*
	isValid -
		Performs all validity checks of the passed in Matrix
		ensuring it is in fact a simple and undirected
	@ param - matrix to verify and size of the matrix
	@ return - bool t/f if tests are passed/failed
*/
bool isValid(int **matrix, int size) {
	if (!isSymmetric(matrix, size) ||
		!isValNum(matrix, size) ||
		!isValDiag(matrix, size))
		return false;
	return true;
}

/*
	intToAlpha - 
		converts a passed in integer to alpha character
	@ param - int that relates to alpha char in sequence
	@ return - char associated with int digit passed in
*/
char intToAlpha(int n) {
	static char const alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	return n >= 0 && n < sizeof(alpha) - 1
		? alpha[n] : '?';
}