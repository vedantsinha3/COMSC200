// Header file for the IntegerSet class.
// This file declares the class interface, including its member variables and function prototypes.

#ifndef VEDANT_SINHA_INTEGERSET_H
#define VEDANT_SINHA_INTEGERSET_H

#include <vector> // Required to use the std::vector container

// Defines the IntegerSet class
class IntegerSet {
public:
    // Default constructor: initializes an empty set (all values false)
    IntegerSet();

    // Constructor that initializes a set from an array of integers
    IntegerSet(int arr[], int size);

    // Member function to fill the set with user input
    void inputSet();

    // Member function to return a new set that is the union of this set and another set
    IntegerSet unionOfSets(const IntegerSet& otherSet) const;

    // Member function to return a new set that is the intersection of this set and another set
    IntegerSet intersectionOfSets(const IntegerSet& otherSet) const;

    // Member function to insert a new integer into the set
    void insertElement(int k);

    // Member function to delete an integer from the set
    void deleteElement(int m);

    // Member function to print the set's elements to the console
    void printSet() const;

    // Member function to check if this set is equal to another set
    bool isEqualTo(const IntegerSet& otherSet) const;

private:
    // The internal representation of the set using a vector of booleans.
    // The size is 101 to hold integers from 0 to 100.
    std::vector<bool> set;
};

#endif // JAMES_SMITH_INTEGERSET_H