/*
** EPITECH PROJECT, 2023
** draw_plane
** File description:
** my_radar
*/

#include "./include/struct.h"
#include "./include/my.h"
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdlib.h>

void drawing_plane_bl(window_t *window)
{
    plane_t *current = window->plane;

    while (current != NULL) {
        if (window->total >= current->delay) {
            sfRenderWindow_drawRectangleShape(window->window,
            current->rect, NULL);
            sfRenderWindow_drawSprite(window->window,
            current->spr_plane, NULL);
        }
        current = current->next;
    }
}

void drawing_plane(window_t *window)
{
    drawing_plane_bl(window);
}
