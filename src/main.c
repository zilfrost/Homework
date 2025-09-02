#include <stdio.h>
#include "strutils.h"

int main() {
    // Test string
    char str[] = "   test  ";

    printf("Original string: '%s'\n", str);

    // Test str_trim
    str_trim(str);
    printf("After trim: '%s'\n", str);

    // Test str_reverse
    str_reverse(str);
    printf("After reverse: '%s'\n", str);

    // Test str_to_int
    const char *numStr1 = "12345";
    const char *numStr2 = "99999999999"; // out of int range
    const char *numStr3 = "12a34";       // invalid string

    int number;

    if (str_to_int(numStr1, &number)) {
        printf("'%s' -> %d\n", numStr1, number);
    } else {
        printf("'%s' -> conversion error\n", numStr1);
    }

    if (str_to_int(numStr2, &number)) {
        printf("'%s' -> %d\n", numStr2, number);
    } else {
        printf("'%s' -> conversion error (overflow)\n", numStr2);
    }

    if (str_to_int(numStr3, &number)) {
        printf("'%s' -> %d\n", numStr3, number);
    } else {
        printf("'%s' -> conversion error (invalid string)\n", numStr3);
    }

    return 0;
}
