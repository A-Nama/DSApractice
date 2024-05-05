#include <iostream>

using namespace std;

// Function to search for an element in the matrix and display its position
void searchAndDisplayPosition(int matrix[][5], int rows, int cols, int target) {
    bool found = false;

    // Search for the element
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == target) {
                cout << "Element " << target << " found at position (" << i << ", " << j << ")" << endl;
                found = true;
            }
        }
    }

    // If element not found
    if (!found) {
        cout << "Element " << target << " not found in the matrix" << endl;
    }
}

void printSpiral(int matrix[][5], int rows, int cols, int n) {
    int i = n / 2;
    int j = n / 2;
    int k = 1;

    // Print the central element
    cout << matrix[i][j] << " ";

    while (k <= n) {
        // Move up
        for (int a = 0; a < k; a++) {
            i--;
            if (i >= 0 && i < rows && j >= 0 && j < cols) // Check if within bounds
                cout << matrix[i][j] << " ";
        }
        // Move right
        for (int a = 0; a < k; a++) {
            j++;
            if (i >= 0 && i < rows && j >= 0 && j < cols) // Check if within bounds
                cout << matrix[i][j] << " ";
        }
        k++; // Increase the steps
        
        // Move down
        for (int a = 0; a < k; a++) {
            i++;
            if (i >= 0 && i < rows && j >= 0 && j < cols) // Check if within bounds
                cout << matrix[i][j] << " ";
        }
        // Move left
        for (int a = 0; a < k; a++) {
            j--;
            if (i >= 0 && i < rows && j >= 0 && j < cols) // Check if within bounds
                cout << matrix[i][j] << " ";
        }
        k++; // Increase the steps
    }
}


int main() {
    const int rows = 5;
    const int cols = 5;
    int matrix[rows][cols] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    // Search for element 13
    int target = 13;
    searchAndDisplayPosition(matrix, rows, cols, target);

    // Print matrix in a spiral way
    cout << "Matrix in spiral order: ";
    printSpiral(matrix, rows, cols, 5);
    cout << endl;

    return 0;
}
