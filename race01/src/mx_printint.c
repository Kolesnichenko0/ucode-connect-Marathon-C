#include "../inc/header.h"

void mx_printnum(long long n) {
        if(n < 0) {
                write(1, "-", 1);
		n *= -1;
	}
        if(n == 0) {
                write(1, "0", 1);
                return;
        }
        int counter = 0;
        for(unsigned long long i = (unsigned long long)n; i != 0; i = (i - (i % 10)) / 10)
                counter++;
        int num[counter];
        int j = counter;
        for(unsigned long long i = (unsigned long long) n; i != 0; i = (i - (i % 10)) / 10) {
                num[j - 1] = i % 10;
                j--;
        }
        for(int i = 0; i < counter; i++) {
		int t = num[i] + 48;
                write(1, &t, 1);
	}
}
