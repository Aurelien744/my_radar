/*
** EPITECH PROJECT, 2023
** main
** File description:
** my_radar
*/

#include "./include/my.h"
#include "./include/struct.h"
#include <stdlib.h>
#include <unistd.h>

void display_usage(void)
{
    write(1, "Air traffic simulation panel\n\nUSAGE\n ./my_radar [OPTIONS] "
    "path_to_script\n  path_to_script\tThe path to the script file.\n\n"
    "OPTIONS\n -h\t\tprint the usage and quit.\n\n", 161);
}

int init_struct(window_t *window)
{
    window->plane = NULL;
    window->tower = NULL;
}

int main(int ac, char **av)
{
    window_t *window = malloc(sizeof(window_t));

    if (ac != 2) {
        error_open();
        return (84);
    }
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        display_usage();
        return (0);
    }
    init_struct(window);
    if (parsing_files(av, window) == 84)
        return 84;
    create_window(window);
}
