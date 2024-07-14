#include "list.h"

void mx_push_index(t_list **list, void *data, int index) {
    if(list == NULL || *list == NULL) {
        mx_create_node(data);
        return;
    }
    if (index < 1) {
        mx_push_front(list, data);
        return;
    }
    int count = 0;
    t_list *temp_size = *list;
    while (temp_size != NULL) {
        temp_size = temp_size->next;
        count++;
    }
    if (index >= count) {
        mx_push_back(list,data);
        return;
    }
    t_list *curr = *list;
    t_list *temp = NULL;
    for (int i = 0; i < index; i++) {
        temp = curr;
        curr = curr->next;
    }
    temp->next = mx_create_node(data);
    temp->next->next = curr;
}
