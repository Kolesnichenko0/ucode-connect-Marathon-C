#include "exterminate_agents.h"

void mx_exterminate_agents(t_agent ***agents) {
	if (*agents == NULL)
		return;
	t_agent **temp = *agents;
	for (int i = 0; temp[i] != NULL; i++) {
		free(temp[i]->name);
		temp[i]->name = NULL;
		free(temp[i]);
	}
	free(temp);
	*agents = NULL;
	return;
}

