#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include "Polinom.h"


int main()
{
    Polinom A;
    cout << "(1) Testing `cout << A':  " << A << endl;

    cout << "(2) Testing `cin >> A':\n";
    cout << "Enter the Polinom (integer order then double  coefficients):\n\t ";
    cin >> A;
    cout << endl;
    cout << "(3) Second look at A:  " << A << endl;

    Polinom B(A);
    cout << "(4) Testing `Polinom B(A)':  " << B << endl;

    double clist[]={8, 4.5, 1};
    Polinom C(2, clist);
    cout << "(5) Testing `Polinom C(2, clist)':  " << C << endl;

    Polinom D=C;
    cout << "(6) Testing D = C):  " << D << endl;

    cout << "(7) Testing A == B :  " << (A==B ? "TRUE" : "FALSE") << endl;
    cout << "(8) Testing A == D :  " << (A==D ? "TRUE" : "FALSE")<< endl;

    return 0;
}