#include <stdio.h>
/* copy input to output; repalces one or more blanks with a single blank */
int main() {
    int c;
    int prev_was_blank = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
           if (!prev_was_blank)
               putchar(c);
        } else
           putchar(c);
        prev_was_blank = (c == ' ');
    }
}