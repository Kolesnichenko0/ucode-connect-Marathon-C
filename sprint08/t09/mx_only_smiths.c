#include "only_smiths.h"

t_agent **mx_only_smiths(t_agent **agents, int strength) {
	if (agents == NULL)
		return NULL;
	int new_size = 0;
	for (int i = 0; agents[i] != NULL; i++)
		if(mx_strcmp(agents[i]->name, "Smith") == 0 &&
			       agents[i]->strength < strength)
			new_size++;
	t_agent **new_agents = malloc(sizeof(t_agent*) * new_size + 1);
	new_size = 0;
	for (int i = 0; agents[i] != NULL; i++)
		if (mx_strcmp(agents[i]->name, "Smith") == 0 &&
			       agents[i]->strength < strength) {
			new_agents[new_size] = mx_create_agent(agents[i]->name, agents[i]->power, agents[i]->strength);
			new_size++;
		}
	new_agents[new_size] = NULL;
	mx_exterminate_agents(&agents);
	return new_agents;
}

