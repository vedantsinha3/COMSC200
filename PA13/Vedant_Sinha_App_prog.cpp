#include <iostream>
#include <string>
#include "Vedant_Sinha_Array.h"
using namespace std;

int main() {
   Array<int> intArr(5);
   Array<string> strArr(5);

   cout << "Enter 5 integers:\n";
   for (int i = 0; i < 5; ++i)
      cin >> intArr[i];

   cout << "Enter 5 strings:\n";
   for (int i = 0; i < 5; ++i)
      cin >> strArr[i];

   cout << "\nInteger Array:\n" << intArr;
   cout << "\nString Array:\n" << strArr;

   return 0;
}
