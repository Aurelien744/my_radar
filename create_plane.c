/*
** EPITECH PROJECT, 2023
** create_plane
** File description:
** my_radar
*/

#include "./include/struct.h"
#include "./include/my.h"
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdlib.h>

sfRectangleShape *create_rectangle(sfVector2f position)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect, (sfVector2f){20, 20});
    sfRectangleShape_setPosition(rect, position);
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineThickness(rect, 1.0);
    sfRectangleShape_setOutlineColor(rect, sfRed);
    sfRectangleShape_setOrigin(rect, (sfVector2f){10, 10});
    return (rect);
}

sfSprite *spr_plane(float posx, float posy, sfSprite *spr, sfTexture *tex)
{
    sfSprite_setTexture(spr, tex, sfTrue);
    sfSprite_setPosition(spr, (sfVector2f){posx, posy});
    sfSprite_setOrigin(spr, (sfVector2f){(10), (10)});
    return (spr);
}
