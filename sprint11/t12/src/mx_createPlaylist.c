#include "list.h"

t_list *mx_createPlaylist(char *filename){
    t_list *list = NULL;
    char *fileStr = mx_file_to_str(filename);
    if (fileStr == NULL){
        mx_printerr("ERROR\n");
        return list;
    }
    char **songs = mx_strsplit(fileStr, '\n');
    for (int i = 0; songs[i] != NULL ; ++i) {
        char **buf = mx_strsplit(songs[i], ',');
        t_song *song = malloc(sizeof(t_song));
        song->artist = buf[0];
        song->name = buf[1];

        mx_push_back(&list, (void *)song);
    }

    free(fileStr);
    fileStr = NULL;
    return list;
}
