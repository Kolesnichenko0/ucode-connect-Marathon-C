#include "list.h"

void mx_printPlaylist(t_list *list) {
    int index = 0;
    t_list *curr = list;
    while (curr != NULL) {
        mx_printint(index);
        mx_printstr(". ");
        mx_printstr(((t_song *)curr->data)->artist);
        mx_printstr(" - ");
        mx_printstr(((t_song *)curr->data)->name);
        mx_printchar('\n');
        curr = curr->next;
        index++;
    }
}
