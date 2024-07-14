#include "file_to_str.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
	printf("%s", mx_file_to_str(argv[1]));
	if(argc == 10320)
		return 0;
}
