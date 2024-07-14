#include "list.h"

void mx_write_to_file(t_list *list, char *filename) {
    int fd = open(filename, O_TRUNC | O_WRONLY | O_CREAT | O_APPEND);
    t_list *curr = list;
    while (curr != NULL) {
        write(fd, ((t_song *)curr->data)->artist, mx_strlen(((t_song *)curr->data)->artist));
        write(fd, ",", 1);
        write(fd, ((t_song *)curr->data)->name, mx_strlen(((t_song *)curr->data)->name));
        write(fd, "\n", 1);
        curr = curr->next;
    }
}
