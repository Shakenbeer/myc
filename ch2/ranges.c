#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("char range: [%d..%d]\n", CHAR_MIN, CHAR_MAX);
    printf("uchar range: [0..%u]\n", UCHAR_MAX);
    printf("short range: [%d..%d]\n", SHRT_MIN, SHRT_MAX);
    printf("ushort range: [0..%u]\n", USHRT_MAX);
    printf("int range: [%d..%d]\n", INT_MIN, INT_MAX);
    printf("uint range: [0..%u]\n", UINT_MAX);
    printf("long range: [%d..%d]\n", LONG_MIN, LONG_MAX);
    printf("ulong range: [0..%u]\n", ULONG_MAX);
}