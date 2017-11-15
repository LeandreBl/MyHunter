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

  pos.x = 190.0 / 240.0 * window->width;
  pos.y = 207.0 / 240.0 * window->height;
  put_number((int)misc->score, pos, window, sfWhite);
}
