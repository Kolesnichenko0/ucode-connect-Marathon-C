#include "list.h"

void mx_pop_index(t_list **list, int index) {
    if (list == NULL || *list == NULL)
        return;
    int count = 0;
    t_list *curr = *list;
    while(curr != NULL) {
        curr = curr->next;
        count++;
    }
    if (index >= count - 1) {
        mx_pop_back(list);
        return;
    }
    if (index < 1) {
        mx_pop_front(list);
        return;
    }
    curr = *list;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    t_list *temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
}
