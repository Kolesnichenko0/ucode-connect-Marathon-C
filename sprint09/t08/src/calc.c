#include "../inc/calculator.h"

void check_operand(int num1, int num2, char **argv, bool *flag_error, enum e_error *error ) {
	if (num1 == 0 && mx_strcmp(argv[1], "0") != 0 &&
			mx_strcmp(argv[1], "-0") != 0 &&
			mx_strcmp(argv[1], "+0") != 0) {
		*error = INCORRECT_OPERAND;
        	*flag_error = true;
        }
	if (num2 == 0 && mx_strcmp(argv[3], "0") != 0 &&
			mx_strcmp(argv[3], "-0") != 0 &&
			mx_strcmp(argv[3], "+0") != 0) {
		*error = INCORRECT_OPERAND;
		*flag_error = true;
	}
}

void check_operations(char **argv, bool *flag_oper, bool *flag_error , t_operation *temp, enum e_error *error, enum e_operation *oper) {
	if (mx_strcmp(argv[2], "+") == 0) {
		*oper = ADD;
		temp->op = *oper;
		temp->f = mx_add;
		*flag_oper = true;
	}
	else if(mx_strcmp(argv[2], "-") == 0) {
		*oper = SUB;
		temp->op = *oper;
		temp->f = mx_sub;
		*flag_oper = true;
	}
	else if(mx_strcmp(argv[2], "*") == 0) {
		*oper = MUL;
		temp->op = *oper;
		temp->f = mx_mul;
		*flag_oper = true;
	}
	else if(mx_strcmp(argv[2], "/") == 0) {
		*oper = DIV;
		temp->op = *oper;
		temp->f = mx_div;
		*flag_oper = true;
	}
	else if(mx_strcmp(argv[2], "%") == 0) {
		*oper = MOD;
		temp->op = *oper;
		temp->f = mx_mod;
		*flag_oper = true;
	}
	else {
		*error = INCORRECT_OPERATION;
		*flag_error = true;
	}
}

void print_error(enum e_error *error) {
	switch(*error) {
		case INCORRECT_OPERAND:
			mx_printerr("error: invalid number\n");
			exit(-1);
		case INCORRECT_OPERATION:
			mx_printerr("error: invalid operation\n");
			exit(-1);
		case DIV_BY_ZERO:
			mx_printerr("error: division by zero\n");
			exit(-1);
	}
}

void print_value(int num1, int num2, enum e_operation *oper, t_operation *temp) {
	switch(*oper) {
		case ADD:
			mx_printint(temp->f(num1, num2));
			break;
		case SUB:
			mx_printint(temp->f(num1, num2));
			break;
		case MUL:
			mx_printint(temp->f(num1, num2));
			break;
		case DIV:
			mx_printint(temp->f(num1, num2));
			break;
		case MOD:
			mx_printint(temp->f(num1, num2));
			break;
	}
	mx_printchar('\n');
}

int main(int argc, char *argv[]){
	if (argc != 4) {
		mx_printerr("usage: ./calc [operand1] [operation] [operand2]\n");
		exit(-1);
	}
	t_operation temp;
	enum e_operation oper;
	enum e_error error;
	int num1 = mx_atoi(argv[1]);
	int num2 = mx_atoi(argv[3]);
	bool flag_oper = false;
	bool flag_error = false;
	check_operand(num1, num2, argv, &flag_error, &error);
	check_operations(argv, &flag_oper, &flag_error, &temp, &error, &oper);
	if (num2 == 0 && (oper == DIV || oper == MOD)) {
		error = DIV_BY_ZERO;
		flag_error = true;
	}
	if (flag_error)
		print_error(&error);
	if (flag_oper)
		print_value(num1, num2, &oper, &temp);
	exit(0);
}
