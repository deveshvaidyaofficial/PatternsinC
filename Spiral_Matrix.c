#include <stdio.h>

#define ROWS 4
#define COLS 4

void printSpiral(int matrix[ROWS][COLS], int rows, int cols) {
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
        // Print the top row
        for (int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++;

        // Print the rightmost column
        for (int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;

        // Print the bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        // Print the leftmost column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }
}

int main() {
    int matrix[ROWS][COLS] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9,  10, 11, 12},
        {13, 14, 15, 16}
    };

    printf("Spiral Order of the matrix is: \n");
    printSpiral(matrix, ROWS, COLS);

    return 0;
}


// Input Matrix:

// 1   2   3   4
// 5   6   7   8
// 9  10  11  12
// 13  14  15  16


// Spiral Order Output:

// Spiral Order of the matrix is: 
// 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
