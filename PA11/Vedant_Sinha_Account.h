// Vedant_Sinha_Account.h
#ifndef VEDANT_SINHA_ACCOUNT_H
#define VEDANT_SINHA_ACCOUNT_H

class Account {
public:
    // Comment 1: The constructor initializes an Account object.
    // It takes an initial balance and ensures it is not negative.
    Account(double initialBalance);

    // Comment 2: The credit function adds a specified amount
    // to the account's current balance.
    void credit(double amount);

    // Comment 3: The debit function attempts to withdraw a specified amount.
    // It returns a boolean value: true if the withdrawal is successful,
    // and false if the debit amount exceeds the balance.
    bool debit(double amount);

    // Comment 4: The getBalance function is an accessor (getter)
    // that returns the current account balance.
    double getBalance() const;

private:
    // This data member stores the monetary balance for the account.
    double accountBalance;
};

#endif // VEDANT_SINHA_ACCOUNT_H