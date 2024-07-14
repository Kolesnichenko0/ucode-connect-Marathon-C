#include "create_new_agents.h"

t_agent *mx_create_agent(char *name, int power, int strength) {
	if (name == NULL)
		return NULL;
	t_agent *new_agent = malloc(sizeof(t_agent*));
	if (new_agent == NULL)
		return NULL;
	new_agent->power = power;
	new_agent->strength = strength;
	new_agent->name = mx_strdup(name);
	return new_agent;
}

