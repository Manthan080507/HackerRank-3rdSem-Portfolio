#include <stdio.h>
#include <stdlib.h>

int* compareTriplets(int a_count, int* a, int b_count, int* b, int* result_count) {
    int* score = (int*)calloc(2, sizeof(int));
    *result_count = 2;
    for (int i = 0; i < 3; i++) {
        if (a[i] > b[i]) score[0]++;
        else if (a[i] < b[i]) score[1]++;
    }
    return score;
}

int main() {
    int a[3] = {5, 6, 7};
    int b[3] = {3, 6, 10};
    int count;
    int* res = compareTriplets(3, a, 3, b, &count);
    printf("Scores: Alice = %d, Bob = %d\n", res[0], res[1]);
    return 0;
}