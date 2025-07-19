// Vedant_Sinha_CheckingAccount.h
#ifndef VEDANT_SINHA_CHECKINGACCOUNT_H
#define VEDANT_SINHA_CHECKINGACCOUNT_H

#include "Vedant_Sinha_Account.h" // Include base class definition

// Define CheckingAccount as a derived class of Account. [cite: 524]
class CheckingAccount : public Account {
public:
    // Constructor for CheckingAccount, taking initial balance and a transaction fee. [cite: 539]
    CheckingAccount(double initialBalance, double fee);

    // Comment 9: Redefine the credit and debit functions to include a transaction fee. [cite: 540]
    void credit(double amount);
    bool debit(double amount);

private:
    // Data member for the fee charged per transaction. [cite: 538]
    double transactionFee;
};

#endif // VEDANT_SINHA_CHECKINGACCOUNT_H