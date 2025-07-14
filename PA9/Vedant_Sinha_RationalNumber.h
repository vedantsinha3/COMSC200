#ifndef VEDANT_SINHA_RATIONAL_NUMBER_H
#define VEDANT_SINHA_RATIONAL_NUMBER_H

#include <iostream>

// Comment 1: This is the class specification file for the RationalNumber class.
// It declares the class interface, including its data members (numerator, denominator),
// constructors, and the various functions and operators that work with RationalNumber objects.

class RationalNumber {
public:
    // Comment 2: This is the constructor for the RationalNumber class.
    // It takes two integer arguments, one for the numerator and one for the denominator.
    // It also provides default values (0/1) if no arguments are given.
    RationalNumber(int num = 0, int den = 1);

    // Comment 3: This member function prints the rational number to the console.
    // It displays the fraction as "numerator/denominator" or as a whole number
    // if the denominator is 1. This fulfills the specific requirement for a print function.
    void printRational() const;

    // --- Public accessor functions (getters) ---
    // These functions allow code outside the class to safely access the private
    // numerator and denominator values.
    int getNumerator() const;
    int getDenominator() const;

private:
    int numerator;
    int denominator;

    // Comment 4: This is a private helper function used to simplify the fraction.
    // It's called by the constructor to ensure every RationalNumber is always
    // stored in its simplest form (e.g., 2/4 becomes 1/2) and that the
    // denominator is always positive.
    void reduce();
};

// Comment 5: These are the declarations for the overloaded arithmetic operators.
// They are implemented as non-member functions to allow for operations where
// a different type (like an integer) might appear on the left-hand side.
RationalNumber operator+(const RationalNumber& lhs, const RationalNumber& rhs);
RationalNumber operator-(const RationalNumber& lhs, const RationalNumber& rhs);
RationalNumber operator*(const RationalNumber& lhs, const RationalNumber& rhs);
RationalNumber operator/(const RationalNumber& lhs, const RationalNumber& rhs);

// Comment 6: These are the declarations for the overloaded relational and equality operators.
// They compare two RationalNumber objects and return a boolean (true or false).
// The comparison is done using cross-multiplication to avoid floating-point errors.
bool operator<(const RationalNumber& lhs, const RationalNumber& rhs);
bool operator>(const RationalNumber& lhs, const RationalNumber& rhs);
bool operator<=(const RationalNumber& lhs, const RationalNumber& rhs);
bool operator>=(const RationalNumber& lhs, const RationalNumber& rhs);
bool operator==(const RationalNumber& lhs, const RationalNumber& rhs);
bool operator!=(const RationalNumber& lhs, const RationalNumber& rhs);

// Comment 7: This is the overloaded stream insertion operator (<<).
// It's the standard C++ way to let objects be printed easily using std::cout.
// The provided application files will likely use this for printing.
std::ostream& operator<<(std::ostream& os, const RationalNumber& r);

#endif // RATIONAL_NUMBER_H