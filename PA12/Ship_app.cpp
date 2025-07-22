#include <iostream>
#include <string>
#include "Ship.h"
#include "CruiseShip.h"
#include "CargoShip.h"
using namespace std;


int main()
{
    // Create an array of Ship pointers, initialized with
    // the addresses of 3 dynamically allocated objects.
    Ship *ships[3] = { new Ship("Lolipop", "1960"),
                       new CruiseShip("Disney Magic", "1998", 2400),
                       new CargoShip("Black Pearl", "1800", 50000)
                     };

    // Call each object's print function using polymorphism.
    for (int index=0; index < 3; index++)
    {
        ships[index]->print();
        cout << "----------------------------\n";
        
        delete ships[index];     //release memory (avoid memory leak)
        ships[index] = nullptr;   //avoid dangling pointer
    }
    
           
    system("PAUSE");
    return 0;
}
