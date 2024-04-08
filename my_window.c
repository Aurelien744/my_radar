/*
** EPITECH PROJECT, 2023
** my_window
** File description:
** my_radar
*/

#include "./include/struct.h"
#include "./include/my.h"
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdlib.h>

void background(window_t *window)
{
    window->tex = sfTexture_createFromFile("./carte1.png", NULL);
    window->spr = sfSprite_create();
    sfSprite_setTexture(window->spr, window->tex, sfTrue);
    sfSprite_setScale(window->spr, (sfVector2f){1.5, 1.65});
}

void render(window_t *window)
{
    sfRenderWindow_clear(window->window, sfBlack);
    sfRenderWindow_drawSprite(window->window, window->spr, NULL);
    drawing_circles(window);
    drawing_plane(window);
    sfRenderWindow_display(window->window);
}

void close_window(window_t *window)
{
    if (window->event.type == sfEvtClosed)
        sfRenderWindow_close(window->window);
}

void time_gestion(window_t *window)
{
    window->elapsed = sfClock_getElapsedTime(window->clock);
    if (sfTime_asSeconds(window->elapsed) > 0.01) {
        window->total = window->total + sfTime_asSeconds(window->elapsed);
        sfClock_restart(window->clock);
        updt_plane_bl(window);
    }
}

static void destroy(window_t *window)
{
    sfSprite_destroy(window->spr);
    sfTexture_destroy(window->tex);
}

int create_window(window_t *window)
{
    window->mode.width = 1920;
    window->total = 0;
    window->mode.height = 1080;
    window->mode.bitsPerPixel = 32;
    window->window = sfRenderWindow_create(window->mode, "my_radar", sfClose |
    sfResize, NULL);
    window->clock = sfClock_create();
    background(window);
    while (sfRenderWindow_isOpen(window->window)) {
        while (sfRenderWindow_pollEvent(window->window, &window->event))
            close_window(window);
        time_gestion(window);
        render(window);
    }
    destroy(window);
    sfRenderWindow_destroy(window->window);
    sfClock_destroy(window->clock);
    free(window);
    return 0;
}
