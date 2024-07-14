#include "../inc/header.h"

int main(int argc, char* argv[]) {
	if (argc != 5) {
		mx_printerr(E_USAGE);
		mx_printerr("\n");
		exit(-1);
	}
	char operation = mx_check_find_operation(argv[2]);
	char *operand1 = mx_check_change_num(argv[1]);
	if (operand1 == NULL)
		mx_error(E_OPERAND, argv[1]);
	char *operand2 = mx_check_change_num(argv[3]);
	if (operand2 == NULL)
		mx_error(E_OPERAND, argv[3]);
	char *result = mx_check_change_num(argv[4]);
	if (result == NULL)
		mx_error(E_RESULT, argv[4]);
	mx_compute(operand1, operand2, result, operation);
	exit(1);
}
