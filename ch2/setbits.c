#include <stdio.h>

#define BIT_WIDTH 32

unsigned getbits(unsigned, int, int);
unsigned setbits(unsigned, int, int, unsigned);
char *IntToBin(unsigned n, char *buffer);
void inttobin(unsigned n, char bin[]);
void logbit(char name[], int t);
void reverse(char[]);

int main() {
    unsigned x;
    unsigned y;
    int p, n, bits;
    
    printf("returns x with the n bits that begin at position p set to the rightmost n bits of y\n");
    printf("gimme x, y, p, f\n");
    scanf("%d%d%d%d", &x, &y, &p, &n);
    logbit("x", x);
    logbit("y", y);
    bits = setbits(x, p, n, y);
    logbit("bits", bits);
    return 0;
}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
    /*
      input: x = 678 = 1010100110, p = 4, n = 3
      1. x >> (p+1-n) right shift on 2: 0010101001
      2. ~0 is 11111111111111111111111111111111 (32)
      3. (~0 << 3) = 11111111111111111111111111111000
      4. ~(~0 << 3) = 111
      5. 0010101001 & 0000000111 = 001
    */
}

/* setbits: returns x with the n bits that begin at position p set to the rightmost n bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y) {
    int xWithZeros = ((x >> p + 1) << p + 1) | (x & ~(~0 << (p + 1 - n)));//x & ~(~(~0 << n) << (p + 1 -n));
    int t = (y & ~(~0 << n)) << (p + 1 - n);    

	return xWithZeros | t;
}

void logbit(char name[], int t) {
    char bin[BIT_WIDTH + 1];
    inttobin(t, bin);
    printf("%s %d is %s\n", name, t, bin);
} 

//TODO how does this work?
char *IntToBin(unsigned n, char *buffer) {
    char *ptr = buffer + BIT_WIDTH;
    do {
        *(--ptr) = (n & 1) + '0';
        n >>= 1;
    } while(n);
    return ptr;
}

void inttobin(unsigned n, char bin[]) {
    int i = 0;
    do {
        if (n % 2 == 0) {
            bin[i++] = '0';
        } else {
            bin[i++] = '1';
        }
        n /= 2;
    } while (n > 0);
    bin[i] = '\0';
    reverse(bin);
}

void reverse(char s[]) {
    int len = 0;
    char buffer;
    while (s[len] != '\0')
        len += 1;
    for (int i = 0; i < len / 2; i++) {
        buffer = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = buffer;
    }
}