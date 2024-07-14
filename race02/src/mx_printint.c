#include "header.h"

void mx_printint(int n) {
char a[15];
int i = 0;

if (n == 0) {
write(1, "0", 1);
}
if (n < 0) {
n *= -1;
write(1, "-", 1);
}
for (; n != 0; i++) {
a[i] = (n % 10) + '0';
n /= 10;
}
for (int j = i - 1; j >= 0; j--) {
write(1, &a[j], 1);
}
}
