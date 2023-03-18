#include <stdio.h>

int decrease(int n);

int main()
{
	unsigned int x = 2147483648;
	int y = 2147483648;

	printf("x = %u\n", x);
	printf("y = %d\n", y);

	int i, sum = 0;
	for (i = 1; i <= 3; i++) {
        printf("x = %u\n", x + i);
        printf("y = %d\n", y + i);
	}

	printf("sum = %d\n", sum);

	int m = decrease(67);

	printf("decreased = %d\n", m);

	return 0;
}

int decrease(int n) {
    int m = n - 1;
    return m;
}
