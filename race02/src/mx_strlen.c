#include "header.h"

int mx_strlen(const char *s) {
int m = 0;
while(s[m] != '\0') {
m++;
}
return m;
}
