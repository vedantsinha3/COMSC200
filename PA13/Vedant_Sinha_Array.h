#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

template <typename T>
class Array {
public:
    explicit Array(int size = 10);           // default constructor
    Array(const Array<T> &);                 // copy constructor
    ~Array();                                // destructor
    size_t getSize() const;

    const Array<T> &operator=(const Array<T> &); // assignment operator
    bool operator==(const Array<T> &) const;     // equality operator
    bool operator!=(const Array<T> &right) const {
        return !(*this == right);
    }

    T &operator[](int);            // subscript operator (non-const)
    T operator[](int) const;       // subscript operator (const)

private:
    size_t size;
    T *ptr;
};

// Constructor
template <typename T>
Array<T>::Array(int arraySize)
    : size(arraySize > 0 ? arraySize : throw invalid_argument("Array size must be > 0")),
      ptr(new T[size]) {
    for (size_t i = 0; i < size; ++i)
        ptr[i] = T{};
}

// Copy Constructor
template <typename T>
Array<T>::Array(const Array<T> &other)
    : size(other.size), ptr(new T[size]) {
    for (size_t i = 0; i < size; ++i)
        ptr[i] = other.ptr[i];
}

// Destructor
template <typename T>
Array<T>::~Array() {
    delete[] ptr;
}

// getSize
template <typename T>
size_t Array<T>::getSize() const {
    return size;
}

// Assignment operator
template <typename T>
const Array<T> &Array<T>::operator=(const Array<T> &right) {
    if (this != &right) {
        if (size != right.size) {
            delete[] ptr;
            size = right.size;
            ptr = new T[size];
        }
        for (size_t i = 0; i < size; ++i)
            ptr[i] = right.ptr[i];
    }
    return *this;
}

// Equality operator
template <typename T>
bool Array<T>::operator==(const Array<T> &right) const {
    if (size != right.size)
        return false;
    for (size_t i = 0; i < size; ++i)
        if (ptr[i] != right.ptr[i])
            return false;
    return true;
}

// Subscript operator (non-const)
template <typename T>
T &Array<T>::operator[](int index) {
    if (index < 0 || index >= static_cast<int>(size))
        throw out_of_range("Subscript out of range");
    return ptr[index];
}

// Subscript operator (const)
template <typename T>
T Array<T>::operator[](int index) const {
    if (index < 0 || index >= static_cast<int>(size))
        throw out_of_range("Subscript out of range");
    return ptr[index];
}

// Overloaded input operator
template <typename T>
istream &operator>>(istream &input, Array<T> &a) {
    for (size_t i = 0; i < a.getSize(); ++i)
        input >> a[i];
    return input;
}

// Overloaded output operator
template <typename T>
ostream &operator<<(ostream &output, const Array<T> &a) {
    for (size_t i = 0; i < a.getSize(); ++i) {
        output << setw(12) << a[i];
        if ((i + 1) % 4 == 0)
            output << endl;
    }
    if (a.getSize() % 4 != 0)
        output << endl;
    return output;
}

#endif
