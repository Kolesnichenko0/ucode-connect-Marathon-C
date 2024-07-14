#include "create_new_agents.h"

t_agent **mx_create_new_agents(char **name, int *power, int *strength, int count) {
	if (name == NULL || 
		power == NULL ||
		strength == NULL ||
		count < 0)
		return NULL;
	t_agent **new_agents = malloc(sizeof(t_agent*) * count + 1);
	if (new_agents == NULL)
		return NULL;
	for (int i = 0; i < count; i++)
		new_agents[i] = mx_create_agent(name[i], power[i], strength[i]);
	new_agents[count] = NULL;
	return new_agents;
}

