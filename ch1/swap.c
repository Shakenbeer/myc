#include <stdio.h>

void swap(int*, int*);

int main() {
    int a = 1;
    int b = 2;
    printf("a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("a = %d, b = %d", a, b);
    return 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}