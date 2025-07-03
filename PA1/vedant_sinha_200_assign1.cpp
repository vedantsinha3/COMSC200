// Comment 1: This line includes the iostream library, which is essential for handling 
// input from the user and outputting text to the console, such as our results.
#include <iostream>
#include <vector>

// Comment 2: These lines declare constant integer variables for the number of rows and columns.
// Using constants makes the code more readable and much easier to modify if we decide to change the array's dimensions later.
const int ROWS = 4;
const int COLS = 5;

// Function Prototypes
double getTotal(const int arr[][COLS], int rows);
double getAverage(const int arr[][COLS], int rows);
int getRowTotal(const int arr[][COLS], int row);
int getColumnTotal(const int arr[][COLS], int rows, int col);
int getHighestInRow(const int arr[][COLS], int row);
int getLowestInRow(const int arr[][COLS], int row);
void printArray(const int arr[][COLS], int rows);


// Comment 3: This is the main function, which serves as the entry point for the entire C++ program.
// The program's execution begins here automatically when it is run.
int main() {
    // Comment 4: This line declares and initializes a 2-dimensional integer array named testArray.
    // The data is organized into ROWS (4) rows and COLS (5) columns, filled with our specific test values.
    int testArray[ROWS][COLS] = {
        {2, 9, 5, 7, 8},
        {6, 3, 12, 4, 10},
        {15, 1, 11, 13, 14},
        {8, 16, 7, 2, 5}
    };

    std::cout << "--- 2D Array Analysis Program ---\n" << std::endl;

    // Display the array being analyzed
    std::cout << "Test Data:" << std::endl;
    printArray(testArray, ROWS);

    // --- Function Calls ---

    // Comment 5: This statement calls the getTotal function, passing our testArray to it. 
    // The returned sum is then printed directly to the console using std::cout.
    std::cout << "Total of all values: " << getTotal(testArray, ROWS) << std::endl;

    // Get the average of all values
    std::cout << "Average of all values: " << getAverage(testArray, ROWS) << std::endl;
    std::cout << std::endl;

    // Get the total of a specific row (e.g., row 1, which is the second row)
    int rowToTest = 1;
    std::cout << "Total of row " << rowToTest << ": " << getRowTotal(testArray, rowToTest) << std::endl;

    // Get the total of a specific column (e.g., column 2, which is the third column)
    int colToTest = 2;
    std::cout << "Total of column " << colToTest << ": " << getColumnTotal(testArray, ROWS, colToTest) << std::endl;
    std::cout << std::endl;

    // Get the highest value in a specific row (e.g., row 2)
    rowToTest = 2;
    std::cout << "Highest value in row " << rowToTest << ": " << getHighestInRow(testArray, rowToTest) << std::endl;

    // Get the lowest value in a specific row (e.g., row 3)
    rowToTest = 3;
    std::cout << "Lowest value in row " << rowToTest << ": " << getLowestInRow(testArray, rowToTest) << std::endl;
    std::cout << std::endl;

    return 0;
}

/**
 * @brief Calculates the total of all values in a 2D array.
 * @param arr The 2D array.
 * @param rows The number of rows in the array.
 * @return The sum of all elements.
 */
// Comment 6: This is the full definition of the getTotal function. 
// The 'const' keyword before the array parameter ensures that the function cannot accidentally modify the original array passed into it.
double getTotal(const int arr[][COLS], int rows) {
    // Comment 7: This line initializes a variable named total to zero. 
    // This variable will be used as an accumulator to hold the sum of all array elements as we loop through them.
    double total = 0;
    // Comment 8: This is the outer 'for' loop that iterates through each row of the 2D array. 
    // The loop counter 'i' represents the current row index, starting from 0 up to (but not including) the total number of rows.
    for (int i = 0; i < rows; ++i) {
        // Comment 9: This is the inner 'for' loop, which is nested inside the row loop. 
        // It iterates through each column within the current row (i), and its counter 'j' represents the current column index.
        for (int j = 0; j < COLS; ++j) {
            // Comment 10: This statement is the core of the nested loops' logic. 
            // It takes the value at the current row 'i' and column 'j' and adds it to our running total.
            total += arr[i][j];
        }
    }
    return total;
}

/**
 * @brief Calculates the average of all values in a 2D array.
 * @param arr The 2D array.
 * @param rows The number of rows in the array.
 * @return The average of all elements.
 */
double getAverage(const int arr[][COLS], int rows) {
    double total = getTotal(arr, rows);
    int numElements = rows * COLS;
    return total / numElements;
}

/**
 * @brief Calculates the total of values in a specific row.
 * @param arr The 2D array.
 * @param row The subscript of the row to total.
 * @return The sum of the elements in the specified row.
 */
int getRowTotal(const int arr[][COLS], int row) {
    int total = 0;
    // Input validation
    if (row < 0 || row >= ROWS) {
        std::cout << "Error: Row index out of bounds." << std::endl;
        return 0; // Or handle error appropriately
    }
    for (int j = 0; j < COLS; ++j) {
        total += arr[row][j];
    }
    return total;
}

/**
 * @brief Calculates the total of values in a specific column.
 * @param arr The 2D array.
 * @param rows The number of rows in the array.
 * @param col The subscript of the column to total.
 * @return The sum of the elements in the specified column.
 */
int getColumnTotal(const int arr[][COLS], int rows, int col) {
    int total = 0;
    // Input validation
    if (col < 0 || col >= COLS) {
        std::cout << "Error: Column index out of bounds." << std::endl;
        return 0; // Or handle error appropriately
    }
    for (int i = 0; i < rows; ++i) {
        total += arr[i][col];
    }
    return total;
}

/**
 * @brief Finds the highest value in a specific row.
 * @param arr The 2D array.
 * @param row The subscript of the row to search.
 * @return The highest value in the specified row.
 */
int getHighestInRow(const int arr[][COLS], int row) {
    // Input validation
    if (row < 0 || row >= ROWS) {
        std::cout << "Error: Row index out of bounds." << std::endl;
        return 0; // Or handle error appropriately
    }
    // Comment 11: To start the search for the highest value, we initialize a variable 'highest' with the very first element of the specified row.
    // We will then compare this initial value against all other elements in that same row.
    int highest = arr[row][0]; 
    for (int j = 1; j < COLS; ++j) {
        if (arr[row][j] > highest) {
            highest = arr[row][j];
        }
    }
    return highest;
}

/**
 * @brief Finds the lowest value in a specific row.
 * @param arr The 2D array.
 * @param row The subscript of the row to search.
 * @return The lowest value in the specified row.
 */
int getLowestInRow(const int arr[][COLS], int row) {
    // Input validation
    if (row < 0 || row >= ROWS) {
        std::cout << "Error: Row index out of bounds." << std::endl;
        return 0; // Or handle error appropriately
    }
    int lowest = arr[row][0]; // Assume the first element is the lowest
    for (int j = 1; j < COLS; ++j) {
        if (arr[row][j] < lowest) {
            lowest = arr[row][j];
        }
    }
    return lowest;
}

/**
 * @brief Prints the contents of the 2D array to the console.
 * @param arr The 2D array.
 * @param rows The number of rows in the array.
 */
void printArray(const int arr[][COLS], int rows) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
