// Vedant_Sinha_SavingsAccount.cpp
#include "Vedant_Sinha_SavingsAccount.h"

// Constructor implementation for SavingsAccount
// It calls the base-class (Account) constructor to initialize the balance. [cite: 534]
SavingsAccount::SavingsAccount(double initialBalance, double rate)
    : Account(initialBalance), interestRate(rate) {
    // The body of the constructor is empty as initialization is done in the initializer list.
}

// calculateInterest function implementation
double SavingsAccount::calculateInterest() const {
    // Comment 8: Calculate interest by multiplying the balance by the interest rate. [cite: 536]
    return getBalance() * interestRate;
}