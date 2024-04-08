/*
** EPITECH PROJECT, 2023
** my_purchar.c
** File description:
** Day03
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
