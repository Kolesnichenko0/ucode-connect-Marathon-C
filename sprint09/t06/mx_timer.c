#include <time.h>

double mx_timer(void (*f)()) {
	if (*f == NULL)
		return -1;
	clock_t time_f = clock();
	f();
	time_f = clock() - time_f;
	return (double) time_f / (double)CLOCKS_PER_SEC;
}

