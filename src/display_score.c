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
  if (255 - misc->datas.score / 100 < 0)
    dim = 0;
  else
    dim = 255 - misc->datas.score / 100;
  color = sfColor_fromRGBA(255, dim, dim, 100);
  put_number((int)misc->datas.score, pos, window, color);
}

void		display_ammo(window_t *window, misc_t *misc)
{
  sfVector2f	pos;
  sfVector2f	scale;
  int		i;

  i = 0;
  pos.x = 65.0 / 256.0 * window->width;
  pos.y = 208.0 / 240.0 * window->height;
  scale = xy_vectorf(1, 1);
  while (i < misc->datas.ammo)
  {
    put_sprite_resize(window, misc->misc[5], pos, scale);
    pos.x += 17;
    ++i;
  }
}

void		display_time(window_t *window, misc_t *misc)
{
  sfVector2f	pos;
  char		*time;
  sfColor	color;

  pos.x = 200.0 / 256.0 * window->width;
  pos.y = 206.0 / 240.0 * window->height;
  time = catalloc("%d'%d\"%d", (int)misc->datas.countdown / 60,
		  (int)misc->datas.countdown % 60,
		  (int)(misc->datas.countdown * 10) % 10);
  if (time == NULL)
    return;
  color = sfColor_fromRGBA(255, misc->datas.countdown,
			   misc->datas.countdown, 100);
  put_word(time, pos, window, color);
  sfree(&time);
}
