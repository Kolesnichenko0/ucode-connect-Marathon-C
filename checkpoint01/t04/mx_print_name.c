#include <unistd.h>

int main(int argc, char *argv[]) {
	if(argc < 1)
		return 0;
	int size = 0;
	for (int i = 0; argv[0][i] != '\0'; i++)
		size++;
	write(1, argv[0], size);
	write(1, "\n", 1);
	int counter = 0;
	for (unsigned i = (unsigned)argc; i != 0; i = (i - (i % 10)) / 10)
		counter++;
	int number[counter];
	int j = counter;
	for (unsigned i = (unsigned)argc; i != 0; i = (i - (i % 10)) / 10) {
		number[j - 1] = i % 10;
		j--;
	}
	for (int i = 0; i < counter; i++) {
		int t = number[i] + 48;
		write(1, &t, 1);
	}
	write(1, "\n", 1);
	return 0;
}

