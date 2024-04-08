/*
** EPITECH PROJECT, 2023
** updt_plane_pos
** File description:
** my_radar
*/

#include "./include/struct.h"
#include "./include/my.h"
#include <SFML/Graphics.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

sfVector2f vector(sfVector2f start, sfVector2f end)
{
    sfVector2f dir = {end.x - start.x, end.y - start.y};
    float magnitude = sqrt(dir.x * dir.x + dir.y * dir.y);

    if (magnitude != 0) {
        return (sfVector2f){dir.x / magnitude, dir.y / magnitude};
    } else {
        return (sfVector2f){0, 0};
    }
}

void rotation(plane_t *cur)
{
    float angle;

    angle = atan2f(cur->direction.y, cur->direction.x)
    * 180.0f / M_PI;
    sfSprite_setRotation(cur->spr_plane, angle);
    sfRectangleShape_setRotation(cur->rect, angle);
    sfRectangleShape_setPosition(cur->rect,
    (sfVector2f){cur->depx, cur->depy});
}

int plane_bhvr(plane_t *cur, window_t *window, plane_t *tmp, sfVector2f pos)
{
    if (window->total >= cur->delay) {
        if (cur->depx >= 0 && cur->depx <= cur->arrx && cur->depy >= 0 &&
        cur->depy <= cur->arry) {
            tmp = cur->next;
            delete_bl(window, cur);
            cur = tmp;
            return (1);
        } else {
            cur->depx += cur->direction.x * (cur->speed / 10);
            cur->depy += cur->direction.y * (cur->speed / 10);
            pos = (sfVector2f){cur->depx, cur->depy};
            cur->rect = create_rectangle(pos);
            cur->spr_plane = spr_plane(cur->depx, cur->depy,
            cur->spr_plane, cur->tex_plane);
            rotation(cur);
        }
    }
}

void updt_plane_bl(window_t *window)
{
    plane_t *cur = window->plane;
    plane_t *tmp;
    sfVector2f pos;

    while (cur != NULL) {
        if (plane_bhvr(cur, window, tmp, pos) == -1)
            continue;
        cur = cur->next;
    }
}
