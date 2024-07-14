#include "header.h"

static int mx_search_dist(int height, int width, s_struct map[height][width]){
    int count = 1;

    while (true) {
        int check = 1;
        count++;
        for (int j = 0; j < width; j++) {
            for (int i = 0; i < height; i++) {
                if (map[i][j].label == count - 1) {
                    check = 0;
                    if (j < width && map[i][j + 1].label == 0 && map[i][j + 1].sym == '.')
                        map[i][j + 1].label = count;
                    if (j > 0 && map[i][j - 1].label == 0 && map[i][j - 1].sym == '.')
                        map[i][j - 1].label = count;
                    if (i < height && map[i + 1][j].label == 0 && map[i + 1][j].sym == '.')
                        map[i + 1][j].label = count;
                    if (i > 0 && map[i - 1][j].label == 0 && map[i - 1][j].sym == '.')
                        map[i - 1][j].label = count;
                }
            }
        }

        if (check == 1) return count - 3;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if(argc != 6) {       
        mx_printerr("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n");
        exit(0);
    }

    char buf;
    int width = 0, height = 0;

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        mx_printerr("map does not exist\n");
        exit(1);
    }

    int max_j;
    int caught_chars = 0;
    bool check = false;
    int n_read;

    while ((n_read = read(fd, &buf, 1))) {
        if (n_read == -1) {
            mx_printerr("error\n");
            exit(1);
        }
        if (buf != '#' && buf != '.' && buf != ',' && buf != '\n') {
            mx_printerr("map error\n");
            exit(1);
        }
        if (buf == ',') {
            continue;
        }
        if (buf == '\n') {
            if (!check) {
                check  = true;
                max_j = width;
            }
            else {
                if (width != max_j) {
                    mx_printerr("map error\n");
                    exit(1);
                }
            }
            height++;
            width = 0;
            continue;
        }
        width++;
        caught_chars++;
    }
    width = max_j;
    if (height * width != caught_chars) {
        mx_printerr("map error\n");
        exit(1);
    }
    if (close(fd) == -1) {
        mx_printerr("error\n");
        exit(1);
    }
    int x1 = mx_atoi(argv[2]);
    int y1 = mx_atoi(argv[3]);
    int x2 = mx_atoi(argv[4]);
    int y2 = mx_atoi(argv[5]);

    if (y1 > height || x1 > width || y1 < 0 || x1 < 0 
        || y2 > height || x2 > width || y2 < 0 || x2 < 0) {
        mx_printerr("points are out of map range\n");
        exit(1);
    }

    s_struct map[height][width];

    fd = open(argv[1], O_RDONLY);
    int i = 0;
    int j = 0;
    while (read(fd, &buf, 1)) {
        if (buf == ',') continue;
        if (buf == '\n') {
            i++;
            j = 0;
            continue;
        }
        map[i][j].sym = buf;
        if (buf == '.') map[i][j].label = 0;
        if (buf == '#') map[i][j].label = -1;
        j++;
    }
    if (close(fd) == -1) {
        mx_printerr("error\n");
        exit(1);
    }

    if (map[y1][x1].sym != '.') {
        mx_printerr("entry point cannot be an obstacle\n");
        exit(1);
    }

    if (map[y2][x2].sym != '.') {
        mx_printerr("exit point cannot be an obstacle\n");
        exit(1);
    }

    map[y1][x1].label = 1;

    int dist = mx_search_dist(height, width, map);

    if (map[y2][x2].label == 0) {
        mx_printerr("route not found\n");
        exit(-1);
    }

    mx_printstr("dist=");
    mx_printint(dist);
    mx_printstr("\nexit=");
    mx_printint(map[y2][x2].label - 1);
    mx_printstr("\n");

    mx_building_path(y2, x2, height, width, map, dist);

    int file_write = open("path.txt", O_RDONLY);
    file_write = open("path.txt", O_WRONLY | O_CREAT);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            write(file_write, &map[i][j].sym, 1);
        }
        write(file_write, "\n", 1);
    }
    if (close(file_write) < 0) {
        mx_printerr("error\n");
        exit(-1);            
    }
    close(file_write);
}
