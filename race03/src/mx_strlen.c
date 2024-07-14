#include "header.h"

int mx_strlen(char *s){
	 int size = 0;
	 for(char *i = s; *i != '\0'; i++)
		 size++;
	 return size;
}
