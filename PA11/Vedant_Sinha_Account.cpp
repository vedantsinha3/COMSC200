// Vedant_Sinha_Account.cpp
#include <iostream>
#include "Vedant_Sinha_Account.h"

// Constructor implementation
Account::Account(double initialBalance) {
    // Comment 5: Validate the initial balance. 
    // If the provided balance is less than 0.0, set the balance to 0.0
    // and inform the user of the invalid input. 
    if (initialBalance >= 0.0) {
        accountBalance = initialBalance;
    } else {
        accountBalance = 0.0;
        std::cout << "Error: Initial balance was invalid. Setting balance to 0.0." << std::endl;
    }
}

// credit function implementation
void Account::credit(double amount) {
    accountBalance += amount; // Add the amount to the balance 
}

// debit function implementation
bool Account::debit(double amount) {
    // Comment 6: Check if the debit amount is greater than the balance. 
    if (amount > accountBalance) {
        // If so, print an error and do not change the balance. 
        std::cout << "Debit amount exceeded account balance." << std::endl;
        return false;
    } else {
        // Otherwise, subtract the amount and return true.
        accountBalance -= amount;
        return true;
    }
}

// getBalance function implementation
double Account::getBalance() const {
    return accountBalance; // Return the current balance 
}