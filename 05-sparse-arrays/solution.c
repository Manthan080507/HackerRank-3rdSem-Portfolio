#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* matchingStrings(int stringList_count, char** stringList, int queries_count, char** queries, int* result_count) {
    int* result = (int*)calloc(queries_count, sizeof(int));
    *result_count = queries_count;

    for (int i = 0; i < queries_count; i++) {
        for (int j = 0; j < stringList_count; j++) {
            if (strcmp(queries[i], stringList[j]) == 0) {
                result[i]++;
            }
        }
    }
    return result;
}

int main() {
    printf("Sparse Arrays Implementation Ready.\n");
    return 0;
}