#include "header.h"

void mx_building_path(int y2, int x2, int height, int width, s_struct map[height][width], int dist) {
    int index_y = y2, index_x = x2;
    map[y2][x2].sym = '*';
    while (map[index_y][index_x].label != 1) {
        int temp = map[index_y][index_x].label - 1;
        if (map[index_y][index_x - 1].label == temp && index_x > 0) {
            map[index_y][index_x - 1].sym = '*';
            index_x--;
        }
        if (map[index_y][index_x + 1].label == temp) {
            map[index_y][index_x + 1].sym = '*';
            index_x++;
        }
        if (map[index_y - 1][index_x].label == temp && index_y > 0) {
            map[index_y - 1][index_x].sym = '*';
            index_y--;
        }
        if (map[index_y + 1][index_x].label == temp) {
            map[index_y + 1][index_x].sym = '*';
            index_y++;
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (map[i][j].label == dist + 1 && map[i][j].sym == '*') {
                map[i][j].sym = 'X';
            }
            if (map[i][j].label == dist + 1 && map[i][j].sym == '.') {
                map[i][j].sym = 'D';
            }
        }
    }
}

