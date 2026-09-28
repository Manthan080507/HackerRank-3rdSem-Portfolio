#include <stdio.h>
#include <stdlib.h>

int diagonalDifference(int arr_rows, int arr_columns, int** arr) {
    int primary_sum = 0, secondary_sum = 0;
    for (int i = 0; i < arr_rows; i++) {
        primary_sum += arr[i][i];
        secondary_sum += arr[i][arr_rows - 1 - i];
    }
    return abs(primary_sum - secondary_sum);
}

int main() {
    int n = 3;
    int matrix[3][3] = {
        {11, 2, 4},
        {4, 5, 6},
        {10, 8, -12}
    };

    int* arr[3];
    for (int i = 0; i < n; i++) arr[i] = matrix[i];

    printf("Diagonal Difference: %d\n", diagonalDifference(n, n, arr));
    return 0;
}