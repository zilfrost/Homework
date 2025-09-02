#include <stdio.h>
#include "strutils.h"

//length of string
int my_strlen(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// check whitespace character
int my_isspace(char c) {
    return (c == ' '  ||  // space
            c == '\t' ||  // tab ngang
            c == '\n' ||  // newline
            c == '\v' ||  // vertical tab
            c == '\f' ||  // form feed
            c == '\r');   // carriage return
}

// reverse string in place
void str_reverse(char *str) {
    if (!str) return;
    int len = my_strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// trim leading and trailing whitespace
void str_trim(char *str) {
    if (!str) return;

    int start = 0;
    int end = my_strlen(str) - 1;

    // trim leading whitespace
    while (my_isspace(str[start])) {
        start++;
    }

    // trim trailing whitespace
    while (end >= start && my_isspace(str[end])) {
        end--;
    }

    // shift characters to the front
    int j = 0;
    for (int i = start; i <= end; i++) {
        str[j++] = str[i];
    }
    str[j] = '\0';
}

// safe string to int conversion
int str_to_int(const char *str, int *out) {
    if (!str || !out) return 0;

    int i = 0;
    int sign = 1;
    long result = 0;

    // trim leading whitespace
    while (my_isspace(str[i])) {
        i++;
    }

    // check sign
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    // convert digits
    for (; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        } else {
            return 0; // invalid character
        }
    }

    result *= sign;

    // check overflow
    if (result < -2147483648L || result > 2147483647L) {
        return 0; // overflow
    }

    *out = (int)result;
    return 1;
}