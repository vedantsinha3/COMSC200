// Implementation file for the IntegerSet class.
// This file provides the logic for all the member functions declared in IntegerSet.h.

#include "Vedant_Sinha_IntegerSet.h" // Include the class declaration
#include <iostream>                  // For input/output operations like std::cout and std::cin
#include <vector>                    // To use std::vector

// Comment 1: This is the default constructor. It initializes the set to an empty state.
// It uses a constructor initializer list to efficiently create a vector of 101 boolean 'false' values,
// representing an empty set for numbers 0 through 100.
IntegerSet::IntegerSet() : set(101, false) {
    // The body is empty because the initializer list does all the work.
}

// Comment 2: This is the second constructor. It takes a C-style array of integers and its size.
// It initializes the set by inserting each valid element from the provided array.
IntegerSet::IntegerSet(int arr[], int size) : set(101, false) {
    for (int i = 0; i < size; ++i) {
        // Comment 3: The insertElement function is called here to add each element from the array.
        // This promotes code reuse and ensures that only valid numbers (0-100) are added to the set.
        insertElement(arr[i]);
    }
}

// Comment 4: The inputSet function allows the user to populate the set interactively.
// It first resets the current set to be empty, then reads integers until the user enters -1.
void IntegerSet::inputSet() {
    set.assign(101, false); // Clear the existing set
    int number;
    std::cout << "Enter an element (-1 to end): ";
    while (std::cin >> number && number != -1) {
        if (number >= 0 && number <= 100) {
            insertElement(number);
        } else {
            std::cout << "Invalid element entered: " << number << ". Please enter a number between 0 and 100." << std::endl;
        }
        std::cout << "Enter an element (-1 to end): ";
    }
}

// Comment 5: The unionOfSets function creates and returns a new set that is the
// set-theoretic union of the current set ('this') and another set ('otherSet').
// An element is in the union if it is in either or both sets.
IntegerSet IntegerSet::unionOfSets(const IntegerSet& otherSet) const {
    IntegerSet unionResult;
    for (int i = 0; i < 101; ++i) {
        // The logical OR operator '||' perfectly models the union operation.
        if (this->set[i] || otherSet.set[i]) {
            unionResult.set[i] = true;
        }
    }
    return unionResult;
}

// Comment 6: The intersectionOfSets function is similar to the union function,
// but it computes the set-theoretic intersection. An element is in the intersection
// only if it is present in *both* sets.
IntegerSet IntegerSet::intersectionOfSets(const IntegerSet& otherSet) const {
    IntegerSet intersectionResult;
    for (int i = 0; i < 101; ++i) {
        // The logical AND operator '&&' perfectly models the intersection operation.
        if (this->set[i] && otherSet.set[i]) {
            intersectionResult.set[i] = true;
        }
    }
    return intersectionResult;
}

// Comment 7: insertElement adds a new number to the set. It performs a validity check
// to ensure the number is within the acceptable range [0, 100] before modifying the vector.
// If the number is valid, the boolean at that index is set to 'true'.
void IntegerSet::insertElement(int k) {
    if (k >= 0 && k <= 100) {
        this->set[k] = true;
    }
}

// Comment 8: deleteElement removes a number from the set. Similar to insertElement,
// it validates the range of the number first. If valid, it sets the boolean at that
// index to 'false'.
void IntegerSet::deleteElement(int m) {
    if (m >= 0 && m <= 100) {
        this->set[m] = false;
    }
}

// Comment 9: The printSet function displays the contents of the set. It iterates through
// the vector and prints the index for any element that is 'true'. To handle an empty set,
// a flag 'isEmpty' is used. If no elements are printed, it prints "--" as required.
void IntegerSet::printSet() const {
    bool isEmpty = true;
    for (int i = 0; i < 101; ++i) {
        if (this->set[i]) {
            isEmpty = false;
            std::cout << i << " ";
        }
    }
    if (isEmpty) {
        std::cout << "--";
    }
}

// Comment 10: The isEqualTo function checks for equality between two sets. It iterates
// through both sets and compares them element by element. If it finds any index where the
// boolean values differ, it immediately returns 'false'. If the entire loop completes
// without finding a difference, the sets must be equal, and it returns 'true'.
bool IntegerSet::isEqualTo(const IntegerSet& otherSet) const {
    for (int i = 0; i < 101; ++i) {
        if (this->set[i] != otherSet.set[i]) {
            return false;
        }
    }
    return true;
}