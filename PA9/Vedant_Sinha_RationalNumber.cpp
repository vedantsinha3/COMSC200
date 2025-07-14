#include "Vedant_Sinha_RationalNumber.h" 
#include <iostream>
#include <cmath> 

// A helper function to compute the Greatest Common Divisor (GCD) using the Euclidean algorithm.
// This is used to simplify fractions.
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Comment 8: This is the implementation of the RationalNumber constructor.
// It sets the initial numerator and denominator, and then immediately calls the reduce()
// function to correctly format and simplify the new RationalNumber object.
RationalNumber::RationalNumber(int num, int den) : numerator(num), denominator(den) {
    reduce();
}

// Comment 9: This is the implementation of the private reduce() helper function.
// It standardizes the fraction by handling three key rules from the requirements:
// 1. It prevents the denominator from being zero (defaults it to 1).
// 2. It ensures the denominator is never negative (moves the sign to the numerator).
// 3. It simplifies the fraction by dividing by the greatest common divisor.
void RationalNumber::reduce() {
    // a. Prevent a 0 denominator
    if (denominator == 0) {
        std::cerr << "Error: Denominator cannot be zero. Setting denominator to 1." << std::endl;
        denominator = 1;
    }

    // a. Avoid negative denominators by moving the sign to the numerator
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    // Standardize 0 to be 0/1
    if (numerator == 0) {
        denominator = 1;
        return;
    }

    // a. Reduce the fraction to its simplest form
    int common_divisor = gcd(std::abs(numerator), denominator);
    numerator /= common_divisor;
    denominator /= common_divisor;
}

// b. Implementation of the printRational member function
void RationalNumber::printRational() const {
    if (denominator == 1) {
        std::cout << numerator;
    } else {
        std::cout << numerator << "/" << denominator;
    }
}

// Getters
int RationalNumber::getNumerator() const { return numerator; }
int RationalNumber::getDenominator() const { return denominator; }

// Overloaded stream insertion operator for easy printing with std::cout
std::ostream& operator<<(std::ostream& os, const RationalNumber& r) {
    if (r.getDenominator() == 1) {
        os << r.getNumerator();
    } else {
        os << r.getNumerator() << "/" << r.getDenominator();
    }
    return os;
}

// c. Overload the arithmetic operators
RationalNumber operator+(const RationalNumber& lhs, const RationalNumber& rhs) {
    int new_num = lhs.getNumerator() * rhs.getDenominator() + rhs.getNumerator() * lhs.getDenominator();
    int new_den = lhs.getDenominator() * rhs.getDenominator();
    return RationalNumber(new_num, new_den);
}

RationalNumber operator-(const RationalNumber& lhs, const RationalNumber& rhs) {
    int new_num = lhs.getNumerator() * rhs.getDenominator() - rhs.getNumerator() * lhs.getDenominator();
    int new_den = lhs.getDenominator() * rhs.getDenominator();
    return RationalNumber(new_num, new_den);
}

RationalNumber operator*(const RationalNumber& lhs, const RationalNumber& rhs) {
    int new_num = lhs.getNumerator() * rhs.getNumerator();
    int new_den = lhs.getDenominator() * rhs.getDenominator();
    return RationalNumber(new_num, new_den);
}

// Comment 10: This is the implementation for the division operator.
// Division is performed by multiplying by the reciprocal (e.g., (a/b) / (c/d) = (a/b) * (d/c)).
// It includes an important safety check to prevent division by a zero rational number.
RationalNumber operator/(const RationalNumber& lhs, const RationalNumber& rhs) {
    if (rhs.getNumerator() == 0) {
        std::cerr << "Error: Division by a zero rational number is not allowed." << std::endl;
        return RationalNumber(); // Return 0/1 as a default "error" value
    }
    int new_num = lhs.getNumerator() * rhs.getDenominator();
    int new_den = lhs.getDenominator() * rhs.getNumerator();
    return RationalNumber(new_num, new_den);
}

// d. Overload the relational and equality operators
bool operator<(const RationalNumber& lhs, const RationalNumber& rhs) {
    return (lhs.getNumerator() * rhs.getDenominator()) < (rhs.getNumerator() * lhs.getDenominator());
}

bool operator>(const RationalNumber& lhs, const RationalNumber& rhs) {
    return (rhs < lhs);
}

bool operator<=(const RationalNumber& lhs, const RationalNumber& rhs) {
    return !(lhs > rhs);
}

bool operator>=(const RationalNumber& lhs, const RationalNumber& rhs) {
    return !(lhs < rhs);
}

bool operator==(const RationalNumber& lhs, const RationalNumber& rhs) {
    // Since fractions are always stored in reduced form, we can just compare their parts.
    return (lhs.getNumerator() == rhs.getNumerator()) && (lhs.getDenominator() == rhs.getDenominator());
}

bool operator!=(const RationalNumber& lhs, const RationalNumber& rhs) {
    return !(lhs == rhs);
}