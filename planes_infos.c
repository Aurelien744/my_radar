/*
** EPITECH PROJECT, 2023
** planes_infos
** File description:
** my_radar
*/

#include "./include/struct.h"
#include "./include/my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int bot_left(char **stat, plane_t **head)
{
    plane_t *new_plane = (plane_t *)malloc(sizeof(plane_t));
    sfVector2f pos;

    new_plane->tex_plane = sfTexture_createFromFile("./size.png", NULL);
    new_plane->spr_plane = sfSprite_create();
    new_plane->depx = my_getnbr(stat[1]);
    new_plane->depy = my_getnbr(stat[2]);
    new_plane->arrx = my_getnbr(stat[3]);
    new_plane->arry = my_getnbr(stat[4]);
    new_plane->speed = my_getnbr(stat[5]);
    new_plane->delay = my_getnbr(stat[6]);
    new_plane->next = *head;
    pos = (sfVector2f){new_plane->depx, new_plane->depy};
    new_plane->rect = create_rectangle(pos);
    new_plane->spr_plane = spr_plane(new_plane->depx, new_plane->depy,
    new_plane->spr_plane, new_plane->tex_plane);
    new_plane->direction = vector((sfVector2f){new_plane->depx,
    new_plane->depy}, (sfVector2f){new_plane->arrx, new_plane->arry});
    *head = new_plane;
}
