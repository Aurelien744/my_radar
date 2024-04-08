/*
** EPITECH PROJECT, 2023
** struct.h
** File description:
** my_radar
*/

#include <SFML/Graphics.h>

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct plane_s {
    int depx;
    int depy;
    int arrx;
    int arry;
    int speed;
    int delay;
    sfVector2f direction;
    sfSprite *spr_plane;
    sfTexture *tex_plane;
    sfRectangleShape *rect;
    struct plane_s *next;
} plane_t;

typedef struct tower_s {
    int posx;
    int posy;
    int radius;
    sfCircleShape *circle;
    sfSprite *spr_tower;
    struct tower_s *next;
} tower_t;

typedef struct window_s {
    float total;
    sfSprite *spr;
    sfTexture *tex;
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    sfTime elapsed;
    sfClock *clock;
    tower_t *tower;
    plane_t *plane;
}window_t;

#endif
