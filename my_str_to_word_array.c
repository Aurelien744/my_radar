/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** Day08
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int my_word(char letter)
{
    if ((letter >= 'a' && letter <= 'z') ||
        (letter >= 'A' && letter <= 'Z') ||
        (letter >= '0' && letter <= '9'))
        return (0);
    else
        return (1);
}

int count_letter(char *str)
{
    int size = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        size++;
    }
    return (size);
}

static char **end_tab(char **tab, int x, int y)
{
    tab[x][y] = '\0';
    x++;
    tab[x] = NULL;
    return (tab);
}

char **put_tab(char *str, char **tab)
{
    int x = 0;
    int y = 0;
    int j = 0;

    for (; my_word(str[j]) == 1 && str[j] != '\0'; j++);
    for (; str[j] != '\0'; j++) {
        if ((my_word(str[j]) == 1) && (my_word(str[j + 1]) == 1)) {
            continue;
        }
        if ((my_word(str[j]) == 1)) {
            tab[x][y] = '\0';
            x++;
            y = 0;
        } else {
            tab[x][y] = str[j];
            y++;
        }
    }
    tab = end_tab(tab, x, y);
    return tab;
}

char **my_str_to_word_array(char *str)
{
    char **tab = NULL;
    int word_nb = 1;
    int size = 0;

    if (str[0] == '\0') {
        tab = malloc(sizeof(char *) *1);
        tab[0] = NULL;
        return (tab);
    }
    for (int i = 0; str[i] != '\0'; i++)
        if (i != 0 && (my_word(str[i]) == 0) && (my_word(str[i - 1]) == 1))
            word_nb++;
    tab = malloc(sizeof(char *) * (word_nb + 1));
    tab[word_nb] = 0;
    size = count_letter(str);
    for (int j = 0; j < word_nb; j++)
        tab[j] = malloc(sizeof(char) *(size + 1));
    if (word_nb != 0)
        tab = put_tab(str, tab);
    return (tab);
}
