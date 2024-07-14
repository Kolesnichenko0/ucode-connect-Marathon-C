#include "list.h"

bool mx_compare_artist(void *a, void *b) {
    char *acurr = mx_strnew(mx_strlen(((t_song *)a)->artist));
    char *bcurr = mx_strnew(mx_strlen(((t_song *)b)->artist));
    mx_strcpy(a, ((t_song *)a)->artist);
    mx_strcpy(a, ((t_song *)b)->artist);
    for (int i = 0; acurr[i] != '\0' ; ++i) {
        acurr[i] = mx_tolower(acurr[i]);
    }
    for (int i = 0; bcurr[i] != '\0' ; ++i) {
        bcurr[i] = mx_tolower(acurr[i]);
    }
    //bool check;
    //if (mx_strcmp(acurr, bcurr) > 0)
    //    check = true;
    //else
    //    check = false;
    bool check = mx_strcmp(acurr, bcurr) == 0;
    free(acurr);
    free(bcurr);
    return check;
}
