// Vedant_Sinha_CheckingAccount.cpp
#include <iostream>
#include "Vedant_Sinha_CheckingAccount.h"

// Constructor implementation for CheckingAccount
// It calls the base-class constructor and initializes the transaction fee. 
CheckingAccount::CheckingAccount(double initialBalance, double fee)
    : Account(initialBalance), transactionFee(fee) {
    // Empty constructor body
}

// Redefined credit function implementation
void CheckingAccount::credit(double amount) {
    // First, call the base-class credit function to add the amount.
    Account::credit(amount);
    // Then, subtract the transaction fee. 
    Account::debit(transactionFee);
    std::cout << "$" << transactionFee << " transaction fee charged." << std::endl;
}

// Redefined debit function implementation
bool CheckingAccount::debit(double amount) {
    // Comment 10: Attempt to withdraw money by calling the base-class debit function. 
    bool success = Account::debit(amount);

    // If the withdrawal was successful, charge the transaction fee. 
    if (success) {
        Account::debit(transactionFee);
        std::cout << "$" << transactionFee << " transaction fee charged." << std::endl;
        return true;
    }
    return false;
}