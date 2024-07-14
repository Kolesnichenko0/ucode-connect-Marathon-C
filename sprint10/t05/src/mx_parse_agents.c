#include "header.h"

t_agent **mx_parse_agents(char *src, int count) {
	if(src == NULL)
		return NULL;
	t_agent **dst = (t_agent **)malloc(sizeof(t_agent *) * count + 1);
	dst[count] = NULL;
	int power;
	int strength;
	int counter;
	char *name = NULL;
	for (int i = 0; i < count; i++) {
		src = mx_strstr(src, "name: ");
		src += 6;
		for(counter = 0; src[counter] != '\n'; counter++);
		name = mx_strnew(counter);
		name = mx_strncpy(name, src, counter);

		src = mx_strstr(src, "power: ");
		src += 7;
		power = mx_atoi(src);

		src = mx_strstr(src, "strength: ");
		src += 10;
		strength = mx_atoi(src);
		dst[i] = mx_create_agent(name, power, strength);
	}
	return dst;
}
		
		

		
