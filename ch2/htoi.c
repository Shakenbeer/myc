#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define BASE 16

int htoi(char[]);
int dhtoi(char);

int main() {
    printf("X3 - %d\n", htoi("i"));
    printf("X3 - %d\n", htoi("0i"));
    printf("X3 - %d\n", htoi("0x"));
    printf("0 - %d\n", htoi("0"));
    printf("0 - %d\n", htoi("0x0"));
    printf("11 - %d\n", htoi("b"));
    printf("11 - %d\n", htoi("0Xb"));
    printf("45 - %d\n", htoi("2D"));
    printf("45 - %d\n", htoi("0x2D"));
    printf("666 - %d\n", htoi("29a"));
    printf("666 - %d\n", htoi("29A"));
    printf("666 - %d\n", htoi("0x29a"));
    printf("666 - %d\n", htoi("0X29A"));
    printf("X3 - %d\n", htoi("0X2UA"));
}

int htoi(char hex[]) {
    int len = strlen(hex);
    if (len == 0) {
        return -1;
    }
    if (len == 1 && isxdigit(hex[0])) {
        return dhtoi(hex[0]);
    }
    if (len == 2 && isxdigit(hex[0]) && isxdigit(hex[1])) {
        return dhtoi(hex[0]) * BASE + dhtoi(hex[1]);
    }
    if (len > 2) {
        int start = 0;
        int result = 0;
        if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')) {
            start = 2;
        }
        for (int i = start; i < len; i++) {
            if (!isxdigit(hex[i])) {
                return -1;
            }
            result += dhtoi(hex[i]) * pow(BASE, len - 1 - i);
        }
        return result;
    } else {
        return - 1;
    }
}

int dhtoi(char c) {
    if (isdigit(c)) {
        return c - '0';
    } else if (islower(c)) {
        return c - 'a' + 10;
    } else {
        return c - 'A' + 10;
    }
}

