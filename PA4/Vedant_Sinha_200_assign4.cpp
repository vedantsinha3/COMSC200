#include <iostream>
#include <string>
#include "Vedant_Sinha_HeartRates.h"

// Function to get user input and create a HeartRates object
void getUserInfo(std::string& first, std::string& last, int& month, int& day, int& year) {
    std::cout << "Please enter the following information:" << std::endl;
    std::cout << "First Name: ";
    std::getline(std::cin, first);
    std::cout << "Last Name: ";
    std::getline(std::cin, last);
    std::cout << "Birth Month (1-12): ";
    std::cin >> month;
    std::cout << "Birth Day (1-31): ";
    std::cin >> day;
    std::cout << "Birth Year: ";
    std::cin >> year;
}

// Function to display the person's information
void displayInfo(const HeartRates& person) {
    std::cout << "\n--- Patient Information ---" << std::endl;
    std::cout << "Name: " << person.getFirstName() << " " << person.getLastName() << std::endl;
    std::cout << "Date of Birth: " << person.getBirthMonth() << "/"
              << person.getBirthDay() << "/" << person.getBirthYear() << std::endl;

    int age = person.getAge(); // This will prompt for the current date
    int maxRate = 220 - age;

    std::cout << "Age: " << age << " years" << std::endl;
    std::cout << "Maximum Heart Rate: " << maxRate << " beats per minute" << std::endl;
    
    int lowerBound = maxRate * 0.50;
    int upperBound = maxRate * 0.85;
    std::cout << "Target Heart Rate Range: " << lowerBound << " - " << upperBound << " beats per minute" << std::endl;
    std::cout << "-------------------------" << std::endl;
}


int main() {
    std::string firstName, lastName;
    int birthMonth, birthDay, birthYear;

    // Get information from the user
    getUserInfo(firstName, lastName, birthMonth, birthDay, birthYear);

    // Create a HeartRates object with the user's information
    HeartRates person(firstName, lastName, birthMonth, birthDay, birthYear);

    // Display the calculated information
    displayInfo(person);

    return 0;
}