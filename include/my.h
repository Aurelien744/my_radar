/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my_radar
*/

#include "./struct.h"

#ifndef MY_H_
    #define MY_H_

int create_window(window_t *window);
char **my_str_to_word_array(char *str);
int my_getnbr(char const *str);
int parsing_files(char **av, window_t *window);
int bot_left(char **stat, plane_t **head);
int display_circles(window_t *window);
sfCircleShape *create_circle(sfVector2f position, float radius);
void drawing_circles(window_t *window);
sfRectangleShape *create_rectangle(sfVector2f position);
void drawing_plane_bl(window_t *window);
void drawing_plane(window_t *window);
sfSprite *spr_tower(float positionx, float positiony);
sfSprite *spr_plane(float posx, float posy, sfSprite *spr, sfTexture *tex);
void time_gestion(window_t *window);
void updt_plane_bl(window_t *window);
sfVector2f vector(sfVector2f start, sfVector2f end);
void delete_bl(window_t *window, plane_t *delete);
void background(window_t *window);
void my_putchar(char c);
void error_open(void);

#endif
