/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** background 
*/

#include "my_hunter.h"

void		display_background(window_t *window, misc_t *misc)
{
  sfVector2f	size;
  sfVector2u	bg;

  bg = sfTexture_getSize(misc->misc[0]->texture);
  size.x = (double)window->width / (double)bg.x;
  size.y = (double)window->height / (double)bg.y;
  put_sprite_resize(window, misc->misc[0], ORIGIN, size);
}
