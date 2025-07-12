#include "Vedant_Sinha_Polynomial.h"
#include <algorithm> // Required for std::sort

// Constructor
Polynomial::Polynomial() {
    // The vector is empty by default, so no code is needed.
}

// Allows the user to enter terms until they enter -1 for the coefficient.
void Polynomial::enterTerms() {
    int coeff = 0;
    int exp = 0;

    // Clear any existing terms before entering new ones
    this->terms.clear(); 

    std::cout << "Enter coefficients and exponents for your polynomial.\n";
    std::cout << "Enter -1 for the coefficient to stop.\n";

    while (true) {
        std::cout << "Enter coefficient: ";
        std::cin >> coeff;

        // Stop condition
        if (coeff == -1) {
            break;
        }

        std::cout << "Enter exponent: ";
        std::cin >> exp;

        // Add the term only if the coefficient is not zero
        if (coeff != 0) {
            this->terms.push_back({coeff, exp});
        }
    }
    // Simplify the polynomial after all terms are entered.
    simplify();
}

// Prints the polynomial in a readable format.
void Polynomial::printPolynomial() const {
    if (terms.empty()) {
        std::cout << "0";
        return;
    }

    for (size_t i = 0; i < terms.size(); ++i) {
        const Term& term = terms[i];

        // Handle signs (+/-)
        if (i > 0) {
            if (term.coefficient > 0) std::cout << " + ";
            else std::cout << " - ";
        } else if (term.coefficient < 0) {
            std::cout << "-";
        }

        int absCoeff = abs(term.coefficient);

        // Handle coefficient
        if (absCoeff != 1 || term.exponent == 0) {
            std::cout << absCoeff;
        }

        // Handle variable 'x' and exponent '^'
        if (term.exponent > 0) {
            std::cout << "x";
            if (term.exponent > 1) {
                std::cout << "^" << term.exponent;
            }
        }
    }
}

// Assigns one polynomial to another
Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this != &other) {
        this->terms = other.terms;
    }
    return *this;
}

// Adds two polynomials and returns the new result
Polynomial Polynomial::operator+(const Polynomial& other) const {
    Polynomial result = *this; // Make a copy of the first polynomial
    result += other;           // Use the += operator to add the second
    return result;
}

// Adds the right-side polynomial to the left-side one
Polynomial& Polynomial::operator+=(const Polynomial& other) {
    for (const auto& term : other.terms) {
        this->terms.push_back(term);
    }
    simplify();
    return *this;
}

// Subtracts two polynomials and returns the new result
Polynomial Polynomial::operator-(const Polynomial& other) const {
    Polynomial result = *this; // Make a copy
    result -= other;           // Use the -= operator
    return result;
}

// Subtracts the right-side polynomial from the left-side one
Polynomial& Polynomial::operator-=(const Polynomial& other) {
    for (const auto& term : other.terms) {
        // Add the term with its coefficient negated
        this->terms.push_back({-term.coefficient, term.exponent});
    }
    simplify();
    return *this;
}

// Helper function to combine like terms and sort them.
void Polynomial::simplify() {
    if (terms.empty()) return;

    // Sort terms by exponent in descending order (e.g., x^3, x^2, x)
    std::sort(terms.begin(), terms.end(), [](const Term& a, const Term& b) {
        return a.exponent > b.exponent;
    });

    std::vector<Term> simplified;
    if (!terms.empty()) {
        simplified.push_back(terms[0]);
        for (size_t i = 1; i < terms.size(); ++i) {
            // If exponents are the same, combine coefficients
            if (terms[i].exponent == simplified.back().exponent) {
                simplified.back().coefficient += terms[i].coefficient;
            } else {
                simplified.push_back(terms[i]);
            }
        }
    }
    
    // Final pass to remove any terms that cancelled out (coefficient is 0)
    std::vector<Term> final_terms;
    for(const auto& term : simplified) {
        if(term.coefficient != 0) {
            final_terms.push_back(term);
        }
    }
    
    // Replace the old terms with the new, simplified terms
    this->terms = final_terms;
}