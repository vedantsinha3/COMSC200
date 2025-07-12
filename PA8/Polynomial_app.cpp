#include <iostream>
#include "Vedant_Sinha_Polynomial.h"
#include <limits> // Make sure to add this

using namespace std;

int main()
{
   Polynomial a, b, c, t;

   a.enterTerms();
   b.enterTerms();
   t = a;   // save the value of a
   cout << "\nFirst polynomial is:\n";
   a.printPolynomial();
   cout << "\nSecond polynomial is:\n";
   b.printPolynomial();
   cout << "\nAdding the polynomials yields:\n";
   c = a + b;
   c.printPolynomial();
   cout << "\n+= the polynomials yields:\n";
   a += b;
   a.printPolynomial();
   cout << "\nSubtracting the polynomials yields:\n";
   a = t;  // reset a to original value
   c = a - b;
   c.printPolynomial();
   cout << "\n-= the polynomials yields:\n";
   a -= b;
   a.printPolynomial();
   cout << endl;

   // --- REPLACEMENT CODE ---
   cout << "\nPress Enter to continue...";
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   cin.get();
    
   return 0;
}