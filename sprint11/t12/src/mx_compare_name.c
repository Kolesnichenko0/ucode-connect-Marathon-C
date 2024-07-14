#include "list.h"

bool mx_compare_name(void *a, void *b) {
    char *acu = mx_strnew(mx_strlen(((t_song *)a)->name));
    char *bcu = mx_strnew(mx_strlen(((t_song *)b)->name));
    mx_strcpy(acu, ((t_song *)a)->name);
    mx_strcpy(bcu, ((t_song *)b)->name);
    int i = 0;
    while(acu[i]) {
        acu[i] = mx_tolower(acu[i]);
        i++;
    }
    i = 0;
    while(bcu[i]) {
        bcu[i] = mx_tolower(bcu[i]);
        i++;
    }
    bool check;
    if (mx_strcmp(acu, bcu) > 0)
        check = true;
    else
        check = false;
    free(acu);
    free(bcu);
    return check;
}
