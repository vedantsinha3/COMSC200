#ifndef HEARTRATES_H
#define HEARTRATES_H

#include <string>

// Comment 1: This is the beginning of the HeartRates class definition.
// This class is designed to store information about a person, including their name
// and date of birth, and to calculate their age, maximum heart rate, and
// target heart rate range.
class HeartRates {
public:
    // Comment 2: This is the constructor for the HeartRates class.
    // It initializes a new HeartRates object with the provided first name,
    // last name, and date of birth.
    HeartRates(std::string firstName, std::string lastName, int birthMonth, int birthDay, int birthYear);

    // Set and Get functions for first name
    void setFirstName(std::string firstName);
    std::string getFirstName() const;

    // Set and Get functions for last name
    void setLastName(std::string lastName);
    std::string getLastName() const;

    // Set and Get functions for birth month
    void setBirthMonth(int birthMonth);
    int getBirthMonth() const;

    // Set and Get functions for birth day
    void setBirthDay(int birthDay);
    int getBirthDay() const;

    // Set and Get functions for birth year
    void setBirthYear(int birthYear);
    int getBirthYear() const;

    // Comment 3: This function calculates the person's age in years.
    // It will prompt the user for the current date to perform the calculation.
    int getAge() const;

    // Comment 4: This function calculates the person's maximum heart rate.
    // The formula used is 220 minus the person's age.
    int getMaximumHeartRate() const;

    // Comment 5: This function calculates and displays the target heart rate range.
    // The target range is 50% to 85% of the maximum heart rate.
    void getTargetHeartRate() const;

private:
    // Comment 6: These are the private member variables of the class.
    // They store the person's personal information and can only be accessed
    // through the public member functions (getters and setters).
    std::string firstName;
    std::string lastName;
    int birthMonth;
    int birthDay;
    int birthYear;
};

#endif // HEARTRATES_H