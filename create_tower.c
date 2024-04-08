/*
** EPITECH PROJECT, 2023
** create_tower
** File description:
** my_radar
*/

#include "./include/struct.h"
#include "./include/my.h"
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdlib.h>

void drawing_circles(window_t *window)
{
    tower_t *current = window->tower;

    while (current != NULL) {
        sfRenderWindow_drawCircleShape(window->window, current->circle, NULL);
        sfRenderWindow_drawSprite(window->window,
        current->spr_tower, NULL);
        current = current->next;
    }
}

sfCircleShape *create_circle(sfVector2f position, float radius)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setPosition(circle, position);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOrigin(circle, (sfVector2f){radius, radius});
    sfCircleShape_setOutlineThickness(circle, 1.0);
    sfCircleShape_setOutlineColor(circle, sfGreen);
    return (circle);
}

sfSprite *spr_tower(float positionx, float positiony)
{
    sfTexture *tex_tower = sfTexture_createFromFile("./tower.png", NULL);
    sfSprite *spr_tower = sfSprite_create();

    sfSprite_setTexture(spr_tower, tex_tower, sfTrue);
    sfSprite_setPosition(spr_tower, (sfVector2f){positionx, positiony});
    sfSprite_setOrigin(spr_tower, (sfVector2f){(512 / 2), (512 / 2)});
    sfSprite_setScale(spr_tower, (sfVector2f) {0.15, 0.15});
    return (spr_tower);
}
