#include "list.h"

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b)) {
    if (list == NULL || cmp == NULL)
        return list;
    int size = 0;
    t_list *curr = list;
    while (curr != NULL) {
        curr = curr->next;
        size++;
    }
    int check = 0;
    while (check == 0) {
        check = 1;
        curr = list;
        for (int i = 0; i < size - 1; i++) {
            if (cmp(curr->data, curr->next->data)) {
                void *temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
                check = 0;
            }
            curr = curr->next;
        }
    }
    return list;
}
