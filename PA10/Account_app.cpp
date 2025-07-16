#include <iostream>
#include <iomanip>
#include "Vedant_Sinha_Account.h"
#include "Vedant_Sinha_SavingsAccount.h"
#include "Vedant_Sinha_CheckingAccount.h"
using namespace std;

int main()
{
   Account account1( 125.0 ); // create Account object
   SavingsAccount account2( 200.0, .06 ); // create SavingsAccount object
   CheckingAccount account3( 75.0, 0.5 ); // create CheckingAccount object

   cout << fixed << setprecision( 2 );

   // display initial balance of each object
   cout << "account1 balance: $" << account1.getBalance() << endl;
   cout << "account2 balance: $" << account2.getBalance() << endl;
   cout << "account3 balance: $" << account3.getBalance() << endl;

   cout << "\nAttempting to debit $100.00 from account1." << endl;
   account1.debit( 100.0 ); // try to debit $100.00 from account1
   cout << "\nAttempting to debit $250.00 from account2." << endl;
   account2.debit( 250.0 ); // try to debit $250.00 from account2
   cout << "\nAttempting to debit $25.00 from account3." << endl;
   account3.debit( 25.0 ); // try to debit $25.00 from account3

   // display balances
   cout << "\naccount1 balance: $" << account1.getBalance() << endl;
   cout << "account2 balance: $" << account2.getBalance() << endl;
   cout << "account3 balance: $" << account3.getBalance() << endl;

   cout << "\nCrediting $50.00 to account1." << endl;
   account1.credit( 50.0 ); // credit $50.00 to account1
   cout << "\nCrediting $75.00 to account2." << endl;
   account2.credit( 75.0 ); // credit $75.00 to account2
   cout << "\nCrediting $100.00 to account3." << endl;
   account3.credit( 100.0 ); // credit $100.00 to account3

   // display balances
   cout << "\naccount1 balance: $" << account1.getBalance() << endl;
   cout << "account2 balance: $" << account2.getBalance() << endl;
   cout << "account3 balance: $" << account3.getBalance() << endl;

   // add interest to SavingsAccount object account2
   double interestEarned = account2.calculateInterest();
   cout << "\nAdding $" << interestEarned << " interest to account2." 
      << endl;
   account2.credit( interestEarned );

   cout << "\nNew account2 balance: $" << account2.getBalance() << endl;

   system("PAUSE");
   return 0;
   
}
