// Vedant_Sinha_SavingsAccount.h
#ifndef VEDANT_SINHA_SAVINGSACCOUNT_H
#define VEDANT_SINHA_SAVINGSACCOUNT_H

#include "Vedant_Sinha_Account.h" // Include base class definition

// Comment 7: Define SavingsAccount as a derived class of Account. 
class SavingsAccount : public Account {
public:
    // Constructor for SavingsAccount, taking initial balance and interest rate. 
    SavingsAccount(double initialBalance, double rate);

    // Member function to calculate interest earned. 
    double calculateInterest() const;

private:
    // Data member to store the interest rate for the savings account. 
    double interestRate;
};

#endif // VEDANT_SINHA_SAVINGSACCOUNT_H