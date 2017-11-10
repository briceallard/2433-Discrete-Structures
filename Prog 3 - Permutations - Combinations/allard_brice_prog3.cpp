#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

double factRec(double n) {
    if(n > 1)
        return n * factRec(n -1);
    else
        return 1;
}

double factIter(double n) {
    double fact = 1;

    for (int i = 1; i <= n; i++)
        fact = fact * i;

    return fact;
}

int main() {
    ifstream infile;
    ofstream outfile;
    infile.open("combo.dat");
    outfile.open("allard_brice_prog3.txt");

    outfile << "Brice Allard\n\n";
    cout << "Brice Allard\n\n";
    cout << setprecision(60);
    outfile << setprecision(60);

    char porc;
    double n;
    double r;
    double ans;

    infile >> porc >> n >> r;

    while(!infile.eof()) {
        if(porc == 'P' || porc == 'p') {
            ans = factRec(n) / factIter(n-r);

            cout << "P(" << n << ',' << r << ") = " << ans << endl;
            outfile << "P(" << n << ',' << r << ") = " << ans << endl;            
        }
        else if(porc == 'C' || porc == 'c') {
            ans = factRec(n) / (factIter(n-r) * factIter(r));

            cout << "C(" << n << ',' << r << ") = " << ans << endl;
            outfile << "C(" << n << ',' << r << ") = " << ans << endl;
            
        }

        infile >> porc >> n >> r;
    }
}
