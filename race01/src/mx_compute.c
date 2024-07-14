#include "../inc/header.h"

void mx_compute(char *operand1, char *operand2, char *result_str, char operation) {
	if (operation == '?') {
		mx_compute(operand1, operand2, result_str, '+');
		mx_compute(operand1, operand2, result_str, '-');
		mx_compute(operand1, operand2, result_str, '*');
		mx_compute(operand1, operand2, result_str, '/');
	}
	int op1_size = mx_strlen(operand1);
	int op2_size = mx_strlen(operand2);
	int result_size = mx_strlen(result_str);
	bool op1_negative = false;
	bool op2_negative = false;
	bool result_negative = false;
	long long num1 = mx_atoi(operand1);
	long long num2 = mx_atoi(operand2);
	long long result = mx_atoi(result_str);
	if (operand1[0] == '+' || operand1[0] == '-') {
		if(operand1[0] == '-')
			op1_negative = true;
		operand1++;
		op1_size--;
	}
	if (operand2[0] == '+' || operand2[0] == '-') {
		if(operand2[0] == '-')
			op2_negative = true;
		operand2++;
		op2_size--;
	}
	if (result_str[0] == '+' || result_str[0] == '-') {
		if(result_str[0] == '-')
			result_negative = true;
		result_str++;
		result_size--;
	}
	for (long long i = 0; i < mx_pow(10, op1_size); i++) {
		if (num1 > 0)
			i = num1;
		char *temp1 = mx_itoa(i);
		int difference = op1_size - mx_strlen(temp1);
		bool check = true;
		for (int count = 0; count < difference; count++) {
			if (mx_isdigit(operand1[count]) && operand1[count] != '0') {
				check = false;
				break;
			}
		}
		for (int count = difference; count < op1_size; count++) {
			if (operand1[count] != '?' && operand1[count] != temp1[count - difference]) {
				check = false;
				break;
			}
		}
		free(temp1);
		temp1 = NULL;
		if (!check)
			continue;
		for (long long j = 0; j < mx_pow(10, op2_size); j++) {
			if (num2 > 0)
				j = num2;
			char *temp2 = mx_itoa(j);
			difference = op2_size - mx_strlen(temp2);
			check = true;
			for (int count = 0; count < difference; count++) {
				if (mx_isdigit(operand2[count]) && operand2[count] != '0') {
					check = false;
					break;
				}
            		}
			for (int count = difference; count < op2_size; count++) {
				if (operand2[count] != '?' && operand2[count] != temp2[count - difference]) {
					check = false;
					break;
				}
			}
			free(temp2);
			temp2 = NULL;
			if (!check)
				continue;
			for (long long g = 0; g < mx_pow(10, result_size); g++) {
				if (result > 0) 
					g = result;
				char *temp3 = mx_itoa(g);
				difference = result_size - mx_strlen(temp3);
				check = true;
				for (int count = 0; count < difference; count++) {
					if (mx_isdigit(result_str[count]) && result_str[count] != '0') {
						check = false;
						break;
					}
				}
                		for (int count = difference; count < result_size; count++) {
					if (result_str[count] != '?' && result_str[count] != temp3[count - difference]) {
						check = false;
						break;
					}
				}
				free(temp3);
				temp3 = NULL;
				if (!check) 
					continue;
				if (op1_negative)
					i *= -1;
				if (op2_negative)
					j *= -1;
				if (result_negative)
					g *= -1;
				if (operation == '+') {
					if (i + j == g) {
						mx_printnum(i);
						mx_printstr(" + ");
						mx_printnum(j);
						mx_printstr(" = ");
						mx_printnum(g);
						mx_printchar('\n');
					}
				}
				else if (operation == '-') {
					if (i - j == g) {
						mx_printnum(i);
						mx_printstr(" - ");
						mx_printnum(j);
						mx_printstr(" = ");
						mx_printnum(g);
						mx_printchar('\n');
					}
				}
				else if (operation == '*') {
					if (i * j == g) {
						mx_printnum(i);
						mx_printstr(" * ");
						mx_printnum(j);
						mx_printstr(" = ");
						mx_printnum(g);
						mx_printchar('\n');
					}
				}
				else if (operation == '/') {
					if (j != 0 && i / j == g) {
						mx_printnum(i);
						mx_printstr(" / ");
						mx_printnum(j);
						mx_printstr(" = ");
						mx_printnum(g);
						mx_printchar('\n');
					}
				}
				if (op1_negative)
					i *= -1;
				if (op2_negative)
					j *= -1;
				if (result_negative)
					g *= -1;
				if (result > 0) 
					break;
				}
			if (num2 > 0)
				break;
		}
		if (num1 > 0)
			break;
	}
	if (op1_negative)
		operand1--;
	if (op2_negative)
		operand2--;
	if (result_negative)
        	result--;
}
