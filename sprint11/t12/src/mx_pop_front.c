#include "list.h"

void mx_pop_front(t_list **list) {
    if (*list == NULL || list == NULL)
        return;
    if ((*list)->next == NULL) {
        free(*list);
        *list = NULL;
        return;
    }
    t_list *curr = *list;
    *list = curr->next;
    free(curr);
    curr = NULL;
}

