/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** shot a duck
*/

#include "my_hunter.h"

static int	__try(misc_t *misc, sfVector2i pos, int index)
{
  misc = misc;
  pos = pos;
  index = index;
  return (0);
}

void		shot_duck(misc_t *misc, sfVector2i pos)
{
  int		i;
  vect_t	*duck;
  sfVector2f	fpos;

  i = 0;
  fpos = xy_vectorf(pos.x, pos.y);
  while (i < misc->ducks.size)
  {
    duck = &misc->ducks.ducks[i];
    if (distance(fpos, duck->pos) < 100 &&
	__try(misc, pos, i) == 1)
      return;
    ++i;
  }
}
