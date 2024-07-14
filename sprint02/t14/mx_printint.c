#include <unistd.h>

void mx_printchar(char c) ;

void mx_printint(int n) {
	if(n == 0) {
		write(1, "0", 1);
		return;
	}
	if(n < 0) {
		write(1, "-", 1);
		n *= -1;
	}
	int counter = 0 ;
	for(long i = n; i != 0; i = (i - (i % 10)) / 10) {
		counter++;
	}
	int number[counter];
	int j = counter;
	for(long i = n; i != 0; i = (i - (i % 10)) / 10) {
		number[j - 1] = i % 10 ;
		j--;
	}
	for(int i = 0; i < counter; i++) {
		mx_printchar(number[i] + 48);
	}
}
