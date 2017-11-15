/*
** EPITECH PROJECT, 2017
** myHunter
** File description:
** shot a duck
*/

#include "my_hunter.h"

#include "my.h"
#include "defines.h"

static int	__try(misc_t *misc, vect_t *duck, sfVector2i pos)
{
  pos.x -= 10;
  if (in_rect(pos, duck->pos, xy_vectorf(42, 42)) == 0)
  {
    duck->status = falling;
    duck->id = 6;
    misc->score += (double)(duck->type * 10 + 1) / 2;
  }
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
    if (distance(fpos, duck->pos) < 60 &&
	__try(misc, duck, pos) == 1)
      return;
    ++i;
  }
}
