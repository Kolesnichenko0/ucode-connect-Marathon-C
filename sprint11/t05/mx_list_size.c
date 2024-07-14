#include "list.h"

int mx_list_size(t_list *list) {
    if(list == NULL)
        return 0;
    int count = 0;
    t_list *curr = list;
    while (curr != NULL) {
        curr = curr->next;
        count++;
    }
    return count;
}
