#include <stdio.h>

int tryme(const char[]);

int main() {
    float eps = 78.0e-1;
    printf("hello, " "world %f\n", eps);
    
    char c[3] = "AA";
    printf("%s\n", c);
    tryme(c);
    printf("%s\n", c);
}

int tryme(const char arr[]) {
}

