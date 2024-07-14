#include "list.h"

void mx_pop_back(t_list **list) {
    if(*list == NULL || list == NULL)
        return;

    if ((*list)->next == NULL) {
        free(*list);
        *list = NULL;
        return;
    }

    t_list *curr = *list;
    while(curr->next->next != NULL)
        curr = curr->next;
    free(curr->next);
    curr->next = NULL;
    curr = NULL;
}
