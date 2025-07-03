#include <iostream>
#include "Vedant_Sinha_HeartRates.h" // Include the HeartRates header file

// Comment 7: This is the implementation of the constructor.
// It uses a member initializer list to assign the passed arguments
// to the corresponding private member variables.
HeartRates::HeartRates(std::string fName, std::string lName, int bMonth, int bDay, int bYear)
    : firstName(fName), lastName(lName), birthMonth(bMonth), birthDay(bDay), birthYear(bYear) {
    // The constructor body is empty as the initialization is done in the initializer list.
}

// Setters
void HeartRates::setFirstName(std::string fName) {
    firstName = fName;
}
void HeartRates::setLastName(std::string lName) {
    lastName = lName;
}
void HeartRates::setBirthMonth(int bMonth) {
    birthMonth = bMonth;
}
void HeartRates::setBirthDay(int bDay) {
    birthDay = bDay;
}
void HeartRates::setBirthYear(int bYear) {
    birthYear = bYear;
}

// Getters
std::string HeartRates::getFirstName() const {
    return firstName;
}
std::string HeartRates::getLastName() const {
    return lastName;
}
int HeartRates::getBirthMonth() const {
    return birthMonth;
}
int HeartRates::getBirthDay() const {
    return birthDay;
}
int HeartRates::getBirthYear() const {
    return birthYear;
}

// Comment 8: Implementation of the getAge function.
// It prompts for the current date and calculates the age.
// The age calculation correctly accounts for whether the person's birthday
// has already occurred in the current year.
int HeartRates::getAge() const {
    int currentMonth, currentDay, currentYear;

    std::cout << "\nPlease enter the current date to calculate age." << std::endl;
    std::cout << "Enter current month (1-12): ";
    std::cin >> currentMonth;
    std::cout << "Enter current day (1-31): ";
    std::cin >> currentDay;
    std::cout << "Enter current year: ";
    std::cin >> currentYear;

    int age = currentYear - birthYear;
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--;
    }
    return age;
}

// Comment 9: Implementation of the getMaximumHeartRate function.
// It first calls getAge() to get the person's current age,
// then calculates and returns the maximum heart rate.
int HeartRates::getMaximumHeartRate() const {
    return 220 - getAge();
}

// Comment 10: Implementation of the getTargetHeartRate function.
// It calculates the target heart rate range based on the maximum heart rate.
// The lower bound is 50% and the upper bound is 85% of the max rate.
void HeartRates::getTargetHeartRate() const {
    int maxRate = 220 - getAge(); // Recalculate age and max rate to avoid asking for current date twice
    int lowerBound = maxRate * 0.50;
    int upperBound = maxRate * 0.85;
    std::cout << "Target Heart Rate Range: " << lowerBound << " - " << upperBound << " beats per minute" << std::endl;
}