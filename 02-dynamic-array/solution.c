#include <stdio.h>
#include <stdlib.h>

int* dynamicArray(int n, int queries_rows, int queries_columns, int** queries, int* result_count) {
    int** arr = (int**)malloc(n * sizeof(int*));
    int* sizes = (int*)calloc(n, sizeof(int));
    int* capacities = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        capacities[i] = 2;
        arr[i] = (int*)malloc(capacities[i] * sizeof(int));
    }

    int lastAnswer = 0;
    int* result = (int*)malloc(queries_rows * sizeof(int));
    *result_count = 0;

    for (int i = 0; i < queries_rows; i++) {
        int type = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];
        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            if (sizes[idx] == capacities[idx]) {
                capacities[idx] *= 2;
                arr[idx] = (int*)realloc(arr[idx], capacities[idx] * sizeof(int));
            }
            arr[idx][sizes[idx]++] = y;
        } else if (type == 2) {
            lastAnswer = arr[idx][y % sizes[idx]];
            result[(*result_count)++] = lastAnswer;
        }
    }
    return result;
}

int main() {
    printf("Dynamic Array Implementation Ready.\n");
    return 0;
}