#ifndef VEDANT_SINHA_POLYNOMIAL_H
#define VEDANT_SINHA_POLYNOMIAL_H

#include <iostream>
#include <vector>

// Helper structure to define a single term (e.g., 5x^2)
struct Term {
    int coefficient;
    int exponent;
};

class Polynomial {
public:
    // Default constructor to create an empty polynomial
    Polynomial();

    // Member function for the user to input terms
    void enterTerms();

    // Member function to print the polynomial to the console
    void printPolynomial() const;

    // Overloaded assignment operator (=)
    Polynomial& operator=(const Polynomial& other);

    // Overloaded addition operator (+)
    Polynomial operator+(const Polynomial& other) const;

    // Overloaded subtraction operator (-)
    Polynomial operator-(const Polynomial& other) const;

    // Overloaded addition assignment operator (+=)
    Polynomial& operator+=(const Polynomial& other);

    // Overloaded subtraction assignment operator (-=)
    Polynomial& operator-=(const Polynomial& other);

private:
    // Internal storage for all the terms of the polynomial
    std::vector<Term> terms;

    // Private helper function to combine like terms and sort
    void simplify();
};

#endif // VEDANT_SINHA_POLYNOMIAL_H