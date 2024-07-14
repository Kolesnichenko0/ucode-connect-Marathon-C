#include "header.h"

void mx_sort_agents(t_agent ***agent_kit, char *flag, int count) {
	int check = 1;
	int p_buf, s_buf;
	char *n_buf;
	if (!mx_strcmp(flag, "-p")) {
		while (check == 1) {
			check = 0;
			for (int i = 0; i < count - 1; i++) {
				if((*agent_kit)[i]->power > (*agent_kit)[i + 1]->power) {
					p_buf = (*agent_kit)[i]->power;
					s_buf = (*agent_kit)[i]->strength;
					n_buf = (*agent_kit)[i]->name;
					(*agent_kit)[i]->power = (*agent_kit)[i + 1]->power;
					(*agent_kit)[i]->strength = (*agent_kit)[i + 1]->strength;
					(*agent_kit)[i]->name = (*agent_kit)[i + 1]->name;
					(*agent_kit)[i + 1]->power = p_buf;
					(*agent_kit)[i + 1]->strength = s_buf;
					(*agent_kit)[i + 1]->name = n_buf;
					check = 1;
				}
			}
		}
	}
	else if (!mx_strcmp(flag, "-s")) {
		while (check == 1) {
			check = 0;
			for (int i = 0; i < count - 1; i++) {
				if((*agent_kit)[i]->strength > (*agent_kit)[i + 1]->strength) {
					p_buf = (*agent_kit)[i]->power;
					s_buf = (*agent_kit)[i]->strength;
					n_buf = (*agent_kit)[i]->name;
					(*agent_kit)[i]->power = (*agent_kit)[i + 1]->power;
					(*agent_kit)[i]->strength = (*agent_kit)[i + 1]->strength;
					(*agent_kit)[i]->name = (*agent_kit)[i + 1]->name;
					(*agent_kit)[i + 1]->power = p_buf;
					(*agent_kit)[i + 1]->strength = s_buf;
					(*agent_kit)[i + 1]->name = n_buf;
					check = 1;
				}
			}
		}
	}
	else if (!mx_strcmp(flag, "-n")) {
		while (check == 1) {
			check = 0;
			for (int i = 0; i < count - 1; i++) {
				if(mx_strcmp((*agent_kit)[i]->name, (*agent_kit)[i + 1]->name) > 0) {
					p_buf = (*agent_kit)[i]->power;
					s_buf = (*agent_kit)[i]->strength;
					n_buf = (*agent_kit)[i]->name;
					(*agent_kit)[i]->power = (*agent_kit)[i + 1]->power;
					(*agent_kit)[i]->strength = (*agent_kit)[i + 1]->strength;
					(*agent_kit)[i]->name = (*agent_kit)[i + 1]->name;
					(*agent_kit)[i + 1]->power = p_buf;
					(*agent_kit)[i + 1]->strength = s_buf;
					(*agent_kit)[i + 1]->name = n_buf;
					check = 1;
				}
			}
		}
	}
}


