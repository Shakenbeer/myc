#include <stdio.h>

int main() {
    int a = 3;
    int b = 4;
    int *p1 = &a;
    int p2 = &b;
    
    //printf("pointer %p long %u\n", p1, p1);
    //printf("pointer %p long %u\n", p2, p2);
    printf("a = %d, b = %d\n", *p1);
}