#include "list.h"

void mx_push_front(t_list **list, void *data) {
	if (*list == NULL || list == NULL) {
		*list = mx_create_node(data);
		return;
	}
	t_list *first = mx_create_node(data);
	first->next = *list;
	*list = first;
}

