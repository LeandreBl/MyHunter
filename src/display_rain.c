/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** display rain
*/

#include "my_hunter.h"

void		display_rain(window_t *window, misc_t *misc)
{
  static double	a;
  sfVector2f	scale;

  scale.x = (double)window->width / 800.0;
  scale.y = (double)window->height / 600.0;
  put_sprite_resize(window, misc->misc[9],
		    xy_vectorf(0, a), scale);
  put_sprite_resize(window, misc->misc[9],
		    xy_vectorf(0, a - window->height),
		    scale);
  a = a + 10;
  if (a > window->height)
    a = 0;
}
