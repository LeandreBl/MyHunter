/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** background 
*/

#include "my_hunter.h"

#include "my.h"
#include "defines.h"

void		display_grass(window_t *window, misc_t *misc)
{
  sfVector2f	scale;
  sfVector2u	size;

  size = sfTexture_getSize(misc->misc[3]->texture);
  scale.x = (double)window->width / (double)size.x;
  scale.y = (double)window->height / (double)size.y;
  put_sprite_resize(window, misc->misc[3], ORIGIN, scale);
}

void		display_ducks(window_t *window, misc_t *misc)
{
  int		i;
  vect_t	*duck;

  i = 0;
  while (i < misc->ducks.size)
  {
    duck = &misc->ducks.ducks[i];
    if (duck->status != dead && duck->id >= 0)
      put_sprite(window, misc->duck[duck->type][duck->id], duck->pos);
    ++i;
  }
}

void		display_bushes(window_t *window, misc_t *misc)
{
  sfVector2f	pos;
  sfVector2f	scale;
  sfVector2u	size;

  pos.x = (window->width / 2 - window->mouse.x) / 20 - 20;
  pos.y = (window->height / 2 - window->mouse.y) / 20 - 20;
  size = sfTexture_getSize(misc->misc[0]->texture);
  scale.x = (double)window->width / (double)size.x;
  scale.y = (double)window->height / (double)size.y;
  put_sprite_resize(window, misc->misc[2], pos, scale);
}

void		display_cursor(window_t *window, misc_t *misc)
{
  sfVector2f	pos;
  sfVector2u	size;

  size = sfTexture_getSize(misc->misc[1]->texture);
  pos.x = window->mouse.x - size.x / 2;
  pos.y = window->mouse.y - size.y / 2;
  put_sprite(window, misc->misc[1], pos);
}

void		display_background(window_t *window, misc_t *misc)
{
  sfVector2f	scale;
  sfVector2u	size;

  size = sfTexture_getSize(misc->misc[0]->texture);
  scale.x = (double)window->width / (double)size.x;
  scale.y = (double)window->height / (double)size.y;
  put_sprite_resize(window, misc->misc[0], ORIGIN, scale);
}
