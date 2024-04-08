/*
** EPITECH PROJECT, 2024
** deleting_node
** File description:
** my_radar
*/

#include "./include/struct.h"
#include "./include/my.h"
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdlib.h>

void delete_bl(window_t *window, plane_t *delete)
{
    plane_t *prev;
    plane_t **head = &window->plane;

    if (*head == delete) {
        *head = delete->next;
    } else {
        prev = *head;
        while (prev->next && prev->next != delete) {
            prev = prev->next;
        }
        if (prev->next) {
            prev->next = delete->next;
        }
    }
    sfSprite_destroy(delete->spr_plane);
    sfTexture_destroy(delete->tex_plane);
    sfRectangleShape_destroy(delete->rect);
    free(delete);
}
