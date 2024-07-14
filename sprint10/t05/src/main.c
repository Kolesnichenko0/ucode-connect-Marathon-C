#include "header.h"

int main(int argc, char *argv[]) {
	if (argc != 3 || (( mx_strcmp(argv[1], "-n") != 0) &&
				(mx_strcmp(argv[1], "-s") != 0) &&
				(mx_strcmp(argv[1], "-p") != 0))) {
		mx_printerr("usage: ./parse_agents [-p | -s | -n] [file_name]\n");
		exit(1);
	}
	char *src = mx_file_to_str(argv[2]);
	if (src == NULL) {
		mx_printerr("error\n");
		exit(1);
	}
	int count = mx_count_agents(src);
	if (count == -1) {
		mx_printerr("error\n");
		exit(1);
	}
	t_agent **agent_kit = mx_parse_agents(src, count);
	mx_sort_agents(&agent_kit, argv[1], count);
	for (int i = 0; agent_kit[i] != NULL; i++) {
		mx_printstr("agent: ");
		mx_printstr(agent_kit[i]->name);
		mx_printstr(", strength: ");
		mx_printint(agent_kit[i]->strength);
		mx_printstr(", power: ");
		mx_printint(agent_kit[i]->power);
		mx_printchar('\n');
	}
	exit(0);
}

