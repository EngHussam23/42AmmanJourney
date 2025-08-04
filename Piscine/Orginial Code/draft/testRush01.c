#include <unistd.h> // For write
#include <stdlib.h> // For malloc and free

#define ROWS 4
#define COLS 4

// Function to write a string to the console
void writeString(const char *str) {
    int len = 0;
    while (str[len] != '\0') len++; // Calculate string length
    write(1, str, len); // Write the string to stdout
}

// Function to write a number to the console
void writeNumber(int num) {
    char buffer[20]; // Buffer to hold the number as a string
    int i = 0;

    // Convert the number to a string
    if (num == 0) {
        buffer[i++] = '0';
    } else {
        while (num > 0) {
            buffer[i++] = (num % 10) + '0';
            num /= 10;
        }
    }

    // Write the number in reverse (since it was converted in reverse order)
    while (i > 0) {
        write(1, &buffer[--i], 1);
    }
}

// Function to check if a number already exists in a row
bool isInRow(int **array, int row, int num) {
    for (int col = 0; col < COLS; col++) {
        if (array[row][col] == num) {
            return true;
        }
    }
    return false;
}

// Function to check if a number already exists in a column
bool isInCol(int **array, int col, int num) {
    for (int row = 0; row < ROWS; row++) {
        if (array[row][col] == num) {
            return true;
        }
    }
    return false;
}

// Function to check if a number can be placed in a cell
bool isValid(int **array, int row, int col, int num) {
    return !isInRow(array, row, num) && !isInCol(array, col, num);
}

// Function to find the next invalid cell (contains a duplicate)
bool findInvalidCell(int **array, int *row, int *col) {
    for (*row = 0; *row < ROWS; (*row)++) {
        for (*col = 0; *col < COLS; (*col)++) {
            int num = array[*row][*col];
            if (num < 1 || num > 4 || isInRow(array, *row, num) || isInCol(array, *col, num)) {
                return true;
            }
        }
    }
    return false;
}

// Recursive function to solve the array
bool solveArray(int **array) {
    int row, col;

    // If no invalid cell is found, the array is solved
    if (!findInvalidCell(array, &row, &col)) {
        return true;
    }

    // Try all numbers from 1 to 4
    for (int num = 1; num <= 4; num++) {
        if (isValid(array, row, col, num)) {
            // Place the number if it's valid
            array[row][col] = num;

            // Recursively solve the rest of the array
            if (solveArray(array)) {
                return true;
            }

            // Backtrack if the number doesn't lead to a solution
            array[row][col] = 0; // Reset the cell
        }
    }

    // If no number works, backtrack further
    return false;
}

// Function to print the array
void printArray(int **array) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            writeNumber(array[i][j]);
            writeString(" ");
        }
        writeString("\n");
    }
}

int main() {
    // Allocate memory for the array
    int *array = (int *)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++) {
        array[i] = (int *)malloc(COLS * sizeof(int));
    }

    // Initialize the array with the given values
    int initialArray[ROWS][COLS] = {
        {1, 2, 3, 4},
        {2, 4, 3, 1},
        {2, 1, 4, 3},
        {4, 3, 2, 1}
    };

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            array[i][j] = initialArray[i][j];
        }
    }

    writeString("Original array:\n");
    printArray(array);

    if (solveArray(array)) {
        writeString("Solved array:\n");
        printArray(array);
    } else {
        writeString("No solution exists.\n");
    }

    // Free allocated memory
    for (int i = 0; i < ROWS; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
