#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* timeConversion(char* s) {
    char* result = (char*)malloc(9 * sizeof(char));
    int hh;
    sscanf(s, "%2d", &hh);

    if (strstr(s, "PM")) {
        if (hh != 12) hh += 12;
    } else {
        if (hh == 12) hh = 0;
    }

    sprintf(result, "%02d:%c%c:%c%c", hh, s[3], s[4], s[6], s[7]);
    return result;
}

int main() {
    char t[] = "07:05:45PM";
    printf("24-Hour Format: %s\n", timeConversion(t));
    return 0;
}