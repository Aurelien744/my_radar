/*
** EPITECH PROJECT, 2023
** parsing
** File description:
** my_radar
*/

#include "./include/struct.h"
#include "./include/my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int tower_list(char **stat, tower_t **head)
{
    tower_t *new_tower = (tower_t *)malloc(sizeof(tower_t));
    sfVector2f pos;

    new_tower->posx = my_getnbr(stat[1]);
    new_tower->posy = my_getnbr(stat[2]);
    new_tower->radius = my_getnbr(stat[3]);
    new_tower->radius = new_tower->radius * 1920 / 100;
    new_tower->next = *head;
    pos = (sfVector2f){new_tower->posx, new_tower->posy};
    new_tower->circle = create_circle(pos, new_tower->radius);
    new_tower->spr_tower = spr_tower(new_tower->posx, new_tower->posy);
    *head = new_tower;
}

int plane_list(char **stat, window_t *window)
{
    int posx = my_getnbr(stat[1]);
    int posy = my_getnbr(stat[2]);

    bot_left(stat, &window->plane);
}

int fill_list(char *line, window_t *window)
{
    char **stat = NULL;

    stat = my_str_to_word_array(line);
    if (stat[0][0] == 'A')
        plane_list(stat, window);
    if (stat[0][0] == 'T')
        tower_list(stat, &window->tower);
}

static int correct_file(char *s)
{
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != 'T' && s[i] != 'A' && s[i] != ' ' &&
        s[i] != '\n' && !(s[i] >= '0' && s[i] <= '9')) {
            write(1, "\nAt least one wrong character"
            "in the script file: '", 50);
            my_putchar(s[i]);
            write(1, "'", 1);
            my_putchar('\n');
            my_putchar('\n');
            return (84);
        }
    }
}

void error_open(void)
{
    write(1, "\nBad file script or bad path given\nRetry with -h\n\n", 50);
}

int parsing_files(char **av, window_t *window)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    file = fopen(av[1], "r");
    if (file == NULL) {
        error_open();
        return (84);
    }
    read = getline(&line, &len, file);
    while (read != -1) {
        if (correct_file(line) == 84)
            return (84);
        fill_list(line, window);
        read = getline(&line, &len, file);
    }
    fclose(file);
    free(line);
}
