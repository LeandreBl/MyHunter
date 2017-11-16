/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** display score
*/

#include "my_hunter.h"

#include "my.h"
#include "defines.h"

void		display_score(window_t *window, misc_t *misc)
{
  sfVector2f	pos;
  sfColor	color;
  uint8_t	dim;

  pos.x = 24.0 / 256.0 * window->width;
  pos.y = 206.0 / 240.0 * window->height;
  if (255 - misc->score / 100 < 0)
    dim = 0;
  else
    dim = 255 - misc->score / 100;
  color = sfColor_fromRGBA(255, dim, dim, 100);
  put_number((int)misc->score, pos, window, color);
}

void		display_ammo(window_t *window, misc_t *misc)
{
  window = window;
  misc = misc;
}

void		display_time(window_t *window, misc_t *misc)
{
  sfVector2f	pos;
  char		*time;
  sfColor	color;

  pos.x = 200.0 / 256.0 * window->width;
  pos.y = 206.0 / 240.0 * window->height;
  time = catalloc("%d'%d\"%d", (int)misc->countdown / 60,
		  (int)misc->countdown % 60,
		  (int)(misc->countdown * 10) % 10);
  if (time == NULL)
    return;
  color = sfColor_fromRGBA(255, misc->countdown,
			   misc->countdown, 100);
  put_word(time, pos, window, color);
  sfree(&time);
}
